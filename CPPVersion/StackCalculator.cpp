#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define PARROT 2147483647

#define log(string) { cout << "Line: " << __LINE__ << "\t Function: " << __PRETTY_FUNCTION__ << "\t File: " << __FILE__ << " - "  << string << "\n";  }
#define FUNC(code)   {                       \
                            ControlObject control(__LINE__, __PRETTY_FUNCTION__, __FILE__, this);\
                            {code}                \
                          }                       \



using namespace std;

class Stack;
class ControlObject;

enum State{
    ZEROWARNING = 0, ENDWARNING = 0, OK = 0, BOUNDSERROR = 1
};

struct OKResult{
    State state;
    char* message;
};

class AKException{
public:
    OKResult res;

    AKException(OKResult result) :
    res (result)
    {}
};

class ControlObject{
private:
    static int level__;

    const Stack* stk_;
    int line_;
    const char *func_, *file_ ;
public:
    ControlObject(const int line, const char* func, const char* file, const Stack* stk);

    ~ControlObject();
};

int ControlObject::level__ = 0;

class Stack{
private:
    int* arr;
    int ctr;
    int arrLen;

public:
    Stack() :
    arr (new int[16]),
    ctr (3),
    arrLen(16)
    {
        for(int i = 0; i < 16; i++){
            if(i > 2 && i < 14)  continue;

            arr[i] = PARROT;
        }
    }

    ~Stack(){
        delete [] arr;
    }

    OKResult ok() const{
        State stt = OK;
        char* msg = "";

        //Checking parrots
        for(int i = 0; i < 16; i++){
            if(i > 2 && i < 14)  continue;

            if(arr[i] != PARROT){
                stt = BOUNDSERROR;
                msg = "Some value is out of bounds. ";
                break;
            }
        }

        //Checking warnings
        if(ctr == 3 || ctr == 13){
            stt = stt == OK?   ctr == 3? ZEROWARNING : ENDWARNING   :   stt;
            if(msg == "")
                msg = "Be careful! You can go out of bounds" ;
        }

        //Checking OK
        if(msg == "") msg == "Everything is OK" ;

        return OKResult{ stt, msg } ;
    }

    void push(int value) FUNC(
        arr[ctr] = value;
        ctr++;
    )

    int pop() FUNC(
        ctr--;
        int res = arr[ctr];
        arr[ctr] = 0;
        return res;
    )

    void add() FUNC (
        int res = pop() + pop();
        push(res);
    )

    void deduct() FUNC(
        int res = pop() - pop();
        push(res);
    )

    void multi() FUNC(
        int res = pop() * pop();
        push(res);
    )

    void devide() FUNC(
        int res = pop() / pop();
        push(res);
    )

    void dump() FUNC(
        printf("Stack{ \n");
        for(int i = 0; i < arrLen; i++){
            printf("\t %c[%d]: %d \n", i < ctr? '~' : ' ', i, arr[i]);
        }

        printf("\n  \t  ctr: %d  \n  \t  arrLen: %d \n", ctr, arrLen);

        printf("} \n\n");
    )
};

ControlObject::ControlObject(const int line, const char* func, const char* file, const Stack* stk) :                   //TODO TEMPLATE
    line_ (line),
    func_ (func),
    file_ (file),
    stk_ (stk)
    {
        OKResult res = stk_->ok();
        printf("%*s>>>Line:%d  Function: %s  File: %s - %s \n", level__ * 4, "", line_, func_, file_, res.message);
        if(res.state){
            printf("throw AKException(res); \n");
        }
        level__++;
    }

ControlObject::~ControlObject(){
    OKResult res = stk_->ok();
    level__--;
    printf("%*s<<<Line:%d  Function: %s  File: %s - %s \n", level__ * 4, "", line_, func_, file_, res.message);
    if(res.state){
        printf("throw AKException(res); \n");
    }
}


int main(){
    Stack stk;
    stk.push(10);
    stk.push(10);
    stk.add();
    stk.push(10);
    stk.deduct();
    stk.push(10);
    stk.multi();
    stk.push(10);
    stk.deduct();
}

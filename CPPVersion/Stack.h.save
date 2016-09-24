#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "C:\cppProjects/AKDebug/AKDebug.h"

#define PARROT 0x

class Stack;

class Stack{
private:
    int* buf;
    int* arr;
    int ctr;
    int arrLen;

    const int nParrots = 3;

public:
    Stack() :
    buf (new int[16]),
    arr (buf + nParrots),
    ctr (0),
    arrLen(10)
    {}

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


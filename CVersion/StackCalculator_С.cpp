#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_ARR(array)  (  sizeof(array) / sizeof( (array)[0] )  )
#define square(numb)      (  (numb) * (numb)  )

using std::cout;

struct Stack{
    int* arr;      //Array
    int arrLen;
    int ctr;       //Counter. Basic value has to be 0
};

struct OK{
    bool is;
    char* description;
};

void push(Stack* stk, int value);

int pop(Stack* stk);

void add(Stack* stk);

void deduct(Stack* stk);

void multi(Stack* stk);

void devide(Stack* stk);

void dumpStack(Stack* stk);

Stack StackConstructor();

void StackDestructor(Stack* stk);


int main(){  //Õ≈ –¿¡Œ“¿ﬁ“ Œ“–»÷¿“≈À‹Õ€≈ ◊»—À¿
    Stack stk = StackConstructor();

    push(&stk, 10);
    dumpStack(&stk);

    push(&stk, 15);
    dumpStack(&stk);

    deduct(&stk);
    dumpStack(&stk);

    push(&stk, -5);
    dumpStack(&stk);

    multi(&stk);
    dumpStack(&stk);

    cout << "END";

    StackDestructor(&stk);
}


Stack StackConstructor(){
    Stack stk = {(int*) calloc(10, sizeof(stk.arr[0])), 10, 0};
    return stk;
}

void StackDestructor(Stack* stk){//TODO fix
    for(int i = 0; i < stk->arrLen; i++){
        free((void*) stk->arr[i]);
    }
}

void dumpStack(Stack* stk){
    printf("Stack{ \n");
    for(int i = 0; i < stk->arrLen; i++){
        printf("\t %c[%d]: %d \n", i < stk->ctr? '~' : ' ', i, stk->arr[i]);
    }

    printf("\n  \t  ctr: %d  \n  \t  arrLen: %d \n", stk->ctr, stk->arrLen);

    printf("} \n\n");
}

void push(Stack* stk, int value){
    stk->arr[stk->ctr] = value;
    stk->ctr++;
}
int pop(Stack* stk){
    stk->ctr--;
    return stk->arr[stk->ctr];
}

void add(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 + numb2;
    push(stk, result);
}

void deduct(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 - numb2;
    push(stk, result);
}

void multi(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 * numb2;
    push(stk, result);
}

void devide(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 / numb2;
    push(stk, result);
}

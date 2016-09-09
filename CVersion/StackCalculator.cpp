#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_ARR(array)  (  sizeof(array) / sizeof( (array)[0])  )
#define square(numb)      (  (numb) * (numb)  )

using std::cout;

struct Stack{
    int* arr;      //Array
    int arrLen;
    int ctr;       //Counter. Basic value has to be 0
};

void put(Stack* stk, int value);

int pop(Stack* stk);

void add(Stack* stk);

void deduct(Stack* stk);

void multi(Stack* stk);

void devide(Stack* stk);

void printArr(Stack* stk);


int main(){
    Stack stk = {(int*) calloc(10, sizeof(stk.arr[0])), 10};

    printArr(&stk);

    put(&stk, 10);
    printArr(&stk);

    put(&stk, 7);
    printArr(&stk);

    add(&stk);
    printArr(&stk);

    cout << pop(&stk);
}


void printArr(Stack* stk){
    for(int i = 0; i < stk->arrLen; i++){
        printf("[%d]: %d; ", i, (*stk).arr[i]);
    }
    printf("\t counter: %d \n", stk->ctr);
}

void put(Stack* stk, int value){
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
    put(stk, result);
}

void deduct(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 - numb2;
    put(stk, result);
}

void multi(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 * numb2;
    put(stk, result);
}

void devide(Stack* stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 / numb2;
    put(stk, result);
}

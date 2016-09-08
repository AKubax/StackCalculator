#include <iostream>

using std::cout;

int* mainArr = new int[10];

struct Stack{
    int* arr;      //Array
    int ctr;       //Counter. Basic value has to be 0
};

void put(Stack stk, int value);

int pop(Stack stk);

void add(Stack stk);

void deduct(Stack stk);

void multi(Stack stk);

void devide(Stack stk);

void printArr(Stack stk);


int main(){
    Stack stk;
    stk.arr = mainArr;
    stk.ctr = 0;

    put(stk, 10);
    printArr(stk);

    put(stk, 7);
    printArr(stk);

    add(stk);
    printArr(stk);

    cout << pop(stk);
}

void printArr(Stack stk){
    for(int i = 0; i < 10; i++){
        cout << stk.arr[i] << " " ;
    }
    cout << "\n" ;
}

void put(Stack stk, int value){
    stk.arr[stk.ctr] = value;
    stk.ctr++;
}
int pop(Stack stk){
    int toReturn = stk.arr[stk.ctr];
    stk.ctr--;
    return toReturn;
}

void add(Stack stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 + numb2;
    stk.ctr--;
    put(stk, result);
}

void deduct(Stack stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 - numb2;
    stk.ctr--;
    put(stk, result);
}

void multi(Stack stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 * numb2;
    stk.ctr--;
    put(stk, result);
}

void devide(Stack stk){
    int numb1 = pop(stk);
    int numb2 = pop(stk);
    int result = numb1 / numb2;
    stk.ctr--;
    put(stk, result);
}

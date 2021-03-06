#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "../../AKDebug/AKDebug.h"

#define PARROT 0x15072003
#define POISON 0xDEADF00D

class Stack;

class Stack{
private:
    int safeBegin = PARROT;

    int* buf;
    int* arr;
    int ctr;

    int arrLen;
    int nParrots;
    int bufLen;

    int totalAdd;

    const int safeEnd = PARROT;

//    int updateTotalAdd(){
//        return ((int) buf) + ((int) arr) + ((int) &ctr) + ((int) &arrLen) + ((int) &nParrots) + ((int) &totalAdd) + ((int) &safeBegin) + ((int) &safeEnd);
//    }

    void spillPoison(){
        for(int i = 0; i < arrLen; i++){
            arr[i] = POISON;
        }
    }

public:
    Stack() :
    buf ( (printf("buf \n"), new int[16]) ),
    arr ( (printf("arr \n"), buf + nParrots) ),
    ctr ( (printf("ctr \n"), 0) ),
    arrLen ( (printf("arrLen \n"), 10) ),
    nParrots ( (printf("nParrots \n"), 3) ),
    bufLen ( arrLen + nParrots * 2 ),
    totalAdd (0)                                             //TODO Fix all constructor. DEBUG EVERYWHERE.                                                                                                 //THIS STACK CAN SURVIVE IN A NUCLEAR EXPLOSION AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    {
        printf("Constructor started \n");

        for(int i = 0; i < 16; i++){
            if(i > 2 && i < 14) continue;

            printf("Trying to make parrot \n");

            buf[i] = PARROT;
        }
        printf("Spilling poison \n");
        spillPoison();
    }

    ~Stack(){
        delete [] arr;
        delete [] buf;
    }


    OKResult ok() const{
        OKResult ok;

        //Checking bufLen and arrLen connection
        if(bufLen != arrLen + nParrots * 2){
            ok.error = true;

        }

        //Checking class parrots
        if(safeBegin != PARROT || safeEnd != PARROT){
            ok.error = true;
            ok.message += "|Somebody has incorrect access for class members|";
        }

        //Checking stack parrots
        for(int i = 0; i < nParrots; i++){
            if(buf[i] != PARROT){
                ok.error = true;
                ok.message += "|You or higher power has got out of stack bounds|";
            }
        }

        //Checking if counter was illegally modified
        for(int i = ctr; i < arrLen; i++){
            if(arr[i] != POISON){
                ok.error = true;
                ok.message += "|Stack counter was illegally modified|";
            }
        }

        //Checking if u r in unsafe zone
        if(ctr == 0 || ctr == (arrLen - 1)){
            ok.message += "|WARNING! You can go out of bounds with the next action|";
        }

        return OKResult{ ok.error, ok.message};
    }

    void push(int value) FUNC(
        arr[ctr] = value;
        ctr++;
    )

    int pop() FUNC(
        ctr--;
        int res = arr[ctr];
        arr[ctr] = POISON;
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

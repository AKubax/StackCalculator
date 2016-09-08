#include <iostream>

using namespace std;

class StackCalculator{
public:
    int* arr = new int[10];
    int counter = 0;

    void put(int value){
        arr[counter++] = value;
    }

    int pop(){
        counter--;
        int res = arr[counter];
        arr[counter] = 1;
        return res;
    }

    void add(){
        int res = pop() + pop();
        put(res);
    }

    void ddt(){
        int res = pop() - pop();
        put(res);
    }

    void mlt(){
        int res = pop() * pop();
        put(res);
    }

    void dvd(){
        int res = pop() / pop();
        put(res);
    }

    void printArr(){
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " " ;
    }
    cout << "\t" << counter;
    cout << "\n" ;
}
};


int main(){




}

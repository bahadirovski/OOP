#include <iostream>
#include "stdlib.h"
#include <ctime>
using namespace std;

template <class T = int, class M = int> // default template
class SafeArray {
  private:
    int N;
    T *arr;

    void put(int i, T val) {
      arr[i] = val;
    }

  public:
    SafeArray() {
      N = 0;
      arr = NULL;
    }

    SafeArray(int SIZE, int FILL = 0) {
      if (SIZE != 0) {
        N = SIZE;
        arr = new T[SIZE];
        if (FILL == 0) {
          for (int i = 0; i < SIZE; i++) arr[i] = (T)0; 
        } else {
          T t = static_cast<T>(time(NULL));
          srand(t);
          for (int i = 0; i < SIZE; i++) arr[i] = T(i)/33.; //static_cast<T>(rand()%FILL);
        }
      }   
    }

    T at(M i) {
      if (i < N && i >= 0) {
        return arr[i];
      } else {
        cout << "out of bound !!!" << endl;
        return 0;
      }
    }

    SafeArray<T,M> operator + (SafeArray<T,M> &other) {
      SafeArray<T,M> tmp(N);
      for (int i = 0; i < N; i++) {
        //tmp.put(i, arr[i]+other.arr[i]);
        tmp.arr[i] = arr[i]+other.arr[i];
      }
      return tmp;
    }
};

int main(){
  // test default constructor
  SafeArray <double> sa0;

  // test overloaded constructor
  SafeArray <double> sa1(10, 10);
  SafeArray <double> sa2(10, 5);

  // perform arithmetic operation
  SafeArray <double> sa3 = sa1+sa2;
  //sa3[5] = 4;

  // print content
  for (int i = 0; i < 10; i++){
    cout << sa1.at(i) << "+" << sa2.at(i) << " = " << sa3.at(i) << endl;
    //cout << sa1[i] << "+" << sa2[i] << " = " << sa3[i] << endl;
  }

 return 0;
}

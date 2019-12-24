#ifndef SORT_H_
#define SORT_H_

#include <iostream>
using namespace std;

template <class T>
class Sort{

public:
  Sort(T *arr, int length);
  ~Sort();
  void popSort();
  void quickSort();
  void insertSort();
  void mergeSort();
  void stackSort();
  void display();

private:
  T *arr_ = nullptr;
  int len_ = 0;
};
#endif

template<class T>
Sort<T>::Sort(T *arr, int length):arr_(arr),len_(length)
{
  cout<<"struction func is working !!"<<endl;
}

template<class T>
Sort<T>::~Sort()
{
}

template<class T>
void Sort<T>::popSort()
{
  if(len_ <= 0)
    return;

  for(int i = 0; i < len_ - 1; ++i){
    for(int j = i; j < len_; ++j){
      if(arr_[i] > arr_[j]){
        T tmp = arr_[j];
        arr_[j] = arr_[i];
        arr_[i] = tmp;
      }
    }
  }
}

template<class T>
void Sort<T>::display()
{
  for(int i = 0; i < len_; ++i){
    cout<<" i: "<<arr_[i]<<endl;
  }
}

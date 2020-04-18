#ifndef SORT_H_
#define SORT_H_

#include <iostream>
using namespace std;

template <typename T>
class Sort;

enum SortType{
  POP_SORT=0,
  QUICK_SORT=1,
  INSERT_SORT=2,
  MERGE_SORT=3
};

template <typename T>
class Sort{

public:
  Sort(T *arr, int length);
  ~Sort();
  void SetSortType(SortType type);
  void RunSort();
  void PopSort();//冒泡排序
  void QuickSort(int low, int high);//快速排序
  int GetIndex(int low, int high);//快排获取标志位
  void InsertSort();//插入排序
  void MergeSort(int start, int end);//TODO归并排序
  void Merge(int start, int middle, int end);//TODO合并区间
  void StackSort();//TODO堆排序
  void Display();

private:
  T *arr_ = nullptr;
  int len_ = 0;
  SortType current_sort_type_;
};
#endif

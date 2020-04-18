#include "sort.h"

template<typename T>
Sort<T>::Sort(T *arr, int length):arr_(arr),len_(length)
{
  cout<<"struction func is working !!"<<endl;
}

template<typename T>
Sort<T>::~Sort()
{
}

template<typename T>
void Sort<T>::SetSortType(SortType type)
{
    current_sort_type_ = type;
}

template<typename T>
void Sort<T>::RunSort()
{
    switch (current_sort_type_)
    {
    case POP_SORT:
        PopSort();
        break;
    case QUICK_SORT:
        QuickSort(0, len_-1);
        break;
    case INSERT_SORT:
        InsertSort();
        break;
    case MERGE_SORT:
        MergeSort(0, len_-1);
        break;
    default:
        break;
    }
    Sort<T>::Display();
}

template<typename T>
void Sort<T>::PopSort()
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

template<typename T>
void Sort<T>::QuickSort(int low, int high)
{
    //利用迭代进行快排
    if (low<high)
    {
        int index = GetIndex(low, high);
        QuickSort(low, index-1);
        QuickSort(index+1, high);
    }
}

template<typename T>
int Sort<T>::GetIndex(int low, int high)
{
    T tmp = arr_[low];
    while (high>low)
    {
        while (tmp<arr_[high] && high>low)
        {
            high--;   
        }
        arr_[low] = arr_[high];
        while (tmp>arr_[low] && high>low)
        {
            low++;
        }
        arr_[high] = arr_[low];
    }
    arr_[low] = tmp;
    return low;
}

template<typename T>
void Sort<T>::InsertSort() 
{ 
    for (size_t i = 1; i < len_; i++)
    {
        T tmp = arr_[i];
        for (size_t j=i-1; j>=0; j--)
        {
            if (tmp>=arr_[j])
            {
                arr_[j+1] = tmp;
                break;
            }
            arr_[j+1]=arr_[j];
        }
    }
}

template<typename T>
void Sort<T>::MergeSort(int start, int end)
{
    if (start>=end)
    {
        return;
    }
    int devide = (start+end)/2;
    MergeSort(start, devide);  
    MergeSort(devide+1, end);
    Merge(start, devide, end);
}

template<typename T>
void Sort<T>::Merge(int start, int middle, int end)
{
    //定义好两个区间的标志符
    int i = start, j= middle + 1;
    int size = end - start + 1;
    int pos = 0;
    //为新数组开辟空间
    T* tmp = new T[size];

    //为两个区间排序
    while (i <= middle && j <= end)
    {
        if (arr_[i] <= arr_[j])
        {
            tmp[pos] = arr_[i];
            i++;
            pos++;
            continue;
        } else
        {
            tmp[pos] = arr_[j];
            j++;
            pos++;
            continue;
        }
    }
    while (j<=end)
    {
        tmp[pos] = arr_[j];
        pos++;
        j++;
    }
    while (i<=middle)
    {
        tmp[pos] = arr_[i];
        pos++;
        i++;
    }

    //将排好序的数组转移到原数组里面
    for (size_t i = 0; i < size; i++)
    {
        arr_[i+start] = tmp[i];
    }
    delete [] tmp; 
}

template<typename T>
void Sort<T>::Display()
{
  for(int i = 0; i < len_; ++i){
    cout<<" i: "<<arr_[i]<<endl;
  }
} 

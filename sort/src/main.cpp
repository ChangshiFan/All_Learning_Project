#include <iostream>
#include <array>
#include "sort.hpp"


using namespace std;


int main()
{
  int arr_test[] = {21, 34, 3, 56, 7, 12, 8, 9, 87, 54};
  int size = sizeof (arr_test)/sizeof(arr_test[0]);
  Sort<int> sort(arr_test, size);
  // sort.SetSortType(POP_SORT);
  //sort.SetSortType(QUICK_SORT);
  // sort.SetSortType(INSERT_SORT);
  sort.SetSortType(MERGE_SORT);
  //sort.popSort();
  sort.RunSort();
  return 0;
}



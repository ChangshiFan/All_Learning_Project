#include <iostream>
#include <array>
#include "sort.h"


using namespace std;


int main()
{
  int arr_test[] = {21, 34, 3, 56, 7, 12, 8, 9, 87, 54};
  int size = sizeof (arr_test)/sizeof(arr_test[0]);
  Sort<int> sort(arr_test, size);
  sort.popSort();
  sort.display();
  return 0;
}



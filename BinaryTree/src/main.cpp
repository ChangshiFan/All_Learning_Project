#include <iostream>
#include "binary_tree.h"

using namespace std;
int main()
{
  int arr[] = {8, 2, 9, 6, 14, 17, 3, 1, 0, 20};
  int length = sizeof(arr)/sizeof (arr[0]);
  BinaryTree<int> bt(arr, length);

  //cout<<"test: "<<n.value<<"  "<<n.left<<endl;

  return 0;
}


#include <iostream>
#include "binary_tree.hpp"

using namespace std;
int main()
{
  int arr[] = {8, 2, 14, 6, 9, 17, 3, 1, 0, 20};
  int length = sizeof(arr)/sizeof (arr[0]);
  BinaryTree<int> bt(arr, length);
  bt.Traverse(POST_ORDER);

  //cout<<"test: "<<n.value<<"  "<<n.left<<endl;

  return 0;
}


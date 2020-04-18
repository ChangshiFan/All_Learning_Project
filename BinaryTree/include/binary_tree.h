#ifndef BINARY_TREE_H
#define BINARY_TREE_H
 
#include <iostream>

enum TraverseType{
  PRO_ORDER=0,
  IN_ORDER=1,
  POST_ORDER=2 
};

template<class T> 
struct Node{
public:
  T value;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

template<class T>
class BinaryTree{
public: 
  BinaryTree(); 
  BinaryTree(const T arr[], int length);
  ~BinaryTree();
  void insertNode(T value);
  void Traverse(TraverseType traverse_type);
  void deletNode(T value);
  bool serchNode(T value);
  void serchTree(int mode);

private:
  void preOrder(Node<T> *root);//TODO前序遍历
  void inOrder();//TODO中序遍历
  void postOrder(Node<T> *root);//TODO后序遍历
  void destroyTree(Node<T>* n);

  int node_num_;
  Node<T> *root_node_;

};
#endif

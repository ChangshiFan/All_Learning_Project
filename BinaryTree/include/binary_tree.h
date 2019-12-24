#ifndef BINARY_TREE_H
#define BINARY_TREE_H
 
#include <iostream>

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
  void deletNode(T value);
  bool serchNode(T value);
  void serchTree(int mode);

private:
  void sort();
  void preOrder();
  void inOrder();
  void postOrder();
  void destroyTree(Node<T>* n);

  int node_num_;
  Node<T> *root_node_;

};

template<class T>
BinaryTree<T>::BinaryTree():node_num_(0),root_node_(nullptr)
{

}

template<class T>
BinaryTree<T>::BinaryTree(const T arr[], int length)
{
  node_num_++;
  if(length <= 0){
    std::cout<<"BinaryTree init failed !"<<std::endl;
    return;
  }
  root_node_ = new Node<T>;
  root_node_->value = arr[0];
  node_num_++;
  for(int i = 1; i < length; ++i){
    insertNode(arr[i]);
  }
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
  destroyTree(root_node_);
}

template<class T>
void BinaryTree<T>::insertNode(T value)
{
  std::cout<<"  node_num: "<<node_num_<<" value: "
          <<value<<std::endl;
  Node<T> *new_node = new Node<T>;
  new_node->value = value;

  node_num_++;
  if(root_node_ == nullptr){
    root_node_ = new_node;
    return;
  }

  Node<T> *h = root_node_;
  Node<T> *current = nullptr;

  while(h != nullptr){
    current = h;
    if(value > h->value)
      h = h->right;
    else
      h = h->left;
  }
  new_node->parent = current;
  if(value < current->value){
    current->left = new_node;
  }else{
    current->right = new_node;
  }
}

template<class T>
void BinaryTree<T>::serchTree(int mode)
{

}

template<class T>
void BinaryTree<T>::destroyTree(Node<T> *n)
{
  if(n == nullptr)
    return;

  if(n->left != nullptr)
    destroyTree(n->left);
  else if(n->right != nullptr)
    destroyTree(n->right);

  delete n;
  n = nullptr;
}

#endif

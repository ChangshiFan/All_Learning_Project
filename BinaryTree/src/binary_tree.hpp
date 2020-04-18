#include "binary_tree.h"

template<class T>
BinaryTree<T>::BinaryTree():node_num_(0),root_node_(nullptr)
{

}

template<class T>
BinaryTree<T>::BinaryTree(const T arr[], int length)
{
  node_num_ = 1;
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

template<typename T>
void BinaryTree<T>::Traverse(TraverseType traverse_type)
{
  switch (traverse_type)
  {
  case POST_ORDER:
    postOrder(root_node_);
    break;
  
  default:
    break;
  }
}

template<typename T>
void BinaryTree<T>::preOrder(Node<T> *root)
{
  if (root != nullptr)
  {
    std::cout<<"pre_value: "<<root->value<<std::endl;
    preOrder(root->left);
    preOrder(root->right);
  }
  
}

template<typename T>
void BinaryTree<T>::postOrder(Node<T> *root)
{
  if (root != nullptr)
  {
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<"post_value: "<<root->value<<std::endl;
  }
}
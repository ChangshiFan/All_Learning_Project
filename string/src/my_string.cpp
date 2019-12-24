#include "my_string.h"

MyString::MyString()
{
  len_ = 0;
  my_str_ = new char[1];
  my_str_[0] = '\0';
}

MyString::MyString(const char *const str)
{
  if(str){
    len_ = strlen(str);
    my_str_ = new char [len_ + 1];
    strcpy(my_str_, str);
  }else{
    MyString();
  }
}

MyString::MyString(const MyString &str)
{
  cout<<"copy function !"<<endl;
  len_ = str.length();
  my_str_ = new char [len_ + 1];
  strcpy(my_str_, str.getStr());
}

MyString::~MyString()
{
  delete []my_str_;
  len_ = 0;
}

MyString MyString::operator+(const MyString &str)
{
//  MyString new_str;
//  new_str.len_ = str.length() + len_;
//  new_str.my_str_ = new char[new_str.len_ + 1];
//  strcpy(new_str.my_str_, str.my_str_);
//  strcat(new_str.my_str_, my_str_);
//  return new_str;
  int len = str.length() + len_;
  char* new_str = new char[len + 1];
  strcat(new_str, my_str_);
  strcat(new_str, str.getStr());
  MyString new_my_str(new_str);
  delete[] new_str;
  return new_my_str;
}

MyString &MyString::operator+=(const MyString &str)
{
  if(str.length() <= 0)
    return *this;
  len_ += str.length();
  char *new_my_str = new char[len_ + 1];
  strcpy(new_my_str, my_str_);
  strcat(new_my_str, str.getStr());
  delete []my_str_;
  my_str_ = new_my_str;
  delete new_my_str;
  return *this;
}

char MyString::operator[](int index)
{
  if(index > len_){
    std::cout<<"index out of range ！！"<<std::endl;
    std::cout<<"The last char is : ";
    return my_str_[-1];
  }
  return my_str_[index-1];
}

bool MyString::operator==(const MyString &str)
{
  if(str.length() != len_)
    return false;
  if(strcmp(my_str_, str.getStr()))
    return true;
}

MyString &MyString::operator=(const MyString &str)
{
  if(this == &str)
    return *this;

  delete []my_str_;
  my_str_ = new char[str.length() + 1];
  strcpy(my_str_, str.getStr());
  return *this;
}

MyString &MyString::operator=(const char *str)
{
  delete []my_str_;
  this->len_ = strlen(str);
  my_str_ = new char[len_ + 1];
  strcpy(my_str_, str);
  return *this;
}

char &MyString::strOfIndex(int index)
{
  if(index > len_){
    std::cout<<"index out of range ！！"<<std::endl;
    std::cout<<"The last char is : ";
    return my_str_[-1];
  }
  return my_str_[index];
}

const char *MyString::getStr()const
{
  return my_str_;
}

ostream &operator<<(ostream &os, const MyString &str)
{
  os << str.getStr();
  return os;
}

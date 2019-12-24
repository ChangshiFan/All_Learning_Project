#pragma once
 
#include <iostream>
#include <string.h>

using namespace std;
class MyString{

public:
  MyString();//默认构造函数
  MyString(const char *str);//使用字符串进行初始化
  MyString(const MyString &str);//拷贝构造函数
  ~MyString();//析构函数
  //重载运算符
  MyString operator+(const MyString &str);//字符串拼接
  MyString &operator+=(const MyString &str);//字符串延长
  char operator[](int index);//返回特定位置字符
  inline bool operator==(const MyString &str);
  MyString &operator=(const MyString &str);
  MyString &operator=(const char *str);
  friend ostream &operator<<(ostream &os, const MyString &str);//重载输出符号

  //基本功能函数
  char &strOfIndex(int index);
  int length() const {return len_;}
  const char *getStr()const;

private:
  int len_;
  char *my_str_;

};

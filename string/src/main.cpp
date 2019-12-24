#include <iostream>
#include"my_string.h"

using namespace std;
void display(MyString str);
int main()
{
  char str[] = "hello world";
  char sstr[] = "hello every";
  char sssre[] = "hello beautiful";

  MyString m_string;
  m_string = str;
  cout<<"test_01: "<<m_string.getStr()<<"  char's number: "<<m_string.length()<<endl;

  MyString my_string(sstr);
  cout<<"test_02: "<<my_string.getStr()<<endl;

  MyString plus_string = my_string + m_string;
  cout<<"test_03: "<<plus_string<<endl;

  MyString myy_string(sssre);
  cout<<"test_04: "<<myy_string<<endl;

  myy_string = my_string;
  char id = myy_string[7];
  cout<<"test_05: "<<myy_string<<" index 7 :"<<id<<endl;

  display(myy_string);

  return 0;
}

void display(MyString str)
{
  cout<<str<<endl;
}

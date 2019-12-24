#include "kongfu.h"

JianFa::JianFa(std::string janfa_name, int damage_value)
  :janfa_name_(janfa_name), damage_value_(damage_value)
{
  std::cout<<"jan fa is construction !"<<std::endl;
}

std::string JianFa::getKongFuName() const
{
  return janfa_name_;
}

int JianFa::getDamageValue() const
{
  return damage_value_;
}

void JianFa::setJanFaName(std::string janfa_name)
{
  janfa_name_ = janfa_name;
}

void JianFa::Jprint() const
{
  std::cout<<"  Jian Fa name: "<<getJanFaName()<<" damage_value: "<<getJanFaDamageValue()<<std::endl;
}

//DuGuJiuJian::DuGuJiuJian(std::string jf_name, int damage_value)
//  :JianFa(jf_name, damage_value)
//{
//  std::cout<<"du gu jiu jian is construction !"<<std::endl;
//}

DuGuJiuJian::DuGuJiuJian(std::string jf_name, int damage_value)
  :JianFa(jf_name, damage_value){
  std::cout<<"du gu jiu jian is construction !"<<std::endl;
}

std::string DuGuJiuJian::getJanFaName() const
{
  return JianFa::getJanFaName();
}

int DuGuJiuJian::getJanFaDamageValue() const
{
  return JianFa::getJanFaDamageValue();
}

void DuGuJiuJian::Jprint() const
{
  std::cout<<"  Du Gu Jiu Jian ";
  JianFa::Jprint();
}

//PiXieJianFa::PiXieJianFa(std::string jf_name, int damage_value)
//  :JianFa(jf_name, damage_value)
//{
//  std::cout<<" pi xie jian fa is construction !"<<std::endl;
//}

PiXieJianFa::PiXieJianFa(std::string jf_name, int damage_value)
  :JianFa(jf_name, damage_value){
  std::cout<<" pi xie jian fa is construction !"<<std::endl;
}

std::string PiXieJianFa::getJanFaName() const
{
  return JianFa::getJanFaName();
}

int PiXieJianFa::getJanFaDamageValue() const
{
  return JianFa::getJanFaDamageValue();
}

void PiXieJianFa::Jprint() const
{
  std::cout<<"  Pi Xie Jan Fa ";
  JianFa::Jprint();
}

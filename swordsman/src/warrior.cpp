#include "warrior.h"

DaXia::DaXia(std::string name, int age, int talent)
  :self_name_(name),self_age_(age),talent_(talent)
{
  std::cout<<"DaXia is construction !!"<<std::endl;
}

inline void DaXia::setSelfName(std::string str_name)
{
  self_name_ = str_name;
}

void DaXia::setSelfAge(int age)
{
  self_age_ = age;
}

LingHuChong::LingHuChong(JianFa *jf, std::string name, int age, int talent)
  :DaXia( name, age, talent), jf_(jf)
{
  std::cout<<" ling hu chong construction !"<<std::endl;
}

inline void LingHuChong::setSelfName(std::string str_name)
{
  DaXia::setSelfName(str_name);
  auto ling_name = [this](void)->void{
    std::cout<< "set ling hu chong name: " << this->DaXia::getSelfName() <<std::endl;
  };
  ling_name();
}

void LingHuChong::setSelfAge(int age)
{
  DaXia::setSelfAge(age);
  auto ling_age = [this](void)->void{
    std::cout<< "set ling hu chong age: " << DaXia::getSelfAge() <<std::endl;
  };
  ling_age();
}

void LingHuChong::lprint() const
{
  std::cout<<"name: "<<this->DaXia::getSelfName()<<" age: "<<this->DaXia::getSelfAge()<<
             " talent: "<<this->DaXia::getTalent();
  jf_->Jprint();
}

int LingHuChong::getDamageValue() const
{
  return jf_->getJanFaDamageValue();
}

int LingHuChong::getTalent() const
{
  return DaXia::getTalent();
}

YueBuQun::YueBuQun(JianFa *jf, std::string name, int age, int talent)
  :DaXia(name, age, talent), jf_(jf)
{
  std::cout<<" yue bu qun construction !"<<std::endl;
}

void YueBuQun::setSelfName(std::string str_name)
{
  DaXia::setSelfName(str_name);
  auto yue_name = [this](void)->void{
    std::cout<< "set yue bu qun name: " << this->DaXia::getSelfName() <<std::endl;
  };
  yue_name();
}

void YueBuQun::setSelfAge(int age)
{
  DaXia::setSelfAge(age);
  auto yue_age = [this](void)->void{
    std::cout<< "set yue bu qun age: " << DaXia::getSelfAge() <<std::endl;
  };
  yue_age();
}

void YueBuQun::yprint() const
{
  std::cout<<"name: "<<this->DaXia::getSelfName()<<" age: "<<this->DaXia::getSelfAge()<<
             " talent: "<<this->DaXia::getTalent();

  jf_->Jprint();
}

int YueBuQun::getDamageValue() const
{
  return jf_->getJanFaDamageValue();
}

int YueBuQun::getTalent() const
{
  return DaXia::getTalent();
}

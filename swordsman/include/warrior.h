#ifndef WARRIOR_H_
#define WARRIOR_H_
#include <iostream>
#include "kongfu.h"

class DaXia{
public:
  DaXia(std::string name, int age, int talent_);
  virtual ~DaXia(){
    std::cout<<"DaXia is deleting !"<<std::endl;
  };
  virtual void setSelfName(std::string str_name);
  virtual void setSelfAge(int age);
  std::string getSelfName() const{return self_name_;}
  int getSelfAge() const{return self_age_;}
  int getTalent() const{return talent_;}
private:
  int talent_;
  std::string self_name_;
  int self_age_;
};

class LingHuChong : public DaXia
{
public:
  LingHuChong(JianFa *jf, std::string name, int age, int talent);
  ~LingHuChong() override{
    jf_ = nullptr;
    std::cout<<"ling is deleting !"<<std::endl;
  }
  void setSelfName(std::string str_name) override;
  void setSelfAge(int age) override;
  void lprint() const;
  int getDamageValue() const;
  int getTalent() const;
  std::string getSelfName() const{return DaXia::getSelfName();}
private:

  JianFa *jf_ = nullptr;
};

class YueBuQun : public DaXia
{
public:
  YueBuQun(JianFa *jf, std::string name, int age, int talent);
  ~YueBuQun() override{
    jf_ = nullptr;
    std::cout<<"yue is deleting !"<<std::endl;
  }
  void setSelfName(std::string str_name) override;
  void setSelfAge(int age) override;
  void yprint() const;
  int getDamageValue() const;
  int getTalent() const;
  std::string getSelfName() const{return DaXia::getSelfName();}
private:

  JianFa *jf_ = nullptr;
};
#endif

#ifndef KONGFU_H_
#define KONGFU_H_
#include <iostream>

class KongFu{
 public:
  virtual ~KongFu(){
    //std::cout<<"pur deleting must be defined !"<<std::endl;
  }
  virtual std::string getKongFuName() const=0;
  virtual int getDamageValue() const=0;
  virtual void Jprint() const=0;
};

class JianFa : public KongFu{
 public:
  explicit JianFa(std::string janfa_name, int damage_value);
  virtual ~JianFa() override{}
  std::string getKongFuName() const override;
  int getDamageValue() const override;
  void setJanFaName(std::string janfa_name);
  void setJanFaDamageValue(int damage_value);
  std::string getJanFaName() const{return janfa_name_;}
  int getJanFaDamageValue() const{return damage_value_;}
  virtual void Jprint() const override;
 private:
  std::string janfa_name_;
  int damage_value_;
};

class DuGuJiuJian : public JianFa{
 public:
  DuGuJiuJian(std::string jf_name, int damage_value);
  ~DuGuJiuJian() override{}
  std::string getJanFaName() const;
  int getJanFaDamageValue() const;
  void Jprint() const override;
};

class PiXieJianFa : public JianFa{
 public:
  PiXieJianFa(std::string jf_name, int damage_value);
  ~PiXieJianFa() override{}
  std::string getJanFaName() const;
  int getJanFaDamageValue() const;
  void Jprint() const override;
};
#endif

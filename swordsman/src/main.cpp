/*
 * i'm new, just for testing C plus plus.
 * include inherit, multi state, multi thread
 *
 * author: chance
 * time  : 2019 12 23 18:40
 *
 *
 */
#include <iostream>
#include <memory>
#include <thread>
#include <pthread.h>
#include <mutex>
#include "warrior.h"

using namespace std;
void fire1(LingHuChong *ling, YueBuQun *yue);
void fire2(LingHuChong *ling, YueBuQun *yue);
static std::mutex m_lock;
int main()
{
  shared_ptr<DuGuJiuJian> dgjj(new DuGuJiuJian("D G J J", 100));
  shared_ptr<PiXieJianFa> pxjf(new PiXieJianFa("P X J F", 90));
  LingHuChong linghu(dgjj.get(), "LingHu", 24, 99);
  linghu.lprint();
  YueBuQun buqun(pxjf.get(), "BuQun", 50, 50);
  buqun.yprint();

  std::thread first(fire1, &linghu, &buqun);
  //fire1(&linghu, &buqun);

  ///////////////////////////
  linghu.setSelfName("genius");
  linghu.setSelfAge(26);
  buqun.setSelfName("false_man");
  buqun.setSelfAge(52);
  std::thread second(fire2, &linghu, &buqun);
  //fire2(&linghu, &buqun);
  first.join();
  second.join();
  return 0;
}

void fire1(LingHuChong *ling, YueBuQun *yue)
{
  m_lock.lock();
  int ling_fire_value = ling->getTalent()*ling->getDamageValue()/ling->getSelfAge();
  int yue_fire_value = yue->getTalent()*yue->getDamageValue()/yue->getSelfAge();
  m_lock.unlock();
  std::cout<<"first fire !"<<std::endl;
  if(ling_fire_value > yue_fire_value){
    std::cout<<"LingHuChong is win !"<<std::endl;
  }else{
    std::cout<<"YueBuQun is win !"<<std::endl;
  }
}
void fire2(LingHuChong *ling, YueBuQun *yue)
{
  m_lock.lock();
  int ling_fire_value = ling->getTalent()*ling->getDamageValue()/ling->getSelfAge();
  int yue_fire_value = yue->getTalent()*yue->getDamageValue()/yue->getSelfAge();
  m_lock.unlock();
  std::cout<<"second fire !"<<std::endl;
  if(ling_fire_value > yue_fire_value){
    std::cout<<"LingHuChong is win !"<<std::endl;
  }else{
    std::cout<<"YueBuQun is win !"<<std::endl;
  }
}

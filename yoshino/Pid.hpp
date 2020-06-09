#ifndef PID_H
#define PID_H

#include "PidGain.hpp"

#define ENABLE_RST 0

//タスク周期の定義
extern const double TASK_TERM_MILLIS;

#if ENABLE_RST
/* ------------------------------------------
防飽オプション
RST: "reset"      累積値の消去 
CNT: "continue"   累積の継続
-------------------------------------------*/
enum Option {RST, CNT};
#endif

/* ------------------------------------------
Pidクラス
-------------------------------------------*/
class Pid {
private:
  PidGain gain;
  
  double sum_dt(double target, double output);//積分項
#if ENABLE_RST/*飽和防止オプション*/
  double sum_dt(double target, double output, Option opt);
#endif
  double diff_dt(double target, double output);//微分項

public:
  //コンストラクタ
  Pid(double Kp_, double Ki_, double Kd_);
  
  //誤差出力
  double error(double target, double output);
  //操作量出力
  double control(double target, double output);
  
#if ENABLE_RST//飽和防止オプション
  double control(double target, double output, Option opt);
#endif
};

#endif

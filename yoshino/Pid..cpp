#include "Pid.hpp"

const double TASK_TERM_MILLIS = 0.004;//タスク周期

//コンストラクタ
Pid::Pid(double Kp_, double Ki_, double Kd_)
  : gain(Kp_, Ki_, Kd_)
{
}

//誤差取得
double Pid::error(double target, double output)
{
  return target - output;
}

//制御量出力(ワンショット)
double Pid::control(double target, double output)
{
  return
    gain.Kp * error(target, output)
    + gain.Ki * sum_dt(target, output)
    + gain.Kd * diff_dt(target, output);
}

#if ENABLE_RST
// 第三引数：積分値飽和防止オプション
double Pid::control(double target, double output, Option opt)
{
  return
    gain.Kp * error(target, output)
    + gain.Ki * sum_dt(target, output, opt)
    + gain.Kd * diff_dt(target, output);
}
#endif


/*-----private-------------------------------------*/
//積分項(Pidクラス専用)
double Pid::sum_dt(double target, double output)
{
  static double errSum;//誤差のかき集め
  errSum += error(target, output) * TASK_TERM_MILLIS;
  return errSum;
}

#if ENABLE_RST
//オプション付き積分項  第三引数：飽和防止オプション
double Pid::sum_dt(double target, double output, Option opt)
{
  static double errSum;//誤差のかき集め

  if(opt==RST){//誤差のリセット
    errSum = 0;
    opt = CNT;
  }
  errSum += error(target, output) * TASK_TERM_MILLIS; 
  return errSum;
}
#endif

//微分項(Pidクラス専用)
double Pid::diff_dt(double target, double output)
{
  static double prevErr;//前回の誤差
  double exisErr = error(target, output);//今回の誤差
  double errDiff = (exisErr - prevErr) / TASK_TERM_MILLIS;//微分
    
  //今回の誤差を次回の微分計算に用いるために記憶
  prevErr = exisErr;
  return errDiff;
}
/*-------------------------------------------------*/

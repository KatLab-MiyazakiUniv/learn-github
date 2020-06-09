#ifndef PID_GAIN_H 
#define PID_GAIN_H

class PidGain
{
    public:
        //メンバ変数
        double Kp;
        double Ki;
        double Kd;
        // コンストラクタ
        PidGain(double Kp_ ,double Ki_ , double Kd_);
        //メンバ関数
        void setPidGain(double Kp_ ,double Ki_ , double Kd_);
};

#endif
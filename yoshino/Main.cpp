#include <stdio.h>
#include "Pid.hpp"

#include <stdlib.h>//plot用
#include <math.h>//シミュレート用

#define N 1000 //計算回数
#define M 13  //負荷の重さ
#define DIST -30//外乱

#define DEBUG

//評価用FIRローパスフィルタ
double delayBench(double input);

//Visualize on a laptop
void plot(double* waveTable);
double waveTable[N+1];

//メイン関数
int main(void)
{
  double Kp = 0.15; //見本: 0.6
  double Ki = 0.2; //見本: 0.08
  double Kd = 0.01; //見本: 0.04

  Pid pid(Kp, Ki, Kd);//インスタンス

  double target = 200.0;//目標値
  double output = 0.0;//応答出力

  double controlValue = pid.control(target, output);

  for(int i=0; i<N+1; i++){
    waveTable[i] = output;//可視化テーブルに書き込む
    controlValue = (i<N/2) ? pid.control(target, output)
      : (pid.control(target, output) + DIST);
    output += delayBench( controlValue );
    //output += controlValue; 
  }

  plot(waveTable);//可視化

  return 0;
}


//模擬の制御対象
double delayBench(double input)
{
  const unsigned char len = M;
  static double waveTable[len];
  double output;

  waveTable[0] = input;
  
  for(int i=0; i<len; i++){
    output += waveTable[i];
  } output /= (double)len;

  for(int i=len-1; i>0; i--)
    waveTable[i] = waveTable[i-1];

  return output;  
}


//gnuplot出力
void plot(double* waveTable)
{
  FILE *gp;

  // gnuplotの起動コマンド
  gp = popen("gnuplot -persist", "w");	// gnuplotをパイプで起動
  
  // --- gnuplotにコマンドを送る --- //
  fprintf(gp, "set xrange [0:%d]\n", N); // 範囲の指定(省略可)
  fprintf(gp, "set yrange [0:300]\n");

  //描く
  fprintf(gp, "plot '-' with lines lw 3 title \"PID\"\n");

  for(int i=0; i<N+1; i++)
    fprintf(gp,"%d\t%f\n" , i, waveTable[i]);
 
  fprintf(gp, "exit\n"); // gnuplotの終了
  printf("最終値: %lf\n", waveTable[N-1]);
  pclose(gp);
}

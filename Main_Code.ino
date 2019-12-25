//----------------------------------------------------Definitions------------------------------------------------------------------------------
#include <SparkFun_TB6612.h>

//--------Motor Definitions----------

#define PWMA 5
#define AIN1 7
#define AIN2 6
#define PWMB 11
#define BIN1 9
#define BIN2 10
#define STBY 8

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

//--------Connections----------

#define button 2
#define Rled 13
#define buzzer 3

//------------------------------speed declaration--------------------------------------
int lf_speed = 150;
int t_speed = 170;
int f_speed = 110;

float Kp = 0.07, Ki = 0, Kd = 3;
float error = 0, P = 0, I = 0, D = 0, PIDvalue = 0;
float previousError = 0;

int timer1 = 0;
int limit = 500; //------------Timer limit for node detection---------

int l = 0;
int s = 0;
int r = 0;
int x = 0;
int y = 0;
int u = 0;
int mazesolved = 0;
int calibrated = 0;
byte paths = 0;
bool block = 0;
String str ;
int SValue[8][3];
int endpos = 0;

//-------------------------------------------------------Setup Code----------------------------------------------------------------

void setup()
{

  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(Rled, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
}





//-------------------------------------------------------void_loop--------------------------------------------------------------------------

void loop()
{
  while (calibrated == 0)
  {
    calib();
  }

  while (digitalRead(button) == 0) {} //------------ button press---------
  delay(200);

  while (mazesolved == 0)
  {
    lf_node();
    check_node();
  }

  //----------------------Replacement rules (Need to add for X & Y)
  for (int x = 0; x < 10; x++)
  {
    str.replace("LULUS", "U");
    str.replace("LUSUL", "U");
    str.replace("LUL", "S");
    str.replace("SUS", "U");
    str.replace("SUL", "R");
    str.replace("LUS", "R");
    str.replace("RUL", "U");
    str.replace("XUL", "Y");
    str.replace("XUX", "R");
    str.replace("YUR", "X");
    
  }

  endpos = str.indexOf('E');

  while (digitalRead(button) == 0) {} //------------ button press---------
  delay(200);
  final_run();

}

//-------------------------------------------------------void Cbrake--------------------------------------------------------------------------
void Cbrake()
{
  brake(motor1, motor2);
  delay(20);
  motor1.drive(-50);
  motor2.drive(-50);
  delay(70);
  brake(motor1, motor2);
}
//-------------------------------------------------------void go_left--------------------------------------------------------------------------
void go_left()
{
  while (analogRead(1) > SValue[1][2])
  {
    motor1.drive(-80);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(100);

  motor1.drive(-80);
  motor2.drive(100);
  delay (300);

  while (analogRead(5) > SValue[5][2])
  {
    motor1.drive(-80);
    motor2.drive(100);
  }

  brake(motor1, motor2);
  delay(100);
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}

//-------------------------------------------------------void go_x--------------------------------------------------------------------------
void go_x()
{
  while (analogRead(3) >  SValue[3][2])
  {
    motor1.drive(-100);
    motor2.drive(-100);
  }
  while (analogRead(5) >  SValue[5][2])
  {
    motor1.drive(-80);
    motor2.drive(100);
  }
  brake(motor1, motor2);
  delay(100);

  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}
//-------------------------------------------------------void go_right--------------------------------------------------------------------------
void go_right()
{
  while (analogRead(6) >  SValue[6][2])
  {
    motor1.drive(-80);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(100);

  motor1.drive(100);
  motor2.drive(-80);
  delay (300);

  while (analogRead(4) >  SValue[4][2])
  {
    motor1.drive(100);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(100);
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}

//-------------------------------------------------------void go_y--------------------------------------------------------------------------
void go_y()
{
  while (analogRead(3) >  SValue[3][2])
  {
    motor1.drive(-100);
    motor2.drive(-100);
  }
  while (analogRead(4) > SValue[4][2])
  {
    motor1.drive(100);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(100);
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}
//-------------------------------------------------------void go_straight--------------------------------------------------------------------------

void go_straight()
{
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}

//-------------------------------------------------------void u_turn--------------------------------------------------------------------------

void u_turn()
{
  motor1.drive(-100);
  motor2.drive(-100);
  delay(200);

  brake(motor1, motor2);
  delay(100);

  while (analogRead(2) > SValue[2][2])
  {
    motor1.drive(60);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(50);
  while (analogRead(5) > SValue[5][2])
  {
    motor1.drive(-80);
    motor2.drive(65);
  }
  brake(motor1, motor2);
  delay(100);
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}
void blockTurn()
{
  //  motor1.drive(-100);
  //  motor2.drive(-100);
  //  delay(150);

  //  brake(motor1, motor2);
  //  delay(100);


  motor1.drive(60);
  motor2.drive(-80);
  delay(300);
  
  while (analogRead(2) > SValue[2][2])
  {
    motor1.drive(60);
    motor2.drive(-80);
  }
  brake(motor1, motor2);
  delay(50);
  while (analogRead(5) > SValue[5][2])
  {
    motor1.drive(-80);
    motor2.drive(65);
  }
  brake(motor1, motor2);
  delay(100);
  for (int m = 0; m < 500; m++)
  {
    line_follow();
  }
}

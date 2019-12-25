//-------------------------------------------------------check_node--------------------------------------------------------------------------

void check_node()
{
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  
  if ((analogRead(0) < SValue[0][2]) && (analogRead(1) < SValue[1][2]) && (analogRead(6) < SValue[6][2]) && (analogRead(7) < SValue[7][2]))
  {
    motor1.drive(100);
    motor2.drive(100);
    delay(200);
    Cbrake();
    digitalWrite(Rled, HIGH);
    delay(1000);
    digitalWrite(Rled, LOW);
    mazesolved = 1;
    str += "E";
  }

  else if (l == 1 && paths > 1)
  {
    str += "L";
    go_left();
  }

  else if (x == 1 && paths > 1)
  {
    str += "X";
    go_x();
  }
  else if (s == 1 && paths > 1)
  {
    str += "S";
    go_straight();
  }
  else if (y == 1 && paths > 1)
  {
    str += "Y";
    go_y();
  }
  else if (r == 1 && paths > 1)
  {
    str += "R";
    go_right();
  }
  else if (u == 1)
  {
    str += "U";
    u_turn();
  }
  l = 0; s = 0; r = 0; x = 0; y = 0; u = 0; timer1 = 0; paths = 0;
}

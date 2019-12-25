//-------------------------------------------------------final_run--------------------------------------------------------------------------
void final_run()
{
  for (int i = 0; i <= endpos; i++)
  {
    char node = str.charAt(i);
    switch (node)
    {
      case 'L':
        lf_node();
        brake(motor1, motor2);
        delay(50);
        go_left();
        paths = 0;
        break;

      case 'X':
        lf_node();
        go_x();
        paths = 0;
        break;

      case 'S':
        lf_node();
        go_straight();
        paths = 0;
        break;

      case 'Y':
        lf_node();
        go_y();
        paths = 0;
        break;

      case 'R':
        lf_node();
        go_right();
        paths = 0;
        break;

      case 'E':
        lf_node();
        motor1.drive(100);
        motor2.drive(100);
        delay(200);
        digitalWrite(Rled, HIGH);
        delay(100);
        brake(motor1, motor2);
        for (int h = 0; h < 4; h++)
        {
          digitalWrite(buzzer, HIGH);
          delay(50);
          digitalWrite(buzzer, LOW);
          delay(50);
        }
        delay(5000);
        digitalWrite(Rled, LOW);
        break;
    }//_________end of switch
  }//_________end of for loop

}

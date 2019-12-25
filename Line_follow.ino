
//-------------------------------------------------------line follow--------------------------------------------------------------------------
void line_follow()
{
  int lsp, rsp;

  error = (analogRead(2) - analogRead(5));

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;


  lsp = lf_speed + PIDvalue;
  rsp = lf_speed - PIDvalue;

  if (lsp > 255)    lsp = 255;
  else if (lsp < 0) lsp = 0;
  if (rsp > 255)    rsp = 255;
  else if (rsp < 0) rsp = 0;

  motor1.drive(lsp);
  motor2.drive(rsp);
}

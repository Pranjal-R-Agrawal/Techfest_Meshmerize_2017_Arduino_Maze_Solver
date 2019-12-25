//-------------------------------------------------------calib--------------------------------------------------------------------------
void calib()
{
  while (digitalRead(button) == 0) {} //------------First button press---------
  delay(200);
  Serial.println("Whites");
  for (int i = 0; i < 8; i++)
  {
    SValue[i][0] = analogRead(i);
    Serial.println(SValue[i][0]);
  }
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);

  while (digitalRead(button) == 0) {} //------------Second button press---------
  delay(200);

  Serial.println("Blacks");
  for (int i = 0; i < 8; i++)
  {
    SValue[i][1] = analogRead(i);
    Serial.println(SValue[i][1]);
  }
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);

  Serial.println("Threshold values");
  for (int i = 0; i < 8; i++) //------------Calculate threshold---------
  {
    SValue[i][2] = (SValue[i][0] + SValue[i][1]) / 2;
    Serial.println(SValue[i][2]);
  }
  calibrated = 1;
}

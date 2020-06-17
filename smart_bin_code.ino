#include<Servo.h>
Servo sr;
char t;
double j,z;
int trig = A0, echo = A1, c = 0;
int m = 120, flag = 0, i, r = 0;
long duration;
float distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, 1);
  pinMode(echo, 0);
  for (i = 2; i <= 11; i++)
  {
    pinMode(i, 1);
  }
  sr.attach(12);
}

void loop()
{
  if ( Serial.available() )
  {
    t = Serial.read();
    Serial.println(t);
    if (t == 'F' || t == 'f')
    {
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      delay(12);
    }
    else if (t == 'B' || t == 'b')
    {
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      delay(12);
    }
    else if (t == 'L' || t == 'l')
    {
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      delay(12);
    }
    else if (t == 'R' || t == 'r')
    {
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      delay(12);
    }
    else if (t == 'I' )
    {
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      delay(12);
    }
    else if (t == 'G' )
    {
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      delay(12);
    }
    else if (t == 'J' )
    {
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      delay(12);
    }

    else if (t == 'H' )
    {
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      delay(12);
    }
    else if (t == 'W' || t == 'w' )
    {
      m += 5;
      sr.write(m);
      
    }

    else if (t == 'U' || t == 'u' )
    {
      m -= 2;
      sr.write(m);
    }z
    else if (t == 'S')
    {
      for (i = 2; i <= 9; i++)
      {
        digitalWrite(i, 0);
      }
    }
  }

  digitalWrite(trig, 0);
  delayMicroseconds(5);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  duration = pulseIn(echo, 1);
  if (r == 0)
  {
    distance = 0.0343 * (duration / 2);   
  }
  Serial.println(distance);
  if ( distance <= 10 && flag == 0 )
  {
    r = 1;
    if (c == 0)
    {
      z = millis();
      c = 1;
    }
    digitalWrite(10, 1);
    digitalWrite(11, 0);
    j=millis();
    if ( j - z >= 6000 )
    {
      digitalWrite(10, 0);
      flag = 1;
      r = 0;
      c = 0;
    }
  }
  else if ( distance > 10 && flag == 1 )
  {
    r = 1;
    if (c == 0)
    {
      z = millis();
      c = 1; 
    }
    digitalWrite(10, 0);
    digitalWrite(11, 1);
    if ( millis() - z >= 5600 )
    {
      digitalWrite(11, 0);
      flag = 0;
      r = 0;
      c = 0;
    }
  }
}


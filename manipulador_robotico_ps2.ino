#include <PS2X_lib.h>
#include <Servo.h>
 PS2X ps2x;
 Servo servo1;              //servo da garra
 Servo servo2;             //servo esquerdo 
 Servo servo3;            //servo base
 Servo servo4;            //servo direito
 int val1 = 45, val2 = 170, val3 = 90 ,val4 = 1 ;   // val1 = garra ,val2 = esquerdo, val = base ,val4 = direito
 int error = 0;
 byte vibrate = 0;
 void setup()
{
  servo1.attach(6); 
  servo2.attach(5);
  servo3.attach(3);
  servo4.attach(9);
  pinMode(2, OUTPUT);  // não esta sendo usado
  Serial.begin(9600);
  error = ps2x.config_gamepad(8,12,A0,13,true,true); // (clock, commad, atention,data)
  if error == 0)
  {
    Serial.println("controle encontado");
  }
  else
  {
    Serial.println("error no controle");
  }
}
void loop() 
{
 int ly;
 int lx;
 int ry;
 int rx;
  ps2x.read_gamepad(false,vibrate);
  ly=ps2x.Analog(PSS_LY), DEC;
 lx=ps2x.Analog(PSS_LX), DEC;
 ry=ps2x.Analog(PSS_RY), DEC; 
 rx=ps2x.Analog(PSS_RX), DEC;
 

 /*Serial.print ("LY =  ");
 Serial.print (ly);
 Serial.prin t("   LX");
 Serial.println (lx);*/
 
 Serial.print ("RY = ");
 Serial.print (ry);
 Serial.print ("   RX = ");
 Serial.println (rx);
 
 
    If (lx<125 and val1< 45) val1++; //servo da garra
    If  (lx>130 and val1> 15) val1--
  servo1.write  (val1);

     if  (ly<125 and val2<170) val2++; //servo esquerdo 
   

  if  (ly>130 and val2>80) val2--;
    
    servo2.write (val2); 

     if  (rx<125 and val3<178) val3++; //servo direito
     if  (rx>130 and val3> 1) val3--;

    servo3.write (val3); 

     if  (ry<125 and val4<80) val4++; //servo base
     if  (ry>130 and val4> 1) val4--;

    servo4.write (val4);

 delay (5)
}


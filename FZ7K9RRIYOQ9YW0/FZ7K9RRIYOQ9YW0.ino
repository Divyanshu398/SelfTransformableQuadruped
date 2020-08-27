#include <math.h>
#include <Servo.h>

Servo servo[12];
const int servo_pin[12] ={2,3,4,5,6,7,8,9,10,11,12,13};

float G = 6.5;       /////////dimensions of the robot///////////
float A = 5;
float B = 7;
float Y1=4;
float Y2=7;
float Y3=1;
float H1,H2,b1,b2,h1,h2,g1,g2,a1,a2;
float k1,k2,l1,l2;
int stand_pos_ser2,stand_pos_ser1,lower_pos_ser2,lower_pos_ser1,higher_pos_ser2,higher_pos_ser1;
int STAND_POS_SER2,STAND_POS_SER1,LOWER_POS_SER2,LOWER_POS_SER1,HIGHER_POS_SER2,HIGHER_POS_SER1; 

void servo_attach(void)
{
  for (int i = 0; i < 12; i++)
  {
      servo[i].attach(servo_pin[i]);
      delay(500);
    }
}



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servo_attach();

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////stand_pos/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
H1=sqrt(pow(G,2)+pow(Y1,2));
  
        k1=(pow(A,2)+pow(H1,2)-pow(B,2));
        l1=2*A*H1;
        b1=acos(k1/l1)*(180/M_PI);
        
        h1=asin(H1*sin(b1*M_PI/180)/B)*(180/M_PI);
    stand_pos_ser2 = h1;
  
        g1=atan(G/Y1)*(180/M_PI);
        a1 = (g1+b1)-90;
    stand_pos_ser1 = 90-a1;


//////////////////////////////////////////////////////////////////////////////////
////////////////////////////lower_pos/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
H1=sqrt(pow(G,2)+pow(Y3,2));
  
        k1=(pow(A,2)+pow(H1,2)-pow(B,2));
        l1=2*A*H1;
        b1=acos(k1/l1)*(180/M_PI);
        
        h1=asin(H1*sin(b1*M_PI/180)/B)*(180/M_PI);
    lower_pos_ser2 = h1;
  
        g1=atan(G/Y1)*(180/M_PI);
        a1 = (g1+b1)-90;
    lower_pos_ser1 = 90-a1;


//////////////////////////////////////////////////////////////////////////////////
////////////////////////////higher_pos/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
H2=sqrt(pow(G,2)+pow(Y2,2));
  
        k2=(pow(A,2)+pow(H2,2)-pow(B,2));
        l2=2*A*H2;
        b2=acos(k2/l2)*(180/M_PI);
        
        h2=asin(H2*sin(b2*M_PI/180)/B)*(180/M_PI);
     higher_pos_ser2 = h2;
  
        g2=atan(G/Y2)*(180/M_PI);
        a2 = (g2+b2)-90;
     higher_pos_ser1=90-a2;

STAND_POS_SER2 = 180 - stand_pos_ser2;
STAND_POS_SER1 = 180 - stand_pos_ser1;

LOWER_POS_SER2 = 180 - lower_pos_ser2;
LOWER_POS_SER1 = 180 - lower_pos_ser1;

HIGHER_POS_SER2 = 180 - higher_pos_ser2;
HIGHER_POS_SER1 = 180 - higher_pos_ser1;

servo[3].write(45);

  //////////////////standingpos/////////////////////
servo[0].write(stand_pos_ser2);
servo[3].write(STAND_POS_SER2);
servo[6].write(STAND_POS_SER2);
servo[9].write(stand_pos_ser2);

servo[1].write(stand_pos_ser1);
servo[4].write(STAND_POS_SER1);
servo[7].write(STAND_POS_SER1);
servo[10].write(stand_pos_ser1);
  
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:


///////////////////////leanright//////////////////////
servo[0].write(lower_pos_ser2);
servo[3].write(LOWER_POS_SER2);
servo[6].write(HIGHER_POS_SER2);
servo[9].write(higher_pos_ser2);

servo[1].write(lower_pos_ser1);
servo[4].write(LOWER_POS_SER1);
servo[7].write(HIGHER_POS_SER1);
servo[10].write(higher_pos_ser1);

  delay(1000);
/////////////////////////leanleft////////////////////////////////
servo[0].write(higher_pos_ser2);
servo[3].write(HIGHER_POS_SER2);
servo[6].write(LOWER_POS_SER2);
servo[9].write(lower_pos_ser2);

servo[1].write(higher_pos_ser1);
servo[4].write(HIGHER_POS_SER1);
servo[7].write(LOWER_POS_SER1);
servo[10].write(lower_pos_ser1);
delay(1000);

}

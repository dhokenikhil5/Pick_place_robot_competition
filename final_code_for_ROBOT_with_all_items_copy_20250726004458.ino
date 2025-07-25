/*------------------------------ PICK AND PLACE ROBOT MADE - BY NIKHIL DHOKE ------------------------------*/

/*-------------------------------------- HEADER FILES --------------------------------------------------*/

  #include <Servo.h>

/*--------------------------------------- PINS DEFINITION-------------------------------------------------*/

  #define enA 3   // PWM Enabled Pin
  #define in1 4
  #define in2 5
  #define enB 9   // PWM Enabled Pin
  #define in3 6
  #define in4 7
  #define ENA 11  // PWM Enabled Pin
  #define IN1 10
  #define IN2 9

/*----------------------------------- CREATING SERVO OBJECTS  ---------------------------------------------*/

   Servo myservo1; 
   Servo myservo2;

/*----------------------------------------- VARIABLES -----------------------------------------------------*/

int motorSpeedA = 0;
 int motorSpeedB = 0;
 int potpin = 0;                 // analog pin used to connect the potentiometer
 int sev =analogRead(potpin);    // variable to read the sevue from the analog pin

/*----------------------------------------- SETUP PART -----------------------------------------------------*/

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  myservo1.attach(9);
  myservo2.attach(8);// attaches the servo on pin 9 to the servo object
}
/*----------------------------------------- LOOPING PART -----------------------------------------------------*/

void loop() 
{

/*----------------------------------------- SETUP PART -----------------------------------------------------*/

  int xAxis = analogRead(A0);     // Read Joysticks X-axis
  int yAxis = analogRead(A1);     // Read Joysticks Y-axis
  int zAxis = analogRead(A3);     //Read joystick  Y axis for bot Hand ( up or down)

/*-------------------------------------------------------------------------------------------------------------------------*/

  // Y-axis used for forward and backward control
  if (yAxis < 470) 
  {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
/*-------------------------------------------------------------------------------------------------------------------------*/

  else if (yAxis > 550) 
  {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  
  else 
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
/*-------------------------------------------------------------------------------------------------------------------------*/

   if (xAxis < 470) 
   {
    
    int xMapped = map(xAxis, 470, 0, 0, 255);
    
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    if (motorSpeedA < 0) 
    {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) 
    {
      motorSpeedB = 255;
    }
  }
/*-------------------------------------------------------------------------------------------------------------------------*/

  if (xAxis > 550) 
  {
    
     int xMapped = map(xAxis, 550, 1023, 0, 255);
     motorSpeedA = motorSpeedA + xMapped;
     motorSpeedB = motorSpeedB - xMapped;
    
    if (motorSpeedA > 255) 
    {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) 
    {
      motorSpeedB = 0;
    }
  }
/*-------------------------------------------------------------------------------------------------------------------------*/

  if (motorSpeedA < 70) 
  {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) 
  {
    motorSpeedB = 0;
  }
    {
        analogWrite(enA, motorSpeedA);        // Send PWM signal to motor A
        analogWrite(enB, motorSpeedB);         // Send PWM signal to motor B

        sev = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
        sev = map(sev, 0,460, 30, 130);     // scale it to use it with the servo (value between 0 and 180)
        myservo1.write(sev); 
        // sets the servo position according to the scaled value

        sev = analogRead(potpin);
        sev = map(sev,0,460,150,90);
        myservo2.write(sev);
      delay(15);                           // waits for the servo to get there
    }

if(zAxis>550)
{
// set motor upwards
  
digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(ENA,HIGH);
}

else if(zAxis<470)
{
   digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
   digitalWrite(ENA,HIGH);
}
}


#define motor1_en 10
#define motor2_en 11
#define motor1_dir1 5
#define motor1_dir2 4
#define motor2_dir1 6
#define motor2_dir2 7
int degs=0;
void setup() 
    {
       // put your setup code here, to run once:
       Serial.begin(9600);

    
         pinMode(motor1_en,OUTPUT);
         pinMode(motor2_en,OUTPUT);
//        Serial.println("WELCOME");

    
    }
        

void loop() 
     {
      
       if (Serial.available()>=0) 
       {
    String data = Serial.readStringUntil('\n');
    delay(500);
    degs=data.toInt();
//    Serial.println(degs);
       }

        if((5>degs>0)||(90>degs>85))
          {
//            Serial.println("UP");
//           delay(500);
            forward();
            
          }

       else  if ((50>degs)&&(degs>5))
          {
//            Serial.println("Right");
//             delay(500);
             right();
          }

       else  if ((50<degs)&&(degs<85))
           {
//              Serial.println("Left");
//              delay(500);
              left();
           }

       

           else 
           {
            Stop();
           }


     }

     void forward()
     {
        analogWrite(motor1_en,200);
        analogWrite(motor2_en,200);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void backward()
     {
        analogWrite(motor1_en,200);
        analogWrite(motor2_en,200);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void left()
     {
        analogWrite(motor1_en,200);
        analogWrite(motor2_en,200);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void right()
     {
        analogWrite(motor1_en,200);
        analogWrite(motor2_en,200);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void Stop()
     {
        analogWrite(motor1_en,0);
        analogWrite(motor2_en,0);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,LOW);
      
     }

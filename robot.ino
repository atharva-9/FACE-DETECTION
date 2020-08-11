
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
       Serial.begin(115200);

    
         pinMode(motor1_en,OUTPUT);
         pinMode(motor2_en,OUTPUT);
//        Serial.println("WELCOME");
analogWrite(motor1_en,150);
analogWrite(motor2_en,150);



    
    }
        

void loop() 
     {
       if (Serial.available()>0) 
      {
String   data = Serial.readStringUntil("\n");
    degs=data.toFloat();
//    Serial.println(degs); 
      }
       
  
        if((4.99>degs>0.0)||(90.0>degs>85.0))
          {
//            Serial.println("UP");
//           delay(500);
            forward();
            
          }

       else  if ((50.0>degs)&&(degs>=5.0))
          {
//            Serial.println("Right");
//             delay(500);
             left();
          }

       else  if ((50.0<degs)&&(degs<=85.0))
           {
//    Serial.println("Left");
//              delay(500);
              right();
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

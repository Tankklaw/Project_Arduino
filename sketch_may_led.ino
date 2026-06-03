boolean butt_flag =0; //флаг нажатия кнопки
boolean butt;
boolean led_flag = 0; // флаг роста или снижение количества зажигаемых светодиотов
unsigned long last_press; // время последнего нажатия кнопки
byte LEDcounter = 4;  // номера светодиодов

void setup() {
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  
  
}

void loop() {
  butt = !digitalRead(3);

  if (butt == 1 && butt_flag == 0 && millis() - last_press >100){
    butt_flag =1;
    last_press = millis();
    Serial.println("Button pressed");
    if(LEDcounter < 7 && led_flag ==0){
      digitalWrite(LEDcounter,1);
      LEDcounter++;
      return;
    }
    if(LEDcounter > 4 && led_flag ==1){
      digitalWrite(LEDcounter,0);
      LEDcounter--;
      return;
    }
    if(LEDcounter == 7){
      if(led_flag == 0){
        digitalWrite(LEDcounter,1);
      }else{
         digitalWrite(LEDcounter,0);
         LEDcounter--;
      }
      led_flag = 1;
      return;
    }
    if(LEDcounter == 4){
      if(led_flag == 1){
        digitalWrite(LEDcounter,0);
        
      }else{
         digitalWrite(LEDcounter,1);
         LEDcounter++;
      }
      led_flag = 0;
      return;
    }


    
    
  }
  if (butt == 0 && butt_flag ==1){
    butt_flag = 0;
    Serial.println("Button released");
  }
  
}

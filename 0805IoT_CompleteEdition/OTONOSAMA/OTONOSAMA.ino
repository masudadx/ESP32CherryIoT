//オトのさま
//お手洗いなどでサウンドを消すことが出来ます!
const int spkrPin = 25; //3:ConnectorA 4:ConnectorB
const int trigPin = 32; //4:ConnectorA 9:ConnectorB
const int echoPin = 33; //5:ConnectorA 8:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration

#define BEAT 200 //4分音符
#define halfBEAT 100
#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883
#define octDO 523.251
#define BEAT2 300
#define halfBEAT 150
#define hhBEAT 75
#define hhhBEAT 37.5
#define hhhhBEAT 18.75


void SAKURA(){
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
   ledcWriteTone(spkrPin, TI);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
   ledcWriteTone(spkrPin, TI);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
    ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
   ledcWriteTone(spkrPin, TI);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
    ledcWriteTone(spkrPin, octDO);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
   ledcWriteTone(spkrPin, TI);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
     ledcWriteTone(spkrPin, RA);
  delay(BEAT);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);
     ledcWriteTone(spkrPin, TI);
  delay(BEAT);
     ledcWriteTone(spkrPin, RA);
  delay(BEAT);
   ledcWriteTone(spkrPin, FA);
  delay(BEAT);  
  ledcWriteTone(spkrPin, 0);
  delay(BEAT);

}

void mcdParty(){

  for(int i = 0 ; i < 4 ; i++){

  ledcWriteTone(spkrPin, SO);
  delay(BEAT2);
  ledcWriteTone(spkrPin, FA);
  delay(BEAT2);  
  ledcWriteTone(spkrPin, SO);
  delay(BEAT2);
  ledcWriteTone(spkrPin, 0);
  delay(BEAT2);
  }

  for(int i = 0 ; i < 4 ; i++){

  ledcWriteTone(spkrPin, SO);
  delay(halfBEAT);
  ledcWriteTone(spkrPin, FA);
  delay(halfBEAT); 
  ledcWriteTone(spkrPin, SO);
  delay(halfBEAT);
  ledcWriteTone(spkrPin, 0);
  delay(halfBEAT);

  }


  for(int i = 0 ; i < 8 ; i++){

  ledcWriteTone(spkrPin, SO);
  delay(hhBEAT);
  ledcWriteTone(spkrPin, FA);
  delay(hhBEAT); 
  ledcWriteTone(spkrPin, SO);
  delay(hhBEAT);
  ledcWriteTone(spkrPin, 0);
  delay(hhBEAT);

  }

  for(int i = 0 ; i < 12 ; i++){

  ledcWriteTone(spkrPin, SO);
  delay(hhhBEAT);
  ledcWriteTone(spkrPin, FA);
  delay(hhhBEAT); 
  ledcWriteTone(spkrPin, SO);
  delay(hhhBEAT);
  ledcWriteTone(spkrPin, 0);
  delay(hhhBEAT);

  }

  for(int i = 0 ; i < 16 ; i++){

  ledcWriteTone(spkrPin, SO);
  delay(hhhhBEAT);
  ledcWriteTone(spkrPin, FA);
  delay(hhhhBEAT); 

  }
  
}


void setup() {

  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Distance = Duration*340*100/1000000; //Set sonic speed to 340 m/s
  Serial.println(Distance);

  delay(300);

  if (Distance < 10) { 

    // SAKURA();
    mcdParty();
    delay(200);

  } 
  
}

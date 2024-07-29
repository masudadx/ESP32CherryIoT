const int trigPin = 32; //4:ConnectorA 9:ConnectorB
const int echoPin = 33; //5:ConnectorA 8:ConnectorB
const int ledPin = 25;

float measureDist(){
  float Duration = 0; //Received Interval
  float Calc_Dist = 0; //Calculation results from Duration

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Calc_Dist = Duration*340*100/1000000; //Set sonic speed to 340 m/s
  return Calc_Dist;
}

void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Look at the serial monitor
  float result = measureDist();
  Serial.print("Distance:");
  Serial.print(result);
  Serial.println("cm");

  if( result < 10){
    digitalWrite(ledPin, HIGH);

  } else{
    digitalWrite(ledPin, LOW);
  }

  

  delay(50);

}

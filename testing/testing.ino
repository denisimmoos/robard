/*
   Define HC-SRO4 sensor pins
*/

#define CatEchoPin 30 // Ultrasonic Echo pin
#define CatTriggerPin 31  // Ultrasonic Trig pin

#define FrontEchoPin 32 // Ultrasonic Echo pin
#define FrontTriggerPin 33  // Ultrasonic Trig pin

#define BackEchoPin 34 // Ultrasonic Echo pin
#define BackTriggerPin 35  // Ultrasonic Trig pin

#define RightEchoPin 36 // Ultrasonic Echo pin
#define RightTriggerPin 37  // Ultrasonic Trig pin

#define LeftEchoPin 38 // Ultrasonic Echo pin
#define LeftTriggerPin 39  // Ultrasonic Trig pin

#define BackBottomEchoPin 40 // Ultrasonic Echo pin
#define BackBottomTriggerPin 41  // Ultrasonic Trig pin


/*
   Define SDL,SDA sensor pins
*/


float Cat_Distance;

/*
  FUNCTIONS
*/

float getHCSRO4Distance(int TriggerPin, int EchoPin){

  pinMode(TriggerPin, OUTPUT);  // Sets the TriggerPin as an Output
  pinMode(EchoPin, INPUT);     // Sets the EchoPin as an Input

  float distincm,duration;
  int delay_ms = 10;

  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(delay_ms);
  digitalWrite(TriggerPin,LOW);

  // Reads the EchoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(EchoPin,HIGH);

  // Speed of sound wave minus the delay_mdivided by 2 (go and back)
  distincm = (duration - delay_ms)* 0.034 / 2;

  return float(distincm)
}



int getIndexOfMaxValue(int* array, int size){
 int maxIndex = 0;
 int max = array[maxIndex];
 for (int i=1; i<size; i++){
   if (max<array[i]){
     max = array[i];
     maxIndex = i;
   }
 }
 return maxIndex;
}

int getIndexOfMinValue(int* array, int size){
 int minIndex = 0;
 int min = array[minIndex];
 for (int i=1; i<size; i++){
   if (min>array[i]){
     min = array[i];
     minIndex = i;
   }
 }
 return minIndex;
}


/*
  VOID's
*/

void mesure_distances(){

  Cat_Distance = getHCSRO4Distance(CatTriggerPin,CatEchoPin);
  Serial.println(Cat_Distance);

}


void setup() {


  Serial.begin(9600);


/*

 int myasize = 8;
 int mya[myasize] = {5,1,7,8,9,30,6,0};
 int mymax;
 int mymin;

 Serial.println("The contents of the array:");

  mymax = getIndexOfMaxValue(mya,myasize);
  Serial.println(mymax);

  mymin = getIndexOfMinValue(mya,myasize);
  Serial.println(mymin);
 */

 }

void loop() {

  mesure_distances();

 }

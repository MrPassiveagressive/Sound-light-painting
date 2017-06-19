#include <FastLED.h>
int soundSensorPin=A0;
int soundReading=0;
int soundThreshold=790;
int previousThreshold = 0;
int threshold_diff = 0;
#define NUM_LEDS 48
int currentLEDs[48]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int numberOfPins=NUM_LEDS;
int currentPin=0;
int fadeCounter=0;
int fadeDelay=1;

boolean switcher = true;

//start ani

#define DATA_PIN 2
CRGB leds[NUM_LEDS];


void setup(){
 delay(2000);
 Serial.begin(9600);
 pinMode(soundSensorPin, INPUT);
 FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
 //for not needed
 pinMode(2,OUTPUT);
 for(int i=0; i<numberOfPins;i++){
   leds[i] = CRGB::Gray;
 }
}

void loop(){
 soundReading=analogRead(soundSensorPin);
 threshold_diff = soundReading - previousThreshold;
 if(soundReading>soundThreshold && threshold_diff < 500){

 if(switcher){
   aboveThreshold();
   switcher=true;
  }
 } else {
 if(switcher){
 belowThreshold();
 switcher=true;
  }
 }
 previousThreshold = soundReading;
}

void aboveThreshold(){
 switcher=false;
    Serial.println("above threshhold");
 for(int i=0;i<numberOfPins;i++) {
  currentLEDs[i] = random(0,1);
  Serial.println(currentLEDs[i]);
  if(currentLEDs[i] == 1) {
    leds[i] = CRGB::White;
  }
 }
 FastLED.show();
  
 delay(100);
 for(int i=0;i<numberOfPins;i++) {
    leds[i] = CRGB::Black;
    currentLEDs[i] = 0;
 }
}

void belowThreshold(){
 switcher=false;
 //fadeCounter++;
 //if(fadeCounter==fadeDelay){
 //fadeCounter=0;
 //for(int i=0; i<NUM_LEDS;i++){
 //analogWrite(LEDPins[i],intensity[i]);
 //analogWrite(leds[i],intensity[i]);
 //}
 //for(int i=0; i<numberOfPins;i++){
 //intensity[i]--;
 //if(intensity[i]<0){
 //intensity[i]=0;
 //  }
 // }
 //}
}


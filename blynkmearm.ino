
/*
* This sketch demonstrates how to scan WiFi networks.
* The API is almost the same as with the WiFi Shield library,
* the most obvious difference being the different file you need to include:
*/
#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>



// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2ce6c5a66876421a827b9ea948a78d17";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VaasaHacklab-n-2.4GHz";
char pass[] = "mendel90";

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int SA1=2000;
int SA2=1500;
int SA3=2000;
int SA4=1500;

int changeStep = 3;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, "WiFi Name", "Password"); // replace with your WiFi router details
  servo1.attach(16);
  servo2.attach(5);
  servo3.attach(4);
  servo4.attach(0);
  ESP.wdtDisable();
  ESP.wdtEnable(WDTO_8S);
}

BLYNK_WRITE(V0){
  ESP.wdtDisable();
  int newSA1 = param.asInt();
  int change = -changeStep;
  if (newSA1< SA1) {
    change = -changeStep;
  } else {
    change = +changeStep;
  }
  while ((abs(SA1-newSA1))>5) {
    servo1.writeMicroseconds(SA1);
    SA1+=change;
    Serial.println(int(SA1));
    Serial.println(int(newSA1));
  }  
  ESP.wdtEnable(WDTO_8S);
}

BLYNK_WRITE(V1){
  ESP.wdtDisable();
  int newSA2 = param.asInt();
  int change = -5;
  if (newSA2< SA2) {
    change = -5;
  } else {
    change = +5;
  }
  while ((abs(SA2-newSA2))>5) {
    servo2.writeMicroseconds(SA2);
    SA2+=change;
    Serial.println(int(SA2));
    Serial.println(int(newSA2));
  }  
  ESP.wdtEnable(WDTO_8S);
}

BLYNK_WRITE(V2){
  ESP.wdtDisable();
  int newSA3 = param.asInt();
  int change = -5;
  if (newSA3< SA3) {
    change = -5;
  } else {
    change = +5;
  }
  while ((abs(SA3-newSA3))>5) {
    servo3.writeMicroseconds(SA3);
    SA3+=change;
    Serial.println(int(SA3));
    Serial.println(int(newSA3));
  }  
  ESP.wdtEnable(WDTO_8S);
}

BLYNK_WRITE(V3){
  ESP.wdtDisable();
  int newSA4 = param.asInt();
  int change = -5;
  if (newSA4< SA4) {
    change = -5;
  } else {
    change = +5;
  }
  while ((abs(SA4-newSA4))>5) {
    servo4.writeMicroseconds(SA4);
    SA4+=change;
    Serial.println(int(SA4));
    Serial.println(int(newSA4));
  }  
  ESP.wdtEnable(WDTO_8S);
}


void loop(){
  //ESP.wdtFeed();
  Blynk.run();
}

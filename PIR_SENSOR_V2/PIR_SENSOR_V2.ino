/*#include "SoftwareSerial.h"
#include "DFPlayer_Mini_Mp3.h"

SoftwareSerial mySerial(7, 6); // RX, TX

void setup() {
    mySerial.begin(9600);
    mp3_set_serial(mySerial);
    mp3_set_volume(15);       // fixe le son (30 maximum)
    mp3_set_EQ(0);            // equalizer de 0 à 5
}

void loop() {
    mp3_play();  // joue mp3/0001.mp3
    delay(5000); // pause de 5 secondes

    mp3_next();  // joue le prochain mp3
    delay(5000); // pause de 5 secondes

    mp3_play(3); // joue mp3/0004.mp3
    delay(5000); // pause de 5 secondes

    mp3_next();  // joue le prochain mp3
    delay(5000); // pause de 5 secondes
}
*/
#define SIGNAL_PIN 2
#define LED1 3
#define LED2 5
#define DATA_PIN 4
#include "SoftwareSerial.h"
#include <DFRobotDFPlayerMini.h> 

SoftwareSerial mySoftwareSerial(7, 6); // RX, TX

DFRobotDFPlayerMini myDFPlayer ; 

void setup()
{
  mySoftwareSerial.begin(9600) ;
  myDFPlayer.begin(mySoftwareSerial) ;
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  delay(2000); 
  myDFPlayer.volume(20);
  myDFPlayer.play(2);
  delay(13000);
}

void loop() {
  if(digitalRead(SIGNAL_PIN)==HIGH) {
    myDFPlayer.setTimeOut(1500) ;
    myDFPlayer.volume(15);
    myDFPlayer.play(1);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    } else {     
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, HIGH);

     
  }

  
}

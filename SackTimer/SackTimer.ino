/*
Blue Owl Labs

A product of Blue Owl Vines LLC.
This sketch was designed specfically for a 7 on 7 quarterback sack timer.
Upon the first button press, a tone is made by the buzzer to signify the 
'clock' has started. After 5 seconds another tone will sound, letting the 
player know that 5 more seconds remain. Lastly, a final tone will sound 
resulting in a sack, provided the quarterback still has the football, behind 
the line os scrimmage. The tone durations vary based off tone meaning.

Hardware:
Arduino UNO/Mega
Ardunio button
piezoelectric 12mm buzzer

Connections:
Button
pin 1 to 5v
pin 2 to digital 2
pin 2 to 100r/GND
Buzzer
+ to digital 8
- to digital GND
*/

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {    
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
  pinMode(8, OUTPUT);        // initializes the buzzer pin as an output:
}

void loop(){
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value:
  if (buttonState == HIGH) { // check if the pushbutton is pressed. The buttonState is HIGH:
    digitalWrite(8, 60);     // 'clock' start, snap of the ball
    delay(200);
    digitalWrite(8, 0);      // turns tone off
    delay(5000);
    digitalWrite(8, 60);     // 5 second warning
    delay(200);
    digitalWrite(8, 0);
    delay(5000);
    digitalWrite(8, 80);     // 'clock' end, sack
    delay(1000);
    digitalWrite(8, 0);
  } 
}

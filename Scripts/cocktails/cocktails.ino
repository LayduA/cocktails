//Necessary variables
int state = 0;
int flag = 0; 
int NUMBER_COCKTAILS = 3;

//Example variables:
//Green LED to Arduino PIN 9
//Blue LED to Arduino PIN 10
//Red LED to Arduino PIN 11
//Yellow (control) LED to Arduino PIN 12
 
int GREEN_LED = 9;
int BLUE_LED = 10;
int RED_LED = 11;
int CONTROL_LED = 12;
 
void setup() {
 pinMode(CONTROL_LED, OUTPUT);
 pinMode(GREEN_LED, OUTPUT);
 pinMode(RED_LED, OUTPUT);
 pinMode(BLUE_LED, OUTPUT);
 
 //This line should NEVER be removed
 Serial.begin(9600); // Default connection rate for BT module
 
 delay(1000);
}
 
void loop() {

 //The state 0 is when waiting for a command. 
 
 if (state == 0) {
   //What to do when idle (for example, wait).
   
   digitalWrite(CONTROL_LED, HIGH);
   delay(2000);
 }


 //If the machine is idle and an order is waiting, we read the cocktail number.
 //Note that this is called with a frequency defined by the delay above.
 
 if(state == 0 && Serial.available() > 0){
   state = Serial.read();
 }


 //We check that the number of the cocktail is valid (and it should be if the app
 //is coded properly (haha, what a joke))
 
 if (0 < state && state <= NUMBER_COCKTAILS) { 
   
   //This is where we do stuff for the cocktail, the variable "state" represents 
   //the number of the cocktail starting from 1.

   //For the example, we turn on the led with the corresponding color
   //of the cocktail.
   digitalWrite(GREEN_LED - 1 + state, HIGH);
   digitalWrite(CONTROL_LED, LOW);
   
   //DON'T REMOVE UNLESS YOU DONT WANT AN ACTION AFTER AN ORDER.
   flag = 1;
 }


 
 if(flag == 1){
   //Optional instructions at the end of any order (play a sound or whatever)

   //For the example, we stay 2s with the LED on, then turn it off.
   delay(2000);
   digitalWrite(GREEN_LED - 1 + state, LOW);
   delay(500);
   
   //DON'T REMOVE UNLESS YOU DONT WANT TO GO BACK TO IDLE
   flag = 0;
   state = 0;
 }
 
}

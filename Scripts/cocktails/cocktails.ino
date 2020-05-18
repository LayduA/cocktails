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
   delay(1000);
 }


 //If the machine is idle and an order is waiting, we read the cocktail number.
 //Note that this is called with a frequency defined by the delay above.
 
 if(state == 0 && Serial.available() > 0){
   state = Serial.read();
 }


 //127 is the beginning of the order
 else if (state == 127 ){
  while(state != 0 && Serial.available() > 0){
   state = Serial.read();
   for(int i = 0; i < 4; i++){
     digitalWrite(GREEN_LED + i, (state - 'a' == i ? LOW : HIGH));
   }
   delay(750);
   
  } 
   flag = 1;
 }

 //Purge code
 else if (state == 'P') {
   for(int i = 0; i < 4; i++){
     digitalWrite(GREEN_LED + i, HIGH);
   }
   delay(750);
   for(int i = 0; i < 4; i++){
     digitalWrite(GREEN_LED + i, LOW);
   }
   delay(750);
   for(int i = 0; i < 4; i++){
     digitalWrite(GREEN_LED + i, HIGH);
   }
   delay(750);

   flag = 1;
 }


 
 if(flag == 1){
   //Optional instructions at the end of any order (play a sound or whatever)

   //For example, a little animation with the lights.

   
   for(int i = 0; i < 4; i++){
       digitalWrite(GREEN_LED + i, LOW);
   }
   digitalWrite(GREEN_LED, HIGH);
   delay(100);
   for(int i = 1; i < 4; i++){
       digitalWrite(GREEN_LED + i - 1 , LOW);
       digitalWrite(GREEN_LED + i, HIGH);
       delay(100);
   }
   for(int i = 2; i >= 0; i--){
       digitalWrite(GREEN_LED + i + 1, LOW);
       digitalWrite(GREEN_LED + i, HIGH);
       delay(100);
   }
   digitalWrite(GREEN_LED, LOW);
   
   delay(500);
   
   //DON'T REMOVE UNLESS YOU DONT WANT TO GO BACK TO IDLE
   flag = 0;
   state = 0;
 }
 
}

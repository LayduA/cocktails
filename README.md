# Cocktails
An app and script to operate an automated cocktail machine remotely via bluetooth

## How to setup :
Upload the script located in the Scripts/cocktails folder to the Arduino.
Download the APK from the APK folder to your (Android) phone and install it (may require special authorisations).

## How to use :
Once the Arduino is up and running, the HC-06 should be blinking 2 times/sec. That means it's ready to pair. Go to your phone's bluetooth settings and pair with the HC-06. **The PIN is 1234.**
Once done, launch the cocktails app and tap the bluetooth (or bloutousse lmao) button. The list of paired devices should now appear. Select HC-06. On the Arduino, after a little bit, the HC-06 should now blink once every couple seconds. The app is now ready to use.

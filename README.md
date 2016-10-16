# DvDuinoServer
Sketch for Arduino for controlling a Samsung BluRay player using the DvDuino Android application.

## Dependency
This script requires the [Arduino-IRremote](https://github.com/CodeMinion/Arduino-IRremote). Download it and unzip it in your Arduino Library folder. If you already have one, you might need to replace it since this version includes the Samsung36 protocol.

## Arduino Setup Notes
IR Pin: Wire to pin 9 if using ATmega1280 or ATmega2560, otherwise wire to Pin 3.
BT Module (HC5/HC6): Wire module Module TX to Arduino RX(Pin0). Wire Module RX to Arduino TX (Pin1). Wire Module Power to Arduino 5V and wire Module Ground to Arduino Ground. 

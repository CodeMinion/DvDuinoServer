/*
 * Setup Notes:
 * IR Pin: Wire to pin 9 if using ATmega1280 or ATmega2560,
 * otherwise wire to Pin 3.
 * BT Module: Wire module Module TX to Arduino RX(Pin0). Wire
 * Module RX to Arduino TX (Pin1). Wire Module Power to Arduino
 * 5V and wire Module Ground to Arduino Ground. 
 */

#include <IRremote.h>
 
// This is the address of BlueRay DVD
#define ADDRESS 0x0400

const long KEY_POWER      = 0xE00FF;
const long KEY_EXIT       = 0xED42B;
const long KEY_ENTER      = 0xE38C7;
const long KEY_RETURN     = 0xEE817;
const long KEY_EJECT      = 0xE807F;
const long KEY_DISC_MENU  = 0xEB847;
const long KEY_TITLE_MENU = 0xE04FB;
const long KEY_STOP       = 0xEC837;
const long KEY_PLAY       = 0xE28D7;
const long KEY_PAUSE      = 0xE4CB3;
const long KEY_AUDIO      = 0xEA45B;
const long KEY_HOME       = 0xE6897;
const long KEY_SUBS       = 0xE649B;
const long KEY_UP         = 0xE18E7;
const long KEY_DOWN       = 0xE9867;
const long KEY_LEFT       = 0xED827;
const long KEY_RIGHT      = 0xE58A7;
const long KEY_SKIP_RIGHT = 0xE8877;
const long KEY_SKIP_LEFT  = 0xEB04F;
const long KEY_FF         = 0xEA857;
const long KEY_RWD        = 0xE48B7;

const String CMD_POWER = "P";
const String CMD_EXIT = "X";
const String CMD_ENTER = "E";
const String CMD_RETURN = "R";
const String CMD_EJECT = "J";
const String CMD_DISC_MENU  = "DM";
const String CMD_TITLE_MENU = "TM";
const String CMD_STOP       = "S";
const String CMD_PLAY       = "Y";
const String CMD_PAUSE      = "U";
const String CMD_AUDIO      = "Au";
const String CMD_HOME       = "H";
const String CMD_SUBS       = "Sb";
const String CMD_UP         = "Up";
const String CMD_DOWN       = "Dw";
const String CMD_LEFT       = "Lf";
const String CMD_RIGHT      = "Rg";
const String CMD_SKIP_RIGHT = "SR";
const String CMD_SKIP_LEFT  = "SL";
const String CMD_FF         = "FF";
const String CMD_RWD        = "Rw";

IRsend irsend;
String cmdIn = "";
boolean cmdComplete = false;

void setup() {
  Serial.begin(9600);
  while(!Serial)
  {
   ; // Wait for serial port to be open. 
  }
  cmdIn.reserve(200);
  Serial.println("DvDuino Ready\n");

}

void loop() {
  
  if(!cmdComplete)
  {
    return;
  }
  
  if(CMD_POWER == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_POWER);
  }
  else if (CMD_EJECT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_EJECT);  
  }
  else if (CMD_EXIT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_EXIT);  
  }
  else if (CMD_ENTER == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_ENTER);  
  }
  else if (CMD_RETURN == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_RETURN);  
  }
  else if (CMD_DISC_MENU == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_DISC_MENU);  
  }
  else if (CMD_TITLE_MENU == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_TITLE_MENU);  
  }
  else if (CMD_STOP == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_STOP);  
  }
  else if (CMD_PLAY == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_PLAY);  
  }
  else if (CMD_PAUSE == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_PAUSE);  
  }
  else if (CMD_AUDIO == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_AUDIO);  
  }
  else if (CMD_HOME == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_HOME);  
  }
  else if (CMD_SUBS == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_SUBS);  
  }
  else if (CMD_UP == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_UP);  
  }
  else if (CMD_DOWN == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_DOWN);  
  }
  else if (CMD_LEFT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_LEFT);  
  }
  else if (CMD_RIGHT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_RIGHT);  
  }
  else if (CMD_SKIP_RIGHT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_SKIP_RIGHT);  
  }
  else if (CMD_SKIP_LEFT == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_SKIP_LEFT);  
  }
  else if (CMD_FF == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_FF);  
  }
  else if (CMD_RWD == cmdIn)
  {
    sendDvdCommand(ADDRESS, KEY_RWD);  
  }
  
  delay(60);  
  cmdIn = "";
  cmdComplete = false;
  
}

void serialEvent() 
{
    retrieveCommand();
}
void sendDvdCommand(unsigned long address, unsigned long data)
{
    long long inData = (address << 20);
    inData |= data;
    irsend.sendSAMSUNG36(inData, 36);
}

void retrieveCommand()
{
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    if(inChar == '\n' || inChar =='\r')
    {
      cmdComplete = true;
      Serial.println(cmdIn);
      break; 
    }
    else
    {
      cmdIn += inChar;
    }
  }   
}


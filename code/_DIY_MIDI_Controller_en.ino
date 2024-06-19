/*
  Made by Gustavo Silveira, 2023.

  http://www.musiconerd.com
  http://www.youtube.com/musiconerd
  http://facebook.com/musiconerdmusiconerd
  http://instagram.com/musiconerd/
  http://www.gustavosilveira.net
  gustavosilveira@musiconerd.com

  If you are using for anything that's not for personal use don't forget to give credit.

  PS: Just change the value that has a comment like " // "

*/

/////////////////////////////////////////////
// Choosing your board
// Define your board, choose:
// "ATMEGA328" if using ATmega328 - Uno, Mega, Nano...
// "ATMEGA32U4" if using with ATmega32U4 - Micro, Pro Micro, Leonardo...
// "TEENSY" if using a Teensy board
// "BLEMIDI" if using BLE MIDI (ESP32)
// "DEBUG" if you just want to debug the code in the serial monitor

#define ATMEGA32U4 1  // put here the uC you are using, like in the lines above followed by "1", like "ATMEGA328 1", "DEBUG 1", etc.

/////////////////////////////////////////////
// Are you using buttons?
//#define USING_BUTTONS 1  // comment if not using buttons

/////////////////////////////////////////////
// Are you using potentiometers?
#define USING_POTENTIOMETERS 1  // comment if not using potentiometers

// Are you using high res faders?
//#define USING_HIGH_RES_FADERS 1 // comment if not using high res faders (any fader can be high res)

// Are you using Motorized Faders?
//#define USING_MOTORIZED_FADERS 1 // comment if not using a motorized fader

/////////////////////////////////////////////
// Are you using a multiplexer?
#define USING_MUX 1 // comment if not using a multiplexer, uncomment if using it.

/////////////////////////////////////////////
// Are you using encoders?
//#define USING_ENCODER 1  // comment if not using encoders, uncomment if using it.
//#define USING_ENCODER_MCP23017 1
//#define TRAKTOR 1 // uncomment if using with traktor, comment if not

// Are you using high res ENCODER?
//#define USING_HIGH_RES_ENC 1  // comment if not using high res faders (any fader can be high res)

/////////////////////////////////////////////
// Are you using neopixels (any addressable strips)?
//#define USING_NEOPIXEL 1 // comment if not using neopixels, uncomment if using it.

/////////////////////////////////////////////
// Are you using an I2C Oled Display?
//#define USING_DISPLAY 1 // comment if not using an I2C Oled Display.

/////////////////////////////////////////////
// Are you using banks that can be switched with 2 buttons?
//#define USING_BANKS_WITH_BUTTONS 1 // comment if not using banks with buttons.

//#define BANKS_FOR_BUTTONS 1
//#define BANKS_FOR_POTS 1
//#define BANKS_FOR_ENCODERS 1

// Are you using LED note feedback?
//#define USING_LED_FEEDBACK 1  // comment if not using a VU

/////////////////////////////////////////////
// Are you using a 74HC595 Bit Shifter?
// Below, use either "USING_VU" or "USING_LED_FEEDBACK"
// Use VU to monitor audio levels, or LED feedback to get note feedback

//#define USING_74HC595 1 // comment if not using 74HC595 Bit Shifter

// Are you using a VU (led meter)?
//#define USING_VU 1// comment if not using a VU

// Are you using the Mackie Protocol?
//#define USING_MACKIE 1

// Are you using two buttons for octave change?
//#define USING_OCTAVE 1

// Are you using Physical MIDI din 5-pin connector?
//#define MIDI_DIN 1


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////
// LIBRARIES
// -- Defines the MIDI library -- //
//////////////////////////////////////

// if using with ATmega328 - Uno, Mega, Nano...
#ifdef ATMEGA328
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
#endif

// if using with ATmega32U4 - Micro, Pro Micro, Leonardo...
#ifdef ATMEGA32U4
#include <MIDIUSB.h>

#ifdef MIDI_DIN
#include <MIDI.h>  // adds the MIDI library to use the hardware serial with a MIDI cable
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, midi2);
#endif  //MIDI_DIN

#endif  // ATMEGA32U4

//////////////////////////////////////

//////////////////////
// Add this lib if using a cd4067 multiplexer
#ifdef USING_MUX
#include <Multiplexer4067.h>  // Multiplexer CD4067 library >> https://github.com/sumotoy/Multiplexer4067
#endif

//////////////////////
// Threads
#include <Thread.h>            // Threads library >> https://github.com/ivanseidel/ArduinoThread
#include <ThreadController.h>  // Same as above

///////////////////////////////////////////
// MULTIPLEXERS
#ifdef USING_MUX

#define N_MUX 1  // number of multiplexers

#define s0 10
#define s1 11
#define s2 14
#define s3 13

#define x1 A0  // analog pin of the first mux
//#define x2 A1 // analog pin of the second mux
//#define x3 A2 // analog pin of the third mux

// Define s0, s1, s2, s3, and x pins
const int mux_s[4] = { s0,s1,s2,s3 };
const int mux_x[N_MUX] = { A0 };  // analog pin of the first mux

// add more #define and the x number if you need

// *** IMPORTANT: if you want to add more than one mux! ***
// In the Setup tab, line 123, add another "pinMode(x2, INPUT_PULLUP);" if you want to add a second mux,
// and "pinMode(x3, INPUT_PULLUP);" for a third mux, and so on...

// Initializes the multiplexer
Multiplexer4067 mux[N_MUX] = {
  Multiplexer4067(s0, s1, s2, s3, x1),  // The SIG pin where the multiplexer is connnected
  //  Multiplexer4067(s0, s1, s2, s3, x2), // The SIG pin where the multiplexer is connnected
  //  Multiplexer4067(s0, s1, s2, s3, x3) // The SIG pin where the multiplexer is connnected
  // ...
};

#endif

#ifdef USING_POTENTIOMETERS
// include the ResponsiveAnalogRead library
#include <ResponsiveAnalogRead.h>  // https://github.com/dxinteractive/ResponsiveAnalogRead
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Types of MIDI messages to send - DO NOT TOUCH
byte NN = 0;  // Note number or MACKIE
byte CC = 1;  // Control change
byte T = 2;   // Toggle
byte PC = 3;  // Program Change
byte PB = 4;  // Pitch Bend

/////////////////////////////////////////////
// BUTTONS
#ifdef USING_BUTTONS

const byte N_BUTTONS = 0;                          //  total numbers of buttons. Number of buttons in the Arduino + number of buttons on multiplexer 1 + number of buttons on multiplexer 2... (DON'T put Octave and MIDI channel (bank) buttons here)

const byte N_BUTTONS_ARDUINO = 0;                             // number of buttons connected straight to the Arduino
const byte BUTTON_ARDUINO_PIN[N_BUTTONS_ARDUINO] = {  };  // pins of each button connected straight to the Arduino

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifdef USING_MUX                                      // Fill if you are using mux, otherwise just leave it
const byte N_BUTTONS_PER_MUX[N_MUX] = { 0 };  // number of buttons in each mux (in order)
const byte BUTTON_MUX_PIN[N_MUX][16] = {  };

int buttonMuxThreshold = 850;

#endif  //USING_MUX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// What type of message do you want to send?
// Note Number - Control Change - Toggle - Program Change

// NN: Note number or MACKIE
// CC: Control change
// T: Toggle
// PC: Program Change

// Put here the type of message you want to send, in the same order you declared the button pins
// "NN" for Note Number | "CC" for Control Change | "T" for Note Number but in toggle mode | "PC" for Program Change
byte MESSAGE_TYPE[N_BUTTONS] = { button-msg-type };

// Put here the number of the message you want to send, in the right order, no matter if it's a note number, CC (or MACKIE), Program Change
byte MESSAGE_VAL[N_BUTTONS] = { buttons-msg-val };


// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifdef USING_BANKS_WITH_BUTTONS

//#define USING_MUX_BANK_BUTTON_PIN 1; // Define if you are using the bank buttons on the Mux pin. It has to be the first mux.
const byte BANK_BUTTON_PIN[2] = { 16, 10 };  // first will decrease MIDI chennel and second will increase

#endif  //USING_BANKS_WITH_BUTTONS

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifdef USING_OCTAVE

#define USING_MUX_OCTAVE_PIN 1;              // Define if you are using the octave buttons on the Mux pin. It has to be the first mux.
const byte OCTAVE_BUTTON_PIN[2] = { 5, 4 };  // first will decrease MIDI channel and second will increase

#endif  // USING_OCTAVE

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//#define pin13 1 // uncomment if you are using pin 13 (pin with led), or comment the line if it is not
byte pin13index = 12;  // put the index of the pin 13 of the buttonPin[] array if you are using, if not, comment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// debounce
unsigned long debounceDelay = 50;  // the debounce time; increase if the output flickers

#endif  // USING_BUTTONS


/////////////////////////////////////////////
// POTENTIOMETERS

#ifdef USING_POTENTIOMETERS

const byte N_POTS = 4;  // total numbers of pots (slide & rotary). Number of pots in the Arduino + number of pots on multiplexer 1 + number of pots on multiplexer 2...

const byte N_POTS_ARDUINO = 0;  // number of pots connected straight to the Arduino
// If using the Arduino declare as "A1, A2"
// If using ESP32 only use the GPIO number as "11, 10"
const byte POT_ARDUINO_PIN[N_POTS_ARDUINO] = {  };  // pins of each pot connected straight to the Arduino (don't use "A" if you are using ESP32, only the number)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifdef USING_MUX
const byte N_POTS_PER_MUX[N_MUX] = { 4 };  // number of pots in each multiplexer (in order)
const byte POT_MUX_PIN[N_MUX][16] = { 0,1,2,3 };
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define USING_CUSTOM_CC_N 1  // comment if not using CUSTOM CC NUMBERS, uncomment if using it.
#ifdef USING_CUSTOM_CC_N

// What type of message do you want to send?
// Control Change - Pitch Bend

// CC: Control change
// PB: Pitch Bend

// Put here the type of message you want to send, in the same order you declared the button pins
// "CC" for Control Change | "PB" for Pitch Bend
byte MESSAGE_TYPE_POT[N_POTS] = { CC };

byte POT_CC_N[N_POTS] = { 0,1,2,3 };  // Add the CC, or PB, NUMBER or MACKIE of each pot you want

#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

const int TIMEOUT = 300;      // Amount of time the potentiometer will be read after it exceeds the varThreshold
const byte varThreshold = 8;  // Threshold for the potentiometer signal variation - Increase if using ESP32
// For varThreshold I usually use "8" for normal Arduino and "30" for ESP32

// put here the min and max reading in the potCState
// in the potMin put a little bit more and in the potMax put a little bit less
// IMPORTANT:
// Regular Arduinos have 10 bit resolution: 0 - 1023
// ESP32 boards have 12 bit resolution: 0 - 4095
const int potMin = 20;
const unsigned int potMax = 940;

#endif  // USING_POTENTIOMETERS

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/////////////////////////////////////////////
// ENCODERS

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CALIBRATION
byte encoderMinVal = 0;  // encoder minimum value

#ifdef USING_HIGH_RES_ENC
const unsigned int encoderMaxVal = 16383;  // encoder max value HIGH RES 14bit
#else
const byte encoderMaxVal = 127;  // encoder max value NORMAL MIDI 7bit
#endif

//#endif

// Encoder Sensitivity
// choose between a (float) number greater than 0 (0.2 for example) and 4.
// "1" will give you 4 readings per click, it will increament in 4, like 4, 8, 12...
// "4" will give you 1 reading per click, like 1, 2, 3, 4...
// so "4" will give the most precise reading
const float encSensitivity = 0.1;  // change the encoder sensitivity here

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PINS


/////////////////////////////////////////////
// MIDI CHANNEL
byte POT_MIDI_CH = 1;  // MIDI channel to be used
byte BUTTON_MIDI_CH = 1;
byte ENCODER_MIDI_CH = 1;

byte NOTE = 36;      // Lowest NOTE to be used - if not using custom NOTE NUMBER
byte CC_NUMBER = 1;  // Lowest MIDI CC to be used - if not using custom CC NUMBER


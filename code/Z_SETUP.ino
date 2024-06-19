void setup() {

  // Baud Rate
  // use if using with ATmega328 (uno, mega, nano...)
  // 31250 for MIDI class compliant | 115200 for Hairless MIDI

  int baudRate = 115200;

  #ifdef ATMEGA32U4

    #ifdef DEBUG
      while (!Serial) {
        Serial.println("waiting...");
      }
      Serial.println();
    #endif

  #endif //ATMEGA32U4


  delay(100);

  #ifdef DEBUG
    Serial.begin(baudRate);
    Serial.println("Debug mode");
    Serial.println();
  #endif

  //////////////////////////////////////
  // Buttons
  #ifdef USING_BUTTONS

    // Initialize buttons with pull up resistors
    for (int i = 0; i < N_BUTTONS_ARDUINO; i++) {
      pinMode(BUTTON_ARDUINO_PIN[i], INPUT_PULLUP);
    }

  #endif  //USING_BUTTONS
  ////////////////////////////////////

  //////////////////////////////////////
  // Potentiometer
  #ifdef USING_POTENTIOMETERS
    // Initialize pots with pull up resistors
    //  for (int i = 0; i < N_POTS_ARDUINO; i++) {
    //    pinMode(POT_ARDUINO_PIN[i], INPUT_PULLUP);
    //
    //  }

    for (int i = 0; i < N_POTS; i++) {
      responsivePot[i] = ResponsiveAnalogRead(0, true, snapMultiplier);
      responsivePot[i].setAnalogResolution(potMax + 1);  // sets the resolution
    }
  #endif
  ////////////////////////////////////


  /////////////////////////////////////////////
  // Multiplexers
  #ifdef USING_MUX

    // Initialize the multiplexers
    for (int i = 0; i < N_MUX; i++) {
      mux[i].begin();
    }
    //* Set each X pin as input_pullup (avoid floating behavior)
    pinMode(x1, INPUT_PULLUP);
    //  pinMode(x2, INPUT_PULLUP);
    //  pinMode(x3, INPUT_PULLUP);

  #endif

  /////////////////////////////////////////////
  // Threads
  #ifdef USING_POTENTIOMETERS
    // Potentiometers
    threadPotentiometers.setInterval(5);         // every how many millisiconds
    threadPotentiometers.onRun(potentiometers);  // the function that will be added to the thread
    cpu.add(&threadPotentiometers);              // add every thread here
  #endif
}

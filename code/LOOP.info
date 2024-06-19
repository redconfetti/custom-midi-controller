void loop() {

  #ifdef ATMEGA32U4

    // it will read MIDI incoming messages if using ATMEGA32U4
    MIDIread();

    #ifdef MIDI_DIN
      midi2.read();
    #endif

  #endif

  #ifdef USING_BUTTONS
    buttons();
  #endif

  cpu.run(); // for threads

}

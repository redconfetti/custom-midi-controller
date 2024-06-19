# Development

## Arduino Sketch Basics

You can use the [Arduino IDE][] to develop a "sketch" that can be compiled and
uploaded to an Arduino-compatible microcontroller.

Sketches are stored in your "Documents" folder, under the 'Arduino' folder.

A sketch consists of a folder containing a file with the `ino` extension. Both
the folder and the file must have the same name.

* _DIY_MIDI_Controller_en
  * _DIY_MIDI_Controller_en.ino

Inside of your primary INO file you are
[required to have 2 functions declared][setup and loop].

* [setup()][] - Runs once, used to initialize variables, pin modes, initialize
  libraries, etc.
* [loop()][] - Runs the code infinitely. Intended to check for input on pins
  coming from components like potentiometers, buttons/switches, and sensors,
  and then respond with ouput on other pins.

### Reference

* [Getting Started with Arduino Products][]
* [Learn Arduino][]
* [Arduino Programming Docs][]
* [Arduino Sketch Specifications][]

[Arduino IDE]: https://docs.arduino.cc/software/ide/
[setup and loop]: https://docs.arduino.cc/learn/programming/sketches/#setup-and-loop
[setup()]: https://www.arduino.cc/reference/en/language/structure/sketch/setup/
[loop()]: https://www.arduino.cc/reference/en/language/structure/sketch/loop/
[Getting Started with Arduino Products]: https://www.arduino.cc/en/Guide
[Learn Arduino]: https://docs.arduino.cc/learn/
[Arduino Programming Docs]: https://docs.arduino.cc/programming/
[Arduino Sketch Specifications]: https://arduino.github.io/arduino-cli/0.20/sketch-specification/

## Arduino Tabs

The complexity of a large sketch file with over 1000 lines of code can be
daunting. In the Arduino IDE you can break up your sketch into separate files,
instead of storing all code in one file.

As outlined in the [Sketch Build Process][], your primary INO file that matches
the name of the sketch folder is concatenated with the code from the other INO
files in alphabetical order.

> All .ino and .pde files in the sketch folder (shown in the Arduino IDE as tabs
> with no extension) are concatenated together, starting with the file that
> matches the folder name followed by the others in alphabetical order

[Sketch Build Process]: https://arduino.github.io/arduino-cli/1.0/sketch-build-process/

## VS-Code

The Arduino IDE is designed to be less daunting for non-tech-related folks, so
it is limited in the options it provides.

If you want more abilities when developing, you can use [VS-Code][] to develop
sketches.

[How to Use VS Code for Creating and Uploading Arduino Sketches]

* [Arduino CLI]

[VS-Code]: https://code.visualstudio.com/
[How to Use VS Code for Creating and Uploading Arduino Sketches]: https://www.circuitstate.com/tutorials/how-to-use-vs-code-for-creating-and-uploading-arduino-sketches/
[Arduino CLI]: https://arduino.github.io/arduino-cli/0.34/

## C Programming Notes

### C PreProcessor

* [C Define PreProcessor]
* [C IfDef/EndIf]

```c
#define YEARS_OLD 6

function potentiometer() {
  // macros do not need to be unindented
  #ifdef YEARS_OLD
    Serial.print("Augustus Corgan is over %d years old.\n", YEARS_OLD);
  #endif
}
```

[C Define PreProcessor]: https://www.geeksforgeeks.org/c-define-preprocessor/
[C IfDef/EndIf]: https://www.techonthenet.com/c_language/directives/ifdef.php

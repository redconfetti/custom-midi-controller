# Arduino

## Reference

* [Getting Started with Arduino][]
* [Language Reference][]

[Getting Started with Arduino]: https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/
[Language Reference]: https://www.arduino.cc/reference/en/

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

## Pullup Input

In the examples provided by the Nerd Musician course material, buttons are
configured with input pins that are configured with the [INPUT_PULLUP][]
constant.

Other docs include:

* [Arduino INPUT_PULLUP Explained][] - Best explanation
* [Digital Input Pull-Up resistor][]
* [Digital Read Serial][]

[INPUT_PULLUP]: https://www.arduino.cc/reference/en/language/variables/constants/inputoutputpullup/
[Arduino INPUT_PULLUP Explained]: https://roboticsbackend.com/arduino-input_pullup-pinmode/
[Digital Input Pull-Up resistor]: https://www.arduino.cc/en/Tutorial/DigitalInputPullup
[Digital Read Serial]: https://docs.arduino.cc/built-in-examples/basics/DigitalReadSerial/

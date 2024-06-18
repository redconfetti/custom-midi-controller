# Embedded Development Framework

## Wokwi

We are using the [Wokwi for VS Code][] extension, provided by the [Wokwi]
platform, to support a virtual prototype of the MIDI Controller.

Wokwi enables developers to simulate the behavior of common microcontrollers
such as the Arduino, ESP32, STM32, and Raspberry Pi Pico.

* [Wokwi - Project Config][]

[Wokwi]: https://wokwi.com/
[Wokwi for VS Code]: https://docs.wokwi.com/vscode/getting-started
[Wokwi - Project Config]: https://docs.wokwi.com/vscode/project-config

### Arduino Support

Arduino boards supported are:

* Arduino Uno - Used by this project in diagram.json
* Arduino Mega
* Arduino Nano

Only certain Arduino models are able to act as MIDI-class compliant controllers,
where you plug them in and the computer detects them as a MIDI device. This is
any Arduino with an ATmega16U2 and ATmega32U4.

* Official Arduino
  * Arduino Mega 2560 Rev3
    * Processor: ATmega2560
    * Interface: ATmega16U2 USB chip
  * [Arduino Uno Rev3][]
    * Processor: ATmega328P
    * Interface: ATmega16U2 USB chip
  * [Arduino Leonardo][]
    * Processor: ATmega32U4
    * Interface: USB controller built into processor
    * 20 digital I/O Pins
      * 7 can also be PWM Outputs
      * 12 act as Analog Inputs
  * [Arduino Micro][]
    * Processor: ATmega32U4
    * Interface: USB controller built into processor
* Arduino Compatible Devices
  * [Pro Micro][]
    * Processor: ATmega32U4
    * Interface: USB controller built into processor
    * A popular low-cost compact Arduino-compatible board.
    * Available in 3.3 V and 5 V versions.
  * [Teensy 4.0][]

An Uno, Leonardo, or Mega are recommended only for prototyping, with a Micro or
Pro Micro used for final products, in combination with Multiplexers to increase
the number of inputs.

[Arduino Uno rev3]: https://docs.arduino.cc/hardware/uno-rev3/
[Arduino Leonardo]: https://docs.arduino.cc/hardware/leonardo/
[Arduino Micro]: https://docs.arduino.cc/hardware/micro/
[Pro Micro]: https://www.sparkfun.com/products/12640
[Teensy 4.0]: https://www.pjrc.com/store/teensy40.html

## PlatformIO

Wokwi is a cloud-based platform, but you can also use it with the
[VSCode][Wokwi VS Code Extension]. The extension can be used with many
embedded development frameworks such as Zehpyr Project, PlatformIO, ESP-IDF,
Pi Pico SDK, NuttX, Rust, Arduino CLI, and MicroPython.

The [Arduino Simon Game][] example uses PlatformIO.

Arduino boards are based on the [AVR family of microcontrollers][] by Atmel.
Because of this, we specify the "platform" we use with the PlatformIO framework
as [Atmel AVR][Atmel AVR Platform].

[Wokwi VS Code Extension]: https://docs.wokwi.com/vscode/getting-started
[ARduino Simon Game]: https://github.com/wokwi/arduino-simon-game
[AVR family of microcontrollers]: https://en.wikipedia.org/wiki/AVR_microcontrollers
[Atmel AVR Platform]: https://docs.platformio.org/en/latest/platforms/atmelavr.html

* [PlatformIO][]
* [PlatformIO Examples][]

[PlatformIO]: https://platformio.org/
[PlatformIO Examples]: https://docs.wokwi.com/vscode/getting-started#platform-io-examples

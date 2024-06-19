# Components

![MIDI Controller Diagram]

[MIDI Controller Diagram]: /assets/midi-controller_bb.png "MIDI Controller Diagram"

* 1 - Arduino Pro Micro*
* 24 - B10K potentiometers
* 24 - Momentary Push Buttons / Switches
* 3 - 4067 Multiplexers

* Prototyping can be accomplished with a Leonardo, Micro, or Pro Micro

## Arduino Micro Controller

Only certain Arduino models are able to act as MIDI-class compliant controllers,
where you plug them in and the computer detects them as a MIDI device. Although
the Mega and Uno are compatible to do this, this project is coded for boards
using the ATmega32U4 processor.

* Official Arduino
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

A Leonardo is recommended for prototyping, with a Micro or Pro Micro used for
final products. These are combinated with Multiplexers to increase the number of
inputs.

[Arduino Leonardo]: https://docs.arduino.cc/hardware/leonardo/
[Arduino Micro]: https://docs.arduino.cc/hardware/micro/
[Pro Micro]: https://www.sparkfun.com/products/12640

## CD4067BE Multiplexer IC

[CD4067 16-Channel Analog Multiplexer/ Demultiplexer][]

![CD4067BE pinout]

![CD74HC4067 Breakout Schematic]
*Taken from [Sparkfun Multiplexer Breakout]*

[Sparkfun Multiplexer Breakout]: https://cdn.sparkfun.com/datasheets/BreakoutBoards/Analog-Digital-Mux-Breakout-v11.pdf

Course example uses a CD74HC4067 Multiplexer Breakout board.

| Pinout     | Breakout | Description      | Pin |
| ---------- | -------- | ---------------- | --- |
| OUT/IN     | SIG      | Common           | 1   |
| OUT 7      | C7       | Channel 8        | 2   |
| OUT 6      | C6       | Channel 7        | 3   |
| OUT 5      | C5       | Channel 6        | 4   |
| OUT 4      | C4       | Channel 5        | 5   |
| OUT 3      | C3       | Channel 4        | 6   |
| OUT 2      | C2       | Channel 3        | 7   |
| OUT 1      | C1       | Channel 2        | 8   |
| OUT 0      | C0       | Channel 1        | 9   |
| A          | S0       | Address Select 1 | 10  |
| B          | S1       | Address Select 2 | 11  |
| VSS        | GND      | Ground           | 12  |
| D          | S3       | Address Select 4 | 13  |
| C          | S2       | Address Select 3 | 14  |
| INHIBIT    | EN       |                  | 15  |
| OUT 15     | C15      | Channel 16       | 16  |
| OUT 14     | C14      | Channel 15       | 17  |
| OUT 13     | C13      | Channel 14       | 18  |
| OUT 12     | C12      | Channel 13       | 19  |
| OUT 11     | C11      | Channel 12       | 20  |
| OUT 10     | C10      | Channel 11       | 21  |
| OUT 9      | C9       | Channel 10       | 22  |
| OUT 8      | C8       | Channel 9        | 23  |
| VDD        | VCC      | 5 volt           | 24  |

[CD4067 16-Channel Analog Multiplexer/ Demultiplexer]: https://components101.com/article/cd4067-16-channel-analog-multiplexer-demultiplexer
[CD4067BE pinout]: /assets/cd4067b-pinout.jpg "CD4067B Pin-out"
[CD74HC4067 Breakout Schematic]: /assets/mux-breakout-schematic.png "CD74HC4067 Multiplexer Breakout Schematic"

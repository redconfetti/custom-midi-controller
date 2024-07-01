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

## Potentiometers

![Potentiometer B10K]
*Image from [Quartz Components][]*

[Quartz Components]: https://quartzcomponents.com/products/10k-potentiometer
[Potentiometer B10K]: /assets/Potentiometer-B10K-3pin.png "Potentiometer B10K 3 pin"

## Buttons

This form of button is known as a [tactile switch][].

![Tactile Switch PNG]

Although it appears to have 4 pins, it only has 2. The two pins on the left are
connected, as are the other two pins on the right (top and bottom). When you
press the switch, the two sides become connected and current flows through.

The left pin connects to Ground (GND), and the left connects to the input pin.

Analog switches can conduct both analog and digital signals from the input pin
to the output pin.

[tactile switch]: https://www.cuidevices.com/blog/tactile-switches-101
[Tactile Switch PNG]: /assets/tactile-switch.png "Tactile Switch"

## CD4067BE Multiplexer IC

[CD4067 16-Channel Analog Multiplexer/ Demultiplexer][]

![CD4067BE pinout]

![CD74HC4067 Breakout Schematic]
*Taken from [Sparkfun Multiplexer Breakout]*

[Multiplexer Breakout Hookup][]

[Multiplexer Breakout Hookup]: https://learn.sparkfun.com/tutorials/multiplexer-breakout-hookup-guide/all
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


### Bitwise Operations

A combination of a Binary Right Shift Operator (`>>`) and
a [Bitwise Operation AND][], results in the values our microcontroller needs to
send to the multiplexer to read the values of a specific channel.

The [CD74HC4067] docs provided by Wokwi link to [an example][] that uses the
following function to read from a specific input pin on the multiplexer.

```c
#define COM 34
const uint8_t controlPins[] = { 23, 22, 21, 19 };

float readMux(int channel)
{
  for(int i = 0; i < 4; i ++)
  {
    digitalWrite(controlPins[i], channel >> i & 1);
  }
  delay(10);
  return analogRead(COM);
}
```

The `channel >> i & 1` portion of the above code creates a 4 bit output
on the 4 control pins of the multiplexer.

With the "Binary Right Shift Operator" - `>>`, the left operands value is moved
right by the number of bits specified by the right operand.

Here is a Ruby equivalent of the same operations.

```ruby
(0..15).each do |channel|
  bits = []
  4.times do |i|
    bits << (channel >> i & 1)
  end
  puts "channel \##{channel}; bits: #{bits.inspect}"
end
# channel #0; bits: [0, 0, 0, 0]
# channel #1; bits: [1, 0, 0, 0]
# channel #2; bits: [0, 1, 0, 0]
# channel #3; bits: [1, 1, 0, 0]
# channel #4; bits: [0, 0, 1, 0]
# channel #5; bits: [1, 0, 1, 0]
# channel #6; bits: [0, 1, 1, 0]
# channel #7; bits: [1, 1, 1, 0]
# channel #8; bits: [0, 0, 0, 1]
# channel #9; bits: [1, 0, 0, 1]
# channel #10; bits: [0, 1, 0, 1]
# channel #11; bits: [1, 1, 0, 1]
# channel #12; bits: [0, 0, 1, 1]
# channel #13; bits: [1, 0, 1, 1]
# channel #14; bits: [0, 1, 1, 1]
# channel #15; bits: [1, 1, 1, 1]
```

It appears that converting decimal numbers to Base-2 strings, with 4-bit zero
padding, reversed, brings the same result.

```ruby
13.to_s(2).rjust(4, "0").reverse
=> "1011"
8.to_s(2).rjust(4, "0").reverse
=> "0001"
```

Nonetheless, it just works.

[Bitwise Operation AND]: https://en.wikipedia.org/wiki/Bitwise_operation#AND
[CD74HC4067]: https://github.com/Droog71/CD74HC4067/blob/main/README.md
[an example]: https://wokwi.com/projects/366560040454111233

[CD4067 16-Channel Analog Multiplexer/ Demultiplexer]: https://components101.com/article/cd4067-16-channel-analog-multiplexer-demultiplexer
[CD4067BE pinout]: /assets/cd4067b-pinout.jpg "CD4067B Pin-out"
[CD74HC4067 Breakout Schematic]: /assets/mux-breakout-schematic.png "CD74HC4067 Multiplexer Breakout Schematic"

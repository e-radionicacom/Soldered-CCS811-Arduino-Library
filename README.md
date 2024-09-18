# Air quality sensor CCS811 breakout Arduino library

[![Make docs and publish to GitHub Pages](https://github.com/SolderedElectronics/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/actions/workflows/make_docs.yml/badge.svg?branch=dev)](https://github.com/SolderedElectronics/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/actions/workflows/make_docs.yml)
[![Arduino Library Manager Compatibility](https://github.com/SolderedElectronics/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/actions/workflows/arduino_lint.yml/badge.svg?branch=dev)](https://github.com/SolderedElectronics/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/actions/workflows/arduino_lint.yml)


| ![Air quality sensor CCS811 breakout](https://github.com/SolderedElectronics/Air-quality-sensor-CCS811-breakout-hardware-design/blob/main/OUTPUTS/V1.1.1/333009.jpg) |
| :------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|                                                  [Air quality sensor CCS811 breakout](https://solde.red/333009)                                                  |

The CCS811 sensor is designed to measure various volatile particles in the air (TVOC - Total Volatile Organic Compounds), which include eCO2 (CO2 equivalent) and MOX (metal oxides). VOCs are generally defined as air pollutants, and can come from a variety of sources, starting with ordinary breathing, smoking, coloring, welding, and generally all processes that release particles into the surrounding air.

This sensor is often used to measure indoor air quality, which can work very well and indicate current air pollution, for example, in an office. It communicates via I2C, making it easy to connect, especially through easyC. Sensor itself should be powered for at least 20 minutes to start making accurate readings.

- Voltage: 1.8V - 3.3V
- TVOC range: 0 - 32768 ppb
- Range of eCO2: 400 - 29206 ppm
- Communication: I2C
- Dimensions: 22 x 22mm
- with two easyC connectors (https://www.soldered.com/en/easyC).

### Repository Contents

- **/src** - source files for the library (.h & .cpp)
- **/examples** - examples for using the library
- **_other_** - _keywords_ file highlights function words in your IDE, _library.properties_ enables implementation with Arduino Library Manager.

### Hardware design

You can find hardware design for this board in [_Air quality sensor CCS811 breakout_](https://github.com/SolderedElectronics/Air-quality-sensor-CCS811-breakout-hardware-design) hardware repository.

### Documentation

Access Arduino library documentation [here](https://SolderedElectronics.github.io/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/).

- Tutorial for using the Air quality sensor board
- Installing an Arduino library

### Board compatibility

The library is compatible with board & microcontroller families shown in green below:

[![Compile Sketches](http://github-actions.40ants.com/e-radionicacom/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/matrix.svg?branch=dev&only=Compile%20Sketches)](https://github.com/SolderedElectronics/Soldered-CCS811-Air-Quality-Sensor-Arduino-Library/actions/workflows/compile_test.yml)

### About Soldered

<img src="https://raw.githubusercontent.com/e-radionicacom/Soldered-Generic-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

At Soldered, we design and manufacture a wide selection of electronic products to help you turn your ideas into acts and bring you one step closer to your final project. Our products are intented for makers and crafted in-house by our experienced team in Osijek, Croatia. We believe that sharing is a crucial element for improvement and innovation, and we work hard to stay connected with all our makers regardless of their skill or experience level. Therefore, all our products are open-source. Finally, we always have your back. If you face any problem concerning either your shopping experience or your electronics project, our team will help you deal with it, offering efficient customer service and cost-free technical support anytime. Some of those might be useful for you:

- [Web Store](https://www.soldered.com/shop)
- [Tutorials & Projects](https://soldered.com/learn)
- [Community & Technical support](https://soldered.com/community)

### Original source

This library is possible thanks to original [SparkFun CCS811 Arduino Library](https://github.com/sparkfun/SparkFun_CCS811_Arduino_Library) library. Thank you, SparkFun.

### Open-source license

Soldered invests vast amounts of time into hardware & software for these products, which are all open-source. Please support future development by buying one of our products.

Check license details in the LICENSE file. Long story short, use these open-source files for any purpose you want to, as long as you apply the same open-source licence to it and disclose the original source. No warranty - all designs in this repository are distributed in the hope that they will be useful, but without any warranty. They are provided "AS IS", therefore without warranty of any kind, either expressed or implied. The entire quality and performance of what you do with the contents of this repository are your responsibility. In no event, Soldered (TAVU) will be liable for your damages, losses, including any general, special, incidental or consequential damage arising out of the use or inability to use the contents of this repository.

## Have fun!

And thank you from your fellow makers at Soldered Electronics.

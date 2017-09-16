# antplus-arduino
An Implementation of the Ant+ Network on top of ant-arduino

## Status

[![Build Status](https://travis-ci.org/cujomalainey/antplus-arduino.svg?branch=master)](https://travis-ci.org/cujomalainey/antplus-arduino)

## News

* 9/4/2017 Project Started

## Roadmap

* v0.1.0 Build Initial Framework with HR profile slave
* v0.2.0 Build Framework for Channel Master with HR master
* v0.3.0 Build support for non-ANT+ channel interfacing
* v1.0.0 Finalize and verify system
* v1.X.X Adding more profiles

[Developer's Guide](https://github.com/cujomalainey/antplus-arduino/wiki/Developer's-Guide)

## Example
I have created several sketches of configuring the radio with the ant-arduino library. You can find these in the examples folder. Here's an example of configuring a channel with a NRF51 radio:

```


// Wait for the responses
```

See the examples folder for the full source. There are more examples in the download.

To add ANT support to a new sketch, add "#include <ANTPLUS.h>" (without quotes) to the top of your sketch. You can also add it by selecting the "sketch" menu, and choosing "Import Library->ANT+".

## Hardware

See [ant-arduino](https://github.com/cujomalainey/ant-arduino)

## Installation

**Note: This library depends on [ant-arduino](https://github.com/cujomalainey/ant-arduino). You must have it installed for it to work.** If you are using platformio you don't have to worry about this.

Arduino 1.5 and later

Arduino now includes a library manager for easier library installation. From the Sketch menu select include library->Manage Libraries, then type "antplus-arduino" in the filter and install.

Prior to Arduino 1.5 installation is a manual

Download a .zip or .tar.gz release from github. Determine the location of your sketchbook by selecting "preferences" on the Arduino menu. Create a "libraries" folder in your sketchbook and unzip the release file in that location.

If you are using platformio you can install the library by running
``` platformio lib install ### ```

## Uploading Sketches

Uploading sketches with a Leonardo is as simple as connecting the Arduino to your computer and uploading. When using a single serial port Arduino, such as the Pro Mini (3.3V), the jumpers on the ANT Radio must be disconnected. Then, after upload, reconnect the lines to have access to the serial port. Always remember to power off the Arduino before moving the jumpers.

## Configuration

See [ant-arduino](https://github.com/cujomalainey/ant-arduino)

## Questions/Feedback

Questions about this project should be posted to http://groups.google.com/group/antplus-api?pli=1 Be sure to provide as much detail as possible (e.g. what radios, firmware versions, configuration and code).

## Consulting/Commercial Licenses
At the current time there is zero support for commercial usage. Contact me via email if you are looking to use this code commercially.

If you are looking for commercial support for ANT radios go to thisisant.com

NOTE: This library is not ANT+ certified and does not intend to be. It is meant to be tool to get quick and easy access to sensors in the ANT+ network. There are edge cases where it will fail to meet the spec of the ANT+ protocol.

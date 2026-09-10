# ESP8266 Micro Weather Monitoring System

A compact ESP8266 and DHT11 proof-of-concept that measures temperature and relative humidity and serves the latest readings through a local Wi-Fi access point.

> **Project status:** Legacy prototype. The original implementation was created in 2017 and is preserved as a small, reproducible reference project. The firmware has not yet been modernized for current ESP8266 and DHT library releases.

## Overview

The firmware:

- configures the ESP8266 as a Wi-Fi access point named `Weather_station`;
- reads temperature and relative humidity from a DHT11 sensor connected to GPIO 2;
- runs a small HTTP server on the ESP8266;
- exposes the readings at `192.168.4.1`; and
- refreshes the browser page every five seconds.

## Hardware

- ESP8266-based module
- DHT11 temperature and humidity sensor
- Suitable regulated power supply for the selected ESP8266 module
- USB-to-serial programming interface when required by the module

### Sensor connection

The current firmware expects the DHT11 data line on **GPIO 2**. Power and logic levels must match the requirements of the specific ESP8266 module and sensor board being used.

## Software requirements

The original sketch depends on:

- Arduino IDE or Arduino CLI
- ESP8266 Arduino core
- DHT sensor library compatible with `DHT.h`

Because this is a legacy project, dependency versions are not currently pinned. If reproducible builds become necessary, a future revision should add an Arduino CLI or PlatformIO configuration with tested versions.

## Running the project

1. Install ESP8266 board support in the Arduino development environment.
2. Install a compatible DHT sensor library.
3. Open `micro_weather_monitoring_system.ino`.
4. Select the correct ESP8266 board/module and serial port for the hardware in use.
5. Compile and upload the sketch.
6. Connect a client device to the Wi-Fi network `Weather_station`.
7. Open `http://192.168.4.1` in a web browser.

## Security note

The original firmware intentionally creates an **open Wi-Fi access point** and serves data over unencrypted HTTP. This is acceptable only for isolated demonstrations, bench testing, or controlled local experiments. It should not be treated as a secure deployment configuration.

Before using the design in an operational environment, add appropriate Wi-Fi authentication, consider network isolation, validate input/error handling, and review whether transport security is required for the intended deployment.

## Current limitations

The original implementation is intentionally minimal and currently has several limitations:

- no Wi-Fi authentication;
- no TLS or application-level authentication;
- no persistent data logging;
- no explicit handling of failed DHT readings;
- dependencies and toolchain versions are not pinned;
- no automated build or hardware-in-the-loop test workflow; and
- compatibility with current library releases has not yet been verified.

## Repository layout

```text
.
├── micro_weather_monitoring_system.ino   # ESP8266 firmware
└── README.md                             # Project documentation
```

## Modernization path

A production-oriented revision should separate configuration from application logic, add sensor error handling, pin dependencies, add automated compilation checks, document the exact board and wiring, and introduce a secure network configuration appropriate to the deployment environment.

## License

No open-source license has currently been selected for this repository. A license should be chosen explicitly before the project is promoted for third-party reuse or contribution.

## Author

Abhijith Padukana

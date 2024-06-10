# ESP Clock

<img align="right" src="https://github.com/Yanndroid/espc-hardware/raw/main/readme-res/clock.jpg" alt="ESP Clock" width="30%">

ESPC stands for [ESP](https://www.espressif.com/) Clock and is a digital IoT clock. It's connected to WiFi, automatically syncs time, shows weather information, and most importantly, has RGB! At its core, there is an ESP8266, and the display is made of WS2812B LEDs.  
It's a project I've been working on over the past few years, and it has allowed me to learn a lot about the C language and PCB designs.

This project consists of multiple repositories:

- [espc-firmware](https://github.com/Yanndroid/espc-firmware)
- [espc-hardware](https://github.com/Yanndroid/espc-hardware)
- [espc-python-client](https://github.com/Yanndroid/espc-python-client)
- espc-dev-tools

# ESP Clock Dev Tools

This repository contains development tools for the ESPC.

## OTA Crypto
For security purposes, the ESPC requires signed binaries for OTA updates. Here you can find two scripts to generate a valid key pair and signing binary files with the private key.

### Usage
Use `make all` to compile the scripts. Run `gen-keys` to generate a key pair and run `get-signature <filepath> <private-key>` to calculate the signature.

## Icon Compressor
In order to reduce the firmware binary size for the very limited flash size of the esp8266, this script compresses icons from 14 bytes down to only 4 bytes! This might seem insignificant, but with a current total of 17 weather icons, this saves us 170 bytes of precious flash storage.

### Usage
Edit the `input` array in the script and run it.
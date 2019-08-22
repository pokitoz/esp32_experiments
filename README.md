ESP32 Experiments
=================

- Wemos Lolin ESP32 OLED Display Module (https://www.wemos.cc/)

References:
- https://diyprojects.io/unpacking-wemos-esp32-lolin-clone-0-96-ssd1306-monochrome-oled-display/#.XV7Upvwo9wd


Setup
-----

Useful link: https://dl.espressif.com/doc/esp-idf/latest/get-started/index.html

Get the followings:
- Use _esptool_ (https://github.com/espressif/esptool)
- Get esp-idf: https://github.com/espressif/esp-idf.git
- Get the toolchain: https://dl.espressif.com/doc/esp-idf/latest/get-started/linux-setup.html

Setup the variables:
- export IDF_PATH to the repository cloned: `esp-idf`.
- export the path to toolchain `xtensa-esp32-elf-` in the PATH.

Build the project
-----------------

Once the project is setup, here are the commands to build it:
```
cd src
. ${IDF_PATH}/add_path.sh
make
```

Program the board
-----------------

Once the board is plugged in, `dmesg` should output the following:

_Note: In a VM, the USB controller CP2102 in Devices/USB must be enabled_

```
usb 2-2: new full-speed USB device number 3 using ohci-pci
usb 2-2: New USB device found, idVendor=10c4, idProduct=ea60
usb 2-2: New USB device strings: Mfr=1, Product=2, SerialNumber=3
usb 2-2: Product: CP2102 USB to UART Bridge Controller
usb 2-2: Manufacturer: Silicon Labs
usb 2-2: SerialNumber: 0001
usbcore: registered new interface driver usbserial
usbcore: registered new interface driver usbserial_generic
usbserial: USB Serial support registered for generic
usbcore: registered new interface driver cp210x
usbserial: USB Serial support registered for cp210x
cp210x 2-2:1.0: cp210x converter detected
usb 2-2: cp210x converter now attached to ttyUSB0
```

After building the .elf file, the following command can be executed using the
isp makefile, to flash and start the monitor:
```
make flash
make monitor
```

_Note: Use CTRL+] to escape the monitor._

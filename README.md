Team Members:
Hayden Walpole; Undergraduate; Computer Engineering 
Andy Tran; Undergraduate; Computer Engineering 
Dinali Assylbek; Undergraduate; Computer Engineering
Stein Witt; Undergraduate; Mechanical Engineering

-File Directory-
CAD_FILES: file for the Platic Housing of our Watch Monitor
Datasheetes: BOM and datasheets for the given componants
HealthMonitor: Main Code file to be used to Flash the board with initialization and reading the sensor
Nucleo_Board_Testing: Code used to Test Dev board and Flashing with our 6-pin SWD cable.
PCB: PCB Scematic files and Board Design
Photos: Pictures of the development and debugging process. Also contains helpful refrence photos
Analog Discovery Code Attempts: Code we tried to use to communicate over I2C using Waveform with an analog discovery.

Milestone 4 Powerpoint presentation: https://1drv.ms/p/c/c447666567076377/EbAtq3pLUSZKpYCg5cf9b-IBzeUnjeowH9_FPiCp1k7Zxw?e=1KSI1v

You need to install the following for the STM32 VSCode extension to work.

-STMCubeIDE
-STMCubeMX
-STMCLT
-STMMCU
ECE 5780 – ReadMe Documentation
Project Name: Wearable Health Monitor 
Purpose:
The purpose of this project is to design, assemble, and program a custom PCB for a compact wearable device that allows a person to continuously monitor their heart rate and blood oxygen levels (SpO₂). The device provides real-time feedback when readings fall outside safe thresholds by using an onboard vibrating motor and status LEDs. It is intended to be a low-power, discreet health monitoring solution suitable for everyday use.
Functionality:
The Wearable Health Monitor includes the following features:
•	Real-Time Heart Rate Monitoring: Uses the MAX30102 optical sensor to continuously measure the user’s heart rate.
•	SpO₂ (Blood Oxygen) Monitoring: Calculates and updates the user’s oxygen saturation level every few seconds.
•	Vibration Motor and Status LED: Activates when heart rate or oxygen levels are outside the defined safe range.
•	Power Supply: Currently powered via USB-C. However, the board can run on a battery if connected through the USB-C port (e.g., with a USB-C battery pack).

•	Optional Bluetooth: The board supports Bluetooth; however, Bluetooth functionality is not implemented in the driver code.

Setup Instructions:
1.	PCB Fabrication:
To manufacture the board, use the schematic and PCB layout files found in the PCB directory of the GitHub repository. These files are compatible with common PCB manufacturers such as PCBWay (used for this project). Before submission, make sure to generate and include:
o	Gerber files
o	Bill of Materials (BOM)
o	Pick-and-place files (if needed)
The schematic for this project is presented below: 
 
2.	Assembly Guidelines:
Component assembly is a critical step due to the small form factor and use of QFN or similar packages that do not expose all pins. Many components have pads located underneath, making traditional soldering difficult.
Important:
Avoid using a reflow oven. While convenient, reflow can result in unreliable connections or floating components. Instead:
o	Use solder paste with a precision heat gun
o	Inspect each connection carefully under magnification
However, if your manufacturer offers services for PCB assembly, it is advisable to have them assemble the board for you. This is to avoid any potential problems regarding the PCB itself.
Note: Be careful when handling the board after assembly, the parts are delicate!
3.	Programming the Board:
The board is programmed using a dedicated ST-Link programmer with a 6-pin Tag-Connect cable.
o	To enter bootloader mode:
	Power the board
	Press and hold the BOOT button
	Momentarily ground the NRST (reset) pin (accessible via the ST-Link header)
	Release NRST while continuing to hold BOOT for a few seconds
Note: While USB-C bootloader programming is theoretically possible, it has not been tested. The ST-Link method is the recommended and verified approach.
When using the ST-Link, bootloader mode is not required.
4.	Firmware Setup:
o	Clone the repository and open the Health Monitor project
o	All source files are in the Core directory
o	A custom library for the MAX30102 sensor is included
Pin Configuration:
o	PB8 → I2C1_SCL (Clock Line)
o	PB9 → I2C1_SDA (Data Line)
o	Pin 12 → Controls both the vibration motor and status LED
The project builds and runs best using the STM32CubeIDE and STM32CubeProgrammer.
Once the board is powered and connected via ST-Link:
o	Build the project
o	Flash the firmware using the programmer
o	The device will begin operation immediately after flashing

5.	Troubleshooting
In the case where you may encounter issues with the PCB, there are several steps you can take to diagnose and resolve problems:
o	No Power to the Board:
o	Confirm that the USB-C cable is securely connected and providing power. If not, try to use a different cable to supply power to the chip
o	Check the voltages along all the voltage lines (3.3V and 1.8V) using a multimeter.
o	Ensure all power-related components (LDO regulator, bypass caps, etc.) are properly soldered. If the board starts to heat up rapidly, use a thermal camera to help check for shorts.
o	Sensor Not Detected (MAX30102):
o	Double-check I2C connections (PB8 for SCL, PB9 for SDA).
o	Use a logic analyzer or oscilloscope to verify I2C traffic.
o	Confirm the sensor that the registers and addresses are configured correctly.
o	Programming Issues:
o	Make sure the ST-Link is correctly connected via the Tag-Connect header.
o	Ensure that the Tag-Connect and ST-Link work. This can be achieved by uploading code to a breakout board.
o	Ensure that all user code lies in the correct regions as defined in the cube IDE. Check that all the correct header files are included and desired code is not commented out.
o	Miscellaneous Issues:
o	If the PCB fails to work, inspect solder joints again for bridges or incomplete connections. Examine under a microscope. If possible, reach out to someone with a more trained eye to look at the soldering job.
o	Make sure components on the board are assembled correctly. This means making sure the orientations of the components are in the right place, and no components are missing.
o	Be careful when disconnecting the cable when flashing the board. This potentially could cause you to brick the chip on the PCB. 



Videos Used as Refrences:
Schematic Design Video: https://www.youtube.com/watch?v=nkHFoxe0mrU
PBC Design Video: https://www.youtube.com/watch?v=PlXd3lLZ4vc&t=10184s

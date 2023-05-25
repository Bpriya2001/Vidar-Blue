Title: Seismic Monitor Control (AHU)
=====================================

Priyamvadha Balakrishnan (45541474)
===================================

Folder structure
=================
Repo
    prac1
        ahu
            build
            src
                main.c
            app.overlay
            CMakeLists.txt
            prj.conf
            README.rst

    myoslib
        ahu_driver
            ahu_hci
                ahu_hci.c
                ahu_hci.h

Description of the functionality Acheived
==========================================
AHU_HCI 
=======

1. The ahu_hci folder consists of the ahu_hci.c and ahu_hci.h file. 
These files contain the code for setting up the uart1 for communication between shu and ahu.
2. ahu_hci.c initialises the uart1 in the init_uart() function.
3. print_uart(char* buf) -> the function writes the contents of the buffer to uart1.
4. recv_uart(char* buf) -> write the values in the receive line of uart1 into the buffer in the parameter.

Prac1/ahu/main.c 
================
Shell commands for finding the following information have been set up:
1*. System timer in hours:min:seconds format and seconds format
2*. commands to find the sensor values for lsm6dsl, lps22 have been set up
3*. shell commands for controlling scu led, finding pushbutton state and sampling time have also been set up.
4*. communicaiton between scu and ahu have been set up using uart1. The shell commands send requests to the scu through the uart1 in the form of packets in the format mentioned in the hci spec sheet.
5*. The shell command line interface is run in a thread.

Instruction to run the file
============================
1. go into the directory in the rpeo: prac1->ahu
2. build the program using the following command: west build -p auto -b esp32c3_devkitm
3. When testing only the ahu without the scu-> connect the GPIO4 pin (TX) to the GPIO5 pin (RX).
4. connect the esp32c3_devkitm and flash the board using command: west flash
5. open the screen and run the sheel commands. open screen using following command: screen /dev/ttyUSB0 115200

User Instructions 
=================
1. To find the System Timer use shell command: time f
-> to display it in hours: min: time fomat: time f h

Scu command line inteface commands
==================================
1. system time: time f [h]
2. lsm6dsl accellometer values: lsm6dsl r a {t|x|y|z}
3. lsm6dsl gyroscope values: lsm6dsl r g {x|y|z}
4. lsm6dsl magnetometer values: lsm6dsl r m {x|y|z}
5. lps22 pressure values: lps22 r
6. scu led control: led w [o|f] [0|1]
7. set sample time : sample w [sec]
8. find pushbutton state: pb r

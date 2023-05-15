import serial.tools.list_ports
import re

ports = list(serial.tools.list_ports.comports())

for port in ports:
    print(port)


ser = serial.Serial('/dev/ttyUSB0', 115200)  # open serial port at 9600 baud rate
datafile = open('data.txt', 'w+');

while True:
    value = ser.readline().decode().rstrip()
    #text = "some text 170, 123, 456, 789, 012\n some more text 170, 111, 222, 333, 444\n"
    pattern = r'170,\s*\d+,\s*\d+,\s*\d+,\s*\d+\s*'
    matches = re.findall(pattern, value)
    datafile.write(matches[0]+'\n')

ser.close()
datafile.close()
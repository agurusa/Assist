
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "serial.cpp"
#include <unistd.h>
using namespace std;


int main(int argc, char **argv){

	string serialDev ("/dev/ttyACM0");
	string getVersion = "getVersion\n";
	string turnOnTestmode = "Testmode on\n";
	string command = "Setmotor -300 300 300\n";
	SimpleSerial serial(serialDev, 115200);
	serial.writeString(getVersion);
	serial.readLine();
	sleep(2);
	serial.writeString(turnOnTestmode);
	sleep(2);
	serial.writeString(command);
	sleep(2);
	return 0;

};

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "serial.cpp"
#include <unistd.h>
using namespace std;


int main(int argc, char **argv){

	// set serialDev variable to the same port that the neato will be plugged in to the raspberry pi
	string serialDev ("/dev/ttyACM0");

	string getVersion = "getVersion\n";
	string turnOnTestmode = "Testmode on\n";
	string command = "Setmotor -300 300 300\n";

	// create a new serial port connection using the SimpleSerial class.
	SimpleSerial serial(serialDev, 115200);

	// send a simple command to make sure the connection has been made.
	serial.writeString(getVersion);
	// read the response from that command
	serial.readLine();
	// wait for 1 second.
	sleep(1);

	// put the neato on testmode.
	serial.writeString(turnOnTestmode);
	sleep(1);
	// make the neato move.
	serial.writeString(command);
	sleep(1);
	
	return 0;

};
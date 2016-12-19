#include <ros/ros.h>
#include <stdlib.h>
#include "std_msgs/String.h"
#include <iostream>
#include <boost/asio.hpp> 
// #include <boost/asio/serial_port.hpp">
#include <boost/bind.hpp>
#include <boost/integer.hpp>
using namespace boost;
using namespace boost::asio;
using namespace std;

// class NeatoNode{
	//should this be public or private?
	// public: 
		//start node
		// ros::NodeHandle nh("~");
		// std::string s;
		// //check if the port is on /ttyACM0 and assign that value to the port attribute
		// bool port = nh.getParam("port", s);
// };

void chatterCallback(const std_msgs::String::ConstPtr& msg){
	ROS_INFO("I heard: [%s]", msg->data.c_str());
};

int main(int argc, char **argv){

	//is this a thing?!
	boost::asio::io_service io;
	std::string serialDev = "/dev/ttyACM0";
	std::string command = "GetVersion";
	boost::asio::serial_port serial(io, serialDev);
	write( serial, boost::asio::buffer(command));
	cout << "I did it";
	// sleep(1);
	// string ver = "";
	// char c = 0;
	// bool reading = true;
	// while(reading){
	// 	asio::read(serial,asio::buffer(&c,1));
	// 	switch(c){
	// 		case '\0':
	// 		asio::read(serial,asio::buffer(&c,1));
	// 		reading = false;
	// 		break;
	// 	default:
	// 		ver+=c;
	// 	}
	// }
	// cout << "version: " <<ver << endl;
	// return 0
	//up till here.

	//initialize new instance of ros node and name it neato
	ros::init(argc, argv, "neato");
	// start node
	ros::NodeHandle nh;
	// ros:: NodeHandle nh("~");
	// define the port you want it set to
	// string thePort = "/dev/ttyACM0";
	// set the port
	// nh.setParam("port", thePort);
	// bool port = nh.getParam("port", thePort);
	// // while(ros::ok()){
	// // 	cout << port;
	// // cout << "hi";
	// //create a new object neato of class NeatoNode
	// // NeatoNode neato2;
	// // cout << neato2.port;
	// }
	ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
	ros::spin();
	return 0;

};

// define robot port


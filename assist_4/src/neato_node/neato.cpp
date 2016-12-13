#include <ros/ros.h>
#include <stdlib.h>
#include "std_msgs/String.h"
#include <iostream>
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

}
// this will be the file that talks to the neato. it's a publisher node
#include <ros/ros.h>
#include <stdlib.h>
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
	ros::init(argc, argv, "talker");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
	ros::Rate rate(10);
	while (ros::ok()){
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world";
		msg.data = ss.str();
		ROS_INFO("[Talker] I published %s\n", msg.data.c_str());

		// publish the message
		pub.publish(msg);
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
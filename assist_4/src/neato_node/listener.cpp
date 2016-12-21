#include <ros/ros.h>
#include <std_msgs/String.h>
using namespace std;
using namespace ros;

void chatterCallback(const std_msgs::String::ConstPtr& msg){
	ROS_INFO("I heard: [%s]", msg->data.c_str());
};

int main(int argc, char **argv){
	// initialize new instance of ros node and name it listener
	init(argc, argv, "listener");
	// start node
	NodeHandle nh;
	// define the port you wnat to set it to
	string thePort = "/dev/ttyACM0";
	// set the port
	nh.setParam("port", thePort);
	Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
	spin();
	return 0;
};
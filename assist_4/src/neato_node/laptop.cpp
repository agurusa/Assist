// The laptop has to communicate to the raspberry pi.
// It sends commands to the pi.
// It listens for the response from the pi.

// I need to create inheritance for ros nodes publishers and subscribers.

class Laptop{
	public:
		// sends commands to pi as a ROS Node
		void sendToPi(){
			while(ros::ok(std::stringstream ss)){
				std_msgs::String msg;
				msg.data = ss.str();
				ROS_INFO("I published %s\n", msg.data.c_str());
			}

		};
		// listens for response from pi as a ROS Node
		void listenForPi(const std_msgs::String::ConstPtr& msg){
			ROS_INFO("I heard: [%s]", msg->data.c_str());
		};
};

int main(int argc, char **argv){
	ros::init(argc, argv, "laptop");
	ros::NodeHandle laptop;
	string thePort = "/dev/ttyACM0";
	laptop.setParam("port", thePort);
	ros::Subsriber laptopSubsriber = laptop.subscribe("the pi", 1000, listenForPi)
}
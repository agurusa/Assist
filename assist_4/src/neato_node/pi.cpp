// The raspberry pi has to communicate to both the laptop and the pi. 
// It listens for commands from the laptop.
// It sends those commands to the neato.
// It listens for the response from the neato.
// It sends the response to the latpop.

class Pi{
	public:
		// listens for laptop as a ROS Node
		void listenForLaptop(const std_msgs::String::ConstPtr& msg){
			ROS_INFO("I heard: [%s]", msg->data.c_str());
		};
		// sends to neato through a serial port
		void sendToNeato(string s){

		}
		// listens to neato through a serial port
		void listenForPi(string s){

		}
		// sends to laptop as a ROS Node
		void sendToLaptop(string s){

		}
}

// The pi has to act as a ROS Node. It must be a publisher and subscriber.

int main(int argc, char **argv){
	ros::init(argc, argv, "pi");
	NodeHandle pi;
	// make the port a global variable
	string thePort = "/dev/ttyACM0";
	pi.setParam("port", thePort);
	ros::Subscriber piSubscriber = pi.subscribe("the laptop", 1000, listenForLaptop);
	spin();
	return 0;
}
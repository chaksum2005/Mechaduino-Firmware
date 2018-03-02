#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mechaduino_stepper/Move.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "stepper_talker");

	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<mechaduino_stepper::Move>("/movedeg", 1000);

	mechaduino_stepper::Move msg;
	msg.deg = atoll(argv[1]);

	while (pub.getNumSubscribers() < 1){
		if (!ros::ok()){
			return 0;
		}
	}
	pub.publish(msg);
	ros::spinOnce();
	ROS_INFO("Command Sent");

	return 0;
}

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mechaduino_stepper/Move.h"
#include "serial/serial.h"

void commandCallback(const mechaduino_stepper::Move& msg);
void talk (serial::Serial *ser, int deg);
void initiate (serial::Serial *ser);


serial::Serial *ser;


int main(int argc, char **argv){
	ros::init(argc, argv, "stepper_control");
	ros::NodeHandle n;

	serial::Serial serial("/dev/ttyUSB0", 115200, serial::Timeout::simpleTimeout(1000));
	ser = &serial;

	if( ser->isOpen()){
	
	}
	else{
		std::cout << "connection error\n";
		return 0;
	}
	ros::Subscriber sub = n.subscribe("/movedeg", 1000, commandCallback);
	printf("Ready for serial communications\n");
	ros::spin();

}

void commandCallback(const mechaduino_stepper::Move& msg){
	talk (ser, msg.deg);
}

void talk (serial::Serial *ser, int deg){
	std::string result("");
	std::string message("");
	
	std::ostringstream os;
 	os << deg;
  	std::cout << os.str();	

	ser->write(os.str());
	ser->flush();
	ser->readline( result );
	std::cout << result;
	std::cout << "done\n";
}


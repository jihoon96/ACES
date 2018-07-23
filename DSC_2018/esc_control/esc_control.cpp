#include "ros/ros.h"
#include "esc_control/esc_signal.h"
#include <iostream>
#include "my_header.h"

void msgCallback(const esc_control::esc_signal msg)
{
	unsigned char digest[SHA_DIGEST_LENGTH];
	char steering[5];
	char motor[5];
	if( msg.steering == 1200 )
		steering = "1200";
	else if( msg.steering == /*  */ )
		steering = "/* */";

	char string[] = "1200";

	SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

	unsigned short the_crc;

	the_crc = CRCCCITT(digest, sizeof(digest),0,0);

	transmit(digest, the_crc);

/*
	int steering = msg.steering;
	int motor = msg.motor;
	gpioPWM(STEERING_PIN, steering);
	gpioPWM(MOTOR_PIN, motor);
	ROS_INFO("steering : %d, motor : %d", steering, motor);
*/
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "esc_control");
	ros::NodeHandle n;

	ros::Subscriber esc_signal_sub = n.subscribe("esc_signal_msg",10, msgCallback);

	// LOOP
	ros::spin();

	return 0;
}

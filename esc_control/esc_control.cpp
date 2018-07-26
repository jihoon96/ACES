#include "ros/ros.h"
#include "esc_control/esc_signal.h"
#include <iostream>
#include "my_header.h"

void msgCallback(const esc_control::esc_signal msg)
{
	unsigned char digest[SHA_DIGEST_LENGTH];
	char string[9];

	sprintf(string, "%d%d", msg.steering, msg.motor);

	SHA1((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

	for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	printf("SHA digest: %s\n", mdString);

	unsigned short the_crc;

	the_crc = CRCCCITT(digest, sizeof(digest),0,0);

	//Randomly inverse SHA-1 bits
	srand((int)time(NULL));
	int rand_val = rand()%10 + 1;

	if(rand_val < 6){
		for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
			digest[i] = (unsigned int)digest[i]^0xFF;
	}

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

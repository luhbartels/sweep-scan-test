#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

int i;
float dist[6280];

void clb(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	for (i=0; i<6280; i++)
	{
	dist[i] = msg->ranges[i];
	
	//printf("Reading ranges: [%f] \n", dist[i]);
	//printf("Reading angles: [%d] \n", i);

	if (dist[i]>0.000 && dist[i]<40.000)
	{
		printf("Object detected!");
		printf("Angle: %d \n", i);	 
		printf("Distance: %.3f \n", dist[i]);	

	} 
	}
	
	

}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "my_node");
	
	ros::NodeHandle n;
	
	ros::Subscriber sub_laser = n.subscribe("/scan", 1000, clb);
	
	ros::spin();
	
}

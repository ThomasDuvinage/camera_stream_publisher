#include <cstdlib>
#include <ros/ros.h>
#include <ros/console.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream> // for converting the command line parameter to integer

#include <iostream>

int main(int argc, char** argv)
{

  ros::init(argc, argv, "camera_stream_publisher_node");
  ros::NodeHandle nh("~");
  image_transport::ImageTransport it(nh);

  int video_source;
  nh.param<int>("video_source", video_source, 0);

  std::string topic;
  nh.param<std::string>("published_topic", topic, "image");

  
  image_transport::Publisher pub = it.advertise(topic, 100);

  cv::VideoCapture cap(video_source);
  // Check if video device can be opened with the given index
  if(!cap.isOpened()){
    ROS_ERROR("Unable to open camera");
    return EXIT_FAILURE;
  }

  cv::Mat frame;
  sensor_msgs::ImagePtr msg;

  ros::Rate loop_rate(60);
  while (nh.ok()) {
    cap >> frame;
    // Check if grabbed frame is actually full with some content
    if(!frame.empty()) {
      msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      pub.publish(msg);
    }

    ros::spinOnce();
    loop_rate.sleep();
  }
}
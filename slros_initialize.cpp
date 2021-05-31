#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ghostfollower";

// For Block ghostfollower/Subscribe1
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_187;

// For Block ghostfollower/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_207;

// For Block ghostfollower/Subscribe3
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_41;

// For Block ghostfollower/Follower Stopper Switch Control/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ghostfollower_std_msgs_Float64> Pub_ghostfollower_234;

// For Block ghostfollower/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Pub_ghostfollower_37;

// For Block ghostfollower/Publish Region/Publish1
SimulinkPublisher<std_msgs::UInt8, SL_Bus_ghostfollower_std_msgs_UInt8> Pub_ghostfollower_165;

// For Block ghostfollower/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ghostfollower_std_msgs_Float64> Pub_ghostfollower_223;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_228;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_226;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter3
SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_230;

// For Block ghostfollower/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_236;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}


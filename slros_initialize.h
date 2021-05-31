#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ghostfollower/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_187;

// For Block ghostfollower/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_207;

// For Block ghostfollower/Subscribe3
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Sub_ghostfollower_41;

// For Block ghostfollower/Follower Stopper Switch Control/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ghostfollower_std_msgs_Float64> Pub_ghostfollower_234;

// For Block ghostfollower/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ghostfollower_geometry_msgs_Twist> Pub_ghostfollower_37;

// For Block ghostfollower/Publish Region/Publish1
extern SimulinkPublisher<std_msgs::UInt8, SL_Bus_ghostfollower_std_msgs_UInt8> Pub_ghostfollower_165;

// For Block ghostfollower/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ghostfollower_std_msgs_Float64> Pub_ghostfollower_223;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_228;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_226;

// For Block ghostfollower/Follower Stopper Switch Control/Get Parameter3
extern SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_230;

// For Block ghostfollower/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_ghostfollower_236;

void slros_node_init(int argc, char** argv);

#endif

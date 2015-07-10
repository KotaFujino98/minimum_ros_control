#include <ros/ros.h>
#include <ros/package.h>
#include <angles/angles.h>
#include <trobo_control/trobo_hw.h>
#include <iostream> // for debug
#include <math.h>

TRobo::TRobo()
{
  // connect and register the joint state interface
  hardware_interface::JointStateHandle state_handle_1("joint1", &pos_[0], &vel_[0], &eff_[0]);
  jnt_state_interface.registerHandle(state_handle_1);
  registerInterface(&jnt_state_interface);

  // connect and register the joint effort interface
  hardware_interface::JointHandle vel_handle_1(jnt_state_interface.getHandle("joint1"), &cmd_[0]);
  jnt_vel_interface.registerHandle(vel_handle_1);
  registerInterface(&jnt_vel_interface);
}

void TRobo::read(ros::Time time, ros::Duration period)
{
}

void TRobo::write(ros::Time time, ros::Duration period)
{
  pos_[0] = cmd_[0];
}


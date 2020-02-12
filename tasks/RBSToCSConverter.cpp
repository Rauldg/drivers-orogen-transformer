/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "RBSToCSConverter.hpp"

using namespace transformer;

base::samples::CartesianState rbsToCartesianState(const base::samples::RigidBodyState& in){
    base::samples::CartesianState out;
    out.time = in.time;
    out.source_frame = in.sourceFrame;
    out.target_frame = in.targetFrame;
    out.pose.position = in.position;
    out.pose.orientation = in.orientation;
    out.twist.linear = in.velocity;
    out.twist.angular = in.angular_velocity;
    return out;
}

RBSToCSConverter::RBSToCSConverter(std::string const& name, TaskCore::TaskState initial_state)
    : RBSToCSConverterBase(name, initial_state)
{
}

RBSToCSConverter::~RBSToCSConverter()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See RBSToCSConverter.hpp for more detailed
// documentation about them.

bool RBSToCSConverter::configureHook()
{
    if (! RBSToCSConverterBase::configureHook())
        return false;
    return true;
}
bool RBSToCSConverter::startHook()
{
    if (! RBSToCSConverterBase::startHook())
        return false;
    return true;
}
void RBSToCSConverter::updateHook()
{
    RBSToCSConverterBase::updateHook();

    base::samples::RigidBodyState sample;
    while(_input.read(sample) == RTT::NewData){
        _output.write(rbsToCartesianState(sample));
    }
}
void RBSToCSConverter::errorHook()
{
    RBSToCSConverterBase::errorHook();
}
void RBSToCSConverter::stopHook()
{
    RBSToCSConverterBase::stopHook();
}
void RBSToCSConverter::cleanupHook()
{
    RBSToCSConverterBase::cleanupHook();
}

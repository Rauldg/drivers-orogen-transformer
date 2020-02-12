/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "CSToRBSConverter.hpp"

using namespace transformer;

base::samples::RigidBodyState cartesianStateToRbs(const base::samples::CartesianState& in){
    base::samples::RigidBodyState out;
    out.time = in.time;
    out.sourceFrame = in.source_frame;
    out.targetFrame = in.target_frame;
    out.position = in.pose.position;
    out.orientation = in.pose.orientation;
    out.velocity = in.twist.linear;
    out.angular_velocity = in.twist.angular;
    return out;
}

CSToRBSConverter::CSToRBSConverter(std::string const& name, TaskCore::TaskState initial_state)
    : CSToRBSConverterBase(name, initial_state)
{
}

CSToRBSConverter::~CSToRBSConverter()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See CSToRBSConverter.hpp for more detailed
// documentation about them.

bool CSToRBSConverter::configureHook()
{
    if (! CSToRBSConverterBase::configureHook())
        return false;
    return true;
}
bool CSToRBSConverter::startHook()
{
    if (! CSToRBSConverterBase::startHook())
        return false;
    return true;
}
void CSToRBSConverter::updateHook()
{
    CSToRBSConverterBase::updateHook();

    base::samples::CartesianState sample;
    while(_input.read(sample) == RTT::NewData){
        _output.write(cartesianStateToRbs(sample));
    }
}
void CSToRBSConverter::errorHook()
{
    CSToRBSConverterBase::errorHook();
}
void CSToRBSConverter::stopHook()
{
    CSToRBSConverterBase::stopHook();
}
void CSToRBSConverter::cleanupHook()
{
    CSToRBSConverterBase::cleanupHook();
}

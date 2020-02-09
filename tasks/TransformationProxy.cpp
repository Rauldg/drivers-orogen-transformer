/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "TransformationProxy.hpp"

using namespace transformer;

TransformationProxy::TransformationProxy(std::string const& name, TaskCore::TaskState initial_state)
    : TransformationProxyBase(name, initial_state)
{
}

TransformationProxy::TransformationProxy(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : TransformationProxyBase(name, engine, initial_state)
{
}

TransformationProxy::~TransformationProxy()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See TransformationProxy.hpp for more detailed
// documentation about them.

bool TransformationProxy::configureHook()
{
    if (! TransformationProxyBase::configureHook())
        return false;
    return true;
}
bool TransformationProxy::startHook()
{
    if (! TransformationProxyBase::startHook())
        return false;
    last_forwarded = base::Time::now();
    count = 0;
    return true;
}
void TransformationProxy::updateHook()
{
    TransformationProxyBase::updateHook();

    base::samples::RigidBodyState sample;
    while(_input.read(sample) == RTT::NewData){
        switch(_policy.get().policy){
        case SINGLE_SHOT:
            if(count < 1){
                _output.write(sample);
                count++;
            }
            break;
        case DOWNSAMPLE_BY_TIME:
            if((base::Time::now()-last_forwarded).toSeconds() > _policy.get().arg){
                _output.write(sample);
                last_forwarded = base::Time::now();
            }
            break;
        case DOWNSAMPLE_BY_NSAMPLE:
            if(count >= _policy.get().arg){
                _output.write(sample);
                count = 0;
            }
            break;
        case REDIRECT_ALL:
            _output.write(sample);
            break;
        }
    }
}
void TransformationProxy::errorHook()
{
    TransformationProxyBase::errorHook();
}
void TransformationProxy::stopHook()
{
    TransformationProxyBase::stopHook();
}
void TransformationProxy::cleanupHook()
{
    TransformationProxyBase::cleanupHook();
}

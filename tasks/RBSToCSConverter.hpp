/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef TRANSFORMER_RBSTOCSCONVERTER_TASK_HPP
#define TRANSFORMER_RBSTOCSCONVERTER_TASK_HPP

#include "transformer/RBSToCSConverterBase.hpp"

namespace transformer{

    class RBSToCSConverter : public RBSToCSConverterBase
    {
	friend class RBSToCSConverterBase;
    protected:



    public:
       RBSToCSConverter(std::string const& name = "transformer::RBSToCSConverter", TaskCore::TaskState initial_state = Stopped);
	~RBSToCSConverter();
        bool configureHook();
        bool startHook();
        void updateHook();
        void errorHook();
        void stopHook();
        void cleanupHook();
    };
}

#endif


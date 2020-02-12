/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef TRANSFORMER_CSTORBSCONVERTER_TASK_HPP
#define TRANSFORMER_CSTORBSCONVERTER_TASK_HPP

#include "transformer/CSToRBSConverterBase.hpp"

namespace transformer{
    class CSToRBSConverter : public CSToRBSConverterBase
    {
	friend class CSToRBSConverterBase;
    protected:



    public:
        CSToRBSConverter(std::string const& name = "transformer::CSToRBSConverter", TaskCore::TaskState initial_state = Stopped);
	~CSToRBSConverter();
        bool configureHook();
        bool startHook();
        void updateHook();
        void errorHook();
        void stopHook();
        void cleanupHook();
    };
}

#endif


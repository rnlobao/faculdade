#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"

using namespace std;

class FlowImpl : public Flow{

    protected:
        string name; 
        System* source; 
        System* target; 
        FlowImpl(const Flow& flow);
        FlowImpl& operator=(const Flow& flow);

    public:
        friend class Model; 
        friend class ModelImpl; 
        friend class unit_Flow; 

        FlowImpl(string name = "", System* source = NULL, System* target = NULL);
    
        virtual ~FlowImpl();

        virtual double execute() = 0;

        string getName() const;

        void setName(string flowName);

        System* getSource() const;

        void setSource(System* sourceSys);

        void clearSource();

        System* getTarget() const;
        
        void setTarget(System* targetSys);

        void clearTarget();
};

#endif
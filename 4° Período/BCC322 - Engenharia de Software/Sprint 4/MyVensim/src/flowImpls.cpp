#include "flowImpl.h"

FlowImpl::FlowImpl(const Flow& flow){
    if (this == &flow){
        return;
    }
    
    name = flow.getName();
    source = NULL;
    target = NULL;
}

FlowImpl& FlowImpl::operator=(const Flow& flow){
    if (this == &flow){
        return *this;
    }

    setName(flow.getName());
    setSource(NULL);
    setTarget(NULL);

    return *this;
}

FlowImpl::FlowImpl(string name, System* source, System* target):name(name), source(source), target(target){}

FlowImpl::~FlowImpl(){}

string FlowImpl::getName() const {
    return name;
}
        
void FlowImpl::setName(string flowName){
    name = flowName;
}

System* FlowImpl::getSource() const{
    return source;
}

void FlowImpl::setSource(System* sourceSys){
    source = sourceSys;
}

void FlowImpl::clearSource() {
    source = NULL;
}

System* FlowImpl::getTarget() const {
    return target;
}

void FlowImpl::setTarget(System* targetSys) {
    target = targetSys;
}

void FlowImpl::clearTarget() {
    target = NULL;
}
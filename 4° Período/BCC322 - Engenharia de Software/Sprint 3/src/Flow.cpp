#include "Flow.h"
using namespace std;

string Flow::getName() {
    return this->name;
}

void Flow::setName(string flowName){
    this->name = flowName;
}

System* Flow::getSource() {
    return this->source;
}

void Flow::setSource(System* sourceSys){
    this->source = sourceSys;
}

void Flow::clearSource() {
    this->source = NULL;
}

System* Flow::getTarget() {
    return this->target;
}
        
void Flow::setTarget(System* targetSys) {
    this->target = targetSys;
}

void Flow::clearTarget() {
    this->target = NULL;
}

Flow& Flow::operator=(const Flow& flow){
    if (this == &flow){
        return *this;
    }

    name = flow.name;           
    source = flow.source;
    target = flow.target;
    return *this;
}

Flow::Flow(const Flow& flow){
    name = flow.name;           
    source = flow.source;
    target = flow.target;
}
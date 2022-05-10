#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./System.h"

using namespace std;

class Flow{

    protected:
        string name;
        System* source; 
        System* target; 

    public:
        friend class Model; 

        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        

        virtual ~Flow(){}
        virtual double execute() = 0;
        string getName() const{
            return name;
        }

        void setName(string flowName){
            name = flowName;
        }


        System* getSource() const{
            return source;
        }

        void setSource(System* sourceSys){
            source = sourceSys;
        }

        void clearSource() {
            source = NULL;
        }

        System* getTarget() const{
            return target;
        }
        
        void setTarget(System* targetSys) {
            target = targetSys;
        }

        void clearTarget() {
            target = NULL;
        }

    private:

        Flow (const Flow& flow){
            name = flow.name;           
            source = flow.source;
            target = flow.target;
        }

        Flow& operator=(const Flow& flow){
            if (this == &flow){
                return *this;
            }

            name = flow.name;           
            source = flow.source;
            target = flow.target;
            return *this;
        }

};

#endif
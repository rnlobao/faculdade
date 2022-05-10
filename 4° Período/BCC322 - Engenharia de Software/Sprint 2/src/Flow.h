#ifndef FLOW_H
#define FLOW_H

#include "./System.h"
#include "./Model.h"
#include <windef.h>
#include <string>
using namespace std;

class Flow {
    protected:
        string name;
        System* source;
        System* target;
    public:
        friend class Model;
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        virtual ~Flow() {}
        virtual double execute() = 0;
        string getName() const{
            return name;
        }

        void setName(string nameFlow){
            name = nameFlow;
        } 

        System* getTarget() const{
            return target;
        }

        void setTarget(System* targetSys){
            target = targetSys;
        }

        System* getSource() const{
            return source;
        }

        void setSource(System* sourceSys){
            source = sourceSys;
        }

    private:
        Flow (const Flow& flow){         
            source = flow.source;
            target = flow.target;
            name = flow.name;
        }

        Flow& operator=(const Flow& flow){
            if (this == &flow){
                return *this;
            }

            target = flow.target;
            source = flow.source;
            name = flow.name;
            return *this;
        }
};

#endif
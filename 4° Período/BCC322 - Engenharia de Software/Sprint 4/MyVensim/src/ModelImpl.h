#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"

using namespace std;

class ModelImpl : public Model{

    protected:
        string name;
        double time; 
        vector<System*> systems; 
        vector<Flow*> flows;       
    public:             
        typedef vector<System *>::iterator systemIterator;
        typedef vector<Flow *>::iterator flowIterator;

        systemIterator beginSystems(); 
        systemIterator endSystems(); 
        flowIterator beginFlows(); 
        flowIterator endFlows(); 
    
        ModelImpl(string name="", double time=0.0);
        
        virtual ~ModelImpl();
  
        void execute(double start=0.0, double final=0.0, double increment=1.0);

        void add(System* sys);
        
        void add(Flow* flow);
         
        void remove(System* sys);
      
        void remove(Flow* flow);

        void setName(string modelName);

        string getName() const;

        void setTime(double currentTime);

        double getTime() const;

        void incrementTime(double increment);

        System* getSystem(int index);

        Flow* getFlow(int index);

    private:
        ModelImpl (const ModelImpl& model);
        void operator=(const ModelImpl& model);

};

#endif
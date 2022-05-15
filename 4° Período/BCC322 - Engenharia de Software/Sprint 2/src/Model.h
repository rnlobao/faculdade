#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "./System.h"
#include "./Flow.h"

using namespace std;

class Model{

    protected:
        string name;
        double time; 
        vector<System*> systems;  
        vector<Flow*> flows; 

    public:
        auto beginSystems();
        auto endSystems();
        auto beginFlows();
        auto endFlows();

        Model(){}

        Model(string name="", double time=0.0):name(name), time(time){}

        virtual ~Model(){}
        void execute(double start, double final, double increment);
        void add(System* sys);
        void add(Flow* flow);
        void remove(System* sys);
        void remove(Flow* flow);
        void setName(string modelName);
        string getName();
        void setTime(double currentTime);
        double getTime();
        void incrementTime(double increment);

    private: 
        Model (const Model& model);
        Model& operator=(const Model& model);
};

#endif
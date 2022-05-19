#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

#include "Flow.h"

using namespace std;

class Model{
    public:
        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;

        virtual systemIterator beginSystems() = 0;
        virtual systemIterator endSystems() = 0;
        virtual flowIterator beginFlows() = 0;
        virtual flowIterator endFlows() = 0;

        virtual ~Model(){}
        virtual void execute(double start, double final, double increment) = 0;
        virtual void add(System* sys) = 0;
        virtual void add(Flow* flow) = 0;
        virtual void remove(System* sys) = 0;
        virtual void remove(Flow* flow) = 0;
        virtual void setName(string modelName) = 0;
        virtual string getName() = 0;
        virtual void setTime(double currentTime) = 0;
        virtual double getTime() = 0;
        virtual void incrementTime(double increment) = 0;
};

#endif
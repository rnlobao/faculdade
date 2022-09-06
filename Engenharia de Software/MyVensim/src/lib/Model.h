#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>

#include "Flow.h"

using namespace std;
/**
 * @brief Model class
 * 
 */
class Model{
    public:
        /**
         * @brief vector of systems
         * 
         */
        typedef vector<System*>::iterator systemIterator;
        /**
         * @brief vector of flows
         * 
         */
        typedef vector<Flow*>::iterator flowIterator;
        /**
         * @brief begin of systems
         * 
         * @return systemIterator 
         */
        virtual systemIterator beginSystems() = 0;
        /**
         * @brief end os systems
         * 
         * @return systemIterator 
         */
        virtual systemIterator endSystems() = 0;
        /**
         * @brief begin of flows
         * 
         * @return flowIterator 
         */
        virtual flowIterator beginFlows() = 0;
        /**
         * @brief end of flows
         * 
         * @return flowIterator 
         */
        virtual flowIterator endFlows() = 0;
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model(){}
        /**
         * @brief virtual execute
         * 
         * @param start the start time
         * @param increment increment value
         */
        virtual void execute(double start, double final, double increment) = 0;
        /**
         * @brief add a system
         * 
         * @param sys system to add
         */
        virtual void add(System* sys) = 0;
        /**
         * @brief add a flow
         * 
         * @param flow flow to add
         */
        virtual void add(Flow* flow) = 0;
        /**
         * @brief remove a systrem
         * 
         * @param sys system to remove
         */
        virtual void remove(System* sys) = 0;
        /**
         * @brief remove a flow
         * 
         * @param flow flow to remove
         */
        virtual void remove(Flow* flow) = 0;
        /**
         * @brief Set the Name object
         * 
         * @param modelName the name of the model
         */
        virtual void setName(string modelName) = 0;
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the Time object
         * 
         * @param currentTime the current time
         */
        virtual void setTime(double currentTime) = 0;
        /**
         * @brief Get the Time object
         * 
         * @return double 
         */
        virtual double getTime() const = 0;
        /**
         * @brief what unity will be incremented
         * 
         * @param increment the value to increment
         */
        virtual void incrementTime(double increment) = 0;
};

#endif
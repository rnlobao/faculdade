#ifndef FLOW_H
#define FLOW_H

#include <string>
#include <iostream>
#include "System.h"

using namespace std;

/**
 * @brief Flow class
 * 
 */
class Flow{
    public:
        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow() {}
        /**
         * @brief virtual execute
         * 
         * @return double 
         */
        virtual double execute() = 0;
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the Name object
         * 
         * @param flowName the name of the flow
         */
        virtual void setName(string flowName) = 0;
        /**
         * @brief Get the Source object
         * 
         * @return System* 
         */
        virtual System* getSource() const = 0;
        /**
         * @brief Set the Source object
         * 
         * @param sourceSys the source System
         */
        virtual void setSource(System* sourceSys) = 0;
        /**
         * @brief Clear the source
         * 
         */
        virtual void clearSource() = 0;
        /**
         * @brief Get the Target object
         * 
         * @return System* 
         */
        virtual System* getTarget() const = 0;
        /**
         * @brief Set the Target object
         * 
         * @param targetSys the target System
         */
        virtual void setTarget(System* targetSys) = 0;
        /**
         * @brief Clear the target
         * 
         */
        virtual void clearTarget() = 0;
};

#endif
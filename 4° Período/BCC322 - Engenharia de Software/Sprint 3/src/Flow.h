#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./System.h"

using namespace std;

/**
 * @brief My flow class
 * 
 */
class Flow{
    protected:
        /**
         * @brief Name in flow class
         * 
         */
        string name;
        /**
         * @brief Source of the Flow
         * 
         */
        System* source; 
        /**
         * @brief Target of the flow
         * 
         */
        System* target; 
    public:
        /**
         * @brief Friend class model
         * 
         */
        friend class Model; 
        /**
         * @brief Construct a new Flow object
         * 
         */
        Flow(){};
        /**
         * @brief Construct a new Flow object
         * 
         * @param name name of class
         * @param source source of class
         * @param target target of class
         */
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow(){}
        /**
         * @brief Execute of the flow
         * 
         * @return double 
         */
        virtual double execute() = 0;
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName();
        /**
         * @brief Set the Name object
         * 
         * @param flowName here we give the flow name
         */
        void setName(string flowName);
        /**
         * @brief Get the Source object
         * 
         * @return System* 
         */
        System* getSource();
        /**
         * @brief Set the Source object
         * 
         * @param sourceSys here we give the source of the system
         */
        void setSource(System* sourceSys);
        /**
         * @brief clear the source
         * 
         */
        void clearSource();
        /**
         * @brief Get the Target object
         * 
         * @return System* 
         */
        System* getTarget();
        /**
         * @brief Set the Target object
         * 
         * @param targetSys here we give the target of the system
         */
        void setTarget(System* targetSys);
        /**
         * @brief clear the target
         * 
         */
        void clearTarget();
    private:
        /**
         * @brief Construct a new Flow object
         * 
         * @param flow we provide the flow to copy
         */
        Flow (const Flow& flow);
        /**
         * @brief Overloading =
         * 
         * @param flow we provide the flow to overload
         * @return Flow& 
         */
        Flow& operator=(const Flow& flow);
};

#endif
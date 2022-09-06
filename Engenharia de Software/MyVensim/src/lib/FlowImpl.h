#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"

using namespace std;

/**
 * @brief Flow Impl
 * 
 */
class FlowImpl : public Flow{

    protected:
        /**
         * @brief Name of flow
         * 
         */
        string name; 
        /**
         * @brief Source of flow
         * 
         */
        System* source; 
        /**
         * @brief Target of flow
         * 
         */
        System* target; 
    public:
        /**
         * @brief Construct a new Flow Impl object
         * 
         * @param name name in flow
         * @param source source in Flow
         * @param target target in flow
         */
        FlowImpl(string name = "", System* source = NULL, System* target = NULL);
        /**
         * @brief Destroy the Flow Impl object
         * 
         */
        virtual ~FlowImpl();
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
        string getName() const;
        /**
         * @brief Set the Name object
         * 
         * @param flowName name in flow
         */
        void setName(string flowName);
        /**
         * @brief Get the Source object
         * 
         * @return System* 
         */
        System* getSource() const;
        /**
         * @brief Set the Source object
         * 
         * @param sourceSys source system in flow
         */
        void setSource(System* sourceSys);
        /**
         * @brief clear source
         * 
         */
        void clearSource();
        /**
         * @brief Get the Target object
         * 
         * @return System* 
         */
        System* getTarget() const;
        /**
         * @brief Set the Target object
         * 
         * @param targetSys target system in flow
         */
        void setTarget(System* targetSys);
        /**
         * @brief clear the target
         * 
         */
        void clearTarget();
    private:
        /**
         * @brief Construct a new Flow Impl object
         * 
         * @param flow flow to copy
         */
        FlowImpl(const Flow& flow);
        /**
         * @brief Overloading = operator
         * 
         * @param flow flow to overload
         * @return FlowImpl& 
         */
        FlowImpl& operator=(const Flow& flow);
};

#endif
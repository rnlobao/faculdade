#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"

using namespace std;
/**
 * @brief Model Impl
 * 
 */
class ModelImpl : public Model{

    protected:
        /**
         * @brief name of Model
         * 
         */
        string name;
        /**
         * @brief time of Model
         * 
         */
        double time; 
        /**
         * @brief systems in Model
         * 
         */
        vector<System*> systems; 
        /**
         * @brief flows in Model
         * 
         */
        vector<Flow*> flows;       
    public:    
        /**
         * @brief iterator of systems
         * 
         */
        typedef vector<System *>::iterator systemIterator;
        /**
         * @brief iterator of flows
         * 
         */
        typedef vector<Flow *>::iterator flowIterator;
        /**
         * @brief begin in systems
         * 
         * @return systemIterator 
         */
        systemIterator beginSystems(); 
        /**
         * @brief end in systems
         * 
         * @return systemIterator 
         */
        systemIterator endSystems(); 
        /**
         * @brief begin in Flows
         * 
         * @return flowIterator 
         */
        flowIterator beginFlows(); 
        /**
         * @brief end in Flows
         * 
         * @return flowIterator 
         */
        flowIterator endFlows(); 
        /**
         * @brief Construct a new Model Impl object
         * 
         * @param name name in Model
         * @param time time in Model
         */
        ModelImpl(string name="", double time=0.0);
        /**
         * @brief Destroy the Model Impl object
         * 
         */
        virtual ~ModelImpl();
        /**
         * @brief execute of the model
         * 
         * @param start start time
         * @param increment the time will be increased
         */
        void execute(double start=0.0, double final=0.0, double increment=1.0);
        /**
         * @brief add system
         * 
         * @param sys system to be added
         */
        void add(System* sys);
        /**
         * @brief add flow
         * 
         * @param flow flow to be added
         */
        void add(Flow* flow);
        /**
         * @brief remove system
         * 
         * @param sys system to be removed
         */
        void remove(System* sys);
        /**
         * @brief remove flow
         * 
         * @param flow flow to be removed
         */
        void remove(Flow* flow);
        /**
         * @brief Set the Name object
         * 
         * @param modelName name choosen
         */
        void setName(string modelName);
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName() const;
        /**
         * @brief Set the Time object
         * 
         * @param currentTime current time in Model
         */
        void setTime(double currentTime);
        /**
         * @brief Get the Time object
         * 
         * @return double 
         */
        double getTime() const;
        /**
         * @brief time to increase
         * 
         * @param increment unity to increase
         */
        void incrementTime(double increment);
        /**
         * @brief Get the System object
         * 
         * @param index iterator of systems
         * @return System* 
         */
        System* getSystem(int index);
        /**
         * @brief Get the Flow object
         * 
         * @param index iterator of flows
         * @return Flow* 
         */
        Flow* getFlow(int index);

    private:
        /**
         * @brief Construct a new Model Impl object
         * 
         * @param model model to copy
         */
        ModelImpl (const ModelImpl& model);
        /**
         * @brief overload = operator
         * 
         * @param model model to overload method
         */
        void operator=(const ModelImpl& model);

};

#endif
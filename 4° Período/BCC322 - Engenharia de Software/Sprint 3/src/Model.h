#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "./System.h"
#include "./Flow.h"

using namespace std;

/**
 * @brief My Model Class
 * 
 */
class Model{

    protected:
        /**
         * @brief Name in Model Class
         * 
         */
        string name;
        /**
         * @brief Time in Model Class
         * 
         */
        double time; 
        /**
         * @brief Systems in Model
         * 
         */
        vector<System*> systems;  
        /**
         * @brief Flows in Model
         * 
         */
        vector<Flow*> flows; 

    public:
        /**
         * @brief the beginning of the System vector
         * 
         * @return auto 
         */
        auto beginSystems();
        /**
         * @brief The end of the System vector
         * 
         * @return auto 
         */
        auto endSystems();
        /**
         * @brief The beginning of the Flow vector
         * 
         * @return auto 
         */
        auto beginFlows();
        /**
         * @brief The end of the Flow vector
         * 
         * @return auto 
         */
        auto endFlows();
        /**
         * @brief Construct a new Model object
         * 
         */
        Model(){}
        /**
         * @brief Construct a new Model object
         * 
         * @param name Name in the Model
         * @param time  Time in the Model
         */
        Model(string name="", double time=0.0):name(name), time(time){}
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model(){}
        /**
         * @brief Execute the command
         * 
         * @param start start of the execute
         * @param increment increment of the execute
         */
        void execute(double start, double final, double increment);
        /**
         * @brief adding a system
         * 
         * @param sys the system added
         */
        void add(System* sys);
        /**
         * @brief adding a flow
         * 
         * @param flow the flow added
         */
        void add(Flow* flow);
        /**
         * @brief removing a system
         * 
         * @param sys system that will be removed
         */
        void remove(System* sys);
        /**
         * @brief removing flow
         * 
         * @param flow flow that will be removed
         */
        void remove(Flow* flow);
        /**
         * @brief Set the Name object
         * 
         * @param modelName the name of the Model
         */
        void setName(string modelName);
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName();
        /**
         * @brief Set the Time object
         * 
         * @param currentTime the time now
         */
        void setTime(double currentTime);
        /**
         * @brief Get the Time object
         * 
         * @return double 
         */
        double getTime();
        /**
         * @brief how many points the time will increase
         * 
         * @param increment the number of times
         */
        void incrementTime(double increment);

    private: 
        /**
         * @brief Construct a new Model object
         * 
         * @param model that will be copied
         */
        Model (const Model& model);
        /**
         * @brief Overloading =
         * 
         * @param model model that the = operator will be overloaded
         * @return Model& 
         */
        Model& operator=(const Model& model);
};

#endif
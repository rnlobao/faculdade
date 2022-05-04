#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include <string>
#include "./System.h"
#include "./Flow.h"

using namespace std;

class Model{

    protected:
        /**
         * @brief Name of the Model
         * 
         */
        string name;
        /**
         * @brief time that this model is going to operate
         * 
         */
        double time; 
        /**
         * @brief all the system in the model
         * 
         */
        vector<System*> systems;
        /**
         * @brief all the flow in the model
         * 
         */
        vector<Flow*> flows;      

    public:
        /**
         * @brief this takes the beginning of the system vector
         * 
         * @return auto 
         */
        auto beginSystems( void ) const {
            return systems.begin();
        }
        /**
         * @brief this take the end of the system vector
         * 
         * @return auto 
         */
        auto endSystems( void ) const {
            return systems.end();
        } 
        /**
         * @brief this take the beginning of the flow vector
         * 
         * @return auto 
         */
        auto beginFlows( void ) const {
            return flows.begin();
        }
        /**
         * @brief this take the end of the flow vector
         * 
         * @return auto 
         */
        auto endFlows( void ) const {
            return flows.end();
        } 
        /**
         * @brief Construct a new Model object
         * 
         */
        Model(){}
        /**
         * @brief Construct a new Model object
         * 
         * @param name 
         * @param time 
         */
        Model(string name = "", double time = 0.0):name(name), time(time){}
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model(){           
            for (System* item : systems) {
                delete (item);
            }

            for (Flow* item : flows) {
                delete (item);
            }
        }
        /**
         * @brief this take the params and execute the specific type of flow depending on the application
         * 
         * @param start 
         * @param increment 
         * @param final
         */
        void execute(double start = 0.0, double final = 0.0, double increment = 1.0){
            vector<double> resultados;
            int count = 0;
            for (double i = start; i < final; i += increment){
                for (Flow* flowsPresentesNoModel : flows) {
                    double resultmaDeDestino = flowsPresentesNoModel->getTarget();
                    sistemaDeDestino->setValue(sistemaDeDestino->getValue() + resultados[count]);
                    count++;
                } = flowsPresentesNoModel->execute();
                    resultados.push_back(result);
                }
                count = 0;
                for (Flow* flowsPresentesNoModel : flows) {
                    System* sistemaDeOrigem = flowsPresentesNoModel->getSource();
                    sistemaDeOrigem->setValue(sistemaDeOrigem->getValue() - resultados[count]);
                    System* siste
                for (auto j = beginFlows(); j != endFlows(); ++j){
                    resultados.pop_back();
                }
                time += increment;
            }
        }
        
        /**
         * @brief add some system
         * 
         * @param sys 
         */
        void add(System* sys){
            systems.insert(endSystems(), sys);
        }
        /**
         * @brief add some flow
         * 
         * @param flow 
         */
        void add(Flow* flow){
            flows.insert(endFlows(), flow);            
        }
        /**
         * @brief remove some system
         * 
         * @param sys 
         */
        void remove(System* sys){
            auto i = beginSystems();
            for (System* item : systems){
                if (sys == item){
                    systems.erase(i);
                    break;
                }
                ++i;
            }

        }
        /**
         * @brief remove some flow
         * 
         * @param flow 
         */
        void remove(Flow* flow){
            auto i = beginFlows();
            for (Flow* item : flows){
                if (flow == item){
                    flows.erase(i);
                    break;
                }
                ++i;
            }

        }
        /**
         * @brief Set the Name object
         * 
         * @param modelName 
         */
        void setName(string modelName){
            name = modelName;
        }
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName() const{
            return name;
        }    
        /**
         * @brief Set the Time object
         * 
         * @param currentTime 
         */
        void setTime(double currentTime){
            time = currentTime;
        }

        /**
         * @brief Get the Time object
         * 
         * @return double 
         */
        double getTime() const{
            return time;
        }    
        /**
         * @brief 
         * 
         * @param increment 
         */
        void incrementTime(double increment) {
            time += increment;
        }

    private: 
        /**
         * @brief Construct a new Model object
         * 
         * @param model 
         */
        Model (const Model& model){
            if (this == &model){
                return;
            }

            name = model.getName();
            time = model.getTime();   
            
            for (System* item : systems){
                System* copy(item);
                systems.insert(endSystems(), copy);
            }         

            for (Flow* item : flows){
                Flow* copy(item);
                flows.insert(endFlows(), copy);
            }
           
        }
        /**
         * @brief overloading this method
         * 
         * @param model 
         * @return Model& 
         */
        Model& operator=(const Model& model){
            if (this == &model){
                return *this;
            }

            name = model.getName();
            time = model.getTime();


            for (System* item : systems){
                System* copy(item);
                systems.insert(endSystems(), copy);
            }

            for (Flow* item : flows){
                Flow* copy(item);
                flows.insert(endFlows(), copy);
            }

            return *this;
        }
};
#endif
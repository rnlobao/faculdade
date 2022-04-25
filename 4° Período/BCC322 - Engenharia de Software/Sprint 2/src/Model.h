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
        string name;
        double time; 
        vector<System*> systems;
        vector<Flow*> flows;      

    public:
        auto beginSystems( void ) const {
            return systems.begin();
        }
        auto endSystems( void ) const {
            return systems.end();
        } 
        auto beginFlows( void ) const {
            return flows.begin();
        }
        auto endFlows( void ) const {
            return flows.end();
        } 
                        
        Model(){}
        Model(string name = "", double time = 0.0):name(name), time(time){}

        virtual ~Model(){           
            for (System* item : systems) {
                delete (item);
            }

            for (Flow* item : flows) {
                delete (item);
            }
        }

        void execute(double start = 0.0, double final = 0.0, double increment = 1.0){
            vector<double> resultados;
            int count = 0;
            for (double i = start; i < final; i += increment){
                for (Flow* flowsPresentesNoModel : flows) {
                    double result = flowsPresentesNoModel->execute();
                    resultados.push_back(result);
                }
                count = 0;
                for (Flow* flowsPresentesNoModel : flows) {
                    System* sistemaDeOrigem = flowsPresentesNoModel->getSource();
                    sistemaDeOrigem->setValue(sistemaDeOrigem->getValue() - resultados[count]);
                    System* sistemaDeDestino = flowsPresentesNoModel->getTarget();
                    sistemaDeDestino->setValue(sistemaDeDestino->getValue() + resultados[count]);
                    count++;
                }
                for (auto j = beginFlows(); j != endFlows(); ++j){
                    resultados.pop_back();
                }
                time += increment;
            }
        }
        

        void add(System* sys){
            systems.insert(endSystems(), sys);
        }
        
        void add(Flow* flow){
            flows.insert(endFlows(), flow);            
        }
        
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

        void setName(string modelName){
            name = modelName;
        }

        string getName() const{
            return name;
        }    

        void setTime(double currentTime){
            time = currentTime;
        }

        double getTime() const{
            return time;
        }    

        void incrementTime(double increment) {
            time += increment;
        }

    private: 
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
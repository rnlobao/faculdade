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
        auto beginSystems( void ) const {return systems.begin();} 
        auto endSystems( void ) const {return systems.end();} 
        auto beginFlows( void ) const {return flows.begin();} 
        auto endFlows( void ) const {return flows.end();} 

        Model(){}

        Model(string name="", double time=0.0):name(name), time(time){}

        virtual ~Model(){}

        void execute(double start=0.0, double final=0.0, double increment=1.0){
            
            vector<double> results;
            int count = 0;

            for (double k = start; k < final; k += increment){
                for (Flow* item : flows) {
                    double result = item->execute();
                    results.push_back(result);
                }

                count = 0;
                for (Flow* item : flows) {
                    System* origin = item->getSource();
                    origin->setValue(origin->getValue() - results[count]);

                    System* destiny = item->getTarget();
                    destiny->setValue(destiny->getValue() + results[count]);

                    count++;
                }

                for (auto i = beginFlows(); i != endFlows(); ++i){
                    results.pop_back();
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
            name = model.name;
            time = model.time;  
            systems = model.systems;
            flows = model.flows;
        }
  
        Model& operator=(const Model& model){
            if (this == &model){
                return *this;
            }
            name = model.name;
            time = model.time;  
            systems = model.systems;
            flows = model.flows;
            return *this;
        }
};

#endif
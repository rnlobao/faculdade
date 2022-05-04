#ifndef FLOW_H
#define FLOW_H

#include "./System.h"
#include <windef.h>
#include <string>
using namespace std;

/**
 * @brief 
 * 
 */

class Flow {
    protected:
        /**
         * @brief Name of the flow
         * 
         */
        string name;
        /**
         * @brief which system this flow is conected
         * 
         */
        System* source;
        /**
         * @brief which system this flow is connecting
         * 
         */
        System* target;

    public:
        friend class Model;
        /**
         * @brief Construct a new Flow object
         * 
         * @param name 
         * @param source 
         * @param target 
         */
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow() {}
        /**
         * @brief Later in the code the execute will be implemented depending on the flow context
         * 
         * @return double 
         */
        virtual double execute() = 0;

        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName() const{
            return name;
        }


        /**
         * @brief Set the Name object
         * 
         * @param nameFlow 
         */
        void setName(string nameFlow){
            name = nameFlow;
        } 
        /**
         * @brief Get the Target object
         * 
         * @return System* 
         */
        System* getTarget() const{
            return target;
        }
        /**
         * @brief Set the Target object
         * 
         * @param targetSys 
         */
        void setTarget(System* targetSys){
            target = targetSys;
        }
        /**
         * @brief Get the Source object
         * 
         * @return System* 
         */
        System* getSource() const{
            return source;
        }
        /**
         * @brief Set the Source object
         * 
         * @param sourceSys 
         */
        void setSource(System* sourceSys){
            source = sourceSys;
        }

    private:
        Flow (const Flow& flow){
            System* sourceCopy = new System(flow.getSource()->getName(), flow.getSource()->getValue());
            System* targetCopy = new System(flow.getTarget()->getName(), flow.getTarget()->getValue());
            
            name = flow.getName();           
            source = sourceCopy;
            target = targetCopy;
        }

        Flow& operator=(const Flow& flow){
            if (this == &flow){
                return *this;
            }

            if(getSource() != NULL){
                delete (getSource());
            }

            if(getTarget() != NULL){
                delete (getTarget());
            }

            System* sourceCopy = new System(flow.getSource()->getName(), flow.getSource()->getValue());
            System* targetCopy = new System(flow.getTarget()->getName(), flow.getTarget()->getValue());

            name = flow.getName();
            source = sourceCopy;
            target = targetCopy;
            return *this;
        }

};

#endif
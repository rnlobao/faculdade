#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
    protected:
        /**
         * @brief name of the system
         * 
         */
        string name;
        /**
         * @brief initial value of system
         * 
         */
        double value;

    public:
        /**
         * @brief declaring friend classes
         * 
         */
        friend class Flow;
        /**
         * @brief declaring friend classes
         * 
         */
        friend class Model;
        /**
         * @brief Construct a new System object
         * 
         * @param name 
         * @param value 
         */
        System(string name = "", double value = 0.0):name(name), value(value){}
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~System(){}
        /**
         * @brief Set the Name object
         * 
         * @param sysName 
         */
        void setName(string sysName){
            name = sysName;
        }
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */

        string getName() const {
            return name;
        }    
        /**
         * @brief Set the Value object
         * 
         * @param sysValue 
         */

        void setValue(double sysValue){
            value = sysValue;
        }
        /**
         * @brief Get the Value object
         * 
         * @return double 
         */

        double getValue() const{
            return value;
        }  

    private:
        /**
         * @brief Construct a new System object
         * 
         * @param s 
         */
        System (const System& s){
            name = s.getName();
            value = s.getValue();
        }
        /**
         * @brief overloading method =
         * 
         * @param s 
         * @return System& 
         */
        System& operator=(const System& s){
            if (this == &s){
                return *this;
            }

            name = s.getName();
            value = s.getValue();  

            return *this;
        }
};

#endif
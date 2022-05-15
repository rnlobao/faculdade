#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @brief My system class
 * 
 */
class System{

    protected:
        /**
         * @brief Name of the System
         * 
         */
        string name;
        /**
         * @brief Value of the System
         * 
         */
        double value; 

    public:
        /**
         * @brief Friend class Flow
         * 
         */
        friend class Flow;
        /**
         * @brief Friend class Model
         * 
         */
        friend class Model; 
        /**
         * @brief Construct a new System object
         * 
         * @param name Name of System
         * @param value Value of System
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
         * @param sysName The name for my system
         */
        void setName(string sysName);
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName();
        /**
         * @brief Set the Value object
         * 
         * @param sysValue The value for my system
         */
        void setValue(double sysValue);
        /**
         * @brief Get the Value object
         * 
         * @return double 
         */
        double getValue();
    private:
        /**
         * @brief Construct a new System object
         * 
         * @param sys System that will be copied
         */
        System (const System& sys);
        /**
         * @brief Overloading = operator
         * 
         * @param sys system that the = operator will be overloaded
         * @return System& 
         */
        System& operator=(const System& sys);
};

#endif
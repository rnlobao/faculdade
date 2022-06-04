#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/**
 * @brief System class
 * 
 */
class System{
    public:
        /**
         * @brief Destroy the System object
         * 
         */
        virtual ~System(){}
        /**
         * @brief Set the Name object
         * 
         * @param sysName name choosen
         */
        virtual void setName(string sysName) = 0;
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the Value object
         * 
         * @param sysValue value choosen
         */
        virtual void setValue(double sysValue) = 0;
        /**
         * @brief Get the Value object
         * 
         * @return double 
         */
        virtual double getValue() const = 0;
};

#endif
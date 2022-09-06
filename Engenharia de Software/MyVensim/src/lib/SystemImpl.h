#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h"

using namespace std;
/**
 * @brief System Impl
 * 
 */
class SystemImpl : public System{

    protected:
        /**
         * @brief name in systemImpl
         * 
         */
        string name; 
        /**
         * @brief Value in systemImpl
         * 
         */
        double value; 

    public:
       /**
        * @brief Construct a new System Impl object
        * 
        * @param name name in systemImpl
        * @param value value in systemImpl
        */
        SystemImpl(string name = "", double value = 0.0);
        /**
         * @brief Destroy the System Impl object
         * 
         */
        virtual ~SystemImpl();
        /**
         * @brief Set the Name object
         * 
         * @param sysName name in system
         */
        void setName(string sysName);
        /**
         * @brief Get the Name object
         * 
         * @return string 
         */
        string getName() const;
        /**
         * @brief Set the Value object
         * 
         * @param sysValue value in system
         */
        void setValue(double sysValue);
        /**
         * @brief Get the Value object
         * 
         * @return double 
         */
        double getValue() const; 
    private:
        /**
         * @brief Construct a new System Impl object
         * 
         * @param sys system to be copied
         */
        SystemImpl (const SystemImpl& sys);
        /**
         * @brief overload = method
         * 
         * @param sys system to overload method
         * @return SystemImpl& 
         */
        SystemImpl& operator=(const SystemImpl& sys);
};


#endif
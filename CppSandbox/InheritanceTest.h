/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Test.h
 * Author: Admin
 *
 * Created on September 4, 2016, 10:25 AM
 */

#ifndef TEST_H
#define TEST_H

#include <cstdio>
#include <iostream>

class A
{
    public:    
    A()
    {
        std::cout << "knob A"<< std::endl;
    }
    
    virtual ~A()
    {
        std::cout << "Destroying A"<< std::endl;
    }
    
    virtual void f()
    {
        std::cout << "in A!!!" << std::endl;
    }
};

class B : public A
{
    public:
    B()
    {
        std::cout << "knob B"<< std::endl;
    }
    virtual void f()
    {
        std::cout << "in B!!!" << std::endl;
    }
};

#endif /* TEST_H */


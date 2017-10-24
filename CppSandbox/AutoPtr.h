/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AutoPtr.h
 * Author: Admin
 *
 * Created on September 4, 2016, 12:43 PM
 */

#ifndef AUTOPTR_H
#define AUTOPTR_H

template <typename T>
class AutoPtr
{
    private:
        
        
    public:
        T* _data;
        AutoPtr(T* data)
        {
            _data = data;
        }
        
        ~AutoPtr()
        {
            delete _data;
        }
    
};

#endif /* AUTOPTR_H */


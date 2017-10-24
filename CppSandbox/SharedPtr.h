/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SharedPtr.h
 * Author: Admin
 *
 * Created on September 4, 2016, 12:58 PM
 */

#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>

using namespace std;

class RC
{
    private:
    int count; // Reference count

    public:
    void AddRef()
    {
        // Increment the reference count
        count++;
        cout << "Incrementing Ref Count:" << count << endl;
    }

    int Release()
    {
        // Decrement the reference count and
        // return the reference count.
        cout << "Decrementing Ref Count:" << count << endl;
        return --count;
    }
};

template <typename T>
class SharedPtr
{
    private:
        T* _data;
        RC* _refCount;
       
    public:
        //Default constructor
        SharedPtr() : _data(0), _refCount(0)
        {
            _refCount = new RC();
            _refCount->AddRef();
        }
        
        SharedPtr(T* obj): _data(obj), _refCount(0)
        {
            _refCount = new RC();
            _refCount->AddRef();
        }           
        
        //Copy constructor
        SharedPtr(const SharedPtr<T>& rhs): _data(rhs._data), _refCount(rhs._refCount)
        {
            _refCount->AddRef();
        }
                
        //Destructor    
        ~SharedPtr()
        {
            if(_refCount->Release() == 0)
            {
                cout << "RefCount == 0, destroying object" << endl;
                delete _data;
                delete _refCount;                
            }
        }
        
        //Dereference operator
        T* operator->()
        {
            return _data;
        }

        //Dereference operator
        T& operator*()
        {
            return *_data;
        }
        
        SharedPtr<T>& operator=(const SharedPtr<T>& sp)
        {
            if(this != sp)
            {
                //Old value - release reference and release data if required
                if(_refCount->Release()==0)
                {
                    delete _data;
                    delete _refCount;
                }
                _data = sp._data;
                _refCount = sp._refCount;
                _refCount->AddRef();
            }
            return *this;
        }
};




#endif /* SHAREDPTR_H */


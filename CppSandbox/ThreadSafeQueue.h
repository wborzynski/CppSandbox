/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadSafeQueue.h
 * Author: Admin
 *
 * Created on September 10, 2016, 11:05 AM
 */

#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

template <typename T>
class ThreadSafeQueue
{
    private:
        mutex _lock;
        condition_variable _cond;
        queue<T> _q;
        
    public:
        Send(T o)
        {
            std::lock_guard<mutex> lock(_lock);
            _q.push(o);
            _cond.notify_one();
        }
                        
        T Receive()
        {
            std::unique_lock<mutex> lock(_lock);
            
            //Spurious wakeup
            _cond.wait(lock, [this]{return !_q.empty();});
            auto ret = _q.front();
            _q.pop();
            return ret;
        }
};


#endif /* THREADSAFEQUEUE_H */


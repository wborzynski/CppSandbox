/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on September 3, 2016, 1:44 PM
 */

#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <map>
#include <list>
#include <thread>
#include <chrono>
#include <string.h>
#include <unordered_set>
#include "AutoPtr.h"
#include "SharedPtr.h"
#include "SimpleBinaryTree.h"
#include "ThreadSafeQueue.h"
using namespace std;

/*
 * 
 */
void TestAutoPtr();
void TestSharedPointer();
void TestBinaryTree();
double CalcSqRoot(double num);
double CalcStdDeviation(vector<int> data);
void TestStdDeviation();
void ReverseVector(vector<int> v);
void TestReverseVector();
void StringWordFreq();
void TestQuickSort();
void quickSort(vector<int>& input, int left, int right);
int partition(vector<int>& input, const int& left, const int& right);
int bitcount(int n);
void TestBitcount();
void PrimeSieve(int n);
void TestThreadSafeQueue();
void ReceiverThread(ThreadSafeQueue<string>& q);
void SenderThread(ThreadSafeQueue<string>& q, int threadId);
void TestFunkyLoopOutput();
void ReverseString(string& s);
void RemoveDuplicates(string& s);
bool is_letter(char c);

/*int main(int argc, char** argv) 
{   
    TestA();
    /*
    TestAutoPtr();
    TestSharedPointer();
    CalcSqRoot(16);
    TestBinaryTree();
    TestStdDeviation();
    TestReverseVector();
    //StringWordFreq();
    TestQuickSort();
    TestBitcount();
    PrimeSieve(10);
    PrimeSieve(100);
    PrimeSieve(1000);
    //PrimeSieve(1000000);
    PrimeSieve(7);

    //TestThreadSafeQueue();
    //TestFunkyLoopOutput();
    string s = "abcdefghijklmnopqrst";
    ReverseString(s);
    string s2 = "AAAAAAaaaaabbbcaaaa";
    RemoveDuplicates(s2);
    return 0;
}*/

double CalcSqRoot(double num)
{
    double lower_bound = 0.0;
    double upper_bound = num;
    
    double temp = 0;
    while(fabs(num - (temp * temp)) > numeric_limits<double>::epsilon())
    {
        temp = (lower_bound + upper_bound) / 2;
        if(temp*temp >= num)
            upper_bound = temp;
        else
            lower_bound = temp;
    }
    cout << "Square root of " << num << " is " << temp << endl;
    return temp;
}

void TestBinaryTree()
{
    SimpleBinaryTree myTree;
    Node* root = NULL;
    int t;
    int data;

    root = myTree.insert(root, 10);
    root = myTree.insert(root, 1);
    root = myTree.insert(root, 5);
    root = myTree.insert(root, 3);
    root = myTree.insert(root, 6);
    root = myTree.insert(root, 7);
    root = myTree.insert(root, 15);
    cout << "Tree Height:" << myTree.getHeight(root) << endl;
    
    cout << "BreadthFirstTraverse:" << endl;
    myTree.BreadthFirstTraverse(root);
    
    cout << "DFS PreOrder:" << endl;
    myTree.DepthFirstTraversePreOrder(root);
    
    cout << "DFS PostOrder:" << endl;
    myTree.DepthFirstTraversePostOrder(root);
    
    cout << "DFS In Order:" << endl;
    myTree.DepthFirstTraverseInOrder(root);    
}


void TestStdDeviation()
{
    vector<int> v = {1,5,11,16,21,26};
    cout << "std deviation:" << CalcStdDeviation(v) << endl;
}

double CalcStdDeviation(vector<int> data)
{
    double avg;
    double sum;
    for(auto d : data)
    {
        sum += d;
    }
    avg = sum / data.size();
    
    double sumDiffSquared;
    for(auto d: data)
    {
        sumDiffSquared += pow((d-avg),2);
    }
    
    double variance = sumDiffSquared/data.size();
    double stdDeviation = sqrt(variance);
}

void TestReverseVector()
{
    vector<int> v = {1,5,11,16,21,26};
    ReverseVector(v);
}

void ReverseVector(vector<int> v)
{
    cout << "Reversing vector:" << endl;
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    
    auto begin = v.begin();
    auto end = v.end();
    
    while(begin != end && begin !=--end)
    {
        iter_swap(begin, end);
        ++begin;
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
    
    cout << endl;
}

void TestQuickSort()
{
    vector<int> data = {5,1,20,3,8,7,6,30};
    cout << "unsorted:" << endl;
    for(auto a : data)
    {
        cout << a << " ";
    }
    cout << endl;
    
    quickSort(data, 0,8);
    cout <<endl << "sorted:" << endl;
    for(auto a : data)
    {
        cout << a << " ";
    }
}

void quickSort(vector<int>& input, int left, int right)
{
    for(auto a : input)
    {
        cout << a << " ";
    }
    cout << endl << "left:" << left << "right: " << right << endl;
    
    if(left>=right)
    {
        return;
    }
    
    int part = partition(input, left, right);
    
    quickSort(input, left, part-1);    
    quickSort(input, part+1, right);
}

int partition(vector<int>& input, const int& left, const int& right)
{
    const int mid = left + (right - left) /2;
    const int pivot = input[mid];
    
    std::swap(input[mid], input[left]);
    int i= left + 1;
    int j = right;
    
    while(i <= j)
    {
        while(i <=j && input[i] <= pivot)
        {
            i++;
        }
        while(i <= j && input[j] > pivot)
        {
            j--;
        }
        
        if(i<j)
        {
            std::swap(input[i], input[j]);
        }
    }
    std::swap(input[i-1], input[left]);
    return i-1;
}

void TestBitcount()
{
    int count1 = bitcount(5);
    int count2 = bitcount(12);
    int count3 = bitcount(64);
    
    cout << endl << "bitcount(5) = " << count1 << endl;
    cout << endl << "bitcount(12) = " << count2 << endl;
    cout << endl << "bitcount(64) = " << count3 << endl;
}

int bitcount(int n)
{
    cout << endl << "Binary representation of " << n << " is:";
    int count = 0;
    list<int>l;
    while(n > 0)
    {
        int rem = n%2;
        n = n / 2;
        l.push_front(rem);        
    }
    
    for(int i : l)
    {
        cout << i;
        if(i==1)
            count++;
        
    }
    cout << endl;
    
    return count;
}


void PrimeSieve(int n)
{
    vector<bool>isPrime(n, true);
    
    for(int factor = 2; factor * factor <= n; factor++)
    {
        if(isPrime[factor])
        {
            for(int j = factor; factor*j <= n; j++)
                isPrime[factor*j] = false;
        }
    }
    cout << "Prime Numbers up to: " << n << endl;
    for(int i = 0; i<n; i++)
    {
        if(isPrime[i] == true)
            cout << i << ",";
    }
}

void TestThreadSafeQueue()
{
    cout << "Testing multithreaded queue with 3 senders and 1 receiver" << endl;
    ThreadSafeQueue<string> q;
    thread t1([&]{ReceiverThread(q);});   
    
    //this_thread::sleep_for(5);
    thread t2([&]{SenderThread(q, 1);});
    thread t3([&]{SenderThread(q, 555);});
    thread t4([&]{SenderThread(q,666);});
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    cout << "Multithreaded queue test complete" << endl;
}


void SenderThread(ThreadSafeQueue<string>& q, int threadId)
{
    int msgCount = 0;
    while(msgCount < 50)
    {
        string msg = threadId + "Says:" + msgCount;
        q.Send(msg);
        msgCount ++ ;
    }
}
void ReceiverThread(ThreadSafeQueue<string>& q)
{
    int msgCount = 0;
    while(msgCount < 150)
    {
        string msg = q.Receive();
        std::cout << "Message Received:" << msg << endl;
    }
}

void ReverseString(string& s)
{
    cout << endl << s << endl;
    auto i1 = s.begin();
    auto i2 = s.end();
    
    while(i1 < i2 && i1 != --i2)
    {
        iter_swap(i1, i2);
        i1++;
    }    
    cout << endl << s << endl;
}

void RemoveDuplicates(string& s)
{
  unordered_set<char> log;
  cout << "Before: " << s << endl;
  s.erase(std::remove_if(s.begin(), s.end(), 
          [&] (char const c) { return !(log.insert(c).second); }), s.end());
  std::cout << "After:  " << s << std::endl;
}

size_t num_words(const std::string &sentence)
{
    bool previous_char_was_letter=false;
    size_t n=0;

    for (char c:sentence)
    {
        bool this_char_is_letter=is_letter(c);

        if (!previous_char_was_letter && this_char_is_letter)
             ++n;

        previous_char_was_letter=this_char_is_letter;
    }

    return n;
}

bool is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
         ? true:false;
}


/*Write a Fibonacci function and discuss recursive functions*/
int fib(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fib(x-1)+fib(x-2);
}

int myAtoi(char *str)
{
    int res = 0; // Initialize result
    //The char datatype (and literal chars like '0') are integral numbers. In this case, '0' is equivalent to 48. Subtracting this offset will give you the digit in numerical form.
    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    // return result.
    return res;
}


template< typename ContainerT, typename PredicateT >
  void erase_if( ContainerT& items, const PredicateT& predicate ) {
    for( auto it = items.begin(); it != items.end(); ) {
      if( predicate(*it) ) it = items.erase(it);
      else ++it;
    }
  };
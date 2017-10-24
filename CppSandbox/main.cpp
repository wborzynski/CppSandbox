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
#include "InheritanceTest.h"
#include "AutoPtr.h"
#include "SharedPtr.h"
#include "SimpleBinaryTree.h"
#include "ThreadSafeQueue.h"
using namespace std;

/*
 * 
 */
class A;
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
void TestA();
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

void TestA()
{
    A a;
    B b;
    A c;
    
    c = b;
    a.f();
    b.f();
    c.f();
    
    cout << "TESTING VECTOR" << endl;
    cout << "Constructor"<< endl;
    vector<A> v(10,a);
    cout << "Reserve"<< endl;
    v.reserve(10);
    cout << "Push Back"<< endl;
    v.push_back(a);
    cout << "Push Resize"<< endl;
    v.resize(100);
}

void TestAutoPtr()
{
    A* data = new A();
    auto a = AutoPtr<A>(data);
    //cout << "data address:" << a._data << endl;
    //cout << "data:" << *(a._data) << endl;
}

void TestSharedPointer()
{
    A* data = new A();
    auto ptr1 = SharedPtr<A>(data);
    auto ptr2 = ptr1;
    
    if(true)
    {
        auto ptr3 = ptr2;
    }
}

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

/*void StringWordFreq()
{
    map<char*,int> m;
//    char* s = "On a first call, the function expects a C string as argument for str, whose first character is used as the starting location to scan for tokens. In subsequent calls, the function expects a null pointer and uses the position right after the end of the last token as the new starting location for scanning.";
    
    char* t = strtok(s, " ,.-");
    
    while(t!=NULL)
    {
        auto it = m.find(t);
        if(it == m.end())
            m.insert(make_pair(t, 1));
        
            it->second++;
    }
    
    for(auto pair : m)
    {
        cout << pair.first << " Occurrences:" << pair.second;
    }

}*/

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

void TestFunkyLoopOutput()
{
    cout << endl << "Funky Loop:" << endl;
    int i = 1/2;
    // i=0 
    cout <<"i=" << i << endl;
    
    int j=0;
    if(j==0 || j++ == 1)
    {
        // j=0
        cout << "j=" << j << endl;
    }
    
    int k = 0;
    while(k!=3)// && k < 100)
    {
        k+=2;        
    }
    cout << k;    
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


/*
 ü  Write a function that removes duplicates from a string (with changing requirements, algorithm explanation, syntax questions
 * 
 * 
 */

void RemoveDuplicates(string& s)
{
  unordered_set<char> log;
  cout << "Before: " << s << endl;
  s.erase(std::remove_if(s.begin(), s.end(), 
          [&] (char const c) { return !(log.insert(c).second); }), s.end());
  std::cout << "After:  " << s << std::endl;
}




 /*  
ü  Assume the variable "i" is never referenced in the code of the function, except where it's declared and where it's printed to cout. What do you think could happen so that the variable changed its value?
ü  How would you fix the problem?
  * 
  * Buffer overflow? Casts? Array referencing elsewhere?
  *
  * 
What I would do is set a breakpoint to trip when n=933 and k=1533, then ste through the code and watch cent[255] to see where it changes.

Some debuggers also allow you to set breakpoints that trip when certain variables have changed -- so you could set a breakpoint on cent[255] to find exactly where the offending line is.
  * /

/*
ü  Given a piece of code, what problems do you see with the code?
ü  Implement a smart_ptr class that counts references
  
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

  */





/*
ü  Allocation and life of variables defined in different scopes (global, in method, in function, etc) and using different methods (new(), object instance, statics, pointers, static pointers, etc).
static variable (class)
lifetime = program runtime (1)
visibility = determined by access modifiers (private/protected/public)
static variable (global scope)
lifetime = program runtime (1)
visibility = the compilation unit it is instantiated in (2)
heap variable
lifetime = defined by you (new to delete)
visibility = defined by you (whatever you assign the pointer to)
stack variable
visibility = from declaration until scope is exited
lifetime = from declaration until declaring scope is exited
 
 */







/*ü  Counting the words in sentences with variations (count words with punctuation marks/without them)
std::cout << "number of words: "
          << std::distance(std::istream_iterator<std::string>(
                               std::istringstream(str) >> std::ws),
                           std::istream_iterator<std::string>()) << '\n';
Just for a bit of explanation:

Reading a std::string reads a word after skiping leading whitespace where a word is a sequence of non-whitespace characters.
std::istream_iterator<T> turns an input stream into a sequence of T objects by reading corresponding objects until reading fails.
std::istringstream takes a std::string and turns it into a stream being read from.
The constructor argument to std::istream_iterator<T> is std::istream&, i.e., the temporary std::istringstream can't be used directly but a reference needs to be obtained. This is the only interesting effect of std::ws which also skips leading whitespace.
std::distance() determines how many elements are in a sequence (the originally used std::count() determines how many elements in the sequence match a given condition but hte condition was actually missing).
  
 * 
 * void replace() {
  std::string s = "example string";
  std::replace( s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
}
 */
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


/*
ü  Basic C types such as pointers, chars, array and arithmetic with all of the above.*/

/*
ü  Function returning a pointer to an array on the stack
 int * getArray() {
    int myArray[3] = {4, 65, 23};
    return myArray;
}
myArray is a local variable and as thus the pointer is only valid until the end of its scope (which is in this case the containing function getArray) is left. If you access it later you get undefined behavior.

In practice what happens is that the call to printf overwrites the part of the stack used by myArray and it then contains some other data.

To fix your code you need to either declare the array in a scope that lives long enough(the main function in your example) or allocate it on the heap. If you allocate it on the heap you need to free it either manually, or in C++ using RAII.

One alternative I missed(probably even the best one here) is to wrap your array into a struct and thus make it a value type. Then returning it creates a copy which survives the function return. See tp1's answer for details on this.
 
 */

/*
ü  Various C and C++ constructs, template specialization. 
 To declare a partially specialized template that handles any pointer types, we'd add this class declaration:
template <typename T>
class sortedVector<T *>
{
 
 */

/*
ü  How to design a system that deals with very high execution flows
 * 
 * Multithreaded
 * Sync between worker threads
 *  
 */


/*
ü  III. How can you handle segmentation faults.
 
 * Windows:
 * Windows error reporting
 * Core dump
 * 
 * LINUX:
 * 
 * GDB
 * Core dump
 * 
 #include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
}
int main()
{
    struct sigaction act;
    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
} 
 
 */







/*
ü  V. write a c function which converts a string to integer
 * 
 * The standard requires that the digits are consecutive in the character set. That means you can use:

 str[i] - '0'
To translate the character's value into its equivalent numerical value.

The res * 10 part is to shuffle left the digits in the running total to make room for the new digit you're inserting.

For example, if you were to pass "123" to this function, res would be 1 after the first loop iteration, then 12, and finally 123.
 * 
 * 
 * 
 */
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




/*
ü  VI. how you can remove students from a map container, remove those whose grades are below a threshold. complexity discussion.


for(; iter != endIter; ) {
            if (Some Condition) {
                    aMap.erase(iter++);
            } else {
                    ++iter;
            }
}
*/

template< typename ContainerT, typename PredicateT >
  void erase_if( ContainerT& items, const PredicateT& predicate ) {
    for( auto it = items.begin(); it != items.end(); ) {
      if( predicate(*it) ) it = items.erase(it);
      else ++it;
    }
  };

/*  VII. templates: using them as a compilation time, parameter checking fence.
 * 
 *  is_same
 * If T and U name the same type with the same const-volatile qualifications, provides the member constant value equal to true. Otherwise value is false.
 *  */
  
  
  /*
ü  Given some function that gets current date and time and copies it to character array, which is allocated at the beginning of function. The wrong thing was that the array allocated inside the function scope and it will be destroyed at the end, but the function returns the address of that array. 
ü  

   * Goes out of scope, gets destroyed, undefined behaviour   
   */
  
  
  
  
  /*Character arrays and pointer arithmetic. Given array of characters and different expressions to access specific element in array. Need to answer what is result type and value.*/
  
  
  
  /*Given class A, and class B which is derived from A. Both of them contains function foo. Then created objects of class A and B and called functions using pointers either the same type or parent type. The question was which function will be called for each case.
   * 
class Animal
{
public:
virtual void eat() { std::cout << "I'm eating generic food."; }
}
class Cat : public Animal
{
public:
void eat() { std::cout << "I'm eating a rat."; }
}
Main:

func(animal); // outputs: "I'm eating generic food."
func(cat);    // outputs: "I'm eating a rat."   * 
   * 
   * 
   * 
   * 
   * 
   * 
   *   
   * 
   * 
   * 
375
down vote
Without "virtual" you get "early binding". Which implementation of the method is used gets decided at compile time based on the type of the pointer that you call through.

With "virtual" you get "late binding". Which implementation of the method is used gets decided at run time based on the type of the pointed-to object - what it was originally constructed as. This is not necessarily what you'd think based on the type of the pointer that points to that object.

class Base
{
  public:
            void Method1 ()  {  std::cout << "Base::Method1" << std::endl;  }
    virtual void Method2 ()  {  std::cout << "Base::Method2" << std::endl;  }
};

class Derived : public Base
{
  public:
    void Method1 ()  {  std::cout << "Derived::Method1" << std::endl;  }
    void Method2 ()  {  std::cout << "Derived::Method2" << std::endl;  }
};

Base* obj = new Derived ();
  //  Note - constructed as Derived, but pointer stored as Base*

obj->Method1 ();  //  Prints "Base::Method1"
obj->Method2 ();  //  Prints "Derived::Method2"
   */
  
 /*Algorithm to reverse strings*/

  void ReverseString2(string& s)
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

  
  
  /*
ü  Non-virtual/virtual function calls
ü  Splitting linked-list algo
   * 
   * list::splice
   * 
   * mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

element range (3)	
void splice (iterator position, list& x, iterator first, iterator last);
   * insert at begin
   * 
   * Iterate through linked list until you're at last node you want before split.
Store this address in temporary variable, end.
Create new LinkedList instance.
Set head of new linked list to end.next. //Starts new linked list
Set end.next to null. //Cuts off old linked at end.
  */




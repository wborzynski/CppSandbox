 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InterviewPrep.cpp
 * Author: W
 * 
 * Created on October 3, 2017, 10:23 PM
 */

#include "InterviewPrep.h"
#include <iostream>
#include <unordered_map>

InterviewPrep::InterviewPrep() {
}

InterviewPrep::InterviewPrep(const InterviewPrep& orig) {
}

InterviewPrep::~InterviewPrep() {
}


int main(int argc, char** argv) 
{   
    InterviewPrep test;
    test.TestNumberOperations();
    test.TestLinkedList();
    test.TestBinaryTree();
    test.TestStringOperations();
}

void InterviewPrep::TestLinkedList()
{
    LinkedList list;
    list.insert(0);
    list.insert(1);
    list.insert(5);
    list.insert(5);
    list.insert(155);
    
    LinkedListNode* n=list.head;
    while(n!=NULL)
    {
        std::cout << "LinkedListNode:" << n->val << std::endl;
        n = n->next;
    }
}

void InterviewPrep::TestNumberOperations()
{
    PrimeFactors(197);
    PrimeFactors(25);    
    PrimeFactors(80);
    PrimeFactors(75);
    PrimeFactors(16);
    PrimeFactors(82);
    PrimeFactors(315);
    
    std::vector<int> v = {10, 3, 12, -1, 13, 4, 16, -5, 20, 4};
    int biggestSum = longestSum(v);
    
    
    v = {-1, -22, -11, -1, -2};
    biggestSum = longestSum(v);
}
    
void InterviewPrep::TestStringOperations()
{
    int h1 = hashCode("boat");
    int h2 = hashCode("taob");
    int h3 = hashCode("bota");
    int h4 = hashCode("dicks");
    
    
    std::cout << "String operations:" << std::endl;;
    
    std::string text = "I am so fucking pissed off right now";
    std::string pattern = "maybe";
    
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    pattern = "fucking";
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    pattern = "now";
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    pattern = "w";
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    pattern = "fuckit";
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    pattern = "I";
    std::cout << "IsSubstring:" << text << " , " << pattern << " : " << isSubstring(pattern, text) << std::endl;
    
    std::cout << "isPalindrome: racecar:" << isPalindrome("racecar") << std::endl;
    std::cout << "isPalindrome: madam:" << isPalindrome("madam") << std::endl;
    std::cout << "isPalindrome: turd:" << isPalindrome("turd") << std::endl;
    std::cout << "isPalindrome: turd:" << isPalindrome("tutu") << std::endl;
    std::cout << "isPalindrome: turd:" << isPalindrome("Appa") << std::endl;
    
    std::cout << "isAnagram: sudden, neddus : " << isAnagram("sudden", "neddus") << std::endl ;
    std::cout << "isAnagram: dare, read : " << isAnagram("dare", "read") << std::endl ;
    std::cout << "isAnagram: fate, read : " << isAnagram("fate", "read") << std::endl ;

    std::cout << "isAnagramWithSet: sudden, neddus : " << isAnagramWithSet("sudden", "neddus") << std::endl ;
    std::cout << "isAnagramWithSet: dare, read : " << isAnagramWithSet("dare", "read") << std::endl ;
    std::cout << "isAnagramWithSet: fate, read : " << isAnagramWithSet("fate", "read") << std::endl ;

}

void InterviewPrep::TestBinaryTree()
{
    std::cout << "Binary tree operations" << std::endl;
    BinaryTree myTree;
    BinaryTreeNode* root = NULL;
    root = myTree.insert(root, 7);

    std::vector<int> v = {10, 3, 12, 1, 13, 14, 16, 5, 20, 4};
    
    for(auto const& num : v)
    {
        std::cout << "Inserting: " << num << std::endl;
        myTree.insert(root,num);
    }
    
    std::cout << "Tree Height: " << myTree.getHeight(root) << std::endl;
        
    std::cout << "Breadth first traverse: "<< std::endl;
    myTree.BreadthFirstTraverse(root);
    
    std::cout << "Depth first traverse - pre-order: "<< std::endl;
    myTree.DepthFirstTraversePreOrder(root);
    
    std::cout << "Depth first traverse - in-order: "<< std::endl;
    myTree.DepthFirstTraverseInOrder(root);
    
    std::cout << "Depth first traverse - post-order: "<< std::endl;
    myTree.DepthFirstTraversePostOrder(root);
}


int InterviewPrep::numMultiples(int n)
{
    int m3 = 0, m5 = 0, runningSum = 0;
    bool m3Done = false, m5Done = false;
    
    while(!m3Done || !m5Done)
    {
        m3 += 3;
        if(m3 >= n)
        {    
            m3Done = true;
        }
        else
        {
            if(m3%5 != 0)
            runningSum += m3;
        }
        
        m5 += 5;
        if(m5 >= n)
        {
            m5Done = true;
        }
        else
        {
            runningSum += m5;
        }
    }
    return runningSum;    
}

void InterviewPrep::FibonacciSequence(int max)
{
    int n= 0, m = 0, curr = 0, sumEvens = 0;
    
    while(curr < max)
    {
        if(n == 0)
        {
            m = 1;
        }
        curr = n + m;
        if(curr%2 == 0)
            sumEvens +=curr;
        
        n = m;
        m = curr;
    }
    std::cout << std::endl << sumEvens << std::endl;
}

long int InterviewPrep::largestPrimeFactor(long int n)
{
    std::vector<long int> allPrimes, primeFactors;
    PrimeSieve(n, allPrimes);
    
    for(long int p : allPrimes)
    {
        if(n%p == 0)
        {
            primeFactors.push_back(p);
        }
    }
    
    long int largestPrimeFactor = 0;
    for(long int pf : primeFactors)
    {
        if(pf > largestPrimeFactor)
            largestPrimeFactor = pf;
    }
    
    return largestPrimeFactor;
}

void InterviewPrep::PrimeSieve(long int n, std::vector<long int>& v)
{
    int size = sqrt(n);
    std::unordered_map<int, bool>isPrime;
    
    std::cout << "Creating map" << std::endl;
    for(int i=0; i < n; i++)
    {
        isPrime.insert(std::make_pair(i,false));
        if(i%10000 == 0)
            std::cout << i << std::endl;
    }
    
    
    std::cout << "Sieve" << std::endl;
    for(long int factor = 2; factor * factor <= size; factor++)
    {
        if(isPrime[factor])
        {
            for(long int j = factor; factor*j <= size; j++)
                isPrime[factor*j] = false;
        }
         if(factor%10000 == 0)
            std::cout << factor << std::endl;
    }
    
    
    std::cout << "Gathering Results" << std::endl;
    for(int i = 0; i<size; i++)
    {
        if(isPrime[i] == true)
            v.push_back(i);
         if(i%10000 == 0)
             std::cout << i << std::endl;
    }
}




/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GsInterviewPrep.h
 * Author: W
 *
 * Created on October 3, 2017, 10:23 PM
 */

#ifndef GSINTERVIEWPREP_H
#define GSINTERVIEWPREP_H

#include <cstddef>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <math.h>
#include "limits.h"

class GsInterviewPrep {
public:
    GsInterviewPrep();
    GsInterviewPrep(const GsInterviewPrep& orig);
    virtual ~GsInterviewPrep();
    
    //Binary tree ops
    //Traverse
    //Flatten
    void TestBinaryTree();
    
    
    void TestLinkedList();
    
    //String ops
    void TestStringOperations();
    
    void TestNumberOperations();
    
    static bool isSubstring(const std::string& pattern, const std::string& text)
    {
        int pos=0;
        while(pos < text.length())
        {
            if(text.at(pos) == pattern.at(0))
            {
                //int patternPos = 1;
                //int foundPos = pos + 1;
                bool found = true;
                for(int patternPos = 1, foundPos = pos+1 ;patternPos < pattern.length() && foundPos < text.length();patternPos++,foundPos++)
                {
                    if(text.at(foundPos) != pattern.at(patternPos))
                    {
                        found = false;
                        break;
                    }                        
                }
                if(found)
                    return true;
            }            
            pos ++;
        }
        return false;
    }
    
    bool isPalindrome(const std::string& str)
    {
        const char* cstr = str.c_str();
        bool isPalindrome = true;
        
        int front=0, back = str.length()-1;
        
        while(front < back)
        {
            if(cstr[front] == cstr[back])
            {
                front ++;
                back --;
            }
            else
            {
                isPalindrome = false;
                break;
            }
        }
        return isPalindrome;
    }
       
    bool isAnagram(std::string s1, std::string s2)
    {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    
    bool isAnagramWithSet(std::string s1, std::string s2)
    {
        for(auto it = s1.begin(); it < s1.end(); it++)
        {
            auto index = s2.find_first_of(*it);
            if(index != std::string::npos)
            {
                s2.erase(index);
            }
        }
        return s2.empty();
    }
        
    //Hash of string/number
    long hashCode(const std::string& s)
    {
        long hash = 0;
        if(hash == 0 && s.length() > 0)
        {
            for(auto it = s.begin(); it < s.end(); it++)
            {
                hash = 31 * hash + (int)*it;
            }
        }
        return hash;
    }
    
    
    //LongestRunningSum
    int longestSum(std::vector<int>& data)
    {
        int biggestSum = INT_MIN;
        int currentBiggestSum = 0;
        
        for(int& n : data)
        {
            currentBiggestSum += n;
            
            if(currentBiggestSum > biggestSum)
            {
                biggestSum = currentBiggestSum;
            }
            
            if(n < 0)
                currentBiggestSum = 0;  
        }
        return biggestSum;
    }
    
    int Factorial(int n)
    {
        if(n <= 0)
            return 1;
        else
        {
            return n * Factorial(n-1);
        }
    }
    
    int Fibonacci(int n)
    {
        if(n <2)
            return n;
        else
        {
            return Fibonacci(n-1) + Fibonacci(n-2);
        }
    }
    
    void PrimeFactors(int n)
    {
        std::cout << "Prime Factors for " << n << ":" << std::endl;
        // Print the number of 2s that divide n
        while (n%2 == 0)
        {
            n = n/2;
        }

        // n must be odd at this point.  So we can skip 
        // one element (Note i = i +2)
        for (int i = 3; i <= std::sqrt(n); i = i+2)
        {
            // While i divides n, print i and divide n
            while (n%i == 0)
            {
                std::cout << i << std::endl;
                n = n/i;
            }
        }

        // This condition is to handle the case when n 
        // is a prime number greater than 2
        if (n > 2)
            std::cout << n << std::endl;
        
        std::cout << std::endl;
    }
    
    //Data Structures
    //LinkedList
    
    //Double linked list
    
    
    //Vector
    
    
    //Map
    
    
    //Set
    
    
private:

};

class BinaryTreeNode
{
    public:
        int val;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        
        BinaryTreeNode(int n)
        {
            val = n;
            left = NULL;
            right = NULL;                    
        }
};

class BinaryTree
{
    public:
        BinaryTreeNode* insert(BinaryTreeNode* root, int n)
        {
            if(root == NULL)
            {
                return new BinaryTreeNode(n);
            }
            else
            {
                if(n <= root->val)
                {
                    root->left = insert(root->left, n);
                }
                else
                {
                    root->right = insert(root->right, n);
                }
                return root;
            }
        }
        
        int getHeight(BinaryTreeNode* root)
        {
            if(root == NULL)
            {
                return -1;
            }
            else
            {
                int leftSubtreeHeight = getHeight(root->left);
                int rightSubTreeHeight = getHeight(root->right);
                
                return 1 + std::max(leftSubtreeHeight, rightSubTreeHeight);
            }
        }
        
        void BreadthFirstTraverse(BinaryTreeNode* root)
        {
            std::queue<BinaryTreeNode*> q;
            if(root != NULL)
            {
                q.push(root);
            }
            while(q.size() != 0)
            {
                BinaryTreeNode* n = q.front();
                std::cout << n->val << std::endl;
                q.pop();
                
                if(n->left != NULL)
                    q.push(n->left);

                if(n->right != NULL)
                    q.push(n->right);
            }
        }
        
        void DepthFirstTraversePreOrder(BinaryTreeNode* root)
        {
            if(root == NULL)
                return;
            else
            {
                std::cout << root->val << std::endl;
                DepthFirstTraversePreOrder(root->left);
                DepthFirstTraversePreOrder(root->right);
            }
        }
        
        
        void DepthFirstTraverseInOrder(BinaryTreeNode* root)
        {
            if(root == NULL)
                return;
            else
            {
                DepthFirstTraversePreOrder(root->left);
                std::cout << root->val << std::endl;
                DepthFirstTraversePreOrder(root->right);
            }
        }
        
        void DepthFirstTraversePostOrder(BinaryTreeNode* root)
        {
            if(root == NULL)
                return;
            else
            {
                DepthFirstTraversePreOrder(root->left);
                DepthFirstTraversePreOrder(root->right);
                std::cout << root->val << std::endl;
            }
        }
    
};

class LinkedListNode
    {
    public:
        LinkedListNode* next;
        int val;

        LinkedListNode(int val)
        {
            this->val = val;
        }
};

class LinkedList
{
    public:
        LinkedListNode* head;
        LinkedListNode* tail;

        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }
        void insert(int val)
        {
            if(head==NULL)
            {
                head = new LinkedListNode(val);
                tail = head;
            }
            else
            {
                tail->next = new LinkedListNode(val);
                tail = tail->next;
            }
        }
    
};

#endif /* GSINTERVIEWPREP_H */


 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GsInterviewPrep.cpp
 * Author: W
 * 
 * Created on October 3, 2017, 10:23 PM
 */

#include "GsInterviewPrep.h"
#include <iostream>


GsInterviewPrep::GsInterviewPrep() {
}

GsInterviewPrep::GsInterviewPrep(const GsInterviewPrep& orig) {
}

GsInterviewPrep::~GsInterviewPrep() {
}


int main(int argc, char** argv) 
{   
    GsInterviewPrep test;
    test.TestNumberOperations();
    test.TestLinkedList();
    test.TestBinaryTree();
    test.TestStringOperations();
}

void GsInterviewPrep::TestLinkedList()
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

void GsInterviewPrep::TestNumberOperations()
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
    
void GsInterviewPrep::TestStringOperations()
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

void GsInterviewPrep::TestBinaryTree()
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




/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleBinaryTree.h
 * Author: Admin
 *
 * Created on September 4, 2016, 6:00 PM
 */

#ifndef SIMPLEBINARYTREE_H
#define SIMPLEBINARYTREE_H

#include <iostream>
#include <cstddef>
#include <queue>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class SimpleBinaryTree{
    public:
        Node* insert(Node* root, int data) 
        {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        
        int getHeight(Node* root)
        {
            if(root == NULL)
            {
                return -1;
            }
            else
            {
                int lHeight = getHeight(root->left);
                int rHeight = getHeight(root->right);
                
                return 1+ (max(lHeight, rHeight));
            }
        }
        
        void BreadthFirstTraverse(Node* root)
        {
           queue<Node*> q;
           if(root != NULL)
           {
               q.push(root);
           }
           while(!q.size() == 0)
           {
               Node* n = q.front();
               cout << n->data << endl;
               q.pop();
               
               if(n->left != NULL)
                   q.push(n->left);
               
               if(n->right!= NULL)
                   q.push(n->right);
           }
        }
        
        void DepthFirstTraversePreOrder(Node* root)
        {
            if(root == NULL)
               return;
            else
            {
                cout << root->data << endl;
                DepthFirstTraversePreOrder(root->left);
                DepthFirstTraversePreOrder(root->right);                        
            }              
        }
        
        void DepthFirstTraversePostOrder(Node* root)
        {
            if(root == NULL)
               return;
            else
            {
                DepthFirstTraversePreOrder(root->left);
                DepthFirstTraversePreOrder(root->right);  
                cout << root->data << endl;                      
            }              
        }
        void DepthFirstTraverseInOrder(Node* root)
        {
            if(root == NULL)
               return;
            else
            {
                DepthFirstTraversePreOrder(root->left); 
                cout << root->data << endl;                 
                DepthFirstTraversePreOrder(root->right);      
            }              
        }
        
};


#endif /* SIMPLEBINARYTREE_H */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int diameter_tree(Node* root, int& diameter){
    if(root==NULL) return 0;
    int lh = diameter_tree(root->left, diameter);
    int rh = diameter_tree(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1+max(lh, rh);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(10);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int diameter = 0;
    cout<<diameter_tree(root, diameter);
    return 0;
}
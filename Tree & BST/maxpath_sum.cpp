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

int maxPathSum(Node* root, int& maxSum){
    if(root==NULL) return 0;
    int left = max(0, maxPathSum(root->left, maxSum));
    int right = max(0, maxPathSum(root->right, maxSum));
    maxSum = max(maxSum, left+right+root->data);
    return max(left, right)+root->data;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int maxSum = 0;
    cout<<maxPathSum(root, maxSum)<<endl;
    
    return 0;
}
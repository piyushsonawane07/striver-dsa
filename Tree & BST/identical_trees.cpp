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

bool checkIdentical(Node* p, Node* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    if(p->data != q->data) return false;
    return checkIdentical(p->left, q->left) && checkIdentical(p->right, q->right);
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    

    cout<<checkIdentical(root, root1)<<endl;
    
    return 0;
}
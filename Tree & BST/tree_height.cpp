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

int heightIterative(Node* root){
    
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* n = q.front();
            q.pop();
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
        height+=1;
    }
    return height;
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
    cout<<heightIterative(root)<<endl;
    return 0;
}
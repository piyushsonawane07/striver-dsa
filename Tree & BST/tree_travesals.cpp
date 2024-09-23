#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void levelOrder(Node* root) {

    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* n = q.front();
            q.pop();
            cout<<n->data<<" ";
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
    }
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left =  new Node(4);
    root->left->right = new Node(5);
    root->right->left =  new Node(6);
    root->right->right = new Node(7);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelOrder(root);

    return 0;
}
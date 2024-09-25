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

bool isLeaf(Node* root){
    return root->left==NULL && root->right==NULL;
}

void addLeftBoundary(Node* root, vector<int>& res) {
    
    Node* curr = root->left;
    
    while (curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addRightBoundary(Node* root, vector<int>& res) {
    
    Node* curr = root->right;
    vector<int> temp;
    while (curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
       
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        
        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
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

    vector<int> res;

    if (!isLeaf(root)) {
        res.push_back(root->data);
    }
    
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    for(auto ele: res){
        cout<<ele<<" ";
    }

    return 0;
}
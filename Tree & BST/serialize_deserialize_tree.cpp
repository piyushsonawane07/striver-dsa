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


string serialize_tree(Node* root) {
    
    if(root==NULL) return "";
    
    string ans="";
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        Node* n = q.front();
        q.pop();
        if(n==NULL) ans+="#,";
        else ans+=to_string(n->data)+",";

        if(n!=NULL){
            q.push(n->left);
            q.push(n->right);
        }
       
    }

    return ans;
}

Node* deserialize_tree(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        Node* n = q.front();
        q.pop();

        getline(s, str, ',');
        if(str=="#") n->left=NULL;
        else{
            Node* left = new Node(stoi(str));
            n->left = left;
            q.push(left);
        }


        getline(s, str, ',');
        if(str=="#") n->right=NULL;
        else{
            Node* right = new Node(stoi(str));
            n->right = right;
            q.push(right);
        }
    }
    return root;
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
    cout<<serialize_tree(root)<<endl;
    cout<<"Root -> "<<deserialize_tree(serialize_tree(root))->data<<endl;
    return 0;
}
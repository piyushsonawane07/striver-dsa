#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
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

void iterativeInorder(Node* root){
    stack<Node*> st;
    
    Node* n = root;
    while(true){
        if(n!=NULL){
            st.push(n);
            n = n->left;
        }else {
            if(st.empty() == true) break;
            n = st.top();
            st.pop();
            cout<<n->data<<" ";
            n = n->right;
        }
    }

}

void iterativePreorder(Node *root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        cout << node->data << " ";
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
}

//using two stacks
void iterativePostOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);

    if (root == NULL)
        return;

    while (!s1.empty())
    {
        Node *n = s1.top();
        s1.pop();
        s2.push(n);
        if (n->left != NULL)
            s1.push(n->left);
        if (n->right != NULL)
            s1.push(n->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data<<" ";
        s2.pop();
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
    iterativePreorder(root);
    cout << endl;
    iterativePostOrder(root);
    cout << endl;
    iterativeInorder(root);
    return 0;
}
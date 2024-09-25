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

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    bool ltr = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node *n = q.front();
            q.pop();
            int index = ltr ? i : (size - i - 1);
            row[index] = n->data;
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
        }
        ltr = !ltr;
        res.push_back(row);
    }
    return res;
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
    vector<vector<int>> ans = zigZagTraversal(root);

    for(auto row: ans){
        for(auto ele: row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
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

vector<vector<int>> verticalTraversal(Node *root)
{

    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int x = it.second.first, y = it.second.second;
        nodes[x][y].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto i : nodes)
    {
        vector<int> col;
        for (auto j : i.second)
        {
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }
    return ans;
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

    vector<vector<int>> ans = verticalTraversal(root);
    for(auto row: ans){
        for(auto ele: row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}
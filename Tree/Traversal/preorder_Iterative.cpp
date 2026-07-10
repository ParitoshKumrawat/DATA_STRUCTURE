#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x):data(x), left(nullptr), right(nullptr){}
};

class preorder_Iterative{
    public:
    vector<int> preorder(TreeNode* root){
        vector<int> pre;

        if(root == nullptr)return pre;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();

            pre.push_back(root->data);

            if(root->right != nullptr)st.push(root->right);
            if(root->left != nullptr)st.push(root->left);
        }

        return pre;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    preorder_Iterative sol;

    // Getting the preorder traversal
    vector<int> result = sol.preorder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
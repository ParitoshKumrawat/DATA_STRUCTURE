#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val):data(val), left(nullptr), right(nullptr) {}
};

class Demo{
    public:
      vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level ;

            for(int i = 0 ; i<size ; i++){
              TreeNode* node = q.front();

              q.pop();

              level.push_back(node->data);

              if(node->left != nullptr)q.push(node->left);
              if(node->right != nullptr)q.push(node->right);

            }
            ans.push_back(level);
        }

        return ans;
      }
};

void printVector(const vector<int>& vec)
      {
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
      }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Demo sol;

    vector<vector<int>> res = sol.levelOrder(root);

    for(const vector<int>& level : res){
        printVector(level);
    }

    return 0;

}





#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* generate_tree(vector<int>& value) {
    TreeNode* father = new TreeNode(value[0]);
    for(int i=1;i<value.size();i++){
        if(father->left == nullptr){
            auto temp = new TreeNode(value[i]);
            father->left = temp;
        }
        else if (father->right == nullptr){
            auto temp = new TreeNode(value[i]);
            father->right = temp;
        }
    }
    return father;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> nodeList1, nodeList2;
        nodeList1.emplace(p);
        nodeList2.emplace(q);
        while(!nodeList1.empty()){
            auto k = nodeList1.front();
            auto m = nodeList2.front();
            nodeList1.pop();
            nodeList2.pop();
            if(k==nullptr&&m==nullptr) continue;
            if(k==nullptr&&m!=nullptr || k!=nullptr&&m==nullptr || k->val!=m->val){
                return false;
            }
            nodeList1.emplace(k->left);
            nodeList1.emplace(k->right);
            nodeList2.emplace(m->left);
            nodeList2.emplace(m->right);
        }
        return true;
    }
};


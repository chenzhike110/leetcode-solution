#include<vector>

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
    int left = value[1];
    int right = value[2];
    if(value.size()>3){
        value.pop_back();
        value.pop_back();
        value.pop_back();
    }
    auto temp = new TreeNode(value[1]);
    father->left = temp;
    auto temp1 = new TreeNode(value[2]);
    father->right = temp1;
    
    return father;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

    }
};
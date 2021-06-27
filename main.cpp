#include <iostream>
#include "bfs/ques100.h"

int main(){
   
    auto solution = Solution();
    vector<int> tree1 = {1,2,3};
    TreeNode* a=generate_tree(tree1);
    vector<int> tree2 = {1,2,3};
    TreeNode* b=generate_tree(tree2);
    bool step = solution.isSameTree(a, b);
    cout<<step<<endl;
    return 0;
}
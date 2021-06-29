#include <iostream>
#include "bfs/ques815.h"

int main(){
   
    auto solution = Solution();
    vector<vector<int>> buses = {{2},{2,8},{18,20,24,34,47,52,56,68,77,82,89,91,97,101,105,106,107,109,118,123,139,141,143,152,153,162,174,180,184,187,188,192,198,202,206,216,224}
    ,{14,15,20,21,31,47,48,59,67,70,74,82,94,102,109,121,125,128,148,162,165,171,180,196,199,202,205,212,214}};
    int result = solution.numBusesToDestination(buses, 180, 143);
    cout<<result<<endl;
    return 0;
}
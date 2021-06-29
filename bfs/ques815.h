#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode_
{
    int _value;
    int _index;
    int _bus;
    TreeNode_(int value, int bus, int index):_value(value), _bus(bus), _index(index){};
};

int find_(vector<int>& route, int temp){

    for(int i=0;i<route.size();i++){
        if(route[i]==temp) return i;
    }
    return -1;
}

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        queue<pair<TreeNode_*, int>> drive_list;
        int on_bus[routes.size()];
        for(int i=0;i<routes.size();i++){
            on_bus[i] = -1;
            int index = find_(routes[i], source);
            if(index != -1){
                auto temp = new TreeNode_(routes[i][(index + 1)%routes[i].size()], i, (index + 1)%routes[i].size());
                drive_list.emplace(temp, 1);
                on_bus[i] = source;
            }
        }
        bool on = true;
        while(on){
            auto front = drive_list.front();
            if(front.first->_value == target) return front.second;
            drive_list.pop();
            // still in the bus
            if(on_bus[front.first->_bus] != -2){
                auto temp = new TreeNode_(routes[(front.first->_bus)][(front.first->_index+1)%routes[(front.first->_bus)].size()], front.first->_bus, (front.first->_index+1)%routes[(front.first->_bus)].size());
                if(temp->_value == target) return front.second;
                drive_list.emplace(temp, front.second);
                cout<<temp->_value<<endl;
                if(temp->_value == on_bus[temp->_bus]) {
                    cout<<"bus "<<temp->_bus<<"over"<<endl;
                    on_bus[temp->_bus] = -2;
                }
            }
            
            // change bus
            int stop = front.first->_value;
            for(int i=0;i<routes.size();i++){
                if(on_bus[i] != -1) continue;
                int index = find_(routes[i], stop);
                if(index != -1){
                    auto temp = new TreeNode_(routes[i][(index+1)%routes[i].size()], i, (index+1)%routes[i].size());
                    if(temp->_value == target) return front.second+1;
                    drive_list.emplace(temp, front.second+1);
                    on_bus[i] = stop;
                }
            }
            on = false;
            for(int i=0;i<routes.size();i++){
                if(on_bus[i]!=-2 && on_bus[i]!=-1){
                    on = true;
                    break;
                }
            }
        }
        return -1;
    }
};
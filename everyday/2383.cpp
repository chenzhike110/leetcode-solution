#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        for(int i=0; i<energy.size(); i++) {
            if (initialEnergy <= energy[i]) {
                hours += energy[i] - initialEnergy + 1; 
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                hours += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return hours;
    }
};

int main(int argv, char* argc[]) {
    int initialEnergy = 5;
    int initialExperience = 3;
    vector<int> energy({1,4,3,2});
    vector<int> experience({2,6,3,1});
    Solution a;
    int hours = a.minNumberOfHours(initialEnergy, initialExperience, energy, experience);
    cout << hours << endl;
    return 0;
}
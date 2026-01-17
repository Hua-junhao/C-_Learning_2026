#include <bits/stdc++.h>
using namespace std;

// ================= Helper for Debugging =================
void printVec(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// ================= YOUR SOLUTION =================
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int max=-1;
        vector<int>v={-1,-1};
        for(int i=0;i<towers.size();i++)
        {
            int s=abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1]);
            if (s<=radius)
            {
                if(towers[i][2]>max)
                {
                    max=towers[i][2];
                    v={towers[i][0],towers[i][1]};
                }
                else if (towers[i][2]==max)
                {
                    if(towers[i][0]<v[0]||towers[i][0]==v[0]&&towers[i][1]<v[1])
                    {
                        v={towers[i][0],towers[i][1]};
                    }
                }
            }
        }
        return v;
    }
};
// =================================================

int main() {
    Solution sol;

    // --- Example 1 ---
    cout << "Test Case 1: ";
    vector<vector<int>> towers1 = {{1,2,5}, {2,1,7}, {3,1,9}};
    vector<int> center1 = {1,1};
    int radius1 = 2;
    vector<int> res1 = sol.bestTower(towers1, center1, radius1);
    printVec(res1); // Expected: [3, 1]

    // --- Example 2 ---
    cout << "Test Case 2: ";
    vector<vector<int>> towers2 = {{1,3,4}, {2,2,4}, {4,4,7}};
    vector<int> center2 = {0,0};
    int radius2 = 5;
    vector<int> res2 = sol.bestTower(towers2, center2, radius2);
    printVec(res2); // Expected: [1, 3]

    // --- Example 3 ---
    cout << "Test Case 3: ";
    vector<vector<int>> towers3 = {{5,6,8}, {0,3,5}};
    vector<int> center3 = {1,2};
    int radius3 = 1;
    vector<int> res3 = sol.bestTower(towers3, center3, radius3);
    printVec(res3); // Expected: [-1, -1]

    return 0;
}
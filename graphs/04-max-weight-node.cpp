/*
    Problem Description: You are given a maze with N cells. Each cell may have multiple
                         entry points but not more than one exit.

                         The cells are named with an integer from 0 to N-1.

    You have to find: Find the node number of maximum weight node
                      (Weight of a node is the sum of all nodes pointing to that node).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] != -1) mp[nums[i]] += i;
    }

    int res = 0;
    int maxi = INT_MIN;
    
    for (auto i : mp) {
        if (maxi < i.second) {
            maxi = i.second;
            res = i.first;
        }
    }
    cout << res;
}
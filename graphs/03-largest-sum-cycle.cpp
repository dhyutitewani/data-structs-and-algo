/*
    Problem Description: The task is to find the largest sum of a cycle in the maze.
                         (sum of a cycle is the sum of the cell indexes of all cells 
                          present in that cycle)

    Solution: uses dfs
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum State { UNVISITED, VISITING, VISITED };

long long dfs(int node, vector<int>& edge, vector<State>& state, vector<long long>& cycleSum) {
    if (state[node] == VISITING) {
        // Cycle detected, calculate the sum of the cycle
        long long sum = 0;
        int current = node;
        do {
            sum += current;
            current = edge[current];
        } while (current != node);
        return sum;
    }
    
    if (state[node] == VISITED || edge[node] == -1) {
        return 0;
    }
    
    state[node] = VISITING;
    long long sum = dfs(edge[node], edge, state, cycleSum);
    state[node] = VISITED;
    cycleSum[node] = sum;
    
    return sum;
}

long long largestSumCycle(int n, vector<int> edge) {
    vector<State> state(n, UNVISITED);
    vector<long long> cycleSum(n, 0);
    long long maxCycleSum = -1;
    
    for (int i = 0; i < n; ++i) {
        if (state[i] == UNVISITED) {
            long long sum = dfs(i, edge, state, cycleSum);
            maxCycleSum = max(maxCycleSum, sum);
        }
    }
    
    return maxCycleSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> edge[i];
    }
  
    long long result = largestSumCycle(n, edge);
    cout << result << endl;
    return 0;
}

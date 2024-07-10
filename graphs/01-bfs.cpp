/*
    BFS implementation
*/

#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void add_edge(int u, int v, bool directed=false) {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    void print_adj() {
        for(auto i: adj) {
            cout << i.first << " -> ";
            for(auto j: i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    static void bfs(unordered_map<int, bool> &visited, unordered_map<int, list<int>> adl, vector<int> &ans, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()) {
            int frontnode = q.front();
            q.pop();

            ans.push_back(frontnode);

            for (auto i: adl[frontnode]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

};

int main() {
    graph g;
    g.add_edge(4, 4);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    // g.print_adj();

    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adl = g.adj;
    vector<int> ans;

    for (int i = 0; i < 4; i++) {
        if (!visited[i]) 
            graph().bfs(visited, adl, ans, i);
    }

    for (auto i: ans) {
        cout << i << " "; 
    }
    cout << endl;
    return 0;
}
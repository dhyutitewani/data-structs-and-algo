/*
    Problem Description: You are given a maze with N cells.
                         Each cell may have multiple entry points but not more than one exit.
                         The cells are named with an integer from 0 to N-1.

    You have to find: Nearest meeting cell : Given any two cells - C1, C2,
                      find the closest cell cm that can be reached from both C1 and C2.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortPath(vector<int> adj[], int c1, int n)
{
    queue<int> q;
    vector<int> dist(n, INT_MAX);

    q.push(c1);
    dist[c1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; i++)
        cin >> edges[i];

    int c1, c2;
    cin >> c1 >> c2;

    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        if (edges[i] == -1) continue;
        adj[i].push_back(edges[i]);
    }
    vector<int> v1 = shortPath(adj, c1, n);
    vector<int> v2 = shortPath(adj, c2, n);

    int mn = INT_MAX, node = -1;
    for (int i = 0; i < n; i++) {
        if (v1[i] == INT_MAX || v2[i] == INT_MAX)
            continue;
        if (v1[i] + v2[i] < mn)
        {
            mn = v1[i] + v2[i];
            node = i;
        }
    }
    cout << node << endl;
    return 0;
}
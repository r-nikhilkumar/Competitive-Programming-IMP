#include <bits/stdc++.h>
using namespace std;

// To find all the ways and paths we  use printPaths and all the auxilliary things but to calculate only the number of ways we can directly use ways array

// void printPaths(vector<vector<int>> &parent, int v, int &numPath);

void solve() {
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adjL(v);
    for (int i = 0; i < e; ++i) {
        int s, d, w;
        cin >> s >> d >> w;
        adjL[s].push_back({d, w});
    }
    int s, d;
    cin >> s >> d;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    // vector<vector<int>> parent(v);
    int ways[v] = {0};
    ways[s] = 1;
/*
    for (int i = 0; i < parent.size(); ++i) {
        parent[i].push_back(i);
    }
*/
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int it_s = it.second;
        int it_w = it.first;
        if (it_s == d) break;
        for (auto i : adjL[it_s]) {
            if (dist[i.first] > i.second + it_w) {
                // parent[i.first].clear();
                // parent[i.first].push_back(it_s);
                dist[i.first] = i.second + it_w;
                ways[i.first] = ways[it_s];
                pq.push({dist[i.first], i.first});
            } else if (dist[i.first] == i.second + it_w) {
                // parent[i.first].push_back(it_s);
                ways[i.first] += ways[it_s];
            }
        }
    }

    if (dist[d] != 1e9) {
        // int numPath = 0;
        // printPaths(parent, d, numPath);
        cout << ways[d] << endl;
    } else {
        cout << -1 << endl;
    }
}
/*
void printPaths(vector<vector<int>> &parent, int v, int &numPath) {
    if (parent[v].size() == 1 && parent[v][0] == v) {
        // cout << v << " ";
        numPath++;
        return;
    }
    for (auto i : parent[v]) {
        printPaths(parent, i, numPath);
        // cout << v << " ";
    }
}
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

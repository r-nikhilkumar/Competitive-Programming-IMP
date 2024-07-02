#include <bits/stdc++.h>
using namespace std;

void solve(){
    int v, e, k;
    cin>>v>>e>>k;
    vector<pair<int, int>> adjL[v];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;
        adjL[s].push_back({d, w});
    }
    int s, d;
    cin>>s>>d;
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    queue<pair<int, pair<int, int>>> queue;
    queue.push({0, {s, 0}});
    while(!queue.empty()){
        auto it = queue.front();
        queue.pop();
        int it_s = it.second.first;
        int it_dist = it.second.second;
        int it_k = it.first;
        if(it_k > k) continue;
        for (auto i : adjL[it_s])
        {
            if(dist[i.first] > it_dist + i.second){
                dist[i.first] = it_dist + i.second;
                queue.push({it_k + 1, {i.first, dist[i.first]}});
            }
        }
        
        
    }
    cout<<(dist[d] == INT_MAX ? -1 : dist[d])<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
        
    }

    return 0;
}
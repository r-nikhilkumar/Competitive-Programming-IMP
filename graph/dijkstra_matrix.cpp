#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int** mat = new int*[n];
        for (int i = 0; i < n; ++i)
        {
            mat[i] = new int[m];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>>mat[i][j];
            }
        }
        int i, j;
        cin>>i>>j;
        pair<int, int> s({i, j});
        cin>>i>>j;
        pair<int, int> d({i, j});

        // apply dijkstra algorithm but no need to use priority queue bcz all neighbours weights are equal
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,pair<int,int>>> pq;
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, s});
        dist[s.first][s.second] = 0;
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            i = it.second.first;
            j = it.second.second;
            int wt = it.first;
            if(d == pair<int, int>(i,j)) break;
            if(i+1 < n && dist[i+1][j] > wt + 1){
                dist[i+1][j] = wt + 1;
                pq.push({dist[i+1][j], {i+1, j}});
            }
            if(i-1 >= 0 && dist[i-1][j] > wt + 1){
                dist[i-1][j] = wt + 1;
                pq.push({dist[i-1][j], {i-1, j}});
            }
            if(j+1 < m && dist[i][j+1] > wt + 1){
                dist[i][j+1] = wt + 1;
                pq.push({dist[i][j+1], {i, j+1}});
            }
            if(j-1 >= 0 && dist[i][j-1] > wt + 1){
                dist[i][j-1] = wt + 1;
                pq.push({dist[i][j-1], {i, j-1}});
            }
        }

        cout<<dist[d.first][d.second]<<endl;
    }



    return 0;
}
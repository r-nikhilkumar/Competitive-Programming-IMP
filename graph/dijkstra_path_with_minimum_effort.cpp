#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int t;
    cin>>t;
    while(t--){
    	int n, m;
    	cin>>n>>m;
    	int **mat = new int*[n];
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
    	pair<int, int> s(i, j);
    	cin>>i>>j;
    	pair<int, int> d(i, j);

    	// dijkstra to find min of max efforts

    	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
    	pq.push({0, s});
    	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    	dist[s.first][s.second] = 0;

    	while(!pq.empty()){
    		auto it = pq.top();
    		if(it.second == d) break;
    		int it_dist = it.first;
    		int i = it.second.first;
    		int j = it.second.second;
    		pq.pop();
    		if(i+1 < n && dist[i+1][j] > max(abs(mat[i+1][j] - mat[i][j]), it_dist)){
    			dist[i+1][j] = max(abs(mat[i+1][j] - mat[i][j]), it_dist);
    			pq.push({dist[i+1][j], {i+1, j}});
    		}
    		if(j+1 < m && dist[i][j+1] > max(abs(mat[i][j+1] - mat[i][j]), it_dist)){
    			dist[i][j+1] = max(abs(mat[i][j+1] - mat[i][j]), it_dist);
    			pq.push({dist[i][j+1], {i, j+1}});
    		}
    		if(i-1 >= 0 && dist[i-1][j] > max(abs(mat[i-1][j] - mat[i][j]), it_dist)){
    			dist[i-1][j] = max(abs(mat[i-1][j] - mat[i][j]), it_dist);
    			pq.push({dist[i-1][j], {i-1, j}});
    		}
    		if(j-1 >= 0 && dist[i][j-1] > max(abs(mat[i][j-1] - mat[i][j]), it_dist)){
    			dist[i][j-1] = max(abs(mat[i][j-1] - mat[i][j]), it_dist);
    			pq.push({dist[i][j-1], {i, j-1}});
    		}



    	}
    	cout<<dist[d.first][d.second]<<endl;
        
		// Clean up dynamic memory
        for (int i = 0; i < n; ++i) {
            delete[] mat[i];
        }
        delete[] mat;


    }



    return 0;
}
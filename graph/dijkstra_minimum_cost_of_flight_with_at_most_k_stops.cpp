#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	cin>>t;
    while(t--){
    	int v, e, k;
    	cin>>v>>e>>k;
    	vector<pair<int,int>> adjL[v];
    	for (int i = 0; i < e; ++i)
    	{
    		int s, d, w;
    		cin>>s>>d>>w;
    		adjL[s].push_back({d, w});
    	}
    	int s, d;
    	cin>>s>>d;

    	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    	vector<int> dist(v, INT_MAX);
    	pq.push({{0, s}, 0});
    	dist[s] = 0;

    	while(!pq.empty()){
    		auto it = pq.top();
    		pq.pop();
    		int it_k = it.second;
    		int it_dist = it.first.first;
    		int it_s = it.first.second;
    		for(auto i : adjL[it_s]){
    			if(dist[i.first] > it_dist + i.second){
    				if(i.first != d && it_k < k){
    					dist[i.first] = it_dist + i.second;
                        int new_k = it_k+1;
    					pq.push({{dist[i.first], i.first}, new_k});
    				}else if(i.first == d && it_k <= k){
    					dist[i.first] = it_dist + i.second;
    					pq.push({{dist[i.first], i.first}, it_k});
    				}
    			}
    		}
    	}
		cout<<(dist[d] == INT_MAX ? -1 : dist[d])<<endl;

    }




    return 0;
}
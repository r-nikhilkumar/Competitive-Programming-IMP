#include<bits/stdc++.h>
using namespace std;

int N = 1e5;

void solve(){
	int n;
	cin>>n;
    int* edges = new int[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>edges[i];
    }
    int s, e;
    cin>>s>>e;

    queue<pair<int, int>> queue;
    vector<int> min_mul(N, INT_MAX);
    queue.push({0, s});
    min_mul[s] = 0;
    while(!queue.empty()){
    	auto it = queue.front();
    	queue.pop();
    	int it_min_mul = it.first;
    	int it_s = it.second;
    	if(it.second > e) break;
    	for (int i = 0; i < n; ++i)
    	{
    		int node = (it_s)*(edges[i])%N;
    		if(min_mul[node] > it_min_mul + 1){
    			min_mul[node] = it_min_mul + 1;
    			queue.push({min_mul[node], node});
    		}
    	}
    }
    cout<<(min_mul[e] == INT_MAX ? -1 : min_mul[e])<<endl;
    delete[] edges;


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
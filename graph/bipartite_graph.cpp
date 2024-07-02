#include<bits/stdc++.h>
using namespace std;

// bipartite using dfs:

bool check_bipartite_dfs(vector<int> adjL[], int s, bool visited[], int color[]){
	visited[s] = 1;
	for(auto i : adjL[s]){
		if(!visited[i]){
			color[i] = color[s] == 1 ? 2 : 1;
			if(!check_bipartite_dfs(adjL, i, visited, color)){
				return false;
			}
		} else if(color[i] == color[s]){
			return false;
		}

	}
	return true;
}

// bipartite using bfs:

bool check_bipartite_bfs(vector<int> adjL[], int s, bool visited[], int color[]){
	queue<int> queue;
	queue.push(s);
	color[s] = 1;
	while(!queue.empty()){
		auto it = queue.front();
		queue.pop();
		visited[it] = 1;
		for(auto i : adjL[it]){
		 	if(!visited[i]){
		 		color[i] = color[it] == 1 ? 2 : 1;
		 		queue.push(i);
		 	}
		 	else if(color[i] == color[it]){
		 		return false;
		 	}
		 } 
	}
	return true;
}

bool check_bipartite_dfs_iteration(vector<int> adjL[], int s, bool visited[], int color[]){
	stack<int> stack;
	stack.push(s);
	color[s] = 1;
	while(!stack.empty()){
		auto it = stack.top();
		visited[it] = 1;
		stack.pop();
		for(auto i : adjL[it]){		
			if(!visited[i]){
				color[i] = 1;
				stack.push(i);
			}else if(color[i] == color[it]){
				return false;
			}
		}
	}
	return true;
}


int main() {
    int n, v;
    cin>>n>>v;
    vector<int> adjL[n+1];
    // lets assume 0, 1 and 2 as color
    // initial color array
    int color[n+1] = {0};

    for (int i = 0; i < v; ++i)
    {
    	int s, d;
    	cin>>s>>d;
    	adjL[s].push_back(d);
    	adjL[d].push_back(s);
    }

    bool visited[n+1] = {0};
    color[1] = 1;
    cout<<"bipartite: dfs ";
    cout<<check_bipartite_dfs(adjL, 1, visited, color)<<endl;
    memset(visited, 0, sizeof(visited));
    memset(color, 0, sizeof(color));
    color[1] = 1;
    cout<<"bipartite: bfs ";
    cout<<check_bipartite_bfs(adjL, 1, visited, color)<<endl;
    memset(visited, 0, sizeof(visited));
    memset(color, 0, sizeof(color));
    color[1] = 1;
    cout<<"bipartite: dfs iteration ";
    cout<<check_bipartite_dfs_iteration(adjL, 1, visited, color)<<endl;



    return 0;
}
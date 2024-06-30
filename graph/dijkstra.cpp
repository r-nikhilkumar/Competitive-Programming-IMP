vector<int> dijkstra_pq(vector<pair<int, int>> adjL[], int s, int n, bool visited[]){
	vector<int> dist(n+1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push(pair<int, int>(0, s));
	dist[s] = 0;
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		visited[it.second] = 1;
		for(auto i : adjL[it.second]){
			if(it.first + i.second < dist[i.first]){
				dist[i.first] = it.first + i.second;
				pq.push(pair<int, int>(dist[i.first], i.first));
			}
		}

	}
	return dist;
}


vector<int> dijkstra_set(vector<pair<int, int>> adjL[], int s, int n, bool visited[]){
	set<pair<int, int>> set;
	set.insert({0, s});
	vector<int> dist(n+1, INT_MAX);
	dist[s] = 0;
	while(!set.empty()){
		auto it = *set.begin();
		set.erase(set.begin());
		visited[it.second] = 1;
		for(auto i : adjL[it.second]){
			if(dist[i.first] > it.first + i.second){
				set.erase({dist[i.first], i.first});
				dist[i.first] = it.first + i.second;
				set.insert({dist[i.first], i.first});
			}
		}
	}
	return dist;
}


/*

	Dijkstra algorithm - find shortest path between source to vertex by exploring all the neighbours

	Steps:
	1. go to all the neighbours' vertices from source and mark with the wieght
	2. then take smallest of all of them and then proceed with that and explore all the vertices
	3. if encounter the vertices with already visited and having new weight less than of that then udpate that.
	4. repeat until reach the destination.


	psudo code:

	fun dijkstra(g, s, d, n){
		dist[n+1] (INT_MAX);
		priority_queue<int> pq;
		visited[n+1] (0);
		pq.push(pair(0, s));
		dist[s]=0;
		while(!pq.empty()){
			cur = pq.front();
			pq.pop();
			visited[cur.second] = 1;
			if(cur.second == d){
				return dist[cur.second];
			}
			for(i : g[cur]){
				dist[i.first] = min(dist[i.first], +i.second + dist[cur.second]);
				pq.push(pair(dist[i.first], i.first));
			}

		}
	
	}


*/
class DSU{
	vector<int> parent, rank;
	public:
	
	DSU(int n){
        rank.assign(n+1, 0);
        for (int i = 0; i <= n; ++i)
        {
        	parent.push_back(i);
        }
    }

    int find_parent(int n){
    	if(parent[n] == n){
    		return n;
    	}
    	return parent[n] = find_parent(parent[n]);
    }

    void union_set(int a, int b){
    	a = find_parent(a);
    	b = find_parent(b);
    	if(a==b){
    		return;
    	}
    	if(rank[a]>rank[b]){
    		parent[b] = a;
    	}else{
    		parent[a] = b;
    		if(rank[a] == rank[b]){
    			rank[b]++;
    		}
    	}
    }
};

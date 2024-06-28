#include<bits/stdc++.h>
using namespace std;


/*
	BFS - Breadth First Search - visit neighbours first then move forward
	here I used queue (fcfs) that means we will do operations with the one who entered first 
*/

/*
	Steps for BFS:

	1. start with a source
	2. create a queue and visited boolean array with n size
	3. enque the source and mark visited[s] true
	4. deque it and perform any operation
	5. traverse to all the neighbours of s and if not visited enque it also while enqueing mark it visited
	6. repeat till end of nodes that all visited
*/

void bfs(vector<int> adjL[], int s, int n){ // here o(n+v) is the time complexity and sc is o(n)
	queue<int> queue; // sc - o(n)
	queue.push(s);
	bool visited[n+1] = {0}; // sc - o(n)
	visited[s] = 1;
	while(!queue.empty()){ // time complexity - runs for all the nodes o(n)
		int it = queue.front();
		cout<<it<<"->";
		queue.pop();
		for(int i : adjL[it]){ // time complexity - runs for all the vertices till the end (v)
			if(!visited[i]){
				queue.push(i);
				visited[i] = 1;
			}
		}
	}
}


int main() {
	cout<<"Graph: BFS"<<endl;
	int n, v;
	cin>>n>>v;
	vector<int> a;
	vector<int> adjL[n+1];
	for (int i = 0; i < v; ++i)
	{
		int s, d;
		cin>>s>>d;
		adjL[s].push_back(d);
		adjL[d].push_back(s);
	}

	for (int i = 1; i < n+1; ++i)
	{
		cout<<i<<" -> ";
		for (int j = 0; j < adjL[i].size(); ++j)
		{
			cout<<adjL[i][j]<<" ";
		}
		cout<<endl;
	}

	bfs(adjL, 1, n);




    return 0;
}	
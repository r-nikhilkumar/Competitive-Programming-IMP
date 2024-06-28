#include<bits/stdc++.h>
using namespace std;


// TC = o(n+v)
// SC = visited + recursive stack + constant = o(n) + o(n) +o(1) = o(n)

void dfs_inside_recursive(vector<int> adjL[], bool visited[], int s);
void dfs_inside_iterative(vector<int> adjL[], bool visited[], int s, int);

void dfs(vector<int> adjL[], int n, int s){
	bool visited[n+1] = {0};
	cout<<"Recursive:"<<endl;
	dfs_inside_recursive(adjL, visited, s);
	cout<<endl<<"Iterative:"<<endl;
	bool visited2[n+1] = {0};
	dfs_inside_iterative(adjL, visited2, s, n);
}

void dfs_inside_recursive(vector<int> adjL[], bool visited[], int s){
	visited[s] = 1;
	cout<<s<<" ";
	for (auto i : adjL[s])
	{
		if(!visited[i]){
			dfs_inside_recursive(adjL, visited, i);
		}
	}
}

void dfs_inside_iterative(vector<int> adjL[], bool visited[], int s, int n){
	stack<int> stack;
	stack.push(s);
	while(!stack.empty()){
		auto it = stack.top();
		stack.pop();
		if(!visited[it]){
			cout<<it<<" ";
			visited[it]=1;
		}
		
		for(auto i : adjL[it]){
			if(!visited[i]){
				stack.push(i);
			}
		}
	}
}

int main() {
    int n, v;
    cin>>n>>v;
    vector<int> adjL[n+1];

    for(int i=0;i<v;i++){
    	int s, d;
    	cin>>s>>d;
    	adjL[s].push_back(d);
    	adjL[d].push_back(s);
    }

    dfs(adjL, n, 1);



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(9,false);

void dfs(vector<vector<int>> graph,int source){
	cout<<source+1<<endl;
	visited[source] = true;
	for(int i = 0 ; i < graph.size() ; i++){
		if(visited[i] == false && graph[source][i] != 0)
			dfs(graph,i);
	}
}
void bfs(vector<vector<int>> graph,int source){
	deque<int> q;
	q.push_back(source);
	visited[source] = true;
	int v;
	while(!q.empty()){
		v = q.front();
		q.pop_front();
		cout<<v+1<<" ";
		for(int i = 0 ; i < graph.size() ; i++){
			if(visited[i] == false && graph[v][i] != 0){
				q.push_back(i);
				visited[i] = true;
			}

		}
	}
}
int main(){
	vector<vector<int>> graph ={ { 0, 1, 0, 0, 0, 0, 0, 1, 0 }, 
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0 }, 
						{ 0, 1, 0, 1, 0, 1, 0, 0, 1 }, 
						{ 0, 0, 1, 0, 1, 1, 0, 0, 0 }, 
						{ 0, 0, 0, 1, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 1, 1, 10, 0, 1, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 1, 0, 1, 1 }, 
						{ 1, 1, 0, 0, 0, 0, 1, 0, 1 }, 
						{ 0, 0, 1, 0, 0, 0, 1, 1, 0 }};
	// vector<vector<int>> graph ={ {0,1,1,0},{1,0,0,0},{1,0,0,1},{0,0,1,0}};

	dfs(graph,0);
	fill(visited.begin(),visited.end(),false);
	bfs(graph,0);
					  
}
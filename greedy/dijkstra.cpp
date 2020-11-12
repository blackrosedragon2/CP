#include <bits/stdc++.h>
using namespace std;


int minimumDist(vector<int> dist, vector<bool> visited) 
{
	int min = INT_MAX,index;
	for(int i = 0 ; i < dist.size() ; i++){
		if(visited[i] == false && min >= dist[i]){
			min = dist[i];
			index = i;
		}
	}
	return index;
}
int dijkstra(vector<vector<int>>graph, int source){
	int n = graph.size();
	vector<int> dist(n,INT_MAX);
	vector<bool> visited(n,false);
	dist[source] = 0;
	for(int i = 0 ; i < n ; i ++){
		int u = minimumDist(dist,visited);
		visited[u] = true;
		for(int j = 0 ; j < n ; j ++){
			if(visited[j] == false && graph[u][j] != 0 && dist[u] != INT_MAX && dist[j] > graph[u][j] + dist[u]){
				dist[j] = dist[u] + graph[u][j];
			}
		}
	}

	cout<<"OUTPUT"<<endl;
	for(int i = 0 ; i < dist.size() ; i++){
		cout<<dist[i]<<endl;
	}
}

int main(){
	vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph,0) ;
					  
}
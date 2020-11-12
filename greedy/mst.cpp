#include <bits/stdc++.h>
using namespace std;


int minimumDist(vector<int> value, vector<bool> visited) 
{
	int min = INT_MAX,index;
	for(int i = 0 ; i < value.size() ; i++){
		if(visited[i] == false && min > value[i]){
			min = value[i];
			index = i;
		}
	}
	return index;
}
int mst(vector<vector<int>>graph, int source){
	int n = graph.size();
	vector<int> value(n,INT_MAX);
	vector<int> parent(n);
	vector<bool> visited(n,false);
	parent[source] = -1;
	value[source] = 0;
	for(int i = 0 ; i < n ; i ++){
		int u = minimumDist(value,visited);
		visited[u] = true;
		for(int j = 0 ; j < n ; j ++){
			if(visited[j] == false && graph[u][j] != 0 && value[j] > graph[u][j]){
				value[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}

	cout<<"OUTPUT"<<endl;
	for(int i = 1 ; i < parent.size() ; i++){
		cout<<"NODE "<<i<<"\t"<<parent[i]<<endl;
	}
}

int main(){
	vector<vector<int>> graph = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
	mst(graph,0) ;
					  
}
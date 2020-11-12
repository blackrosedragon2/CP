#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(5,vector<int>(5,-1));
bool is_valid(int n , int i , int j){
	if( i >= 0 && j >= 0 && i < n && j < n)
		return true;
	return false;
}
int weighted_maze(vector<vector<int>> maze, int i , int j , int n, int weight){
	weight = max(weight,maze[i][j]);
	if(i == n-1 && j == n-1)
		return weight;
	int val1=INT_MAX,val2=INT_MAX;
	if(is_valid(n,i+1,j))
		val1 = weighted_maze(maze,i+1,j,n,weight);
	if(is_valid(n,i,j+1))
		val2 = weighted_maze(maze,i,j+1,n,weight);
	return min(val1,val2);
}
//memo not working
/*int weighted_maze_memo(vector<vector<int>> maze, int i , int j , int n, int weight){
	if(memo[i][j] == -1)
	{
		weight = max(weight,maze[i][j]);
		if(i == n-1 && j == n-1)
			memo[i][j] = weight;
		else
		{
			int val1=INT_MAX,val2=INT_MAX;
			if(is_valid(n,i+1,j))
				val1 = weighted_maze(maze,i+1,j,n,weight);
			if(is_valid(n,i,j+1))
				val2 = weighted_maze(maze,i,j+1,n,weight);
			memo[i][j] = min(val1,val2);
		}
	}
	return memo[i][j];
}*/
int main()
{
	vector<vector<int>> maze = {
			{1,8,21,7},
			{19,17,10,20},
			{2,18,23,22},
			{14,25,4,13}
	};
	cout<<weighted_maze(maze,0,0,4,1);
}
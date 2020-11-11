#include <bits/stdc++.h>
using namespace std;
int max_n = 100,max_m = 100;
//max_m based on total weight
//max_n based number of weights
//memo is vector of n_weights * total_weight
vector<vector<int>> memo(max_n,vector<int> (max_m,-1));
int knapsack(vector<int> reward,vector<int> weight, int w , int n){
	if (n==0 || w == 0){
		return 0;
	}
	else if(memo[n][w] != -1){
		return memo[n][w];
	}
	else
	{
		if(weight[n-1] > w ){
			memo[n][w] = knapsack(reward,weight,w,n-1);
		}
		else{
			memo[n][w] = max(knapsack(reward,weight,w,n-1),knapsack(reward,weight,w-weight[n-1],n-1)+reward[n-1]);
		}
		return memo[n][w];
	}
}
int main(){
	vector<int> reward,weight;
	reward = {10,40,30,50};
	weight = {5,4,6,3};
	int w = 10;
	cout<<knapsack(reward,weight,w,weight.size())<<endl;
}
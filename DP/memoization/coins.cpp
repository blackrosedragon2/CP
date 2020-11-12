#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(1000,vector<int>(1000,-1));

int calculate_coins(vector<int> coins , int n , int sum){
	if(n == 0)
		return 0;
	if(sum == 0)
		return 1;
	int res =  calculate_coins(coins,n-1,sum);
	if(sum >= coins[n-1])
		res += calculate_coins(coins,n,sum-coins[n-1]);
	return res;
}

int calculate_coins_memo(vector<int> coins , int n , int sum){
	if(n == 0)
		return 0;
	if(sum == 0)
		return 1;
	if(memo[n-1][sum] == -1){
		int res =  calculate_coins(coins,n-1,sum);
		if(sum >= coins[n-1])
			res += calculate_coins(coins,n,sum-coins[n-1]);
		memo[n-1][sum] = res;
	}
	return memo[n-1][sum];
}
int main(){
	//count total number of ways to generate 10 rupees with given coins
	vector<int> coins = {2,5,3,6};
	cout<<calculate_coins_memo(coins,4,10)<<endl;
}
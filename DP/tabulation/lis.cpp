#include <bits/stdc++.h>
using namespace std;
vector<int> lis(vector<int> arr){
	//implement longest increasing substring
	vector<int> dp(arr.size(),-1);
	dp[0] = 1;
	for(int i = 1 ; i < arr.size() ; i ++){
		dp[i] = 1;
		for(int j = 0 ; j < i; j++){
			if(arr[j] < arr[i])
				//subsequence is increasing
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	return dp;
}
int del_sort(int n ,int lis_out){
	//implement fn that returns minimum number of elements needed to be deleted so that array would be sorted (given LIS)

	return n-lis_out;
}
int msis(vector<int> arr){
	//implement maximum sum of a increasing subsequence
	vector<int> dp(arr.size(),-1);
	dp[0] = arr[0];
	for(int i = 1 ; i < arr.size() ; i ++){
		dp[i] = arr[i];
		for(int j = 0 ; j < i; j++){
			if(arr[j] < arr[i])
				//subsequence is increasing
				dp[i] = max(dp[i],dp[j]+arr[i]);
		}
	}
	int max_element = INT_MIN;
	for(int i = 0 ; i < dp.size() ; i++){
		if(max_element < dp[i])
			max_element = dp[i];
	}
	return max_element;
}
int max_bitonic_subsequence(vector<int> arr){
	//implement maximum bitonic length in a subsequence
	vector<int> lis_arr,lds_arr;
	lis_arr = lis(arr);
	reverse(arr.begin(),arr.end());
	lds_arr = lis(arr);
	int max_len = INT_MIN,temp;
	for(int i = 0 ; i < lis_arr.size() ; i++){
		temp = lis_arr[i] + lds_arr[i] - 1;
		if(max_len < temp)
			max_len = temp;
	}
	return max_len;
}
int main(){
	vector<int> arr = {1,2,1,5,6,3};//{3,20 , 10 ,4,6,7,30}; //= {3,4,2,8,10,5,1};
	vector<int> dp = lis(arr);
	int max_element = INT_MIN;
	for(int i = 0 ; i < dp.size() ; i++){
		if(max_element < dp[i])
			max_element = dp[i];
	}
	cout<<"LIS IS "<<max_element<<endl;
	cout<<"Minimum number of elements needed to be deleted so that array would be sorted (given LIS) "<<del_sort(arr.size(),max_element)<<endl;
	cout<<"MSIS IS "<<msis(arr)<<endl;
	cout<<"Maximum bitonic length is "<<max_bitonic_subsequence(arr)<<endl;
}
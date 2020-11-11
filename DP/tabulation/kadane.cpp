//Implement max sum subarray 
#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(vector<int> arr){
	int max_sum = INT_MIN;
	int temp_sum = 0;

	for(int i = 0 ; i < arr.size(); i ++){
		temp_sum += arr[i];
		if(max_sum < temp_sum){
			max_sum = temp_sum;
		}
		else if(temp_sum < 0)
			temp_sum  = 0;
	}
	return max_sum;
}

int main(){
	vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<"Maximum sum subarray is "<<max_sum_subarray(arr)<<endl;
}
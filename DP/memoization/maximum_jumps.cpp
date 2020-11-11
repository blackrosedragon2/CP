#include <bits/stdc++.h>
using namespace std;
//maximum jumps to reach end 
//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
vector<int> memo(100);
int jump(vector<int> a,int index){
	if(memo[index] != -1)
		return memo[index];
	else{
		if( index >= a.size()-1)
			return 0;
		else
		{
			int result = INT_MAX;
			for(int i = 1 ; i <= a[index] ; i++){
				int temp = jump(a,index+i);
				if(temp != INT_MAX)
					result = min(temp+1,result);
			}
			memo[index] = result;
		}
		return memo[index];
	}
}
int main(){
	vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	for(int i = 0 ; i <= a.size(); i++){
		memo[i] = -1;
	}
	cout<<jump(a,0)<<endl;
}
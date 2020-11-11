/*//optimal strategy for a game
#include <bits/stdc++.h>
using namespace std;

int score(int i, int j, vector<int> arr){
	if (i >= j)
		return min(arr[i],arr[j]);
	return max(score(i+1,j,arr)+arr[i] , score(i,j-1,arr)+arr[j]);
}
int main(){
	vector<int> arr = {2,3,15,7};
	cout<<score(0,arr.size()-1,arr);
}

// (2+(3,15), 7 + (3,15) )
*/
//incorrect
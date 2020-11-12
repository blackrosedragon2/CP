#include <bits/stdc++.h>
using namespace std;

class knapsack{
public:
	int weight,value;
	float ratio;
};
bool comp(knapsack k1,knapsack k2){
	//sorts in descending order of ratio
	return k1.ratio > k2.ratio;
}
float fractional_knapsack(vector<knapsack> arr,float capacity){
	float total = 0;
	for(int i = 0 ; i < arr.size() ; i++){
		arr[i].ratio = ((float)arr[i].value/arr[i].weight);
	}

	sort(arr.begin(),arr.end(),comp);
	for(int i = 0 ; i < arr.size() ; i++){
		if(capacity >= arr[i].weight){
			capacity -= arr[i].weight; 
			total += arr[i].value;
		}
		else{
			total += arr[i].value*(capacity/arr[i].weight);
			break;
		}
	}
	return total;
}
int main(){
	vector<knapsack> arr;
	vector<int> weights={10,20,4},values={200,100,50};
	knapsack k;
	for(int i = 0 ; i< weights.size(); i ++){
		k.weight = weights[i];
		k.value = values[i];
		arr.push_back(k);
	}
	cout<<fractional_knapsack(arr,12)<<endl;
}
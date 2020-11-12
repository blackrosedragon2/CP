#include <bits/stdc++.h>
using namespace std;
vector<int> generate_prime(int n,int start = 0){
	//generate prime numbers uptil N
	vector<bool> prime(n+1,true);
	prime[0] = false;
	prime[1] = false;
	for(int i = 2 ; i*i < n ; i++){
		if (prime[i] == true){
			for(int j = 2 ; i*j < n ; j++){
				prime[i*j] = false;
			}
		}
	}
	vector<int> prime_numbers;
	for(int i = start ; i <= n ; i++){
		if(prime[i] == true)
			prime_numbers.push_back(i);
	}
	return prime_numbers;
}
int main(){
	vector<int> prime_no = generate_prime(15,5);
	for(int i = 0 ; i < prime_no.size() ; i++){
		cout<<prime_no[i]<<endl;
	}
}
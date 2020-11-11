#include <bits/stdc++.h>
using namespace std;
vector<string> permutations;
void permute( string s, int start , int end){
	if(start == end){
		permutations.push_back(s);
	}
	for(int i = start ; i <= end ; i++){
		swap(s[start],s[i]);
		permute(s,start+1,end);
		swap(s[start],s[i]);
	}

}
bool compare(string s1,string s2){
	return s1 > s2;
}

int main(){
	permute("abcd",0,3);
	sort(permutations.begin(),permutations.end(),compare);
	for(int i = 0 ; i < permutations.size() ; i++){
		cout<<permutations[i]<<endl;
	}

}
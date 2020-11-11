//longest common substring
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(100,vector<int> (100,-1));
int lcs(string s1, string s2, int m , int n){
	if(n == 0 || m == 0 )
		return 0;
	if(memo[m-1][n-1] == -1)
	{
		if(s1[m-1] == s2[n-1])
			memo[m-1][n-1] = 1+lcs(s1,s2,m-1,n-1);
		else
			memo[m-1][n-1] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	}
	return memo[m-1][n-1];
}
int lcs_repeating(string s1, string s2, int m , int n){
	if(n == 0 || m == 0 )
		return 0;
	if(memo[m-1][n-1] == -1)
	{
		if(s1[m-1] == s2[n-1] && m != n)
			memo[m-1][n-1] = 1+lcs(s1,s2,m-1,n-1);
		else
			memo[m-1][n-1] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	}
	return memo[m-1][n-1];
}
int main(){

	cout<<"LCS OF GEEK AND EFGEK IS "<<lcs("geek","efgek",4,5)<<endl;
	string str = "helloh",str2=str;
	reverse(str.begin(),str.end());
	cout<<"PALNDROMIC LCS OF helloh IS "<<lcs(str,str2,str.length(),str2.length())<<endl;
	cout<<"LONGEST REPEATING SUBSEQUENCE OF AABBABBA "<<lcs_repeating("AABBABBA","AABBABBA",8,8)<<endl;
	//hllh
}
#include <bits/stdc++.h>
using namespace std;
/*You are climbing a stair case and it takes A steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
//https://www.interviewbit.com/problems/stairs/

int climb(int n,vector<int> &memo){
    if(n<0)
        return 0;
    if(n == 0)
        return 1;
    if(memo[n-1] == -1)
        memo[n-1] = climb(n-1,memo)+climb(n-2,memo);
    return memo[n-1];
}
int main() {
	int A = 15;
    vector<int> memo(A,-1);

    cout<<climb(A,memo);
}

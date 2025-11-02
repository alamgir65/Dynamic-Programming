// problem analysis 
// array size ->    4
// cost ->          10 4 7 5
// weight ->        4 3 2 5
// max_capacity ->  8
// complexity  ->   O(2^N)



#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
vector<int> cost(N);
vector<int> weight(N);
int dp[N][N];

int knapsack(int n, int max_capacity){

    if(n < 1 || max_capacity <= 0) return 0;

    if(dp[n][max_capacity] != -1) return dp[n][max_capacity];

    if(max_capacity >= weight[n]){
        int op1 = knapsack(n-1, max_capacity - weight[n]) + cost[n]; // item nibo
        int op2 = knapsack(n-1, max_capacity); // item nibo nah
        return dp[n][max_capacity] = max(op1, op2);
    }

    return dp[n][max_capacity] = knapsack(n-1,max_capacity);

}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=1;i<=n;i++) cin>>weight[i];
    int max_capacity; cin>> max_capacity;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=max_capacity;j++) dp[i][j]=-1; 
    }

    knapsack(n,max_capacity);
    cout<<"Max possible value : " <<dp[n][max_capacity] << endl;

    return 0;
}
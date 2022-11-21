#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wei[], int n, int c, int index, vector <vector <int>> &dp){
    if(index==0){
        if(c>=wei[0]){
            return val[0];
        }
        else{
            return 0;
        }
    }
    if (dp[index][c]!=-1)
    {
        return dp[index][c];
    }
    int pick;
    int notpick;
    notpick=knapsack(val, wei, n, c, index-1,dp);
    if(c>=wei[index]){
        pick=knapsack(val, wei, n, c-wei[index], index-1,dp)+val[index];
    }
    return dp[index][c]=max(pick, notpick);
}

int main(){
    int n;
    int c;
    cin>>n>>c;
    int val[n];
    int wei[n];
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    for(int i=0; i<n; i++){
        cin>>wei[i];
    }
    vector <vector <int>> dp(n,vector <int> (c+1));
    for (int j=wei[0];j<=c;j++)
    {
        dp[0][j]=val[0];
    }
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<=c;j++)
        {
            dp[i][j]=dp[i-1][j];
            if (j>=wei[i])
            {
                dp[i][j]=max(dp[i][j],val[i]+dp[i-1][j-wei[i]]);
            }
        }
    }
    cout<<dp[n-1][c];
    //cout<<knapsack(val,wei,n,c, n-1,dp)<<"\n";
}
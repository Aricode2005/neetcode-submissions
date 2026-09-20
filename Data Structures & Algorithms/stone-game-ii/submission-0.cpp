class Solution {
public:
    int solve(int i,int m,int n,vector<int>&suff,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(i+2*m>=n){
            return suff[i];
        }
        if(dp[i][m]!=-1){
            return dp[i][m];
        }
        int maxi=0;
        for(int x=1;x<=2*m;x++){
            int opp=solve(i+x,max(m,x),n,suff,dp);
            maxi=max(maxi,suff[i]-opp);
        }
        return dp[i][m]=maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>suff(n,0);
        suff[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=piles[i]+suff[i+1];
        }

        return solve(0,1,n,suff,dp);
    }
};
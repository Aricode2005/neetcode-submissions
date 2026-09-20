class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,-1e9);
        dp[n-1]=stoneValue[n-1];
        vector<int>suff(n,0);
        suff[n-1]=stoneValue[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+stoneValue[i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=3;j++){
                if(i+j>=n){
                    dp[i]=max(dp[i],suff[i]);
                }else{
                    dp[i]=max(dp[i],suff[i]-dp[i+j]);
                }
            }
        }
        int a=dp[0];
        int b=suff[0]-dp[0];
        if(a>b){
            return "Alice";
        }
        else if(a==b){
            return "Tie";
        }else{
            return "Bob";
        }
    }
};
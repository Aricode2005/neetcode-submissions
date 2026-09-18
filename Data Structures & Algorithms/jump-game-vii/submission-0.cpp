class Solution {
public:
    bool canReach(string s, int p, int q) {
        int n = s.size();
        if (s[n - 1] == '1') {
            return false;
        }
        vector<bool> dp(n, false);
        dp[0] = true;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(i>=p && dp[i-p]){
                cnt++;
            }
            if(i>q && dp[i-q-1]){
                cnt--;
            }
            if(cnt>0 && s[i]=='0'){
                dp[i]=true;
            }
        }
        return dp[n-1];       
        
    }
};
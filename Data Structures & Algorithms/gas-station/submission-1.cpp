class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>b(n,0);
        for(int i=0;i<n;i++){
           b[i]=gas[i]-cost[i];
        }
        int sum=0;
        int maxi=INT_MIN;
        int mx=-1;
        for(int i=0;i<n;i++){
            sum+=b[i];
        }
        if(sum<0){
            return -1;
        }
        int total=0;
        int idx=0;
        for(int i=0;i<n;i++){
            total+=b[i];
            if(total<0){
                total=0;
                idx=i+1;
            }
        }
        return idx;

    }
};

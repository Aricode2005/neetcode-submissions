class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int curr=0;
        int far=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            far=max(far,i+nums[i]);
            if(curr==i){
                jumps++;
                curr=max(curr,far);
            }
        }
        return jumps;
    }
};

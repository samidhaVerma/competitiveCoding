class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localMax, globalMax;
        localMax = nums[0];
        globalMax = localMax;
        
        for(int i = 1; i < nums.size(); i++){
            localMax = max(localMax + nums[i], nums[i]);
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
    }
};
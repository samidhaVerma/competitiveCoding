class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZero = 0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[k] = nums[i];
                k++;
            }
            else
                countZero++;
        }
        
        for(int j = 0; j < countZero; j++){
            nums[nums.size()-1-j] = 0;
        }
    }
};
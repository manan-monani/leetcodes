class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // herw we are implementing the kadane's algo fir finding the maximum subarray sum .
        int maxsub = nums[0] , cursum=0;
        for(int num:nums){
        if (cursum<0) cursum=0;
        
        cursum += num;
        maxsub = max(maxsub,cursum);}
        return maxsub;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int maxcount=1, currcount=1;

        //  so now in this for loop basically we have to write 3 cases or conditions for checking , 
        // 1. that is next number is duplicate
        // 2. that is the number is consicutive.
        // 3. number is not consicutive . 

        for(int i =1;i<nums.size();i++){
            
            if(nums[i]==nums[i-1]) continue;

            if(nums[i] == nums[i-1]+1){
                currcount++;
            }

            else{
                maxcount = max(maxcount , currcount);
                currcount = 1;
            }
        }
        return (maxcount = max(maxcount , currcount));
        }
    };
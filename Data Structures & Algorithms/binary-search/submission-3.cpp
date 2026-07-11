class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find the first element that is greater than or equal to target
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        // Check if the target was actually found in the vector
        if (it != nums.end() && *it == target) {
            // Return the index by calculating the distance from the beginning
            return it-nums.begin(); 
        }
        
        // Target is not present in the vector
        return -1;
    }
};
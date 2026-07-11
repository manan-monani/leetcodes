class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; // Stores {number : frequency}
        vector<int> res;
        int threshold = nums.size() / 3;

        // Step 1: Count everything in a single pass
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Check which numbers beat the threshold
        for (auto const& pair : counts) {
            int num = pair.first;
            int count = pair.second;
            
            if (count > threshold) {
                res.push_back(num);
            }
        }
        
        return res;
    }
};

// Hash Map
// Intuition
// We can avoid repeated counting by using a hash map to store the frequency of each element as we iterate through the array. We track the element with the maximum count seen so far. Once any element's count exceeds n/2, it must be the majority element.

// Algorithm
// Create a hash map to store element frequencies.
// Initialize res and maxCount to track the current best candidate.
// For each element num:
// Increment its count in the hash map.
// If its count exceeds maxCount, update res = num and maxCount = count[num].
// Return res.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0, maxCount = 0;

        for (int num : nums) {
            count[num]++;
            if (count[num] > maxCount) {
                res = num;
                maxCount = count[num];
            }
        }
        return res;
    }
};
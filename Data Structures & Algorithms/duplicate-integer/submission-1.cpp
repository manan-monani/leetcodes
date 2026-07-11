class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setofnumbers;

        for(int num : nums){
            if (setofnumbers.count(num)) return true;
            setofnumbers.insert(num);

        }
        return false;
    }
};
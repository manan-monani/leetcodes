class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map structure: { Sorted_Word : List_of_Original_Words }
        unordered_map<string, vector<string>> groups;
        
        for (string s : strs) {
            string key = s; 
            sort(key.begin(), key.end()); // "tea" becomes "aet"
            
            groups[key].push_back(s);     // Group "tea" under "aet"
        }
        
        // Collect all the grouped vectors into our final result
        vector<vector<string>> result;
        for (auto const& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;

        unordered_map<char,int> sseen;
        unordered_map<char,int> tseen;

         for (int i = 0; i < s.length(); i++) {
            sseen[s[i]]++;
            tseen[t[i]]++;
        }
        return sseen == tseen;
    }
};

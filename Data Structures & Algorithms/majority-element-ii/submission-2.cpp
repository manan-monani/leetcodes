// 4. Boyer-Moore Voting Algorithm
// Intuition
// The Boyer-Moore algorithm extends to finding up to two majority elements. We maintain two candidates with their counts. When we see a candidate, we increment its count. When we see a different element and both counts are positive, we decrement both. When a count is 0, we replace that candidate. After one pass, we verify the candidates by counting their actual occurrences.

// Algorithm
// Initialize two candidates num1, num2 and their counts cnt1, cnt2 to 0.
// For each element:
// If it matches num1, increment cnt1.
// Else if it matches num2, increment cnt2.
// Else if cnt1 == 0, set num1 = num and cnt1 = 1.
// Else if cnt2 == 0, set num2 = num and cnt2 = 1.
// Else decrement both counts.
// Count actual occurrences of both candidates.
// Add candidates with count greater than n / 3 to the result.
// Return the result.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

        for (int num : nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == num1) cnt1++;
            else if (num == num2) cnt2++;
        }

        vector<int> res;
        if (cnt1 > n / 3) res.push_back(num1);
        if (cnt2 > n / 3) res.push_back(num2);

        return res;
    }
};

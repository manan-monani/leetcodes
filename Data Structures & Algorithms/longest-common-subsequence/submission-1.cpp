class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // in this first of all write that what is the syntax so we have declred that it is a vector of vector so it will basically become an array so in that we have to do the following thing .
        //  then in the name and size we have to define for the first vector and the vector inside that 
        // dp (text1.size +1 , vector<int> text2.size +1) in this way we can initialize the dp matrix first , if you initialization is good then you are ready to go . 

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

        //  now in the DP approach there is nothing too much of the complex thing . 
        //  you just have to run the two loops and you are ready to go , 
        //  firstly just imagine the whole thing and the scenario in your brain and you are ready to go . 
        //  so write the exact logic that you are taking the steps for do the task dynamically , 
        //  express the whole thing in the words and then you can easily write the logic for the thing 
        //  there is nothing hard into it . 
        //  it is very easy for you , and you can easily do it , it is just a cup of tea for you .
        //  so here we are using the bottom up app , so we have to go back wards to the beginning of the string so write the logic of the loop acording to that . 
        //  so both the loops will go backwards simply there is nothing hard into that . is it clear ?
        


        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        // and remember that in the dp if you are using the backward of the bottom up logic then we have to always return the very first cell of the metrix 
        //  which is here dp[0][0] , so we always have to write the logic that the final result will store into this 
        //  and return that thing only . 
        return dp[0][0];
    }
};
//  this problem is the similar to the brust the balloons problems .
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0;
        int prevend=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start>=prevend){
                prevend = end;
            }
            else{
                res++;
                prevend = min(end,prevend);
            }
        }
        return res;
        
    }
};

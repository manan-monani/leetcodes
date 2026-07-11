/// for this problem solution using the two poniter is most efficient this is the best ex of the 2 pointers 
//  we just have to do l++ and the r-- , always remember that to do the l++ and r-- ;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxarea=0;

        while(l<r){
            int area = min(heights[l],heights[r])*(r-l);
            maxarea = max(maxarea , area);

            if (heights[l]<=heights[r]){
                l++;
            }
                else r--;
        }
        return maxarea;
    }
};

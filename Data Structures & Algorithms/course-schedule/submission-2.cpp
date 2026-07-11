//  ok so we have to form the cycle of the graph , if the cycle is not exists then we can complete the courses other wise not .
//  basically the cycle should not be formed.

class Solution {
    unordered_map<int,vector<int>> preMap;
    unordered_set<int> visiting;


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses;i++){
            preMap[i] = {};
        }

        for(const auto& prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int c=0; c<numCourses; c++ ){
            if(!dfs(c)) return false;
        }
        return true;
    }

    bool dfs(int crs){
        if (visiting.count(crs)) return false; // this means that the cycle detected so we have to cancle from there only .

        if(preMap[crs].empty()) return true;

        visiting.insert(crs);
        for(int pre:preMap[crs]){
            if(!dfs(pre)) return false;
        }

        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    void uniqueCombinations(int i,int n,vector<int>& candidates, int target,vector<int> &temp) {
        if(i==n) {
            if(target == 0) {
                res.push_back(temp);
            }
            return;
        }
        if(target >= candidates[i]){
            temp.push_back(candidates[i]);
            uniqueCombinations(i,n,candidates,target-candidates[i],temp);
            temp.pop_back();
        } 
         uniqueCombinations(i+1,n,candidates,target,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        uniqueCombinations(0,candidates.size(),candidates,target,temp);
        
        return res;
    }
};
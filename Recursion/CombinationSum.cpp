class Solution {
public:
    void generateCombinations(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,int i,int sum,int target){
        if(sum>target || i == nums.size()){
            return;
        }

        if(sum==target){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        sum+=nums[i];
        generateCombinations(nums,ans,curr,i,sum,target);
        curr.pop_back();
        sum-=nums[i];

        
        generateCombinations(nums,ans,curr,i+1,sum,target);
       

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        generateCombinations(candidates,ans,curr,0,0,target);
        return ans;
    }
};
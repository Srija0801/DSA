class Solution {
public:
    void generateCombinations(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,int index,int sum,int target){
        if(sum == target){
           ans.push_back(curr);
           return;
        }
      for(int i=index;i<nums.size();i++){
          if(i>index && nums[i]==nums[i-1]){
            continue;
          }
          if(sum>target){
            break;
          }
          
          curr.push_back(nums[i]);
          sum+=nums[i];
          generateCombinations(nums,ans,curr,i+1,sum,target);
          curr.pop_back();
          sum-=nums[i];
      }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int>curr;
         generateCombinations(candidates,ans,curr,0,0,target);
          return ans; 
    }
};
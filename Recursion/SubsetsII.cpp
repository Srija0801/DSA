class Solution {
public:
    void generateSubset(vector<vector<int>>& ans,vector<int>& curr,vector<int>& nums,int index){
        ans.push_back(curr);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }

            curr.push_back(nums[i]);
            generateSubset(ans,curr,nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>>ans;
       vector<int>curr;
       generateSubset(ans,curr,nums,0); 
       return ans;
    }
};
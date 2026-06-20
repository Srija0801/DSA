class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>summap;
        int index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(summap.find(rem)!=summap.end()){
                return {summap[rem],i};
            }
            summap[nums[i]] = i;
        }
        return {};
    }
};
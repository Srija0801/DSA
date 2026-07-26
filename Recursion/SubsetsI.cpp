class Solution {
public:
    void generate(int index, vector<int>& nums,
                  vector<int>& curr,
                  vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        generate(index + 1, nums, curr, ans);
        curr.pop_back();

        generate(index + 1, nums, curr, ans);
    }

    vector<vector<int>> subsetSums(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(0, nums, curr, ans);

        return ans;
    }
};
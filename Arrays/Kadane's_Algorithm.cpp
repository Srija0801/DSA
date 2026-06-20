class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int sum=0;
        int maxSum=nums[0];
        int n=nums.size();
        for(i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
    }
};
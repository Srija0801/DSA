class Solution {
public:
    bool SplitArrayHelper(vector<int>& nums, int maxSum,int k){
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxSum){
                count++;
                sum=nums[i];
            }
        }
        if(count<=k){
            return true;
        }else{
            return false;
        }
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            bool isMaxSub=SplitArrayHelper(nums,mid,k);
            if(isMaxSub){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
class Solution {
public:
    bool CalculateDis(vector<int> &nums, int dis,int k){
        int last=nums[0];
        int Countcows=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last>=dis){
                Countcows++;
                last=nums[i];
            }else{
                continue;
            }
        }

        if(Countcows>=k){
            return true;
        }else{
            return false;
        }
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int low=1;
        int high=nums.back()-nums.front();
        while(low<=high){
            int mid=(low+high)/2;
            bool isPossible=CalculateDis(nums,mid,k);
            if(isPossible){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};
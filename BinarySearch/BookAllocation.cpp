class Solution {
public:
    bool Calculatebooks(vector<int> &nums, int books,int m){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>books){
                count++;
                sum=nums[i];
            }
        }
        if(count<=m){
            return true;
        }else{
            return false;
        }
    }
    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size()) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
             high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            bool isAllocated=Calculatebooks(nums,mid,m);
            if(isAllocated){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
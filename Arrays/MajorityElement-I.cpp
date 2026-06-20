class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int current=nums[i];
                mpr[current]++;
                if(mpr[current]>n/2){
                    return current;
                }
        }
        return -1;
    }
};
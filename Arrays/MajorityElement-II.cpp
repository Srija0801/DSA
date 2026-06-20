class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int> majority;
       int n=nums.size();

       for(int i=0;i<n;i++){
         if(majority.find(nums[i])!=majority.end()){
            majority[nums[i]]++;
         }
         else{
           majority[nums[i]]=1;  
         }
       }
       
       vector<int> ans;
       for(auto it:majority){
        if(it.second > n/3){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};
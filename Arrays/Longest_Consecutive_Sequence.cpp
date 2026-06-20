class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n=nums.size();
        int maxCount=1;
        if(n==0){
            return 0;
        }
        for(int num:st){
            if(st.find(num-1)==st.end()){
                  int count=1;
                  int index=num;
                while(st.find(index+1)!=st.end()){
                    count++;
                    index=index+1;
                }
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};
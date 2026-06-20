class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {

        unordered_map<int,int> mpp;

        int xr = 0;
        int count = 0;

        mpp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {

            xr ^= nums[i];

            int rem = xr ^ k;

            if(mpp.find(rem) != mpp.end()) {
                count += mpp[rem];
            }

            mpp[xr]++;
        }

        return count;
    }
};
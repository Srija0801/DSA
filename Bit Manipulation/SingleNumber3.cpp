class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xr = 0;

        for (int num : nums)
            xr ^= num;

        int mask = xr & (-xr);

        int first = 0;
        int second = 0;

        for (int num : nums) {

            if (num & mask)
                first ^= num;
            else
                second ^= num;
        }

        return {first, second};
    }
};
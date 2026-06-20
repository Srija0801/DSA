class Solution {
public:

    long long merge(vector<int>& nums, int low, int mid, int high) {

        int left = low;
        int right = mid + 1;

        vector<int> temp;
        long long count = 0;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                count += (mid - left + 1);
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;

        long long count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);

        return count;
    }

    long long int numberOfInversions(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};
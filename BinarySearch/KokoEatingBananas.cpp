class Solution {
public:
    long long CalculateHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (long long)ceil((double)piles[i] / k);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = INT_MIN;
        for (int x : piles) {
            maxPile = max(maxPile, x);
        }

        int low = 1;
        int high = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalhours = CalculateHours(piles, mid);
            if (totalhours <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        for (int i = 31; i >= 0; i--) {

            if ((dvs << i) <= dvd) {

                dvd -= (dvs << i);
                ans += (1LL << i);

            }
        }

        if (negative)
            ans = -ans;

        return (int)ans;
    }
};
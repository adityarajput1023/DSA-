class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        bool negative = (a < 0) != (b < 0);

        a = abs(a);
        b = abs(b);

        long long count = 0;

        while (a >= b) {

            long long temp = b;
            long long c = 1;

            while (a >= temp + temp) {
                temp = temp + temp;
                c = c + c;
            }

            a = a - temp;
            count = count + c;
        }

        if (negative)
            count = -count;

        return count;
    }
};
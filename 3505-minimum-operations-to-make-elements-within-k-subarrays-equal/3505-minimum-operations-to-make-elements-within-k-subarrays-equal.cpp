class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        vector<long long> cost;

        auto balance = [&]() {
            while (left.size() > (x + 1) / 2) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                right.insert(v);
                sumL -= v;
                sumR += v;
            }

            while (left.size() < (x + 1) / 2 && !right.empty()) {
                int v = *right.begin();
                right.erase(right.find(v));
                left.insert(v);
                sumR -= v;
                sumL += v;
            }
        };

        for (int i = 0; i < n; i++) {
            int v = nums[i];

            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }

            if (i >= x) {
                int old = nums[i - x];

                if (left.find(old) != left.end()) {
                    left.erase(left.find(old));
                    sumL -= old;
                } else {
                    right.erase(right.find(old));
                    sumR -= old;
                }
            }

            balance();

            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long operations =
                    median * left.size() - sumL +
                    sumR - median * right.size();

                cost.push_back(operations);
            }
        }

        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                        prev[i - x] + cost[i - x]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
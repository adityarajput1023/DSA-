class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            int prevMax = 0;
            bool ok = true;

            for (int s = 0; s < n; s += k) {
                int mn = nums[s];
                int mx = nums[s];
                int desc = 0;

                for (int i = s; i < s + k; i++) {
                    int j = (i + 1 == s + k) ? s : i + 1;

                    if (nums[i] > nums[j])
                        desc++;

                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (desc > 1 || (s > 0 && prevMax > mn)) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};
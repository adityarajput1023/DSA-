class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int left, int right) {
        if (left == 0 && right == 0) {
            int count = 0;

            for (char c : s) {
                if (c == '(')
                    count++;
                else if (c == ')') {
                    count--;
                    if (count < 0)
                        return;
                }
            }

            if (count == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Skip duplicate removals
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (left > 0 && s[i] == '(') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, left - 1, right);
            }

            // Remove ')'
            if (right > 0 && s[i] == ')') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, left, right - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        // Find how many '(' and ')' need to be removed
        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left, right);

        return ans;
    }
};
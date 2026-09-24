class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        int i = s.size() - 2;

        // 1. Find first decreasing element from right
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        // No greater permutation possible
        if (i < 0) return -1;

        // 2. Find just greater element than s[i]
        int j = s.size() - 1;

        while (s[j] <= s[i]) {
            j--;
        }

        // 3. Swap
        swap(s[i], s[j]);

        // 4. Reverse the remaining part
        reverse(s.begin() + i + 1, s.end());

        // Convert to number
        long long ans = stoll(s);

        if (ans > INT_MAX) return -1;

        return (int)ans;
    }
};
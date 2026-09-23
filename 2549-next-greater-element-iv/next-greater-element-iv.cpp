class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        // first: elements waiting for their 1st greater
        // second: elements waiting for their 2nd greater
        stack<int> first;
        stack<int> second;

        for (int i = 0; i < n; i++) {

            vector<int> temp;

            // Find second greater
            while (!second.empty() && nums[second.top()] < nums[i]) {
                ans[second.top()] = nums[i];
                second.pop();
            }

            // Find first greater
            while (!first.empty() && nums[first.top()] < nums[i]) {
                temp.push_back(first.top());
                first.pop();
            }

            // Move elements from first → second
            for (int j = temp.size() - 1; j >= 0; j--) {
                second.push(temp[j]);
            }

            // Current element is now waiting for its first greater
            first.push(i);
        }

        return ans;
    }
};
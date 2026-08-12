class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;

        for (int i = idx; i < nums.size(); i++) {

            if (s.find(nums[i]) != s.end())
                continue;

            s.insert(nums[i]);

            swap(nums[idx], nums[i]);

            getPerms(nums, idx + 1, ans);

            swap(nums[idx], nums[i]);   // Backtracking
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        getPerms(nums, 0, ans);

        return ans;
    }
};
class Solution {
public:

    set<vector<int>> s;

    void getAllCombinations(vector<int> &arr, int idx, int tar,
                            vector<vector<int>> &ans,
                            vector<int> &combine) {

        if (idx == arr.size() || tar < 0) {
            return;
        }

        if (tar == 0) {
            if (s.find(combine) == s.end()) {
                ans.push_back(combine);
                s.insert(combine);
            }
            return;
        }

        // Single
        combine.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combine);

        // Multiple
        getAllCombinations(arr, idx, tar - arr[idx], ans, combine);

        combine.pop_back();

        // Exclude
        getAllCombinations(arr, idx + 1, tar, ans, combine);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combine;

        getAllCombinations(arr, 0, target, ans, combine);

        return ans;
    }
};
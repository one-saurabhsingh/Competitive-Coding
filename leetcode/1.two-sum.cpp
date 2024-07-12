/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        for (int i = 0; i < v.size(); i++)
        {
            if (ump.find(k - v[i]) != ump.end())
            {
                return {i, ump[k - v[i]]};
            }
            ump[v[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end


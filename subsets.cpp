class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> set;
        recursive(0, set, result, nums);
        
        return result;
    }

    void recursive(int start, vector<int>& set, vector<vector<int>>& result, vector<int>& nums)
    {
        result.push_back(set);
        for(int i=start;i<nums.size();i++)
        {
            set.push_back(nums[i]);
            recursive(i+1,set,result, nums);
            set.pop_back();
        }
    }
};
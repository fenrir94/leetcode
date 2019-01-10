/*
*  2019-01-10
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
           
        int sum;
        
        if(nums.size() < 3) return result;
        
        for(int j=0; j < nums.size()-2;)
        {
            int left = nums[j];
            int i = j+1;
            int range = nums.size()-1;
            
            while( i < range)
            {
                int right = nums[range];
                int mid = nums[i];
                
                sum = left+mid+right;
                
                if(sum > 0) {
                    range--;
                }
                else if(sum < 0)
                {
                    i++;
                }
                else
                {
                    vector<int> sub;
                    sub.push_back(left);
                    sub.push_back(mid);
                    sub.push_back(right);
                    result.push_back(sub);
                    while(i < range && nums[range] == right) {
                        range--;
                    }
                    while(i < range && nums[i] == mid)
                    {
                        i++;
                    }
                }
            }
            while( j < nums.size()-2 && left == nums[j])
            {
                j++;
            }
        }
        return result;
    }
};

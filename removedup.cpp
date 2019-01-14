/*
*  2019-01-14
*  No.26 Remove Duplicates from Sorted Array
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return nums.size();
        }
        vector<int>::iterator inums = nums.begin();
        while(inums+1 < nums.end())
        {
            if(*inums == *(inums+1))
            {
                nums.erase(inums+1);
            }
            else
            {
                inums++;
            }
        }
        return nums.size();
    }
};

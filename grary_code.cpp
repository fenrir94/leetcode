/*
*
* 2019-01-23
*
*/


class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2,n);
        vector<int> result;
        result.push_back(0);
        for(int i=1; i<= n;++i)
        {
            int max = pow(2,i-1);
            for(int j = max; j>0;--j )
            {
                result.push_back(result[j-1]+max);
            }       
        }      
        return result;
    }
};

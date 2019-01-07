/*
* 2019-01-07
* 
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator last = nums.end();
        
        if(first == last) return;
        vector<int>::iterator i = last;
        i--;
        if(first == i) return;
        
        while(true){
            vector<int>::iterator i1,i2;
            i1 = i;
            i--;
            if(*i<*i1){
                i2 = last;
                i2--;
                while(!(*i<*i2))
                {
                    i2--;   
                }
                std::iter_swap(i,i2);
                std::reverse(i1,last);
                return;
            }
            if(i==first){
                std::reverse(first, last);
                return;
            }
        } 
    }
};
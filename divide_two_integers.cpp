/*
*  2019-01-10
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long result = (long)dividend / (long)divisor;
        if(result > INT_MAX || result < INT_MIN) return INT_MAX;
        return (int)result;
    }
};

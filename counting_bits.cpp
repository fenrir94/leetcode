/*
*	date: 2019-01-03
*	author: fenrir94
*
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        
        for(int i=0;i<=num;i++){
            if(i==0){
                v.push_back(0);
            }
            if(i==1){
                v.push_back(1);
            }
            if(i>1){
                if((i%2)==1)
                {
                    v.push_back(v[i/2]+1);    
                }
                else{
                    v.push_back(v[i/2]);
                }
                
            }
        }
        return v;
    }
};
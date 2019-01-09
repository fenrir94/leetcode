class Solution {
public:
    int uniqueLetterString(string S) {
        vector<char> subs;
        int count=0;
        for(int i=0; i< S.length();++i){
            subs.push_back(S[i]);
            count = count + calunique(subs, 0) + recursive(subs, i+1, S, 1);
            subs.pop_back();
        }
        return count;
    } 
    
    int recursive(vector<char>& subs, int next, string s, int precount)
    {
        int count = 0;
        if(next < s.length())
        {
            subs.push_back(s[next]);
            count = calunique(subs, precount);
            count = count + recursive(subs, next+1, s, count);
            subs.pop_back();
        }
        return count;
    }
    
    int calunique(vector<char>& subs, int precount){
        int count = precount;
        int temp = 0;
        for(int i=0; i< subs.size()-1;++i)
        {
            if(subs[i]==subs.back())
            {
                temp++;
                if(temp >= 2) return count;
            }
        }
        if(temp == 1)
        {
            count--;
            if(count < 0) count = 0;
            return count;
        }
        count++;
        return count;
    }
};

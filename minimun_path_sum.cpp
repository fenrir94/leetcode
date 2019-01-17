/*
* 2019-01-17
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> map(m, vector<int>(n,0));
        for(int i=0; i<m;++i)
        {
            for(int j=0; j< n;++j)
            {
                if(i==0 && j==0) map[i][j]=grid[i][j];
                else if(i == 0 && j !=0)
                {
                    map[i][j] = map[i][j-1]+grid[i][j];
                }
                else if(i !=0 && j==0)
                {
                    map[i][j] = map[i-1][j]+grid[i][j];
                }
                else{
                    map[i][j] = min(map[i][j-1],map[i-1][j])+grid[i][j];
                }
            }
        }
        return map[m-1][n-1];
        
    }
};

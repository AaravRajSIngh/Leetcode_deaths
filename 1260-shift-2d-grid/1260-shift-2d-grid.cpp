class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // vector<vector<int>> sol;

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> sol(n, vector<int>(m));
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        k%=arr.size();
        rotate(arr.begin(),arr.end()-k,arr.end());
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sol[i][j]=arr[f++];
            }
        }
        return sol;
    }
};
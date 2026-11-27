class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),sum=0;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i]=max(a[i],grid[i][j]);
                b[i]=max(b[i],grid[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=min(a[i],b[j])-grid[i][j];
            }
        }
        
        return sum;
    }
};
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxRowIndex = -1;
        int j = m - 1; // Start from the top-right corner
        
        for (int i = 0; i < n; ++i) {
            // Move left while we see '1'
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                maxRowIndex = i; // Update row index with the maximum number of 1s
            }
        }
        return maxRowIndex;
    }
};
class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> paths;
        string path;
        int n = mat.size();

        // If the starting cell is blocked, return empty list
        if (mat[0][0] == 0) return paths;

        // Create a visited matrix to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Call the backtracking function
        findPathsUtil(mat, n, 0, 0, visited, path, paths);

        // Sort the paths in lexicographical order
        sort(paths.begin(), paths.end());

        return paths;
    }

private:
    // Function to check if the cell is safe to visit
    bool isSafe(vector<vector<int>> &mat, int x, int y, vector<vector<bool>> &visited) {
        int n = mat.size();
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }

    // Backtracking function to find all paths
    void findPathsUtil(vector<vector<int>> &mat, int n, int x, int y, vector<vector<bool>> &visited, string &path, vector<string> &paths) {

        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = true;

        // Try all 4 possible directions

        // Move Down (D)
        if (isSafe(mat, x + 1, y, visited)) {
            path.push_back('D');
            findPathsUtil(mat, n, x + 1, y, visited, path, paths);
            path.pop_back();
        }

        // Move Left (L)
        if (isSafe(mat, x, y - 1, visited)) {
            path.push_back('L');
            findPathsUtil(mat, n, x, y - 1, visited, path, paths);
            path.pop_back();
        }

        // Move Right (R)
        if (isSafe(mat, x, y + 1, visited)) {
            path.push_back('R');
            findPathsUtil(mat, n, x, y + 1, visited, path, paths);
            path.pop_back();
        }

        // Move Up (U)
        if (isSafe(mat, x - 1, y, visited)) {
            path.push_back('U');
            findPathsUtil(mat, n, x - 1, y, visited, path, paths);
            path.pop_back();
        }

        // Unmark the current cell (backtrack)
        visited[x][y] = false;
    }
};
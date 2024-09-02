// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        if (arr.empty()) return "-1";

        string prefix = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            int j = 0;

            while (j < prefix.size() && j < arr[i].size() && prefix[j] == arr[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);

            if (prefix.empty()) return "-1";
        }
        
        return prefix;
    }
};
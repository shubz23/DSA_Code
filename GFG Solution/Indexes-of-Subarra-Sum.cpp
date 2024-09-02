
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        int start = 0;
        long long current_sum = 0;
        
        for (int end = 0; end < n; ++end) {
            current_sum += arr[end];
            
            while (current_sum > s && start < end) {
                current_sum -= arr[start];
                ++start;
            }
            
            if (current_sum == s) {
                return {start + 1, end + 1}; // 1-based index
            }
        }
        
        return {-1};
    }
};
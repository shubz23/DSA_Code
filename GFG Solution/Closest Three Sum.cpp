// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        
        int closestSum = INT_MAX;
        int n = arr.size();

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];

                if (closestSum == INT_MAX || abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                } else if (abs(target - currentSum) == abs(target - closestSum)) {
                    closestSum = max(closestSum, currentSum);
                }

                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    return currentSum;
                }
            }
        }
        return closestSum;
    }
};
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        int totalSum = n * (n + 1) / 2;

        int arrSum = 0;
        for (int num : arr) {
            arrSum += num;
        }

        return totalSum - arrSum;
    }
};
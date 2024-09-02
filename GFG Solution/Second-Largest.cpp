class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int first_largest = -1, second_largest = -1;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > first_largest) {
                second_largest = first_largest;
                first_largest = arr[i];
            } else if (arr[i] > second_largest && arr[i] != first_largest) {
                second_largest = arr[i];
            }
        }
        
        return second_largest;
    }
};
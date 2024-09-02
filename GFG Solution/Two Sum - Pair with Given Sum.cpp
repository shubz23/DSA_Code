class Solution {
  public:

    bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        unordered_set<int> seen;
        
        for (int num : arr) {
            int complement = x - num;
            if (seen.find(complement) != seen.end()) {
                return true; 
            }
            seen.insert(num);
        }
        
        return false;
    }
};
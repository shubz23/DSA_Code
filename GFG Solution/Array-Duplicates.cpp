class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        unordered_map<long long int, int> count;
        vector<int> duplicates;

        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        for (auto& pair : count) {
            if (pair.second > 1) {
                duplicates.push_back(pair.first);
            }
        }

        if (duplicates.empty()) {
            return {-1};
        } else {
            sort(duplicates.begin(), duplicates.end());
            return duplicates;
        }
    }

};
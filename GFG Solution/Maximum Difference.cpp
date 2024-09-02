class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
    vector<int> ls(n, 0), rs(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ls[i] = arr[s.top()];
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    int maxDiff = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            rs[i] = arr[s.top()];
        }
        maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        s.push(i);
    }

    return maxDiff;
    }
};
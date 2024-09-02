class Solution {
  public:
  void merge(vector<pair<int, int>>& arr, vector<int>& count, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;       
        int j = mid + 1;    
        int k = 0;          
        int rightCounter = 0; 

        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                count[arr[i].second] += rightCounter;
                temp[k++] = arr[i++];
            } else {
                rightCounter++;
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            count[arr[i].second] += rightCounter;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int i = left; i <= right; ++i) {
            arr[i] = temp[i - left];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }

    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<pair<int, int>> arrWithIndex(n);
        for (int i = 0; i < n; ++i) {
            arrWithIndex[i] = {arr[i], i};
        }

        vector<int> count(n, 0);
        mergeSort(arrWithIndex, count, 0, n - 1);
        return count;
        
    }
};
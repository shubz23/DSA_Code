

class Solution{
    public:
    int merge(int arr[], int low, int mid, int high) {
        int temp[high - low + 1];
        int k = 0, i = low, j = mid + 1, inv = 0;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                inv += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int x = low; x <= high; x++) {
            arr[x] = temp[x - low];
        }

        return inv;
    }

    int mergeSort(int arr[], int low, int high) {
        if (low >= high) return 0;
        int inv = 0;
        int mid = low + (high - low) / 2;

        inv += mergeSort(arr, low, mid);
        inv += mergeSort(arr, mid + 1, high);
        inv += merge(arr, low, mid, high);

        return inv;
    }

    int inversionCount(int arr[], int N) {
        return mergeSort(arr, 0, N - 1);
    }

    int countPairs(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            arr[i] *= i;
        }
        return inversionCount(arr, n);
    }
};
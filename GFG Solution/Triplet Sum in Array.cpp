class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n);
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = A[i] + A[l] + A[r];
                if (sum == X)
                    return true;
                else if (sum < X)
                    ++l;
                else
                    --r;
            }
        }
        return false;
    }

};
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int l =0, r=n-1;
        long long int lmax = INT_MIN, rmax = INT_MIN;
        long long int result =0;
        while (l<r){
            lmax = max(lmax, static_cast<long long>(arr[l])); // `static_cast<long long>` ka use karke lmax ko update karna
            rmax = max(rmax, static_cast<long long>(arr[r]));
            result += (lmax<rmax) ? lmax-arr[l++] : rmax-arr[r--];
        }
        return result;
    }
};
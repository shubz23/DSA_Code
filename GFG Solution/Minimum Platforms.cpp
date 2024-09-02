class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
        sort(dep, dep + n);
        
        int i = 0, j = 0;
        int platforms_needed = 0, max_platforms = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            else {
                platforms_needed--;
                j++;
            }
            
            max_platforms = max(max_platforms, platforms_needed);
        }
        
        return max_platforms;
    }
};
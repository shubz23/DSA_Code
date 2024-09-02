class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        
        unordered_set<int> hashSet;
        
        for (int i = 0; i < N; i++) {
            hashSet.insert(arr[i]);
        }
        
        int longestStreak = 0;
        
        for (int i = 0; i < N; i++) {
            if (hashSet.find(arr[i] - 1) == hashSet.end()) {
                int currentNum = arr[i];
                int currentStreak = 1;
                
                while (hashSet.find(currentNum + 1) != hashSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
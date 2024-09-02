class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        if(arr1[0]>arr2[0]){
            return findUnion(arr2, arr1, m, n);
        }
        
        vector<int>res={arr1[0]};
        int i=1, j=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                if(res.back() != arr1[i]){
                    res.push_back(arr1[i]);
                }
                i++;
            }
            else{
                if(res.back() != arr2[j]){
                    res.push_back(arr2[j]);
                }
                j++;
                
            }
        }
        while(i<n){
            if(res.back()!=arr1[i]){
                res.push_back(arr1[i]);
            }
            i++;
        }
        while(j<m){
            if(res.back() != arr2[j]){
                res.push_back(arr2[j]);
            }
            j++;
        }
        
        return res;
    }
};
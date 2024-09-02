class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> result(n, -1); 
        stack<int> s; 
        
        for (int i = 0; i < n; ++i) {

            while (!s.empty() && arr[s.top()] < arr[i]) {
                result[s.top()] = arr[i]; 
                s.pop(); 
            }
            s.push(i);
            
        }
        
        return result;
    }
};
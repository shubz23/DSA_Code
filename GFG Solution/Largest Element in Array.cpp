
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max =0;
        for(int i=0; i< arr.size(); i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
        
    }
};
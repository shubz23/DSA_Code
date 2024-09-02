class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int count = 0;
        int ele = 0;
        
        for(int i=0; i< size; i++){
            if(count == 0){
                count=1;
                ele = a[i];
            }
            else if(a[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        int count1 = 0;
        for(int i=0; i< size; i++){
            if(a[i] == ele) 
            count1++;
        }
        if(count1 > (size / 2 )){
            return ele;
        }
        return -1;
    }
};
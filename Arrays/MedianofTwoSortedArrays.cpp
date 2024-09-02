class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(m<n) return findMedianSortedArrays(nums2,nums1);
        int l=0;
        int r=n;
        while(l<=r){
            int px=(r-l)/2+l;
            int py=(n+m+1)/2-px;
            
            int maxlx=(px==0)?INT_MIN:nums1[px-1];
            int minrx=(px==n)?INT_MAX:nums1[px];
            
            int maxly=(py==0)?INT_MIN:nums2[py-1];
            int minry=(py==m)?INT_MAX:nums2[py];
            
            if(maxlx<=minry && maxly<=minrx){
                if((n+m)%2==0){
                    return double(max(maxlx,maxly)+min(minrx,minry))/2.0;
                }else{
                    return double(max(maxlx,maxly));
                }
            }else if(maxlx>minry){
                r=px-1;
            }else{
                l=px+1;
            }
        }
        return 0.0;
        
    }
};
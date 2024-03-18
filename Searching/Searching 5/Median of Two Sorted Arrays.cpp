class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int c1=(nums1.size()+nums2.size())/2;
        int n=(nums1.size()+nums2.size());
        double v1=0,v2=0;
        int c2=(nums1.size()+nums2.size())/2-1;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(i+j==c1){
                    v1=nums1[i];
                }
                if(n%2==0 && i+j==c2){
                    v2=nums1[i];
                }
                i++;
            }
            else{
                if(i+j==c1){
                    v1=nums2[j];
                }
                if(n%2==0 && i+j==c2){
                    v2=nums2[j];
                }
                j++;
            }
        }
        while(i<nums1.size()){
            if(i+j==c1){
                v1=nums1[i];
            }
            if(n%2==0 && i+j==c2){
                v2=nums1[i];
            }
            i++;
        }
        while(j<nums2.size()){
            if(i+j==c1){
                v1=nums2[j];
            }
            if(n%2==0 && i+j==c2){
                v2=nums2[j];
            }
            j++;
        }
        if(n%2==0) return (v1+v2)/2;
        return v1;
    }
};

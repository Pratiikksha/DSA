class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int mid=0;
        while(l<=h){
            mid=(l+h)/2;
            int left=arr[mid]-mid-1;
            if( left>=k){
                h=mid-1;
            }
            else if(left <k){
                l=mid+1;
            }
        }
        return l+k;
    }
};
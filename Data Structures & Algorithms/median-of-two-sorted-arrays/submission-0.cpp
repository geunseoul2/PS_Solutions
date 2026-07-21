class Solution {
public:
//solution required
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;

        return (getKth(nums1, nums1.size(),nums2, nums2.size(), left, 0,0) + getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    }

    int getKth(vector<int>& a, int m, vector<int>& b, int n, int k, int aStart, int bStart) {
        if(m>n) return getKth(b,n,a,m,k,bStart,aStart);
        if(m==0) return b[bStart+k-1];
        if(k==1) return min(a[aStart],b[bStart]);

        int i = min(m,k/2);
        int j = min(n,k/2);

        if(a[aStart+i-1]>b[bStart+j-1]) return getKth(a,m,b,n-j,k-j,aStart,bStart+j);
        else return getKth(a,m-i,b,n,k-i,aStart+i,bStart);
    }
};

/*
To find the k-th smallest:

We compare the k/2-th element of each array.
The smaller one (and everything before it in that array) cannot be the k-th element,
because there are at least k/2 elements smaller than or equal to it.
So we discard that many elements from one array and reduce k accordingly.
We repeat this process, shrinking the problem each time.
*/

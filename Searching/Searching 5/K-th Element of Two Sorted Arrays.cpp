#include<bits/stdc++.h>

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){

    // Write your code here

    int n1 = n;
    int n2 = m;

    if (n1 > n2) return kthElement(arr2, arr1, n2, n1, k);

    int low = max(k - n2, 0); 
    int high = min(k, n1);
    int left = k;

    n = n1 + n2;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0 && mid1 <= n1) ? arr1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0 && mid2 <= n2) ? arr2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 >= 0 && mid1 < n1) ? arr1[mid1] : INT_MAX;
        int r2 = (mid2 >= 0 && mid2 < n2) ? arr2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0;
}

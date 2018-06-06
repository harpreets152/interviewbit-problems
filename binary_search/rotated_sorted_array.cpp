/*
Rotated Sorted Array Search
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0
*/

int binary(const vector <int> &a,int l,int r,int val){
        if(l>r) return -1;
        int mid=(l+r)/2;
        if(a[mid]==val) return mid;
        if(a[mid]<=a[r]){
            if(a[mid]<val && a[r]>=val) return binary(a,mid+1,r,val);
            return binary(a,l,mid-1,val);
        }
        if(a[mid]>=a[l]){
            if(a[mid]>val && a[l]<=val) return binary(a,l,mid-1,val);
            return binary(a,mid+1,r,val);
        }
    }
int Solution::search(const vector<int> &a, int b) {
    int p=binary(a,0,a.size()-1,b);
    return p;
}

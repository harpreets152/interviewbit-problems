/*

Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

*/


int search_row(vector <vector <int> > &a,int l,int r,int x){
    if(l>r) return -1;
    int mid=l+(r-l)/2;
    int n=a[mid].size()-1;
    if(n>=0){
        if(a[mid][0]<=x && a[mid][n]>=x) return mid;
        if(a[mid][0]<x && a[mid][n]<x) return search_row(a,mid+1,r,x);
        return search_row(a,l,mid-1,x);
    }
    return -1;
}
int search_val(vector <vector <int> > &a,int l,int r,int row,int x){
    if(l>r) return 0;
    int mid=l+(r-l)/2;
    if(a[row][mid]==x) return 1;
    if(a[row][mid]>x) return search_val(a,l,mid-1,row,x);
    return search_val(a,mid+1,r,row,x);
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &a, int b) {
    int row=search_row(a,0,a.size()-1,b);
    if(row!=-1) return search_val(a,0,a[row].size()-1,row,b);
    return 0;
}

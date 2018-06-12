/*

Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3

*/

int Solution::singleNumber(const vector<int> &a) {
    int i,x=0,n=a.size();
    for(i=0;i<n;i++){
        x=x^a[i];
    }
    return x;
}

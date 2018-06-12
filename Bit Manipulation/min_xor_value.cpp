/*

Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.
Examples : 
Input 
0 2 5 7 
Output 
2 (0 XOR 2) 
Input 
0 4 7 9 
Output 
3 (4 XOR 7)

Constraints: 
2 <= N <= 100 000 
0 <= A[i] <= 1 000 000 000

*/
//this is not the best solution to this.

int Solution::findMinXor(vector<int> &a) {
    int i,j,min,n=a.size();
    sort(a.begin(),a.end());
    min=a[0]^a[1];
    for(i=2;i<n;i++){
        if((a[i]^a[i-1])<min) min=a[i]^a[i-1]; 
    }
    return min;
}

//for best solution,try to implement this with trie(link->https://www.geeksforgeeks.org/minimum-xor-value-pair/)

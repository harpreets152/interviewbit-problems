/*

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/

string Solution::longestPalindrome(string a) {
    string ans;
    if(a.length()==0 || a.length()==1) return a;
    int maxlen=1,l_index=0,r_index=0;
    int i,j,k,n=a.length();
    int curr=0,start=0,end=0;
    for(k=0;k<n;k++){
        i=k-1;
        j=k+1;
        while(i>=0 && j<n && a[i]==a[j]){
            if(maxlen<j-i+1){
                maxlen=j-i+1;
                l_index=i;
                r_index=j;
            }
            else if(maxlen==j-i+1 && i<l_index){
                l_index=i;
                r_index=j;
            }
            i--;
            j++;
        }
    }
    for(k=0;k<n-1;k++){
        i=k;
        j=k+1;
        while(i>=0 && j<n && a[i]==a[j]){
            if(maxlen<j-i+1){
                maxlen=j-i+1;
                l_index=i;
                r_index=j;
            }
            else if(maxlen==j-i+1 && i<l_index){
                l_index=i;
                r_index=j;
            }
            i--;
            j++;
        }
    }
    for(i=l_index;i<=r_index;i++) ans.push_back(a[i]);
    return ans;
}

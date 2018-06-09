/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

*/

int Solution::lengthOfLastWord(const string a) {
    int n=a.length();
    int i=0,j;
    int curr=0;
    while(i<n){
        if(a[i]==' '){
            i++;
            continue;
        } 
        if(((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')) && a[i-1]==' ') curr=1;
        else curr++;
        i++;
    }
    return curr;
}

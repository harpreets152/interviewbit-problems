/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int isalphanumeric(char a){
    if(a>='a' && a<='z') return 1;
    if(a>='A' && a<='Z') return 1;
    if(a>='0' && a<='9') return 1;
    return 0;
}
int upper(char c){
    return (c>='A' && c<='Z');
}
int Solution::isPalindrome(string a) {
    int n=a.length(),i,j;
    i=0;j=n-1;
    while(i<=j){
        if(isalphanumeric(a[i]) && isalphanumeric(a[j])){
            if(upper(a[i])) a[i]=a[i]+32;
            if(upper(a[j])) a[j]=a[j]+32;
            if(a[i]!=a[j]) return 0;
            i++;j--;
        }
        else if(!isalphanumeric(a[i]) && isalphanumeric(a[j])) i++;
        else if(isalphanumeric(a[i]) && !isalphanumeric(a[j])) j--;
        else {
            i++;
            j--;
        }
    }
    return 1;
}

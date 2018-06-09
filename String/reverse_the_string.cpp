/*

Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

void Solution::reverseWords(string &a) {
   int i,j,n=a.length();
   i=0;
   if(a.empty() || n==1) return;
   while(i<n && a[i]==' ') i++;
   a.erase(a.begin(),a.begin()+i);
   i=n-1;
   while(i>0 && a[i]==' ') i--;
   a.erase(a.begin()+i+1,a.end());
   reverse(a.begin(),a.end());
   i=0;
   while(i<a.length()){
        j=i;
        while(i<a.length() && a[i]!=' ') i++;
        int temp=i-1;
        while(j<=temp){
            swap(a[j],a[temp]);
            j++;
            temp--;
        }
        j=i;
        while(i<a.length() && a[i]==' ') i++;
        a.erase(a.begin()+j+1,a.begin()+i);
        i=j+1;
   }
}

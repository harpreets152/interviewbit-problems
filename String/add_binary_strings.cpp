/*

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

*/

string Solution::addBinary(string a, string b) {
    string ans;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int n1=a.length(),n2=b.length(),i,j,k;
    int carry=0;
    i=0;
    while(i<n1 || i<n2){
        if(i<n1) carry+=a[i]-'0';
        if(i<n2) carry+=b[i]-'0';
        int temp=carry%2+'0';
        ans.push_back(temp);
        carry=carry/2;
        i++;
    }
    if(carry!=0) ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

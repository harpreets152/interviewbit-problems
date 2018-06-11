/*

Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

*/

int compare(string temp,string ans){
    if(temp.size()==ans.size()) return ans<temp;
    if(temp.size()>ans.size()) return 1;
    return 0;
}
string mutiply_by_two(string a){
    int i,n=a.length(),carry=0;
    reverse(a.begin(),a.end());
    i=0;
    while(i<n){
        carry+=(a[i]-'0')*2;
        a[i]=carry%10+'0';
        carry/=10;
        i++;
    }
    if(carry) a.push_back(carry+'0');
    reverse(a.begin(),a.end());
    return a;
}
int Solution::power(string a) {
    int i,n=a.length();
    string ans,temp;
    i=0;
    while(i<n && a[i]=='0') i++;
    if(i==n) return 0;
    while(i<n){
        temp.push_back(a[i]);
        i++;
    }
    ans="2";
    //cout<<temp<<endl;
    //cout<<ans<<endl;
    while(compare(temp,ans)){
        ans=mutiply_by_two(ans);
       // cout<<ans<<endl;
    }
    if(temp==ans) return 1;
    return 0;
}

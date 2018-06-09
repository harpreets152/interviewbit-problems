/*

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

*/

string Solution::countAndSay(int n) {
    int i=1;
    if(n==0) return "";
    string ans,temp;
    ans.push_back('1');
    //cout<<ans<<endl;
    for(i=2;i<=n;i++){
        int j=1;
        while(j<=ans.length()){
            int count=1;
            while(j<ans.length() && ans[j]==ans[j-1]){
                count++;
                j++;
            }
            string p=to_string(count);
            temp=temp+p;
            temp.push_back(ans[j-1]);
            j++;
        }
        
        ans=temp;
        temp.erase(temp.begin(),temp.end());
     //   cout<<ans<<endl;
    }
    return ans;
}

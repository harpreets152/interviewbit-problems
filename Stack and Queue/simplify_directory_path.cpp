/*

Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

*/

string Solution::simplifyPath(string a) {
    if(a.empty()|| a.size()==1) return a;
    stack <char> s;
    string ans;
    int i,n=a.length();
    s.push(a[0]);
    
    for(i=1;i<n;i++){
        if(a[i]=='.' && a[i-1]=='.'){
            while(!s.empty() && s.top()=='/') s.pop();
            while(!s.empty() && s.top()!='/') s.pop();
            if(!s.empty() && s.top()=='/') s.pop();
        }
        else if(a[i]=='.' && a[i-1]=='/');
        else {
            if(a[i]=='/'){
                if(s.empty()) s.push(a[i]);
                else if(s.top()=='/');
                else s.push(a[i]);
            }
            else s.push(a[i]);
        }
    }
    if(!s.empty() && s.top()=='/' && s.size()>1) s.pop();
    if(s.empty()) s.push('/');
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

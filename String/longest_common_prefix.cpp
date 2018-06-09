/*

Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.

*/


string Solution::longestCommonPrefix(vector<string> &a) {
    int i,j;
    string ans;
    int min=INT_MAX;
    for(i=0;i<a.size();i++){
        if(a[i].length()<min) min=a[i].length();
    }
    if(a.size()==0 || min==0) return ans;
    for(i=0;i<min;i++){
        char c=a[0][i];
        for(j=1;j<a.size();j++){
            if(a[j][i]!=c) break;
        }
        if(j<a.size()) return ans;
        ans.push_back(c);
    }
    return ans;
}

/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

 Visit:->https://www.interviewbit.com/problems/letter-phone/

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

Seen this question in a real interview before

*/



void compute(vector <string> aux,int l,int r,vector <string> &ans,string &s){
    int i;
    if(l>r){
        ans.push_back(s);
        return;
    }
    for(i=0;i<aux[l].size();i++){
        s.push_back(aux[l][i]);
        compute(aux,l+1,r,ans,s);
        s.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector <string> temp[10];
    int i,n=A.length();
    temp[0].push_back("0");
    temp[1].push_back("1");
    temp[2].push_back("abc");
    temp[3].push_back("def");
    temp[4].push_back("ghi");
    temp[5].push_back("jkl");
    temp[6].push_back("mno");
    temp[7].push_back("pqrs");
    temp[8].push_back("tuv");
    temp[9].push_back("wxyz");
    vector <string> aux;
    for(i=0;i<n;i++){
        int p=A[i]-'0';
        aux.push_back(temp[p][0]);
    }
    vector <string> ans;
    string s;
    compute(aux,0,n-1,ans,s);
    return ans;
}

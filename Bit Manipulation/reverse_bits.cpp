/*

Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

*/

unsigned int Solution::reverse(unsigned int a) {
    unsigned int i,ans=0;
    for(i=0;i<32;i++){
        unsigned int bit=a&1;
        ans=ans|bit;
        ans=ans<<1;
        a=a>>1;
        cout<<ans<<endl;
        
    }
    return ans;
}

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ull unsigned long long
#define rep(a,b,i) for(int i=a;i<b;i++)
#define see(v,n)for(int i=0;i<n;i++){int x;cin>>x;v.pb(x);}
#define pb push_back
#define mx 1e18
#define my -1e18
#define endl "\n"
#define modp(a,b) (a%mod+b%mod)%mod
#define mods(a,b) (a%mod-b%mod)%mod
#define modd(a,b) (a%mod/b%mod)%mod
#define modm(a,b) ((a%mod)*(b%mod))%mod
#define bitcount(a) __builtin_popcount(a);
#define ordered_set  tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset  tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
long long mod=1e9+7;
void solve();

signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
    
    
    while(t--)
    { 
    
        solve();
        cout<<endl;
 
       
        
    }
}
void solve() 
{
    string s,s1;

    cin>>s>>s1;
    // ! Time complexity O(N) and Space Complexity O(N)

    s = s1+'#'+s;
    int n  = s.size();
    vector<int>dp(n+1,0);
    int i = 1;
    int len = 0;
    // * Here len is showing the dp[i-1] of string.
    while(i<s.size())  
    {
        if(s[i]==s[len])
        {
            len++;
            dp[i] = len;
            i++;
        }
        else
        {
            if(len>0)
            {
                len = dp[len-1];// ! We are going to len-1 until the len>0 and s[i]!=s[len]
            }
            else
            {
                dp[i] = 0;
                i++;
            }
        }
    }

    vector<int>ans;
    for(int i=s1.size()+1;i<n;i++)
    {
        if(dp[i]>=(int)s1.size())
        {
            ans.push_back(((i+1)-(s1.size()+1))-(s1.size()-1));
            // ! Here we are first subrating the size of pattern string +1 from the number to get the 0th distance index of the Big string
            // ! of the first string then we are subrating the size -1 of pattern string to get the starting index of pattern from the Big string
        }
    }
    if(ans.size()==0)
    {
        cout<<"Not Found";
        return;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
}
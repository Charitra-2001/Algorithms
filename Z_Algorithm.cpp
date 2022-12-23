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
    int l = 0;
    int r = 0;
    for(int i=1;i<s.size();i++)
    {
        if(i<=r)
        {
            dp[i] = min(r-i+1,dp[i-l]);// ! We are checking the minmum of range size from i beacuse we know that the elements of range are only equal to the prefix or checking the dp[i-l] means length of string from prefix from the ith index
        }
        while(i+dp[i]<n and s[dp[i]]==s[i+dp[i]])
        {
            dp[i]++;
        }
        if(i+dp[i]-1>r)
        {
            l = i;
            r = i+dp[i]-1;
        }
    }
    vector<int>ans;
    for(int i=s1.size();i<s.size();i++)
    {
        if(dp[i]>=s1.size())
        {
            ans.push_back(i-s1.size()); // ! As dp[i] will store the size of total matching substring i-dp[i] will provide the index after removing the size of pattern string
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
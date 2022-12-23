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
   int total = 0;
   int pow = 31;
   int p = 31;
   // ! First Find the Hashvalue of the second substring whose occurence has to be found take 31 as any prime number for use
   total = s1[0]-'a'+1;
   for(int i=1;i<s1.size();i++)
   {
        total+=((s1[i]-'a'+1)*pow);// ? Formula to find the hash value
        total%=mod;
        pow*=p;
        pow%=mod;
   }

   vector<int>dp(s.size()+1,0),po(s.size()+1,0);

   dp[0] = s[0]-'a'+1;
   po[0] = 1;
   pow = p;
   // ! Now calculate the hash value for the given big string to count the occurence of the second string
   // * Now in Dp store the hashvalue as prefix sum to count the occurnce ans also store the power of all the indexes
   for(int i=1;i<s.size();i++)
   {
     dp[i] = (dp[i-1] + ((s[i]-'a'+1)*pow))%mod;
     po[i] = pow;
     pow*=p;
     pow%=mod;
   }

   int i = 0;
   int j = s1.size()-1;
   vector<int>ans;
   while(j<s.size())
   {
      int wi = dp[j];
      if(i>0)wi=(wi-dp[i-1]+mod)%mod;// * Now first take the sum of the prefix of the s2 size 
      int x = (total*(po[i]))%mod; // * Multiply the previously calculated hashvalue of second string with the ith power 
      // ! Multiplying total beacuase afer some indexes the pow will become as p^6,p^7...s2.size() so make it with total
      // ! which is starting with p^0 we are multipling the ith power to make it equal to p^6,p^7....s2.size()
      if(wi==x)
      {
        ans.push_back(i+1);
      }
      i++;
      j++;
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
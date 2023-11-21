#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#define ll long long int
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
vector<ll>v;
unordered_map<ll,ll>m;
bool sive[300000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,t;

    for(i=2; i<30000; i++)
        sive[i]=true;
    for(i=2; i*i<=30000; i++)
    {
        if(sive[i]==true)
        {
            for(j=i*i; j<30000; j=i+j)
                sive[j]=false;
        }
    }
    ll n,a,num,c,ans,b,mask,y,mx;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        y=0;
        m.clear();
        v.clear();
        c=0;
        mx=1;
        for(i=0; i<n; i++)
        {
            a=s[i]-48;
            v.pb(a);
            if(sive[a])
            {
                m[a]++;
                c++;
                if(mx<m[a])
                {
                    ans=a;
                    mx=2;
                }
            }
            else{
                y=1;
                ans=a;
                break;
            }
          }
          if(y==1)
            cout<<1<<endl<<ans<<endl;
          else if(mx==2)
            cout<<2<<endl<<ans<<ans<<endl;
          else{
            mx=4;
            y=0;

            ll si=v.size();


            for(mask=1; mask<(1<<si); mask++)
            {
                num=0;
                c=0;
                for(i=0; i<si; i++)
                {
                    if(mask&(1<<i))
                    {
                        num=num*10+v[i];
                        c++;
                    }
                }

                if(sive[num]==false)
                {
                    y=1;
                    if(mx>=c)
                    {
                        ans=num;
                        mx=c;
                    }
                }
            }
          cout<<mx<<endl<<ans<<endl;
          }

    }

    return 0;

}



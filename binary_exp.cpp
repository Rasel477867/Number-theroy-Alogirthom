#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back


using namespace __gnu_pbds;
using namespace std;

typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
//ordered_multiset s3;
//ordered_multiset :: iterator it;
const ll mod=1e9;



ll ex(ll a,ll b,ll mod)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return (ex((a*a)%mod,b/2,mod));
    else
        return (a*ex((a*a)%mod,(b-1)/2,mod))%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    cout<<ex(2,3,mod);





    return 0;

}


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back
#define pf push_front

const ll mod=1e9+7;
const ll N=100;
using namespace std;
ll martix[N][N];
ll I[N][N];
void mul(ll A[][N],ll B[][N],ll n)
{
    ll i,j,k;
    ll r[n+1][n+1];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            r[i][j]=0;
            for(k=1; k<=n ; k++)
            {
                ll x=(A[i][k]*B[k][j])%mod;
                r[i][j]=(x+r[i][j])%mod;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            A[i][j]=r[i][j];
    }
}
void power(ll a[][N],ll n,ll p)
{
    ll i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }
    while(p!=0)
    {
        if(p%2==1)
        {
            mul(I,a,n);
            p--;
        }
        else
        {
            mul(a,a,n);
            p=p/2;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j]=I[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,t;
    ll n,p;
    cin>>t;
    while(t--)
    {


        cin>>n>>p;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin>>martix[i][j];
            }
        }

        power(martix,n,p);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                cout<<martix[i][j]<<" ";
            cout<<endl;
        }

    }


    return 0;
}


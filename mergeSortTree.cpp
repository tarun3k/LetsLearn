#include<bits/stdc++.h>
 
#define MOD 1000000007
#define fio ios_base:: sync_with_stdio(false); cin.tie();
#define ff first
#define ss second
#define INF 100000000
#define all(a)  a.begin(),a.end()
#define mkp(a,b) make_pair(a,b)
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef  pair<ll,ll> pll;
 

vector<vector<pii> > sortArr;
vector<vector<pii> > graph;
 
vector<vector<vector<pii>>> tree;
/*
tree=vector<vector<vector<pii>>>(givenN,vector<vector<pii>>(3*givenN+4));*/
 
 // This is for i trees that has atmost n elements
 //1,1,n,index
 
void init(int n, int b, int e,int i)
{
    if(b==e)
    {
        //given indexs are in 1,n storing indexex in 0,n-1 so b-1
        tree[i][n].push_back(mkp(sortArr[i][b-1].ss,sortArr[i][b-1].ff));
        return;
    }
    int l=n*2,r=l+1,mid=(b+e)/2;
    init(l,b,mid,i);
    init(r,mid+1,e,i);
    //merge both tree
    merge(all(tree[i][l]),all(tree[i][r]),back_inserter(tree[i][n]));
}
 
 // i,j are L,R
// 1,1,n,L,R,index
int queryS(int n, int b, int e, int i, int j, int k,int idx)
{
    if(b==e)
    {
        return tree[idx][n].back().ss;
    }
    int l=n*2,r=l+1,mid=(b+e)/2;
    //{i,j}(j-i) count of all elements..
    int x = upper_bound(all(tree[idx][l]),mkp(j,INT_MAX))-lower_bound(all(tree[idx][l]),mkp(i,0));

    if(x>=k)
    {
        //left mai jao phir process kro...
        return queryS(l,b,mid,i,j,k,idx);
    }
    else// right me jao phir prcess kro
        return queryS(r,mid+1,e,i,j,k-x,idx);
}
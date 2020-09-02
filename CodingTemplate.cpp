
/*
 @tarun3k
*/
//problme link-
#include<bits/stdc++.h>
using namespace std;
//Enable when you need order statistic datastructure
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
*/

#define endl "\n"
#define debug(x,y) cout<<" {"<<x<<","<<y<<"} "
#define IN(file)  freopen(file+".txt", "r", stdin); 
#define OUT(file) freopen(file+".txt", "w", stdout); 
  
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ff first
#define ss second
#define V(l) vector<l>
#define VV(l) vector<V(l)>
#define MAP(a,b) map<a,b>
#define UMAP(a,b) unordered_map<a,b>

using uint=unsigned int;
using ll=long long;
using ull=unsigned ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int INF=1e9+10;

vector<int> boolPrime = {0, 1};
vector<int> primes;
 
void RunLinearSieve(int n) {
  boolPrime.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (boolPrime[i] == 0) {
      boolPrime[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > boolPrime[i] || i * x > n) {
        break;
      }
      boolPrime[i * x] = x;
    }
  }
}
int main(){
//  fio
//  #ifndef ONLINE_JUDGE 
//  IN(in)
//  OUT(out)
//  #endif 
    int t;
    cin>>t;
    while(t--){
    

        
    }


    return 0;

}

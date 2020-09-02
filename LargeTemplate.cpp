/*
 * @Author: tarun3k 
 * @Date: 2020-08-03 21:33:18 
 */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl "\n"
#define IN(file)  freopen(file+".txt", "r", stdin); 
#define OUT(file) freopen(file+".txt", "w", stdout); 
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ff first
#define ss second
#define V(l) vector<l>
#define VV(l) vector<V(l)>
#define MAP(a,b) map<a,b>
#define UMAP(a,b) unordered_map<a,b>
#define SET(a) set(a)
#define USET(a) unordered_set<a>
#define PBS3K(...) tree<__VA_ARGS__, null_type, less<__VA_ARGS__>, rb_tree_tag,tree_order_statistics_node_update> 

//debugging 
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {  return "(" + to_string(p.ff) + ", " + to_string(p.ss) + ")"; }
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#define debug3k(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

using uint=unsigned int;
using ll=long long;
using ull=unsigned ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int INF=1e9+10;

void solve3k(){
    
}
int main(){
//  fio
//  #ifndef ONLINE_JUDGE 
//  IN(in)
//  OUT(out)
//  #endif 
    int t=0;
    cin>>t;
    while(t--){
        solve3k(); 
    }
    return 0;

}
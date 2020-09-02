#include<bits/stdc++.h>
using namespace std;
const int H=20;
const int mod=1e0+7;
using ll=long long;

//define all Array

//Tree structure ,parents for all heights x 2^x,costs of edges
vector<vector<int>> tree,parent,costs;

//chainHead of SegmentTree,ChainId for all vertex to which segment Tree they belong
//SubTree size for all vertex,depth of a node(vertex),posOfvertex in SegemntTree
vector<int> chainHead,chainId,subTreeSize,depth,posOfVertex;

//One Segment Tree for all segments by the help of posOfVertex
vector<ll> segArr;


int n=5e5+10,chainNo=0,position=0;

   /* tree = cost = vector<vector<int> >(n+1);
    depth = sub_size = chainInd = posInbase = chainHead = vector<int>(n+1,-1);
    parent = vector<vector<int> >(H,vector<int>(n+1,-1));
    baseArr = vector<long long>(n<<1);*/

//buildSegmentTree
void build()
{
  for(int i=n-1;i>0;i--) segArr[i]=(segArr[i<<1]+segArr[i<<1 | 1] )%mod;
}

//updateSegmentTree

void update(int p)
{
  p+=n;
  //segArr[p]=(updating Value)
  for(int i=p;i>1;i>>=1){
    //uodataing all ancestor for p
    segArr[i>>1]=segArr[i]+segArr[i^1];
  }
}

//query on SegmentTree
ll query(int l,int r)
{
  ll ans=0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1)
  {
    if(l&1) ans+=segArr[l++];
    if(r&1) ans+=segArr[--r];
  }
  return ans;
}

//run DFS to fill parent,subTreeSize;
void dfs(int node,int par,int dep=0)
{
  depth[node]=dep;
  parent[0][node]=par;
  subTreeSize[node]=1;

  for(int i=0;i<tree[node].size();i++)
  {
    if(tree[node][i]!=par)
    {
      dfs(tree[node][i],node,dep+1),subTreeSize[node]+=subTreeSize[tree[node][i]];
    }
  }
}

//Now initalize all parents for heights x...2^x
//This techniqie is knowm as Binary Lifting
// for all H we do this basically covering all possible cases
void init_LCA()
{
  for(int i=1;i<H;i++)
    for(int j=0;j<n;j++)
      if(parent[i-1][j]!=-1)
        parent[i][j]=parent[i-1][parent[i-1][j]];//this is jump of 2^(i) thats so cool
}

//Lets find The LCA(u,v)
int LCA(int u,int v)
{
  if(depth[u]<depth[v]) swap(u,v);
  int diff=depth[u]-depth[v];

  for(int i=0;i<H;i++) if((diff>>i)&1) u=parent[i][u];
if(u==v) return v;
  for(int i=H-1;i>=0;i--)
    if(parent[i][u]!=parent[i][v]) u=parent[i][u],v=parent[i][v];

    return parent[0][u];
}
//Lets now define the King functin of this whole thing
// this is HLD .. yeah this is HLD
//This function basically divide the n-arry tree into the segments and fill chainNo,chainId,position for all posOfVertex
//Check for heavy edge if exist traverse first heavy edge
// then traverse all light edge
//This HLD function also fill the segTree leafNode
void HLD(int node,int par,ll cost)
{
  if(chainHead[chainNo]==-1) chainHead[chainNo]=node;
  chainId[node]=chainNo,segArr[n+position]=cost,posOfVertex[node]=position++;

  int sc=-1;//Strong,HeavyChain;

  for(int i=0;i<tree[node].size();i++)
   if(tree[node][i]!=par &&(sc==-1||subTreeSize[tree[node][i]]>subTreeSize[tree[node][sc]])) sc=i;

   //if Heavy cSubtree exist lets Move to this chain
   if(sc!=-1)
   HLD(tree[node][sc],node,costs[node][sc]);

   //Now take care for all light edges
   for(int i=0;i<tree[node].size();i++)
   {
     if(tree[node][i]!=par && i!=sc)
     chainNo++,HLD(tree[node][i],node,costs[node][i]);
   }

}
/*All set*/
// lets go For query
ll queryHLD(int u,int v)
{
  if(v==u) return 0;
  ll ans=0;
  int uchainId,vchainId=chainId[v];

  while(1)
  {
    uchainId=chainId[u];
    if(uchainId==vchainId)
    {
      if(v==u) return ans;
    return ans+query(posOfVertex[chainHead[uchainId]]+1,posOfVertex[v]+1);
  }
    ans+= query(posOfVertex[chainHead[uchainId]],posOfVertex[u]+1);
    u=parent[0][chainHead[uchainId]];
  }
  return ans;
}

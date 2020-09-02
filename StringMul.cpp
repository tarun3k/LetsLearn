#include<bits/stdc++.h>
using namespace std;

string mult(string a,string b)
{

  int la=a.size(),lb=b.size();
  vector<int> res(la+lb+1,0);
  int carry=0,in1=0,in2=0;
  int num=0;
  int n1,n2;
  for(int i=la-1;i>=0;i--)
  {

    carry=0;
    in2=0;
    n1=a[i]-'0';
    for(int j=lb-1;j>=0;j-- )
    {
      n2=b[j]-'0';
      num= n1*n2+carry+res[in1+in2];
      res[in1+in2]=num%10;
      carry=num/10;
      in2++;

    }
    if(carry>0) res[in1+in2]+=carry;
    in1++;
  }
  int i=la+lb;
  while(i>=0 && res[i]==0) i--;
  if(i<0) return "0";
 string ans="";
  while(i>=0)
    ans+=to_string(res[i--]);
  return ans;
}

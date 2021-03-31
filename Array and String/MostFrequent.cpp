#include<bits/stdc++.h>
using namespace std;

/* Unordered Map Solution  */

void MostFrequent(vector<int> v){
    int n = v.size();
    unordered_map<int,int>M;
    for(int i=0;i<n;i++){
        M[v[i]]++;
    }
    int maxCount = 0, res =-1;
    for(auto &i:M){
        if(i.second > maxCount){
            res = i.first;
            maxCount = i.second;
        }
    }
    cout<< res<<endl;
}


int main()
{
   map<int,int>m;
   int n,i,p=0,q;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
       m[a[i]]++;     
   }
  for(auto &e:m)    //map traversal
  {
      if(e.second>p)
      {
          p=e.second;
          q=e.first;
      }
  }
  cout<<q;
}

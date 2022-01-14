// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int,int> &p1,pair<int,int> &p2){
        return p1.first<p2.first;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        map<int,int> m;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            pair<int,int> p;
            p.first = arr[i];
            p.second = dep[i];
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans=1;
        for(auto p:vec){
           bool isNew=false;
          for(auto &i:m){
              if(i.second<p.first){
                  i.second = p.second;
                  isNew = true;
                  break;
              }
          }
            if(!isNew){
            m[ans]= p.second;
            ans++;
            }
        }
        return m.size();
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
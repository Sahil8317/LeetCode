// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(vector<int> &v1,vector<int> &v2){
        return v1[1]<v2[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> meetings;
        for(int i=0;i<n;i++){
            vector<int> v;
            v.push_back(start[i]); //0
            v.push_back(end[i]);   //1
            v.push_back(i+1);      //2
            meetings.push_back(v);
        }
        
        sort(meetings.begin(),meetings.end(),comp);
        int endTime = 0,ans=0;
        for(auto vec:meetings){
            if(vec[0]>endTime){
                ans++;
                endTime = vec[1];
            }
        }
        return ans;
        
       
    } 
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
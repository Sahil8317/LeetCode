// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &arr1,Job &arr2){
        return arr1.profit>arr2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(arr[i].dead,maxi);
        }
        int result [maxi+1] = {0};
        int maxProfit = 0,jobCount=0;
        for(int i=0;i<n;i++){
           if(result[arr[i].dead]==0){
               result[arr[i].dead] = arr[i].id;
               maxProfit+=arr[i].profit;
               jobCount+=1;
           } else{
               int j = arr[i].dead;
               while(j>0){
                   if(result[j]==0){
                    result[j] = arr[i].id;
                    maxProfit+=arr[i].profit;
                    jobCount+=1;
                    break;
                   }
                   j--;
               }
           }
        }
        
        vector<int> ans;
        ans.push_back(jobCount);
        ans.push_back(maxProfit);
        return ans;
    
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
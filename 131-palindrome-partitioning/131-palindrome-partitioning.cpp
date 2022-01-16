class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        int low = start;
        int high = end;
        while(low<=high){
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    }
    void findSubstring(string s,int index,vector<vector<string>> &ans,vector<string> &res){
        if(index==s.size()){
            ans.push_back(res);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                res.push_back(s.substr(index,i-index+1));
                findSubstring(s,i+1,ans,res);
                res.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> res;
        findSubstring(s,0,ans,res);
        return ans;
        
    }
};
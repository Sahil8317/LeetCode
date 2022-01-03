class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
        int n =s.size();
        int len = 0;
        int left=0,right = 0;
        while(right<n){
            if(map[s[right]]!=-1){
                left = max(map[s[right]]+1,left);
            }
            map[s[right]] = right;
            
            len = max(right-left+1,len);
            right++;
        }
        return len;
    }
    
};
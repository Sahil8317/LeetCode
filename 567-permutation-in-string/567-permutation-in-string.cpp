class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> map1(26);
        vector<int> map2(26);
        for(int i=0;i<s1.size();i++) map1[s1[i]-'a']+=1;
        int l = 0,h = 0;
        while(h<s2.size()){
            if(h-l ==s1.size()){
                if(map2==map1)return true;
               
                map2[s2[l]-'a']--;
                l++;
            }else{
                map2[s2[h]-'a']++;
                h++;
            }
            
        }
        if(map1==map2)return true;
        return false;
    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1,ver2;    
        int k = 0,i=0;
        for(;i<version1.size();i++){
            if(version1[i]=='.'){
                ver1.push_back(stoi(version1.substr(k,i)));
                    k = i+1;
            }
        }
          ver1.push_back(stoi(version1.substr(k,i)));
        k = 0;
        i = 0;
        for(;i<version2.size();i++){
           if(version2[i]=='.'){
                ver2.push_back(stoi(version2.substr(k,i)));
                    k = i+1;
            }
        }
           ver2.push_back(stoi(version2.substr(k,i)));
         
        
        for(auto i:ver1) cout<< i <<" ";
        cout<<endl;
        for(auto i:ver2) cout<< i <<" ";
         i = 0;
         int j = 0;
        while(i<ver1.size() && j<ver2.size()){
                if(ver1[i]>ver2[j]) return 1;
                if(ver1[i]<ver2[j]) return -1;
            i++;
            j++;
        }
        while(i<ver1.size()) {
         if(ver1[i]!=0) return 1;
            i++;
        }
         while( j<ver2.size()) {
            if(ver2[j]!=0) return -1;
            j++;
        }
          return 0;
        
    }
};
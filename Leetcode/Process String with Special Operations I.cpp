class Solution {
public:
    string processStr(string s) {
       string str="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(str=="" && !islower(s[i])) continue;
            if(s[i]=='*' && str!=""){
                str.pop_back();
            } else if(s[i]=='#' && str!=""){
                str+=str;
            } else if(s[i]=='%' && str!=""){
                reverse(str.begin(),str.end());
            } else{
                str+=s[i];
            }
        }
        return str;
    }
};
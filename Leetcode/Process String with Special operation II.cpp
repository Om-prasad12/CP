class Solution {
public:
    char processStr(string s, long long k) {
        long long size=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(size==0 && !islower(s[i])) continue;
            if(s[i]=='*' && size!=0){
                size--;
            } else if(s[i]=='#'){
                size+=size;
            } else if(s[i]=='%'){
                continue;
            } else{
                size++;
            }
        }
        if(k>size-1) return '.';
        long long ind=k;
        for(int i=n-1;i>=0;i--){
            if(islower(s[i])){
                if (size == ind+1) return s[i]; 
                size--;
            }else if(s[i]=='*'){
                size++;
            } else if(s[i]=='#'){
                size=size/2;
                if(ind>=size) ind=ind-size;
            } else if(s[i]=='%'){
                ind=size-ind-1;
            }
        }
        return '.';
    }
};
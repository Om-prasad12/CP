class Solution {
public:
     string toBase(long long num, int base) {
        if (num==0) return"0";
        string res;
        while (num > 0) {
            int rem = num % base;
            if (rem<10){
                res += ('0' + rem);
            }else{
                res += ('A' + rem - 10);
            }
            num /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string concatHex36(int n) {
        long long square = 1LL*n*n;
        long long cube = 1LL*n*n*n;
        string hex = toBase(square, 16);   
        string base36 = toBase(cube, 36);  

        return hex + base36;
    }
};
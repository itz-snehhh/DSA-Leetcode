class Solution {
public:
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    string pref = "";
    string suff = "";
    bool completePrime(int num) {
        string realNum = to_string(num);
        int st = 0;
        int end = realNum.size() - 1;
        while(st <realNum.size() && end >= 0){
            pref = pref + realNum[st];
            suff = realNum[end] + suff;
            if(!isPrime(stoi(pref)) || !isPrime(stoi(suff))){
                return false;
            }
            st++;
            end--;
        }

        return true;
    }
};
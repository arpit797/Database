class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        
        long long ans = 1;
        
        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;
            
            // Modular inverse using Fermat's theorem
            ans = ans * modPow(i, MOD - 2) % MOD;
        }
        
        return ans;
    }
    
    long long modPow(long long a, long long b) {
        const int MOD = 1e9 + 7;
        long long res = 1;
        
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            
            a = a * a % MOD;
            b >>= 1;
        }
        
        return res;
    }
};
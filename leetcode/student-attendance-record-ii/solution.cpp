#define MOD 1000000007

class Solution {
public:
    int checkRecord(int n) {
        int a0l0 = 1;
        int a0l1 = 0;
        int a0l2 = 0;
        int a1l0 = 0;
        int a1l1 = 0;
        int a1l2 = 0;
        for (int i = 1; i <= n; ++i) {
            int temp_a0l0 = ((a0l0 + a0l1) % MOD + a0l2) % MOD;
            int temp_a0l1 = a0l0;
            int temp_a0l2 = a0l1;
            int temp_a1l0 = (((((a0l0 + a0l1) % MOD + a0l2) % MOD + a1l0) % MOD + a1l1) % MOD + a1l2) % MOD;
            int temp_a1l1 = a1l0;
            int temp_a1l2 = a1l1;
            
            a0l0 = temp_a0l0;
            a0l1 = temp_a0l1;
            a0l2 = temp_a0l2;
            a1l0 = temp_a1l0;
            a1l1 = temp_a1l1;
            a1l2 = temp_a1l2;
        }
        
        return (((((a0l0 + a0l1) % MOD + a0l2) % MOD + a1l0) % MOD + a1l1) % MOD + a1l2) % MOD;
    }
};


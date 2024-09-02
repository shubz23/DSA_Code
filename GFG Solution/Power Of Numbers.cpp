
#define MOD 1000000007

class Solution{
    public:
    //You need to complete this fucntion
    
    long long reverseNumber(long long n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    long long power(long long N, long long R) {
        if (R == 0) {
            return 1;
        }
        long long halfPower = power(N, R / 2) % MOD;
        long long result = (halfPower * halfPower) % MOD;
        if (R % 2 != 0) {
            result = (result * N) % MOD;
        }
        return result;
    }

    // Main function to calculate N raised to the power of its reverse
    long long powerOfReverse(long long N) {
        long long R = reverseNumber(N);
        return power(N, R);
    }

};
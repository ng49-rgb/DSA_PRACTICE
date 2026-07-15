class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 0;
        long long sumEven = 0;

        for(int i = 1; i<=n; i++){
            sumOdd = sumOdd + (2LL*i-1);
            sumEven = sumEven + (2LL*i);
        }
        return __gcd(sumOdd,sumEven);
    }
};
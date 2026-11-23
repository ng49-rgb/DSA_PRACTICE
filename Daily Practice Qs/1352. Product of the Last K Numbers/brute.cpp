#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {

    }

    void add(int num) {
        arr.push_back(num);
    }

    int getProduct(int k) {
        int ans = 1;
        int n = arr.size();

        for(int i = n - 1; k > 0; i--, k--) {
            ans *= arr[i];
        }

        return ans;
    }
};
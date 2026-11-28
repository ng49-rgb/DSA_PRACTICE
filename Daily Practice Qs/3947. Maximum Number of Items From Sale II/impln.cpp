#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int minPrice = INT_MAX;

        //Frequency of each factor
        for(auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        // Count items divisible by each factor
        vector<int> gain(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }

            gain[i]--;
        }

        // Store profitable boosted purchases
        vector<pair<int,int>> v;

        for(auto &it : items) {
            int factor = it[0];
            int price = it[1];

            if(gain[factor] > 0 && price < 2LL * minPrice) {
                v.push_back({price, gain[factor]});
            }
        }

        // Sort by price
        sort(v.begin(), v.end());

        long long ans = 0;

        //Buy boosted copies first
        for(auto &it : v) {
            int price = it.first;
            int cnt = it.second;

            int buy = min(cnt, budget / price);

            ans += 2LL * buy;
            budget -= buy * price;
        }

        // Spend remaining budget on cheapest items
        ans += budget / minPrice;

        return (int)ans;
    }
};
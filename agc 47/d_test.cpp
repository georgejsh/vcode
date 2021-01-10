#include <bits/stdc++.h> // Twin Binary Trees, by Errichto
using namespace std;
 
const int mod = 1e9 + 7;
int mul(int a, int b) { return (long long) a * b % mod; }
 
int answer;
int h, n;
vector<int> perm;
vector<int> sum;
vector<int> clear_leaves;
 
void rec_second_tree(int a, int product, bool left_half) {
    if(a == 1) {
        return;
    }
    product = mul(a, product);
    if(left_half) {
        sum[a] = (sum[a] + product) % mod;
    }
    else {
        cout<<mul(a / 2, mul(sum[a^1], product))<<" ";
        answer = (answer + mul(a / 2, mul(sum[a^1], product))) % mod;
    }
    rec_second_tree(a / 2, product, left_half);    
}
 
void rec(int a, int product, bool left_half) {
    product = mul(a, product);
    if(a >= n) {
        int b = n + perm[a-n]; // special edge from a to b
        rec_second_tree(b, product, left_half);
        clear_leaves.push_back(b);
        return;
    }
    for(int b : {2 * a, 2 * a + 1}) {
        rec(b, product, left_half);
    }
}
 
int main() {
    scanf("%d", &h);
    assert(2 <= h);
    n = 1 << (h - 1); // n = base = number of leaves
    perm.resize(n);
    sum.resize(2 * n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &perm[i]);
        perm[i]--;
    }
    for(int lca1 = 1; lca1 < n; ++lca1) {
        rec(2 * lca1, lca1, true);
        rec(2 * lca1 + 1, 1, false);
        // sum = vector<int>(2 * n);
        for(int a : clear_leaves) {
            for(int x = a; x >= 1; x /= 2) {
                sum[x] = 0;
            }
        }
        clear_leaves.clear();
    }
    printf("%d\n", answer);
}
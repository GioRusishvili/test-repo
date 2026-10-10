#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ამოწმებს, შესაძლებელია თუ არა ყველა ლაბორატორიამ მიაღწიოს X ჯამს
bool check(long long X, int n, long long k, const vector<long long>& S, const vector<long long>& d) {
    long long req = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] < X) {
            if (d[i] == -1) { // -1 ნიშნავს, რომ განბლოკვა შეუძლებელია (a=b=c)
                return false;
            }
            long long needed = X - S[i] + 2LL * d[i];
            req += needed;
            
            // overflow-ს და ზედმეტი გამოთვლების თავიდან ასაცილებლად 
            if (req > k) {
                return false;
            }
        }
    }
    return req <= k;
}

void helper() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> S(n);
    vector<long long> d(n);
    long long low_val = 4e18; // ავიღოთ ძალიან დიდი საწყისი მნიშვნელობა
    for (int i = 0; i < n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        S[i] = a + b + c;
        low_val = min(low_val, S[i]);
        if (a <= b && b <= c) {
            if (a == c) { // ნიშნავს რომ a == b == c
                d[i] = -1;
            } else {
                d[i] = min(b - a, c - b) + 1;
            }
        } else {
            d[i] = 0; // უკვე განბლოკილია
        }
    }
    long long low = low_val;
    long long high = low_val + k + 1;
    long long ans = low;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, S, d)) {
            ans = mid; // mid მიღწევადია, ვცადოთ უფრო დიდი
            low = mid + 1;
        } else {
            high = mid - 1; // mid მიუღწეველია, ვცადოთ პატარა
        }
    }
    cout << ans << "\n";
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        helper();
    }
    return 0;
}
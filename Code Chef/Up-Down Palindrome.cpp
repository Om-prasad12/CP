#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        long long low = 1;
        long long high = 1e18;
        bool ok = true;

        for (int i = 1; i <= n / 2; i++) {
            int a = arr[i];
            int b = arr[n + 1 - i];

            if (a == b)
                continue;

            if (abs(a - b) != 2) {
                ok = false;
                break;
            }

            int mn = min(a, b);

            low = max(low, 1LL * (mn + 1));
            high = min(high, 1LL * (mn + 2));
        }

        if (ok && low <= high)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
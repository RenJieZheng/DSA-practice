#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cin.get();

    char c;
    char prev = -1;
    for (int i = 0; i < N; i++) {
        int count = 0;
        prev = -1;
        while (cin.get(c)) {
            if (c == prev || prev == -1) {
                count++;
            } else {
                cout << count << " " << prev << " ";
                count = 1;
            }
            prev = c;

            if (c == '\n') {
                break;
            }
        }
        cout << endl;
    }
}

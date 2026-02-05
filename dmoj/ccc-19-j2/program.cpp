#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int count;
    char c;
    for (int i = 0; i < N; i++) {
        cin >> count; cin >> c;
        for (int j = 0; j < count; j++) {
            cout << c;
        }
        cout << endl;
    }
}
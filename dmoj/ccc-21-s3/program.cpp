#include <bits/stdc++.h>

using namespace std;

struct Position {
    int p;
    int w;
    int op;

    bool operator<(const Position &other) const {
        return p < other.p;
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    int p;
    int w;
    int d;
    Position positions[400000];

    cin >> N;
    int pos_len = 2 * N;
    int j = 0;
    for (int i = 0; i < N; i++) {
        cin >> p;
        cin >> w;
        cin >> d;
        positions[j] = {p - d, w, 1};
        j++;
        positions[j] = {p + d, w, -1};
        j++;
    }
    sort(positions, positions + pos_len);

    long int left_w = 0;
    long int right_w = 0;
    long int min_cost = 0;
    long int curr_cost = 0;

    int prev_p = positions[pos_len - 1].p;
    for (int i = pos_len - 1; i >= 0; i--) {
        if (positions[i].op == 1) {
            curr_cost += right_w * abs(positions[i].p - prev_p);
            right_w += positions[i].w;
            prev_p = positions[i].p;
        }
    }
    min_cost = curr_cost;
    
    prev_p = positions[0].p;
    for (int i = 0; i < pos_len; i++) {
        int delta = positions[i].p - prev_p;
        curr_cost -= delta * right_w;
        curr_cost += delta * left_w;
        min_cost = min(curr_cost, min_cost);

        prev_p = positions[i].p;

        if (positions[i].op == 1) {
            right_w -= positions[i].w;
        } else if (positions[i].op == -1) {
            left_w += positions[i].w;
        }
    }

    cout << min_cost << endl;
}

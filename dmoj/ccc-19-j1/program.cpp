#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a_score = 0;
    int b_score = 0;

    int input = 0;
    int shot = 3;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        a_score += shot * input;
        shot--;
    }
    shot = 3;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        b_score += shot * input;
        shot--;
    }

    if (a_score > b_score) {
        cout << "A" << endl;
    } else if (b_score > a_score) {
        cout << "B" << endl;
    } else {
        cout << "T" << endl;
    }
}

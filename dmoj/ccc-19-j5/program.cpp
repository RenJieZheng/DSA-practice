#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<string, string>> transitions;
string F;
vector<int> rules;
vector<int> positions;
vector<string> W;
unordered_map<string, int> cache;

bool dfs_search(
    string curr,
    int steps_remaining
) {
    if (steps_remaining == 0) {
        if (curr == F) {
            W.emplace_back(curr);
            return true;
        } else {
            return false;
        }
    }

    if (cache.count(curr) != 0 && cache.at(curr) >= steps_remaining) {
        return false;
    } else {
        cache[curr] = steps_remaining;
    }

    W.emplace_back(curr);

    
    int curr_len = curr.length();
    for (int i = 0; i < 3; i++) {
        int l = 0;
        int r = transitions[i].first.length();

        while (l + r <= curr_len) {
            if (curr.compare(l, r, transitions[i].first) == 0) {
                rules.push_back(i);
                positions.push_back(l);

                string next = curr;
                next.replace(l, r, transitions[i].second);
                if (dfs_search(next, steps_remaining - 1)) {
                    return true;
                }

                rules.pop_back();
                positions.pop_back();
            }

            l++;
        }
    }

    W.pop_back();
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string from_str;
    string to_str;
    for (int i = 0; i < 3; i++) {
        cin >> from_str; cin >> to_str;
        transitions.emplace_back(pair{from_str, to_str});
    }

    int S; string I; 
    cin >> S; cin >> I; cin >> F;

    dfs_search(I, S);

    for (int i = 0; i < S; i++) {
        cout << rules[i] + 1 << " " << positions[i] + 1 << " " << W[i + 1] << endl;
    }
}

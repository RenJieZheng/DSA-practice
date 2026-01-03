#include <bits/stdc++.h>

using namespace std;

class CustomString {
public:
    string_view s;
    size_t hash;

    CustomString(string_view s, size_t hash) : s{s}, hash{hash} 
    {}

    bool operator==(const CustomString &other) const {
        return s == other.s;
    }
};

struct CustomHash {
public:
    size_t operator()(const CustomString &s) const {
        return s.hash;
    }
};


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string needle;
    string haystack;

    getline(cin, needle);
    getline(cin, haystack);

    int m = needle.length();
    int n = haystack.length();

    if (m > n) {
        cout << 0 << endl;
        return 0;
    }

    int needle_counts[26] = {0};
    int needle_chars = 0;

    int window_counts[26] = {0};
    int non_matching_chars = 0;

    const int p = 2000003;
    const int a = 26;
    int hash = 0;
    int power = 1;

    unordered_set<CustomString, CustomHash> permutations;

    // Initialize the needle historgram
    for (const auto &c : needle) {
        needle_counts[c - 'a']++;
        if (needle_counts[c - 'a'] == 1) needle_chars++;
    }
    non_matching_chars = needle_chars;


    // Find the largest power in order to remove the leftmost element in the hash
    for (int i  = 0; i < m; i++) {
        power = (power * a) % p;
    }

    // Initialize the current window historgram
    for (int i = 0; i < m; i++) {
        int chr = haystack[i] - 'a';
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars++;
        }
        window_counts[chr]++;
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars--;
        }
        hash = (hash * a + (chr + 1)) % p;
    }

    if (non_matching_chars == 0) {
        permutations.emplace(string_view(haystack.data(), m), hash);
    }

    int l = 0;
    int r = m;
    while (r < n) {
        int chr = haystack[r] - 'a';
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars++;
        }
        window_counts[chr]++;
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars--;
        }

        chr = haystack[l] - 'a';
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars++;
        }
        window_counts[chr]--;
        if (window_counts[chr] == needle_counts[chr]) {
            non_matching_chars--;
        }

        hash = (hash * a + (haystack[r] - 'a' + 1) - ((haystack[l] - 'a' + 1) * power)) % p;
        if (hash < 0) hash += p;

        l++;
        r++;

        if (non_matching_chars == 0) {
            permutations.emplace(string_view(haystack.data() + l, m), hash);
        }
    }

    cout << permutations.size() << endl;
}
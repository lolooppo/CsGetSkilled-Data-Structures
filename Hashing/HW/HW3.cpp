#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// This class will help unordered_set get hash for the object
// To properly understand, you need to study operator overloading
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        return seed;
    }
};


int count_anagram_substrings(const string &str) {	// O(L^3)
	unordered_set<vector<int>, VectorHash> s1;
	for (int start = 0; start < (int) str.size(); ++start) {
		for (int end = start; end < (int) str.size(); ++end) {
			vector<int> freq(26);	// O(const)
			for (int i = start; i <= end; ++i)
				++freq[str[i] - 'a'];
			s1.insert(freq);
		}
	}
	return s1.size();
}

int main() {
	cout << count_anagram_substrings("abba") << "\n";		// 6
	cout << count_anagram_substrings("aaaaa") << "\n";		// 5
	cout << count_anagram_substrings("abcba") << "\n";		// 9
	cout << count_anagram_substrings("aabade") << "\n";		// 17

	return 0;
}

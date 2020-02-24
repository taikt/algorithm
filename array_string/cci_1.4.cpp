#include <bits/stdc++.h>

bool palindromePermutation(const std::string& input) {
	std::bitset<128> alphabet;  // use bitset as a hash table to store which characters we've seen
	size_t numValidChars = 0;
	for (const char c : input) {
		if ((c >= 0 || c > 127) && c != ' ') {  // ignore non-ASCII & spaces
			numValidChars++;
			alphabet.flip(c); // flip bit corresponding to valid char
		}
	}
	// if even number of chars and all bits are zero, we've seen each char an even # of times
	if ((numValidChars % 2 == 0) && alphabet.none()) {
		return true;
	}
	// if odd number of chars and just one bit is 1, we've seen each char except for 1 an even # of times
	else if (((numValidChars % 2 != 0) && alphabet.count() == 1)) {
		return true;
	}
	return false;
}

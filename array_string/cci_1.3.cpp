#include <bits/stdc++.h>

void URLify(std::string& input) {
	// count how much extra space needs to be added to the string.
	int extraSpace = 0;
	for (const char c : input) {
		if (c == ' ') {
			extraSpace += 2;
		}
	}
	if (extraSpace <= 0) return; // if no extra space is needed, do nothing.
	int fastIndex = input.size() - 1;
	input.append(extraSpace, ' ');
	int slowIndex = input.size() - 1;
	while (fastIndex >= 0 && slowIndex >= 0) {
		if (input[fastIndex] == ' ') {  // if fast index sees a space, add a %20 at slow index's location
			input[slowIndex] = '0';
			input[slowIndex - 1] = '2';
			input[slowIndex - 2] = '%';
			fastIndex--;
			slowIndex-=3;
		} else {  // if fast index does not see a space, simply copy over what it sees
			input[slowIndex] = input[fastIndex];
			fastIndex--;
			slowIndex--;
		}
	}

}

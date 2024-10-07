#include <iostream>
#include <string>
#include <vector>

int boyerMooreSearch(const std::string& text, const std::string& pattern) {
	std::vector<int> shiftTable(256, pattern.size());
	for (int i = 0; i < pattern.size() - 1; ++i) {
		shiftTable[pattern[i]] = pattern.size() - i - 1;
	}

	int textIndex = pattern.size() - 1;
	int patternIndex = pattern.size() - 1;

	while (textIndex < text.size()) {
		if (text[textIndex] == pattern[patternIndex]) {
			if (patternIndex == 0) {
				return textIndex;
			}
			--textIndex;
			--patternIndex;
		} else {
			textIndex += shiftTable[text[textIndex]];
			patternIndex = pattern.size() - 1;
		}
	}

	return -1;
}

int main() {
	std::string text = "ABFFFFFFFCABCAB";
	std::string pattern = "CAB";
	int index = boyerMooreSearch(text, pattern);

	if (index != -1) {
		std::cout << "input position of yr template: " << index << std::endl;
	} else {
		std::cerr << "cant find yr template" << std::endl;
	}
	return 0;
}


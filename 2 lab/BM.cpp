
#include <iostream>
#include <string>
#include <vector>

std::vector<int> createShiftTable(const std::string& pattern) {
    const int maxSizeChar = 256;
    std::vector<int> shiftTable(maxSizeChar, pattern.size());
    int m = pattern.size();
    for (int i = 0; i < m - 1; ++i) {
        shiftTable[pattern[i]] = m - i - 1;
    }
    return shiftTable;
}

void searchPattern(const std::string& text, const std::string& pattern, int start, int end, std::vector<int>& occurrence, bool findFirstOnly) {
    int sizeText = text.size();
    int sizePattern = pattern.size();

    if (sizePattern == 0 || sizeText < sizePattern || start < 0 || end >= sizeText || start > end) {
        return;
    }

    std::vector<int> shiftTable = createShiftTable(pattern);

    int shift = start;
    while (shift <= end - sizePattern + 1) {
        int j = sizePattern - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            --j;
        }

        if (j < 0) {
            occurrence.push_back(shift);
            if (findFirstOnly) {
                return;
            }
            if (shift + sizePattern <= end) {
                shift += sizePattern;
            } else {
                shift += 1;
            }
        } else {
            int badChar = text[shift + j];
            shift += shiftTable[badChar];
        }
    }
}

int findFirstPattern(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrence;
    searchPattern(text, pattern, 0, text.size() - 1, occurrence, true);
    if (occurrence.empty()){
        return -1;
      } else {
        return occurrence[0];
      }
}

std::vector<int> findAllOccurrence(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrence;
    searchPattern(text, pattern, 0, text.size() - 1, occurrence, false);
    return occurrence;
}

std::vector<int> findAllIndexOccurrence(const std::string& text, const std::string& pattern, int start, int end) {
    std::vector<int> occurrence;
    searchPattern(text, pattern, start, end, occurrence, false);
    return occurrence;
}

int main() {
    std::string text;
    std::string pattern;

    std::cout << "Введите строку: ";
    std::getline(std::cin, text);

    std::cout << "Введите подстроку: ";
    std::getline(std::cin, pattern);

    int firstOccurrence = findFirstPattern(text, pattern);
    std::cout << "First occurrence: " << firstOccurrence << std::endl;

    std::vector<int> allOccurrences = findAllOccurrence(text, pattern);
    std::cout << "All occurrences: ";
    for (int i = 0; i < allOccurrences.size(); ++i) {
        std::cout << allOccurrences[i] << " ";
    }
    std::cout << std::endl;

    int start = 0;
    int end = text.size() - 1;
    std::vector<int> rangeOccurrences = findAllIndexOccurrence(text, pattern, start, end);

    std::cout << "Occurrences in the range: ";
    for (int i = 0; i < rangeOccurrences.size(); ++i) {
        std::cout << rangeOccurrences[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

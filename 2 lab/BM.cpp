#include <iostream>
#include <string>
#include <vector>

std::vector<int> createShiftTable(const std::string& pattern) {
    const int maxSizeChar = 256;
    std::vector<int> shiftTable(maxSizeChar, pattern.size());
    int m = pattern.size();
    for (int i = 0; i < m - 1; ++i) {
        shiftTable[pattern[i]] = m - 1 - i;
    }
    return shiftTable;
}

std::vector<int> findOccurrences(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    int m = pattern.size();
    int n = text.size();
    std::vector<int> shiftTable = createShiftTable(pattern);

    int i = m - 1; 
    while (i < n) {
        int j = m - 1;
        int k = i; 

        while (j >= 0 && pattern[j] == text[k]) {
            --j;
            --k;
        }

        if (j < 0) { 
            occurrences.push_back(i + 1 - m); 
            i += m; 
        } else { 
            i += shiftTable[text[i]]; 
        }
    }
    return occurrences;
}

int main() {
    std::string text;
    std::string pattern;

    std::cout << "Введите строку: ";
    std::getline(std::cin, text);

    std::cout << "Введите подстроку: ";
    std::getline(std::cin, pattern);

    std::vector<int> occurrences = findOccurrences(text, pattern);
    if (occurrences.empty()) {
        std::cout << "Подстрока не найдена" << std::endl;
    } else {
        std::cout << "Позиции вхождений подстроки: ";
        for (int occurrence : occurrences) {
            std::cout << occurrence << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <algorithm>
#include <string>
#include <vector>

#include "vowel.hpp"

std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

void removeVowels(std::vector<std::string>& v) {
    for (auto& word : v) {
        auto it_word = word.begin();
        while (it_word != word.end()) {
            if (std::find(vowels.begin(), vowels.end(), std::tolower(*it_word)) != vowels.end()) {
                word.erase(it_word);
            } else {
                std::advance(it_word, 1);
            }
        }
    }
}

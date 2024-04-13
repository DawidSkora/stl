#include <string>
#include <vector>

#include "vowel.hpp"

void removeVowels(std::vector<std::string>& v) {
    for (auto& word : v) {
        word.erase(std::remove_if(word.begin(), word.end(), [](char x) {
                       return x == 'a' || x == 'e' || x == 'o' || x == 'u' || x == 'i' || x == 'y' ||
                              x == 'A' || x == 'E' || x == 'O' || x == 'U' || x == 'I' || x == 'Y';
                   }),
                   word.end());
    }
}

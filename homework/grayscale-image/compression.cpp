#include <array>
#include <utility>
#include <vector>

#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width>& bitMap) {
    std::vector<std::pair<uint8_t, uint8_t>> vec = {};
    uint8_t last_value = bitMap[0][0];
    uint8_t repeats = 0;
    for (auto& bitRow : bitMap) {
        for (auto& bit : bitRow) {
            if (last_value == bit) {
                repeats++;
            } else {
                vec.emplace_back(last_value, repeats);
                repeats = 1;
                last_value = bit;
            }
        }
    }
    vec.emplace_back(last_value, repeats);
    return vec;
}

std::array<std::array<uint8_t, height>, width> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, height>, width> out_arr;
    auto vec_iter = vec.begin();
    uint8_t num_of_elements = (*vec_iter).second;
    for (auto& bitRow : out_arr) {
        for (auto& bit : bitRow) {
            if (num_of_elements > 0) {
                bit = (*vec_iter).first;
                num_of_elements--;
            } else {
                vec_iter++;
                num_of_elements = (*vec_iter).second - 1;
                bit = (*vec_iter).first;
            }
        }
    }
    return out_arr;
}
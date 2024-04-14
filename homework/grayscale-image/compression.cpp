#include <array>
#include <iostream>
#include <utility>
#include <vector>

#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width>& bitMap) {
    std::vector<std::pair<uint8_t, uint8_t>> vec = {};
    uint8_t last_value = bitMap[0][0];
    uint8_t repeats = 0;
    bool new_line = true;
    for (auto& bitRow : bitMap) {
        for (auto& bit : bitRow) {
            if (last_value != bit) {
                if (!new_line) {
                    vec.emplace_back(last_value, repeats);
                }
                repeats = 0;
                last_value = bit;
            }
            new_line = false;
            repeats++;
        }

        vec.emplace_back(last_value, repeats);
        repeats = 0;
        new_line = true;
    }
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

void printMap(std::array<std::array<uint8_t, height>, width>& arr) {
    for (auto& bitRow : arr) {
        for (auto& bit : bitRow) {
            std::cout << bit;
        }
        std::cout << std::endl;
    }
}
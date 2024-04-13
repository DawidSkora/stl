#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl) {
    std::deque<std::string> deq = {};
    auto shortest_it = fl.begin();

    for (auto it = fl.begin(); it != fl.end(); ++it) {
        shortest_it = it;
        for (auto it2 = it; it2 != fl.end(); ++it2) {
            if (
                ((*it2).size() < (*shortest_it).size()) ||
                (((*it2).size() == (*shortest_it).size()) && (*shortest_it) > (*it2))) {
                shortest_it = it2;
            }
        }
        if (shortest_it != it) {
            std::iter_swap(it, shortest_it);
        }
    }

    for (auto& el : fl) {
        deq.push_back(el);
    }
    return deq;
}
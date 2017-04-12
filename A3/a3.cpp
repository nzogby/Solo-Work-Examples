

#include <iostream>
#include "a3.hpp"


int main(int argc, char* argv[]) {
    key_value_sequences A;

    {
        key_value_sequences T;
        // k will be the key
        for (int k = 0; k < 10000; ++k) {

            for (int v = 0; v < k + 1; ++v) T.insert(k, v);
        }

        T = T;

        key_value_sequences V = T;
        A = V;
    }

    std::vector<int> ref;

    if (A.size(-1) != -1) {
        std::cout << "fail" << std::endl;
        return -1;
    }

    for (int k = 0; k < 10000; ++k) {
        if (A.size(k) != k + 1) {
            std::cout << "fail";
            return -1;
        } else {
            ref.clear();
            for (int v = 0; v < k + 1; ++v) ref.push_back(v);
            if (!std::equal(ref.begin(), ref.end(), A.data(k))) {
                std::cout << "fail";
                return -1;
            }
        }
    }

    std::cout << "pass" << std::endl;

    return 0;
} // main

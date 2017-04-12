/***
 *  File: a6.cpp
 *  Author: Jaroslaw Zola <jzola@buffalo.edu>
 */

// DO NOT EDIT THIS FILE
// YOUR CODE MUST BE CONTAINED IN a6.hpp ONLY

#include "symbol.hpp"
#include "a6.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


template <typename IterIn, typename IterOut>
void symbols(IterIn first, IterIn last, IterOut out) {
    std::vector<int> count(256, 0);

    for (; first != last; ++first) {
        const std::string& s = *first;
        for (unsigned int i = 0; i < s.size(); ++i) count[s[i]]++;
    } // for first

    for (int c = 0; c < 256; ++c) {
        if (count[c] > 0) *out++ = symbol(static_cast<char>(c), count[c]);
    }
} // symbols

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "usage: ./a6 file" << std::endl;
        return -1;
    }

    // get input text
    std::ifstream f(argv[1]);

    std::string s;
    std::vector<std::string> lines;

    while (!f.eof()) {
        s = "";
        std::getline(f, s);
        if (!s.empty()) lines.push_back(s);
    }

    f.close();

    // create a list of symbols
    std::vector<symbol> A;
    symbols(lines.begin(), lines.end(), std::back_inserter(A));
    // process the list (student's code)
    bnode<symbol>* tree = huffman_tree(A.begin(), A.end());

    // print dictionary (student's code)
    print_dictionary(std::cout, tree);

    // free memory (student's code)
    release_tree(tree);

    return 0;
} // main

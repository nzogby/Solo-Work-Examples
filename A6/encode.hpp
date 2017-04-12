/***
 *  File: encode.hpp
 *  Author: Nathaniel Zogby njzogby
 */

#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "a6.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>


void get_keys(std::map<char,std::string>& mappy, bnode<symbol>* root, std::string str = ""){
  if (!root) return;
  if (root->left == nullptr && root->right == nullptr){
    mappy.insert(std::pair<char, std::string>(root->value.value,str));
  }

  get_keys(mappy, root->left, str + "0");
  get_keys(mappy, root->right, str + "1");
}

std::string encode(const std::string& M, bnode<symbol>* root){

  std::string binString = "";
  std::map<char,std::string> keyMap;
  get_keys(keyMap, root);

  for (unsigned int i = 0; i < M.size(); ++i){
    binString = binString + keyMap[M.at(i)];
  }
  return binString;
}

#endif

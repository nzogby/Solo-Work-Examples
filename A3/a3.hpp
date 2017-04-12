/***


 *  File: a3.hpp
 *  Author: Nathaniel Zogby njzogby

 A basic key-value data structure
 */

#ifndef A3_HPP
#define A3_HPP


#include <algorithm>
#include <list>
#include <vector>

class key_value_sequences {
public:
	key_value_sequences() : keys_(0), values_(0) {}

	key_value_sequences(const key_value_sequences& A){
		keys_ = A.keys_;
		values_ = A.values_;
	}

	key_value_sequences& operator=(const key_value_sequences& A){
		keys_ = A.keys_;
		values_ = A.values_;
		return *this;
	}


	int size(int key) {
		for (unsigned int i = 0; i < keys_.size(); ++i){
			if (keys_[i] == key) return values_[i].size();
		}
		return -1;
	}

r
	const int* data(int key) {
		for (unsigned int i = 0; i < keys_.size(); ++i){
			if (keys_[i] == key) return values_[i].data();
		}
		return nullptr;
	}

	void insert(int key, int value) {
		bool insertingKey = true;
		for (unsigned int i = 0; i < keys_.size(); ++i){
			if (keys_[i] == key) {
				values_[i].push_back(value);
				i = keys_.size();
				insertingKey = false;
			}
		}
		if (insertingKey){
			std::vector<int> temp;
			temp.push_back(value);
			values_.push_back(temp);
			keys_.push_back(key);
		}
	}

private:
	std::vector<int> keys_; //stores all keys for structure
	std::vector<std::vector<int>> values_; //stores the values for structure

};

#endif 

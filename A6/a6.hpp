/***
 *  File: a6.hpp
 *  Author: Nathaniel Zogby njzogby
 */

#ifndef A6_HPP
#define A6_HPP

#include <iostream>
#include "symbol.hpp"
#include <queue>
#include <vector>

struct comparator{
	bool operator()(const bnode<symbol>* lhs, const bnode<symbol>* rhs){
		return ((*rhs).value < (*lhs).value);
	}
};


template <typename Iter>
	bnode<symbol>* huffman_tree(Iter first, Iter last){
		std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>*>, comparator>  qlist;

		while(first != last){//create sorted list of bnode<symbol>
			bnode<symbol>* temp = new bnode<symbol>;
			temp->value = *first;
			qlist.push(temp);
			++first;
		}

		bnode<symbol>* left;
		bnode<symbol>* right;
		bnode<symbol>* top;

		while (qlist.size() != 1){//iterate through the tree to create final node

			left = qlist.top();//left bnode<symbol>*
			qlist.pop();

			right = qlist.top();//right bnode<symbol>*
			qlist.pop();

			top = new bnode<symbol>;
			top->left = left;
			top->right = right;

			if (left->value.value < right->value.value) top->value.value = left->value.value;
			else top->value.value = right->value.value;

			top->value.count = left->value.count + right->value.count;

			qlist.push(top);
		}//done with final node

		return qlist.top();
	}


void print_dictionary(std::ostream& os, bnode<symbol>* root, std::string str = ""){

	if (!root) return;
	if (root->left == nullptr && root->right == nullptr){
		os << root->value.value << " " << str << "\n";
	}

	print_dictionary(os, root->left, str + "0");
	print_dictionary(os, root->right, str + "1");
};


release_tree
void release_tree(bnode<symbol>* root){;
	if(root!= nullptr)
	{
		release_tree(root->left);
		release_tree(root->right);
		delete root;
	}
}


#endif // A5_HPP

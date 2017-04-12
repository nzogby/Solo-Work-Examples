/*  Author: Nathaniel Zogby njzogby

This assignment required us to use reverse polish notation to make basic calculations
using the "token" interface that was given to us
*/

#ifndef A5_HPP
#define A5_HPP

#include "token.hpp"
#include <stack>
#include <stdexcept>
#include <iostream>

template <typename Iter> double RPN(Iter first, Iter last) {
  std::stack<double> pusher;
  while (first != last){
    //checking if element is an operand. If so,push onto stack
    if ((*first).is_operand()) {
      pusher.push((*first).as_operand());
      ++first;
    }
    //else evauate expression
    else if (pusher.size() < 2) {
      throw std::runtime_error("Error: not enough arguments");
    }
    else{
      double temp = pusher.top();
      pusher.pop();
      //evaluating token
      if ((*first).as_operator() == '+') temp = pusher.top() + temp;
      else if ((*first).as_operator() == '-') temp = pusher.top() - temp;
      else if ((*first).as_operator() == '*') temp = pusher.top() * temp;
      else {
        if (temp == 0) throw std::runtime_error("Error: Divide by zero error");
        temp = pusher.top() / temp;
      }
      //finish evaluation

      pusher.pop();
      pusher.push(temp);
      ++first;
    }
  }
  double answer = pusher.top();
  pusher.pop();
  if (!pusher.empty()) throw std::runtime_error("Error: Too many arguments");
  return answer;
} // RPN

#endif // A5_HPP

#ifndef EXS_EXPRESSION_H
#define EXS_EXPRESSION_H

#include <sstream>

namespace exs {

class Expression {
public:
  std::string left;  // left side
  std::string right; // right side
  std::string expr;  // original expression
  Expression(std::string expression) {
    left  = "";
    right = expression;
    expr  = expression;
  };
  void shift(int nchar=1) {
    left  += right.substr(0,nchar);
    right =  right.substr(nchar,right.length());
  };
  void remove(std::string string) {
    right = right.substr(string.length(), right.length());
  };
  std::string pop_left() {
    std::string dummy = trim(left);
    left = "";
    return dummy;
  };
  std::string to_string() {
    std::stringstream ss;
    ss << "Expression(L'" << left << "' R'" << right << "' E'" << expr << "')";
    return ss.str();
  }
  void print() {
    std::cout << to_string() << std::endl;
  };
};

}

#endif // EXS_EXPRESSION_H

#ifndef EXS_OPERATOR_POWER_H
#define EXS_OPERATOR_POWER_H

#include <math.h>

namespace exs {
  
template <class A>
class OperatorPower: public OperatorBase<A> {
public:
  OperatorPower(std::string s="**"): OperatorBase<A>("pow", s, POWER_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->math_power(right.atom);
    tokens->put_left(left);
  };
};

}

#endif // EXS_OPERATOR_POWER_H

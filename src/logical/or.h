#ifndef EXS_OPERATOR_OR_H
#define EXS_OPERATOR_OR_H

namespace exs {
  
template <class A>
class OperatorOr: public OperatorBase<A> {
public:
  OperatorOr(std::string s="||"): OperatorBase<A>("or", s, OR_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->logical_or(right.atom);
    tokens->put_left(left);
  };
};

}

#endif // EXS_OPERATOR_OR_H

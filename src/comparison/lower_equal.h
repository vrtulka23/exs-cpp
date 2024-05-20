#ifndef OPERATOR_LOWER_EQUAL_H
#define OPERATOR_LOWER_EQUAL_H

template <class A>
class OperatorLowerEqual: public OperatorBase<A> {
public:
    OperatorLowerEqual(std::string s="<="): OperatorBase<A>("le", s, LOWER_EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
        Token<A> left = tokens->get_left();
        Token<A> right = tokens->get_right();
        left.atom->comparison_lower_equal(right.atom);
        tokens->put_left(left);
    };
};

#endif // OPERATOR_LOWER_EQUAL_H
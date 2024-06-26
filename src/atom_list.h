#ifndef EXS_ATOM_LIST_H
#define EXS_ATOM_LIST_H

#include <memory>

namespace exs {
  
template <class A>
class AtomList {
public:
  std::vector<std::shared_ptr<A>> atoms;
  A* append(std::string s) {
    atoms.push_back(std::make_shared<A>(A::from_string(s)));
    return &(*atoms.back());
  };
  A* append(A a) {
    atoms.push_back(std::make_shared<A>(a));
    return &(*atoms.back());
  };
};

}
  
#endif // EXS_ATOM_LIST_H

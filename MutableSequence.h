#include "DynamicArr.h"
template<class ElmType>
class MutableSequence
{
public:
    virtual ElmType getFirst() const = 0;

    virtual ElmType getLast() const = 0;

    virtual void popLast() = 0;

    virtual ElmType get(int) const = 0;

    virtual ElmType& operator[](int index) = 0;

    virtual int get_size() const = 0;

    virtual int get_colElm() const = 0;

    virtual void push_back(ElmType) = 0;

    virtual void set(int, const ElmType&) = 0;

    virtual void concat(const DynamicArray<ElmType>) = 0;
};

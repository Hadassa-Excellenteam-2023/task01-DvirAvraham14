//
// Created by Dvir Avraham on 21/03/2023.
//

#include "Stack.h"

// constructor
Stack::Stack(size_t size, int value)
: _data(size, value) {

}

// destructor
Stack::~Stack() {
};

// copy constructor
Stack::Stack(const Stack &other):
_data(other._data)
{
}

// assignment operator
Stack &Stack::operator=(const Stack &other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

// pop
int Stack::pop() {
    if (_data.empty())
        throw std::out_of_range("stack is empty");
    int value = _data[_data.size() - 1];
    _data.pop_back();
    return value;
}

// push value
void Stack::push(int value) {
    _data.push_back(value);
}

// check if stack is empty
bool Stack::isEmpty() const {
    return (_data.empty());
}

// operator overloading
bool Stack::operator==(const Stack &other) const {
    return _data == other._data;
}

bool Stack::operator!=(const Stack &other) const {
    return _data != other._data;
}

bool Stack::operator>(const Stack &other) const {
    return _data.size() > other._data.size();
}

bool Stack::operator<(const Stack &other) const {
    return _data.size() < other._data.size();
}

void Stack::operator/=(int divisor) {
    for(size_t i = 0; i < _data.size(); i++)
        _data[i] = _data[i] / divisor;
}

void Stack::operator*=(int multiplier) {
    for(size_t i = 0; i < _data.size(); i++)
        _data[i] = _data[i] * multiplier;
}

void Stack::operator+=(int add) {
    for(size_t i = 0; i < _data.size(); i++)
        _data[i] = _data[i] + add;
}

void Stack::operator-=(int sub) {
    for(size_t i = 0; i < _data.size(); i++)
        _data[i] = _data[i] - sub;
}

void Stack::operator+=(Stack &other) const{
    std::cout << "before other size: " << other._data.size()<< std::endl;
    for(size_t i = 0; i < _data.size(); i++)
        other.push(_data[i]);
    std::cout << "after other size: " << other._data.size()<< std::endl;
}

Stack& operator+(const Stack& lhs, const Stack& rhs) {
    auto newStack = new Stack(lhs);
    rhs += *newStack;
    return *newStack;
}
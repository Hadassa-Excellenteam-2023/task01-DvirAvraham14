#include <iostream>
#include "Stack.h"

int main(int argc, const char * argv[]) {

    Vector v(5, 10);  // create vector of size 5 with all elements initialized to 10
    std::cout << "v: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    Vector v2(v);  // create copy of v using copy constructor
    std::cout << "v2: ";
    for (int i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    v2[0] = 20;  // change first element of v2
    std::cout << "v2[0]: " << v2[0] << std::endl;

    v = v2;  // assign v to be equal to v2
    std::cout << "v: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "v empty: " << v.empty() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    std::cout << "v data: " << v.data() << std::endl;

    v.reserve(10);  // increase v's capacity to 10
    std::cout << "v capacity after reserve: " << v.capacity() << std::endl;

    v.clear();  // remove all elements from v
    std::cout << "v size after clear: " << v.size() << std::endl;

    v.push_back(30);  // add element 30 to the end of v
    std::cout << "v after push_back: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    v.pop_back();  // remove last element from v
    std::cout << "v after pop_back: ";
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // Create some stacks and push some values into them
    Stack s1(1, 1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);
    s2 = s1;

    // Test the operators and methods of the stack class
    while(!s2.isEmpty()){
        std::cout << s2.pop() << std::endl;
    }
    std::cout << std::endl;
    s2 = Stack(s1);
    std::cout << "s2 += s1 " << std::endl;
    s2 += 2;
    Stack s3 = s2 + s1;
    while(!s3.isEmpty()){
        std::cout << "x:\t";
        std::cout << s3.pop() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
    std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;

    return 0;
}
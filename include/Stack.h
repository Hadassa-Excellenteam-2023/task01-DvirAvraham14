//
// Created by Dvir Avraham on 21/03/2023.
//

#ifndef TASK_WEEK1_DVIR_AVRAHAM_STACK_H
#define TASK_WEEK1_DVIR_AVRAHAM_STACK_H

#include <cstdio>
#include "Vector.h"

class Stack  {
protected:
    Vector _data;

public:
    explicit Stack(size_t size, int value = 0);
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    int pop();
    void push(int value);
    bool isEmpty() const;

    //operator overloading
    bool operator==(const Stack& other) const;
    bool operator!=(const Stack& other) const;
    bool operator>(const Stack& other) const;
    bool operator<(const Stack& other) const;
    void operator/=(int);
    void operator*=(int);
    void operator+=(int);
    void operator-=(int);
    void operator+=(Stack& other) const;
};

Stack& operator+(const Stack&, const Stack&);

#endif //TASK_WEEK1_DVIR_AVRAHAM_STACK_H

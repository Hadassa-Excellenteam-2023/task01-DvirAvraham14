//
// Created by Dvir Avraham on 19/03/2023.
//

#ifndef TASK_WEEK1_DVIR_AVRAHAM_VECTOR_H
#define TASK_WEEK1_DVIR_AVRAHAM_VECTOR_H

// implemnt vector header file

#include <cstddef>
#include <stdexcept>
#include <iostream>

class Vector {
private:
    int* _data;
protected:
    int _size;
    int _capacity;
public:
    explicit Vector(size_t size, int value = 0);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    int& operator[](int index);
    int operator[](int index) const;
    bool empty() const;
    size_t size() const;
    int* data() const;
    void swap(Vector& other);
    void reserve(size_t newCapacity);
    size_t capacity() const;
    void clear();
    void push_back(int value);
    void pop_back();
    void operator=(int value);
    void insert(int index, int value);
    void erase(int index);
    bool operator!=(const Vector &other) const;
    bool operator==(const Vector &other) const;
    bool operator>=(const Vector &other) const;
    bool operator<=(const Vector &other) const;

};

#endif //TASK_WEEK1_DVIR_AVRAHAM_VECTOR_H

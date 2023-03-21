//
// Created by Dvir Avraham on 21/03/2023.
//

#include "Stack.h"

// constructor
Stack::Stack(size_t size, int value) {
    _data = new int[size];
    _size = size;
    _capacity = size;
    for (int i = 0; i < size; i++) {
        _data[i] = value;
    }
}
// Copyright 2022 Chris Olah

#ifndef _HOME_CHRIS_OLAH_PS4B_CIRCULARBUFFER_HPP_
#define _HOME_CHRIS_OLAH_PS4B_CIRCULARBUFFER_HPP_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>
#include <sstream>

class CircularBuffer {
 public:
    // create an empty ring buffer, with given max capacity
    explicit CircularBuffer(size_t capacity);
    size_t size();  // return number of items currently in the buffer
    bool isEmpty();  // is the buffer empty (size equals zero)?
    bool isFull();  // is the buffer full (size equals capacity)?
    void enqueue(int16_t x);  // add item x to the end
    int16_t dequeue();  // delete and return item from the front
    int16_t peek();  // return (but do not delete) item from the front
    int getCapacity() {
        return cap;
    }
    int getSize() {
        return s;
    }

 private:
    std::vector<int16_t> buf;
    int first;
    int last;
    int cap;
    int s;
};

#endif  // _HOME_CHRIS_OLAH_PS4B_CIRCULARBUFFER_HPP_

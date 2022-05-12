// Copyright 2022 Chris Olah
#include "CircularBuffer.hpp"

CircularBuffer::CircularBuffer(size_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("capacity must be greater than zero");
    }

    last = 0;
    first = 0;
    s = 0;
    cap = capacity;
    buf.resize(capacity);

    return;
}

bool CircularBuffer::isEmpty() {
    if (s != 0) {
        return false;
    } else {
        return true;
    }
}

bool CircularBuffer::isFull() {
    if (s == cap) {
        return true;
    } else {
        return false;
    }
}

size_t CircularBuffer::size() {
    return s;
}

void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    }
    if (last >= cap) {
        last = 0;
    }
    buf.at(last) = x;  // keep going
    last++;
    s++;
}

int16_t CircularBuffer::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("dequeue: can't dequeue an empty ring");
    }
    int16_t first16 = buf.at(first);
    buf.at(first) = 0;
    first++;
    s--;
    if (first >= cap) {
        first = 0;
    }
    return first16;
}

int16_t CircularBuffer::peek() {
    if (isEmpty()) {
        throw std::runtime_error("peek: can't peek an empty ring");
    }
    return buf.at(first);
}

// Copyright 2022 Chris Olah

#include "StringSound.hpp"
#include <vector>

#define SAMPLING_RATE 44100

StringSound::StringSound(std::vector<sf::Int16>init) {
    buffer =  new CircularBuffer(init.size());
    if (buffer == NULL) {
        throw std::runtime_error\
        ("StringSound Constructor: Could not allocate memory");
    }

    std::vector<sf::Int16>::iterator it;

    for (it = init.begin(); it < init.end(); it++) {
        buffer->enqueue((int16_t)*it);
    }
    tic_time = 0;
}

void StringSound::pluck() {
    for (int i = 0; i < num; i++) {
        buffer->dequeue();
    }
    for (int i = 0; i < num; i++) {
        buffer->enqueue((rand() % 32768));  // NOLINT
    }
}

StringSound::StringSound(double frequency) {
    num = ceil(SAMPLING_RATE / frequency);
    buffer = new CircularBuffer(num);
    if (buffer == NULL) {
        throw std::runtime_error\
        ("StringSound Constructor: Could not allocate memory");
    }

    for (int i = 0; i < num; i++) {
        buffer->enqueue((int16_t)0);
    }

    tic_time = 0;
}

void StringSound::tic() {
    int16_t first = buffer->dequeue();
    int16_t second = buffer->peek();

    int16_t newNum = 0.994 *((first+second)/2);

    if (newNum > 0.994 *((first+second)/2)) {
        throw std::invalid_argument("tic(): Wrong value of newNum for buffer");
    }

    buffer->enqueue((sf::Int16)newNum);

    tic_time++;
}

sf::Int16 StringSound::sample() {
    sf::Int16 sample =(sf::Int16)buffer->peek();
    return sample;
}

int StringSound::time() {  // lambda expression
    int lambda = tic_time;
    auto f = [lambda] { return lambda; };
    auto lamby = f();
    return lamby;
}

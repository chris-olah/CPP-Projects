// Copyright 2022 Chris Olah

#ifndef _HOME_CHRIS_OLAH_PS4B_STRINGSOUND_HPP_
#define _HOME_CHRIS_OLAH_PS4B_STRINGSOUND_HPP_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "CircularBuffer.hpp"

class StringSound {
 public:
    explicit StringSound(double frequency);
                                    // create a guitar string sound of the
                                    // given frequency using a sampling rate
                                    // of 44,100

    explicit StringSound(std::vector<sf::Int16> init);
                                       // create a guitar string with
                                       // size and initial values are given by
                                       // the vector

    void pluck();                    // pluck the guitar string by replacing
                                    // the buffer with random values,
                                    // representing white noise
    void tic();                         // advance the simulation one time step
    sf::Int16 sample();                 // return the current sample
    int time();                         // return number of times tic was called
                                    // so far
 private:
    CircularBuffer* buffer;
    int tic_time;
    int num;
};


#endif  // _HOME_CHRIS_OLAH_PS4B_STRINGSOUND_HPP_

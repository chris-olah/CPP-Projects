// Copyright 2022 Chris Olah

#include "EDistance.hpp"

int main(int argc, char* argv[]) {
          sf::Clock clock;
          sf::Time t;

          std::string string1;
        std::string string2;

        std::cin >> string1;
        std::cin >> string2;

        EditDistance test(string1, string2);

        test.alg();
        std::cout << "Edit Distance = " << test.OptDistance() << std::endl;
        std::cout << test.Alignment() << std::endl;

        t = clock.getElapsedTime();
        std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

        return 0;
}

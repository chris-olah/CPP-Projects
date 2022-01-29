/**************************************************
Computing IV Project 0 - Setting Up Coding Environemnt with SFML
Author: Christopher Olah
Date: January 24, 2022
Code Extended From: https://www.sfml-dev.org/documentation/2.5.1/
**************************************************/

#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");

    // Load and display sprite
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Move Sprite 
    int changeX = 200;
    int changeY = 200;
    sprite.move(changeX, changeY);

    // Display Green Circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Move Green Circle
    shape.move(25, 25);

    // Start Window Display Loop
    while (window.isOpen())
    {  
        // Press Up Key to Move Sprite Upwards
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(changeX, changeY - 2);
        } 

        // Press Down Key to Move Sprite Downwards
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(changeX, changeY + 2);
        } 

        // Press R Key to Change Sprite Color to Green 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            sprite.setColor(sf::Color::Green);
        }
        else {
            changeX = 0;
        } 

        //Press Left key to Move Sprite Leftwards
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(changeX - 2, changeY);
        }

        // Press Right Key to Move Sprite Rightwards
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(changeX + 2, changeY);
        } 
        else {
            changeY = 0;
        }

        // Top Wall Collision
        if (sprite.getPosition().y < 0)
            sprite.setPosition(sprite.getPosition().x, 0);
        
        // Bottom Collision
        if (sprite.getPosition().y + sprite.getGlobalBounds().height > 700)
            sprite.setPosition(sprite.getPosition().x, 700 - sprite.getGlobalBounds().height);

        // Left Wall Collision
        if (sprite.getPosition().x < 0)
            sprite.setPosition(0, sprite.getPosition().y);
        
        // Right Wall Collision
        if (sprite.getPosition().x + sprite.getGlobalBounds().width > 1000)
            sprite.setPosition(1000 - sprite.getGlobalBounds().width, sprite.getPosition().y);

        // Process Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Clear Screen
        window.clear();

        // Display sprite
        window.draw(sprite);

        // Display Green Circle
        window.draw(shape);

        // Update Window
        window.display();
    }

    return 0;
}

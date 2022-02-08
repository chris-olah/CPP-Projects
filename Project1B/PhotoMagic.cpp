/************************************************************
* @file PhotoMagic.cpp
* @author: Chris Olah
* @copyright Umass Lowell February 7 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 1B
* Professor: Dr. Daly
************************************************************/

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <string> 
#include "FibLFSR.h"

/**
* @brief Tests if this string starts with the specified prefix.
* @param inputImage Original image to be decrypted into output Image
* @param flfsr Binary seed of FibLFSR class for encryption/decryption process  
* @since 1.0 
*/
void transform(sf::Image& inputImage, FibLFSR* flfsr) {
    sf::Vector2u imageSize = inputImage.getSize(); ///< Size of input image (width * height)

    sf::Color pixel; ///< Single image pixel  

    for (int x = 0; x < (int) imageSize.x; x++) { //< Go through every pixel and encrypt/decrypt them
        for (int y = 0; y < (int) imageSize.y; y++) {
            pixel = inputImage.getPixel(x, y);
            pixel.r = (pixel.r ^ flfsr->generate(8));
            pixel.g = (pixel.g ^ flfsr->generate(8));
            pixel.b = (pixel.b ^ flfsr->generate(8));
            inputImage.setPixel(x, y, pixel);
        }
    }
}

/**
* @brief Dislay original input image along with encrypted/decrypted output image 
* @param inputImage Original image to be decrypted into output Image
* @param flfsr Binary seed of FibLFSR class for encryption/decryption process  
* @since 1.0 
*/
void draw(sf::Image& inputImage, FibLFSR* flfsr) {
    sf::Vector2u imageSize = inputImage.getSize(); //< Size of input image (width * height)
    
    sf::Image outputImage = inputImage; //< Create output image and copy input image to it 

    transform(outputImage, flfsr); //< Encrypt/Decrypt given output image 

    sf:: Texture inputTexture, outputTexture;
    inputTexture.loadFromImage(inputImage);
    outputTexture.loadFromImage(outputImage);

    sf::Sprite inputSprite, outputSprite;
    inputSprite.setTexture(inputTexture); 
    outputSprite.setTexture(outputTexture);

    sf::RenderWindow inputWindow(sf::VideoMode(imageSize.x, imageSize.y), "Input Image");
    sf::RenderWindow outputWindow(sf::VideoMode(imageSize.x, imageSize.y), "Output Image");

    while (inputWindow.isOpen() && outputWindow.isOpen()) { //< Display input and output image in two seperate windows 
        sf::Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                inputWindow.close();
        }
        while (outputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                outputWindow.close();
            }

        inputWindow.clear(sf::Color::Black);
        inputWindow.draw(inputSprite); //< Draw input image
        inputWindow.display();

        outputWindow.clear(sf::Color::Black);
        outputWindow.draw(outputSprite); //< Draw output image 
        outputWindow.display();
    }    

    inputImage = outputImage; //< Maintain original image 
}

int main(int argc, char* argv[]) {
    sf::Image inputImage; //< Create image input image 

    string inputFileName(argv[1]);  //< Take second command store as input file name 
    string outputFileName(argv[2]); //< Take third command store as output file name 
    string seed = argv[3];          //< Take fourth command and store it as seed 

    inputImage.loadFromFile(inputFileName); //< Store input file image into inputImage 

    FibLFSR flfsr(seed); //< Store seed value into FibLFSR 
    
    draw(inputImage, &flfsr); //< Display input and encrypted/decrypted output image given seed 
    
    if (!inputImage.saveToFile(outputFileName)) //< Save encrypted/decrypted image to new output file 
        return -1; 

    return 0;
}

/**********************************************************************
 *  Project 1B - LFSR PhotoMagic 
 **********************************************************************/

Name: Chris Olah

/**********************************************************************
 *  Command Instructions 
 **********************************************************************/
    $ ./PhotoMagic [input file] [output file] [LFSR seed (binary)]
/**********************************************************************
 *  Program Functionality: 
 **********************************************************************/
The PhotoMagic functionality fully works. It is able to take an input image
and then go through each pixel and use 8 bit LFSR seed to encrypt the 
image. Then, it also able to be given the encrypted image, and go through the 
encryption/decryption process again (XOR pixel with 8 bit LFSR value) to 
display the original image. The command functionality works as well. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I recieved help from my instructor via office hours on how to display 
input along with output image in two different windows at the same time

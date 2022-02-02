/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Chris Olah
Hours to complete assignment: 8
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
In this assignment we were required to write a program that produces 
psuedo-random bits by simulating a linear feedback register (LFSR). The
LFSR performs operations such as shifting the btis one position to the 
left as well as replacing the vacated bit with the exclusive or of the 
bits shifted off and the bits previously at the given taps position in 
the register. I accomplished this by implementing a class structure to 
store the seed as well as the necessary member functions to perform the 
operations on the shiftings bits. 

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
To represent the register bits, I chose to add a private string variable 
in the FibLFSR class to represent the present state of the string seed.
The step() function was also impleneted to modify the current state of the 
seed and shift the bits one position to the left and getting the value of
shifted bit adjusted with the tap positions and comparing them using the 
xor comparison. I seleted a string to represent the seed because of 
readability as well as its simplicity in modifying a string.  

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
For the two additional Boost unit tests, I implemented a test of a 20 bit 
all zeroes seed to assure the step() and generate() functions were working
properly. The other test I impemented was a test to make sure the constructor
saved the seed correctly as well as outputted (by overloading the seed 
insertion operator) correctly. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I recieved help from both the instructor and classmates on a makefile issue 
as well as a displaying the seed after using the step() function via Discord. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The biggest problem I ran into was trying to get the seed values to output 
correctly after using the step() function on it. At one point, the newBit 
was not being added to the end of the string after shifting all the bits
to the left, but this was solved after noticing it was a issue of different 
types of variables being introduced to the outputted seed value (int being added to 
character string/character being added to int). The Makefile presented an issue 
too of not being able to locate the main function, but this was solved via discord 
help as well and moving the main into a seperate source file named main.cpp

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
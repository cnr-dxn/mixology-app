# Interactive Mixology App

A mixology app used to identify the drinks the user can make by having them input the ingredients they have and reading from a file of possible combinations.

**Object Oriented Programming**: In order to increase the efficiency of the algorithm, object oriented programming was implemented, with each drink acting as its own object when being analyzed.  

**Ease-of-Access Features**: In order to allow for the best and easiest access by the user, a multitude of different features were put in place to allow for less work to be put in by the user.

## How to run this application:

This is run as a C++ application, and thus to allow correct access to existing credientials to the necessary executables, run the following code:
```
g++ -o main Drink.cpp game.cpp
```
This will compile the necessary code into an executable titled main, so to run simply execute it:
```
./main
```
Then just simply follow the directions output to the screen! It will ask you to enter various ingredients, and when done enter as such and the drinks that can be made will be print to the screen.

## File Structure

**game.cpp** is where all the main functionality is written.

**Drink.h** and **Drink.cpp** are the implimentation of the Drink class, the class responsible for the creation of the drink objects/

## Notes

As seen in the code, there are various ingredients already hardcoded in the project, as at the time of creation those were ingredients I had readily available. Thus, if drinks appear that do not align with the input ingredients, they still are valid.


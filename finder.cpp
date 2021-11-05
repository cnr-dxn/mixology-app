#include "Drink.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <limits>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void diningHallIngredientsPopulate(vector<string> &usersIngredients)
{
	usersIngredients.push_back("soda water");
	usersIngredients.push_back("orange juice");
	usersIngredients.push_back("ginger beer");
	usersIngredients.push_back("sprite");
	usersIngredients.push_back("ice cream");
	usersIngredients.push_back("heavy cream");
	usersIngredients.push_back("coke");
	usersIngredients.push_back("simple syrup");
	usersIngredients.push_back("grenadine");
	usersIngredients.push_back("cranberry juice");
	usersIngredients.push_back("coffee");
	usersIngredients.push_back("lemonade");
	usersIngredients.push_back("apple juice");
	usersIngredients.push_back("chocolate milk");
	usersIngredients.push_back("root beer");
	usersIngredients.push_back("mountain dew");
}


string convert(string input)
{
        string finalString = "";
        for (int i = 0; i < input.length(); i++)
        {
                finalString += tolower(input[i]);
        }

        return finalString;
}

void checkChoicesAgainst(vector<string> &usersIngredients, vector<Drink> &drinks)
{
	bool determiner = false;
	int counter = 0;
	//for (int i = 0; i < usersIngredients.size(); i++)
	for (int i = 0; i < drinks.size(); i++)
	{
		//for (int j = 0; j < drinks.size(); j++)
		for (int j = 0; j < usersIngredients.size(); j++)
		{
			for (int k = 0; k < drinks[i].getIngredientsLength(); k++)
			{
				if (convert(usersIngredients[j]) == convert(drinks[i].getIngredientsAt(k)))
				{
					counter++;
				}
			}
		}

		if (counter == drinks[i].getIngredientsLength())
		{
			determiner = true;
			cout << drinks[i].getName() << " (";
			for (int m = 0; m < drinks[i].getIngredientsLength(); m++)
			{
				if (m == (drinks[i].getIngredientsLength() - 1))
				{
					cout << drinks[i].getIngredientsAt(m);
				}

				else
				{
					cout << drinks[i].getIngredientsAt(m) << ", ";
				}
			}
			cout << ")" << endl; 
		}
		
		counter = 0;
	}

	if (determiner == false)
	{
		cout << "Unfortunately no drinks can be found just with those ingredients." << endl;
	}
}

bool checkChoiceValidity(string input, vector<Drink> &drinks)
{
	bool determiner = false;
	for (int i = 0; i < drinks.size(); i++)
	{
		for (int j = 0; j < drinks[i].getIngredientsLength(); j++)
		{
			if (convert(input) == convert(drinks[i].getIngredientsAt(j)))
			{
				determiner = true;
			}
		}
	}

	return determiner;
}

int split(string lineSequence, char delimitor, vector<string> &vect)
{                 
	string temp;
        // Establish a temporary variable used to transfer array values later
        // in the fuction
        int lengthwords = 0;

        if(lineSequence == "")
        // If the line doesn't exist, return 0
        {
            return 0;
        }

        else
        {

        lineSequence = lineSequence + delimitor;
        // Ensure the sequence includes the delimitor as to prevent unwanted
        // values being populated

        for(int count = 0; count < lineSequence.length(); count++)
        // Enter for loop
        {

            if(lineSequence[count] != delimitor)
            // If the character in the string at that certain point isn't
            // the delimitor, set the temporary variable equal to the temp character
            // plus the new character
            {
                temp = temp + lineSequence[count];
            }

            else
            // Else, create an entry in the array that equals the temp variable
            {
                if(temp.length()!=0)
                {
                        vect.push_back (temp);
                        lengthwords++;
                }
                temp = "";
                // Clear the temp variable
            }   
	  }
	}
        return lengthwords;
        // Return the counter variable (lengthWords)
}

int main()
{
	ifstream fileTool1;
	ifstream fileTool2;
	
	vector<Drink> drinks;
	vector<string> ingredients;
	vector<string> usersIngredients;
	bool determiner;
	string continuer = "";
//=====================================================================================================
	fileTool1.open("drinks.txt");

                if (fileTool1.is_open())
                {
                        string line = "";
                        int counter = 0;
                        while (getline(fileTool1, line))
                        {
				if (line == "" && line == " ")
				{

				}

                                vector<string> tmp;
                                
				tmp.clear();

                                split(line, ',', tmp);

                                Drink temp;
                                // Split the line using the split function by commas
                                temp.setName(tmp[0]);
                                // Set the first entry in the array equal to the author
                                tmp.erase (tmp.begin());
                                // Set the second entry in the array equal to the title
                                temp.setIngredients(tmp);
                                // Set the second entry in the array equal to the title
                                drinks.push_back(temp);
                                // Store the index of the book array equal to the temp
                                // object
                                counter++;
                                // Incriment the number of books now stored in the
                                // arrays by 1
                        }
                }

                else
                {
                        cout << "The file didn't open correctly" << endl;
                        sleep_for(milliseconds(60));
                }
        fileTool1.close();
//=====================================================================================================

	}

}

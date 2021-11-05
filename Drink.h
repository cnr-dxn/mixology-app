#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Drink
{
	public:
	Drink();
	Drink(string);

	void setName(string);
	void setIngredients(vector<string>);

	string getName();
	int getIngredientsLength();
	string getIngredientsAt(int);

	private:
	string name;
	vector<string> ingredients;
};

#endif

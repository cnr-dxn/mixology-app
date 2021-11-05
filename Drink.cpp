#include "Drink.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

Drink::Drink()
{
	name = "";
}

Drink::Drink(string name_)
{
	name = name_;
}

void Drink::setName(string name_)
{
	name = name_;
}

void Drink::setIngredients(vector<string> ingredients_)
{
	ingredients = ingredients_;
}

string Drink::getName()
{
	return name;
}

int Drink::getIngredientsLength()
{
	return ingredients.size();
}

string Drink::getIngredientsAt(int i)
{
	return ingredients[i];
}

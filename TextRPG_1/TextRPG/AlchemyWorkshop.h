#pragma once
#include <iostream>
#include <vector>
#include "PotionRecipe.h"
using namespace std;

class AlchemyWorkshop
{
private:
	vector<PotionRecipe> recipes;
	void printRecipeByIngredient(const PotionRecipe& r);
	void printRecipeByName(const PotionRecipe& r);
public:
	AlchemyWorkshop();
	void ShowAllRecipes();
	void SearchByName(string name);
	void SearchByIngredient(string ingredient);
	void Run();
};
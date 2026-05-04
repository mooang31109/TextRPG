#include "AlchemyWorkshop.h"

//레시피 출력 구조(이름으로 검색)
void AlchemyWorkshop::printRecipeByIngredient(const PotionRecipe& r)
{
	cout << "-> " << r.name << " (" << r.ingredient1 << " x" << r.amount1
		<< ", " << r.ingredient2 << " x" << r.amount2 << ")" << endl;
}

//레시피 출력 구조(재료로 검색)
void AlchemyWorkshop::printRecipeByName(const PotionRecipe& r)
{
	cout << "-> " << r.name << ": " << r.ingredient1 << " x" << r.amount1
		<< ", " << r.ingredient2 << " x" << r.amount2 << endl;
}

//생성자
//포션 레시피 등록
AlchemyWorkshop::AlchemyWorkshop()
{
	recipes.push_back({ "HPPotion", "Herb", 1, "Clear Water", 1});
	recipes.push_back({ "MPPotion", "Mint", 1, "Clear Water", 1 });
	recipes.push_back({ "StaminaPotion", "Herb", 1, "Berry", 1 });
	recipes.push_back({ "PowerPotion", "Mint", 1, "Berry", 1 });
}

//1. 전체 레시피 출력
void AlchemyWorkshop::ShowAllRecipes()
{
	cout << "\n[ All Recipes ]" << endl;
	for (const PotionRecipe& r : recipes)
	{
		printRecipeByIngredient(r);
	}
}

//2. 이름으로 검색
void AlchemyWorkshop::SearchByName(string name)
{
	for (const PotionRecipe& r : recipes)
	{
		if (r.name == name)
		{
			printRecipeByName(r);
			return;
		}
	}
	cout << "-> Not found." << endl;
}

//3. 재료로 검색
void AlchemyWorkshop::SearchByIngredient(string ingredient)
{
	int count = 0;
	for (const PotionRecipe& r : recipes)
	{
		if (r.ingredient1 == ingredient || r.ingredient2 == ingredient)
		{
			printRecipeByIngredient(r);
			count++;
		}
	}
	if (count == 0)
	{
		cout << "-> Not found." << endl;
	}
	else
	{
		cout << "Found " << count << " recipes." << endl;
	}
}

//포션샵 메뉴
void AlchemyWorkshop::Run()
{
	int choice;
	string input;
	bool isShop = true;
	while (isShop)
	{
		cout << "\n=== Potion Shop ===" << endl;
		cout << "1. Show all reecipes" << endl;
		cout << "2. Search by potion name" << endl;
		cout << "3. Search by ingredient" << endl;
		cout << "0. Go back" << endl;
		cout << "\nChoose: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			isShop = false;
			break;
		case 1:
			ShowAllRecipes();
			break;
		case 2:
			cout << "Search potion name: ";
			cin >> input;
			SearchByName(input);
			break;
		case 3:
			cout << "Search ingredient: ";
			cin >> input;
			SearchByIngredient(input);
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}
	}
}
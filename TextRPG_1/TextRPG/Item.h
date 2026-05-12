#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int price;
    string type; //potion drop

    void PrintInfo() const
    {
        cout << name << " (" << price << "G)" << endl;
    }
};
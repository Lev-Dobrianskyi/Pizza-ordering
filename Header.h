#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




using namespace System::IO;
public ref class Pizza
{
private:
    String^ name;
    String^ ingredients;
public:
    Pizza(String^ name, String^ ingredients)
    {
        this->ingredients = ingredients;
        this->name = name;
    }

    void SavePizza()
    {
        StreamWriter^ obj = gcnew StreamWriter("Pizzas/"+name+".txt");
        obj->WriteLine("Pizza ingredients: " + ingredients);
        obj->Close();
    }
};

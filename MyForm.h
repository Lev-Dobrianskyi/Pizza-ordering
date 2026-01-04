#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include "Header.h"
namespace dz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	using namespace msclr::interop; //<<<<<< marshal_as
	using namespace System::Collections::Generic; //<<<<<< List



	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		List<Pizza^>^ Pizzas;
	public:
		MyForm(void)
		{
			InitializeComponent();
			Pizzas = gcnew List<Pizza^>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ createPizza;
	private: System::Windows::Forms::Button^ savePizza;
	private: System::Windows::Forms::TextBox^ ingredientsBox;





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->createPizza = (gcnew System::Windows::Forms::Button());
			this->savePizza = (gcnew System::Windows::Forms::Button());
			this->ingredientsBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pizza generator";
			// 
			// createPizza
			// 
			this->createPizza->Location = System::Drawing::Point(8, 115);
			this->createPizza->Name = L"createPizza";
			this->createPizza->Size = System::Drawing::Size(75, 23);
			this->createPizza->TabIndex = 1;
			this->createPizza->Text = L"Add pizza";
			this->createPizza->UseVisualStyleBackColor = true;
			this->createPizza->Click += gcnew System::EventHandler(this, &MyForm::createPizza_Click);
			// 
			// savePizza
			// 
			this->savePizza->Location = System::Drawing::Point(8, 154);
			this->savePizza->Name = L"savePizza";
			this->savePizza->Size = System::Drawing::Size(84, 23);
			this->savePizza->TabIndex = 2;
			this->savePizza->Text = L"Order pizza(s)";
			this->savePizza->UseVisualStyleBackColor = true;
			this->savePizza->Click += gcnew System::EventHandler(this, &MyForm::savePizza_Click);
			// 
			// ingredientsBox
			// 
			this->ingredientsBox->Location = System::Drawing::Point(8, 89);
			this->ingredientsBox->Name = L"ingredientsBox";
			this->ingredientsBox->Size = System::Drawing::Size(100, 20);
			this->ingredientsBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(114, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"<<< Pizza\'s ingredients";
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(8, 63);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(100, 20);
			this->nameBox->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(114, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"<<< Pizza\'s name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->label4->Location = System::Drawing::Point(124, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"(as a single string)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ingredientsBox);
			this->Controls->Add(this->savePizza);
			this->Controls->Add(this->createPizza);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createPizza_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = nameBox->Text;
		String^ ingredients = ingredientsBox->Text;
		Pizza^ pizzaObj = gcnew Pizza(name, ingredients);
		Pizzas->Add(pizzaObj);
		nameBox->Clear();
		ingredientsBox->Clear();
	}
private: System::Void savePizza_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!Directory::Exists("Pizzas")) {
		Directory::CreateDirectory("Pizzas");
	}
	for each (Pizza^ pizza in Pizzas)
	{
		pizza->SavePizza();
	}

	MessageBox::Show("All pizzas ordered","Order successfull!");
}
};
}

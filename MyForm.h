#pragma once
#include "theGame.h"
#include "RecordsForm.h"

namespace TheBestestGameOfTheWorld {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ welcom_label;
        System::Windows::Forms::RadioButton^ easy_label;
        System::Windows::Forms::RadioButton^ middle_label;
        System::Windows::Forms::RadioButton^ bizzare_label;
        System::Windows::Forms::RadioButton^ hard_label;
        System::Windows::Forms::Label^ welcom2_label;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::GroupBox^ groupBox1;
        System::Windows::Forms::Label^ difficulty_label;
        System::Windows::Forms::Label^ name_label;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::TextBox^ name_textbox;
        System::Windows::Forms::Label^ input_name_label;
        System::Windows::Forms::Button^ run_game_button;
        System::Windows::Forms::Button^ records_button;

        System::String^ playerName;
        System::String^ difficultyChosen;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->welcom_label = (gcnew System::Windows::Forms::Label());
            this->easy_label = (gcnew System::Windows::Forms::RadioButton());
            this->middle_label = (gcnew System::Windows::Forms::RadioButton());
            this->bizzare_label = (gcnew System::Windows::Forms::RadioButton());
            this->hard_label = (gcnew System::Windows::Forms::RadioButton());
            this->welcom2_label = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->name_label = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->difficulty_label = (gcnew System::Windows::Forms::Label());
            this->name_textbox = (gcnew System::Windows::Forms::TextBox());
            this->name_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::name_textbox_TextChanged);
            this->input_name_label = (gcnew System::Windows::Forms::Label());
            this->run_game_button = (gcnew System::Windows::Forms::Button());
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
            // 
            // welcom_label
            // 
            this->welcom_label->AutoSize = true;
            this->welcom_label->Font = (gcnew System::Drawing::Font(L"Calibri", 20, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->welcom_label->Location = System::Drawing::Point(40, 27);
            this->welcom_label->Name = L"welcom_label";
            this->welcom_label->Size = System::Drawing::Size(897, 49);
            this->welcom_label->TabIndex = 1;
            this->welcom_label->Text = L"Добро пожаловать в самое бизарное приключение";
            // 
            // easy_label
            // 
            this->easy_label->AutoSize = true;
            this->easy_label->Location = System::Drawing::Point(49, 194);
            this->easy_label->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->easy_label->Name = L"easy_label";
            this->easy_label->Size = System::Drawing::Size(95, 28);
            this->easy_label->TabIndex = 2;
            this->easy_label->Text = L"Легкий";
            this->easy_label->UseVisualStyleBackColor = true;
            this->easy_label->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::easy_label_MouseCaptureChanged);
            // 
            // middle_label
            // 
            this->middle_label->AutoSize = true;
            this->middle_label->Location = System::Drawing::Point(49, 230);
            this->middle_label->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->middle_label->Name = L"middle_label";
            this->middle_label->Size = System::Drawing::Size(111, 28);
            this->middle_label->TabIndex = 3;
            this->middle_label->Text = L"Средний";
            this->middle_label->UseVisualStyleBackColor = true;
            this->middle_label->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::middle_label_MouseCaptureChanged);
            // 
            // bizzare_label
            // 
            this->bizzare_label->AutoSize = true;
            this->bizzare_label->Location = System::Drawing::Point(49, 266);
            this->bizzare_label->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->bizzare_label->Name = L"bizzare_label";
            this->bizzare_label->Size = System::Drawing::Size(121, 28);
            this->bizzare_label->TabIndex = 4;
            this->bizzare_label->Text = L"Бизарный";
            this->bizzare_label->UseVisualStyleBackColor = true;
            this->bizzare_label->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::bizzare_label_MouseCaptureChanged);
            // 
            // hard_label
            // 
            this->hard_label->AutoSize = true;
            this->hard_label->Location = System::Drawing::Point(49, 302);
            this->hard_label->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->hard_label->Name = L"hard_label";
            this->hard_label->Size = System::Drawing::Size(329, 28);
            this->hard_label->TabIndex = 5;
            this->hard_label->Text = L"Настоящие мужские приключения";
            this->hard_label->UseVisualStyleBackColor = true;
            this->hard_label->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::hard_label_MouseCaptureChanged);
            // 
            // welcom2_label
            // 
            this->welcom2_label->AutoSize = true;
            this->welcom2_label->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->welcom2_label->Location = System::Drawing::Point(44, 141);
            this->welcom2_label->Name = L"welcom2_label";
            this->welcom2_label->Size = System::Drawing::Size(319, 29);
            this->welcom2_label->TabIndex = 6;
            this->welcom2_label->Text = L"Выберите уровень сложности";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(21, 38);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(266, 24);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Текущий уровень сложности: ";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->name_label);
            this->groupBox1->Controls->Add(this->label5);
            this->groupBox1->Controls->Add(this->difficulty_label);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->groupBox1->Location = System::Drawing::Point(495, 158);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(403, 224);
            this->groupBox1->TabIndex = 8;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Настроенные параметры";
            // 
            // name_label
            // 
            this->name_label->AutoSize = true;
            this->name_label->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->name_label->Location = System::Drawing::Point(293, 74);
            this->name_label->Name = L"name_label";
            this->name_label->Size = System::Drawing::Size(59, 24);
            this->name_label->TabIndex = 10;
            this->name_label->Text = L"NONE";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(21, 72);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(229, 24);
            this->label5->TabIndex = 9;
            this->label5->Text = L"Героический псевдоним: ";
            this->label5->TextAlign = System::Drawing::ContentAlignment::TopRight;
            // 
            // difficulty_label
            // 
            this->difficulty_label->AutoSize = true;
            this->difficulty_label->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->difficulty_label->Location = System::Drawing::Point(293, 38);
            this->difficulty_label->Name = L"difficulty_label";
            this->difficulty_label->Size = System::Drawing::Size(59, 24);
            this->difficulty_label->TabIndex = 8;
            this->difficulty_label->Text = L"NONE";
            // 
            // name_textbox
            // 
            this->name_textbox->Location = System::Drawing::Point(49, 415);
            this->name_textbox->Name = L"name_textbox";
            this->name_textbox->Size = System::Drawing::Size(329, 32);
            this->name_textbox->TabIndex = 9;
            this->name_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::name_textbox_KeyDown);
            // 
            // input_name_label
            // 
            this->input_name_label->AutoSize = true;
            this->input_name_label->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->input_name_label->Location = System::Drawing::Point(44, 369);
            this->input_name_label->Name = L"input_name_label";
            this->input_name_label->Size = System::Drawing::Size(384, 29);
            this->input_name_label->TabIndex = 10;
            this->input_name_label->Text = L"Введите ваше имя: (<= 10 символов)";
            // 
            // run_game_button
            // 
            this->run_game_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"run_game_button.BackgroundImage")));
            this->run_game_button->Font = (gcnew System::Drawing::Font(L"Calibri", 16, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->run_game_button->Location = System::Drawing::Point(571, 398);
            this->run_game_button->Name = L"run_game_button";
            this->run_game_button->Size = System::Drawing::Size(256, 74);
            this->run_game_button->TabIndex = 11;
            this->run_game_button->UseVisualStyleBackColor = true;
            this->run_game_button->Click += gcnew System::EventHandler(this, &MyForm::run_game_button_Click);
            //
            // records_button
            // 
            this->records_button = (gcnew System::Windows::Forms::Button());
            this->records_button->Text = L"Рекорды";
            this->records_button->Font = (gcnew System::Drawing::Font(L"Calibri", 16, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->records_button->Location = System::Drawing::Point(571, 300);
            this->records_button->Size = System::Drawing::Size(256, 74);
            this->records_button->Click += gcnew System::EventHandler(this, &MyForm::records_button_Click);
            this->Controls->Add(this->records_button);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 24);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->ClientSize = System::Drawing::Size(998, 484);
            this->Controls->Add(this->run_game_button);
            this->Controls->Add(this->input_name_label);
            this->Controls->Add(this->name_textbox);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->welcom2_label);
            this->Controls->Add(this->hard_label);
            this->Controls->Add(this->bizzare_label);
            this->Controls->Add(this->middle_label);
            this->Controls->Add(this->easy_label);
            this->Controls->Add(this->welcom_label);
            this->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"BizzareAdventure 2";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private: System::Void name_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        System::String^ input = this->name_textbox->Text;
        int maxLength = 10;
        if (input->Length > maxLength) {
            MessageBox::Show("Ваше имя слишком длинное");
            this->name_textbox->Text = input->Substring(0, maxLength);
            this->name_textbox->SelectionStart = this->name_textbox->Text->Length;
        }
        else {
            this->name_label->Text = input;
            this->playerName = input;
        }
    }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void easy_label_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
        this->difficulty_label->Text = "Easy";
        this->difficulty_label->ForeColor = System::Drawing::Color::Green;
        this->difficulty_label->Font = gcnew System::Drawing::Font(this->difficulty_label->Font->FontFamily,
            this->difficulty_label->Font->Size, System::Drawing::FontStyle::Bold);
    }
    private: System::Void middle_label_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
        this->difficulty_label->Text = "Middle";
        this->difficulty_label->ForeColor = System::Drawing::Color::Yellow;
        this->difficulty_label->Font = gcnew System::Drawing::Font(this->difficulty_label->Font->FontFamily,
            this->difficulty_label->Font->Size, System::Drawing::FontStyle::Bold);
    }
    private: System::Void bizzare_label_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
        this->difficulty_label->Text = "BIZZARE";
        this->difficulty_label->ForeColor = System::Drawing::Color::Red;
        this->difficulty_label->Font = gcnew System::Drawing::Font(this->difficulty_label->Font->FontFamily,
            this->difficulty_label->Font->Size, System::Drawing::FontStyle::Bold);
    }
    private: System::Void hard_label_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
        this->difficulty_label->Text = "HARDCORE";
        this->difficulty_label->ForeColor = System::Drawing::Color::Purple;
        this->difficulty_label->Font = gcnew System::Drawing::Font(this->difficulty_label->Font->FontFamily,
            this->difficulty_label->Font->Size, System::Drawing::FontStyle::Bold);
    }

    private: System::Void name_textbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
            System::String^ input = this->name_textbox->Text;
            int maxLength = 10;
            if (input->Length > maxLength) {
                MessageBox::Show("Ваше великолепное имя слишком длинное");
            }
            else if (input->Length == 0) {
                MessageBox::Show("Имя не может быть пустым.");
            }
            else {
                this->name_label->Text = input;
                this->playerName = input;
            }
            e->Handled = true;
        }
    }

    private: System::Void run_game_button_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->difficulty_label->Text == "NONE") {
            MessageBox::Show("Выберите уровень сложности!");
            return;
        }

        if (String::IsNullOrEmpty(this->playerName)) {
            MessageBox::Show("Введите имя!");
            return;
        }

        this->difficultyChosen = this->difficulty_label->Text;

        TheBestestGameOfTheWorld::theGame^ TheGameForm = gcnew TheBestestGameOfTheWorld::theGame(this->playerName, this->difficultyChosen, this);

        TheGameForm->Show();
        this->Hide();
    }

    private: System::Void records_button_Click(System::Object^ sender, System::EventArgs^ e) {
        RecordsForm^ recordsForm = gcnew RecordsForm(this);
        recordsForm->Show();
        this->Hide();
    }
    };
}

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <msclr\marshal_cppstd.h>

//структура для хранения данных о результате (для удобства)
struct RecordEntry {
    std::string name;
    double score;
    std::string datetime;
};

//компаратор >
bool CompareRecords(const RecordEntry& a, const RecordEntry& b) {
    return a.score > b.score;
}

namespace TheBestestGameOfTheWorld {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RecordsForm : public System::Windows::Forms::Form
    {
    private:
        Form^ parentForm;
        System::Windows::Forms::ListView^ recordsListView;
        System::Windows::Forms::Button^ backButton;

    public:
        RecordsForm(Form^ parent)
        {
            InitializeComponent();
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RecordsForm::RecordsForm_FormClosed);
            this->parentForm = parent;
        }

    protected:
        ~RecordsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->recordsListView = (gcnew System::Windows::Forms::ListView());
            this->backButton = (gcnew System::Windows::Forms::Button());

            this->SuspendLayout();
            //
            // recordsListView
            //
            this->recordsListView->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
            this->recordsListView->Location = System::Drawing::Point(20, 20);
            this->recordsListView->Size = System::Drawing::Size(550, 300);
            this->recordsListView->View = System::Windows::Forms::View::Details;
            this->recordsListView->FullRowSelect = true;
            this->recordsListView->GridLines = true;

            //добавление колонок(itemов)
            this->recordsListView->Columns->Add(L"Имя", 200, System::Windows::Forms::HorizontalAlignment::Left);
            this->recordsListView->Columns->Add(L"Очки", 100, System::Windows::Forms::HorizontalAlignment::Center);
            this->recordsListView->Columns->Add(L"Дата", 250, System::Windows::Forms::HorizontalAlignment::Left);
            //
            // backButton
            //
            this->backButton->Text = L"Назад";
            this->backButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
            this->backButton->Location = System::Drawing::Point(20, 350);
            this->backButton->Click += gcnew System::EventHandler(this, &RecordsForm::backButton_Click);

            //
            // RecordsForm
            //
            this->ClientSize = System::Drawing::Size(600, 450);
            this->Controls->Add(this->recordsListView);
            this->Controls->Add(this->backButton);
            this->Text = L"Рекорды";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &RecordsForm::RecordsForm_Load);

            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void RecordsForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        if (this->parentForm == nullptr || !this->parentForm->Visible) {
            Application::Exit();
        }
        else {
            this->parentForm->Show();
        }
    }

    private: System::Void RecordsForm_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadRecords();
    }

    private: void LoadRecords()
    {
        std::string fileName = "records.txt";
        std::ifstream infile(fileName);
        if (!infile.is_open()) {
            return;
        }

        std::vector<RecordEntry> results;

        std::string line;
        while (std::getline(infile, line)) {
            size_t first = line.find(';');
            size_t second = line.find(';', first + 1);
            if (first == std::string::npos || second == std::string::npos) continue;

            std::string name = line.substr(0, first);
            std::string score_str = line.substr(first + 1, second - (first + 1));
            std::string datetime = line.substr(second + 1);

            double score = 0.0;
            try {
                score = std::stod(score_str);
            }
            catch (...) {
                continue;
            }

            RecordEntry entry;
            entry.name = name;
            entry.score = score;
            entry.datetime = datetime;
            results.push_back(entry);
        }
        infile.close();

        std::sort(results.begin(), results.end(), CompareRecords);

        this->recordsListView->Items->Clear();
        for (auto& r : results) {
            auto nameStr = gcnew System::String(r.name.c_str());
            auto scoreStr = gcnew System::String((std::to_string((int)r.score)).c_str());
            auto datetimeStr = gcnew System::String(r.datetime.c_str());

            ListViewItem^ item = gcnew ListViewItem(nameStr);
            item->SubItems->Add(scoreStr);
            item->SubItems->Add(datetimeStr);

            this->recordsListView->Items->Add(item);
        }
    }

    private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (parentForm != nullptr) {
            parentForm->Show();
        }
        this->Close();
    }
    };
}

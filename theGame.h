#pragma once
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System::Media;

namespace TheBestestGameOfTheWorld {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class theGame : public System::Windows::Forms::Form
    {
    private:
        System::String^ playerName;
        System::String^ difficulty;
        double scorePerHit;
        double currentScore;
        int platformHeight;
        int ballSpeedX;
        int ballSpeedY;
        int platformSpeed;
        PictureBox^ ball;
        PictureBox^ platform;
        Timer^ gameTimer;

        Form^ parentForm;

        Label^ scoreLabel;
        Label^ timeLabel;
        int timeCounter; // подсчет количества тиков

        SoundPlayer^ wallSound;
        SoundPlayer^ platformSound;
        SoundPlayer^ gameOverSound;

    public:
        theGame(System::String^ pName, System::String^ diff, Form^ parent)
        {
            InitializeComponent();
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &theGame::theGame_FormClosed);
            this->playerName = pName;
            this->difficulty = diff;
            this->parentForm = parent;
            this->DoubleBuffered = true;
            SetupGameParameters();
            CreateGameObjects();
            wallSound = gcnew SoundPlayer("wall_hit.wav");
            platformSound = gcnew SoundPlayer("platform_hit.wav");
            gameOverSound = gcnew SoundPlayer("gameover.wav");
        }

    protected:
        ~theGame()
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
            this->SuspendLayout();
            this->BackgroundImage = Image::FromFile("background.jpg");
            this->BackgroundImageLayout = ImageLayout::Stretch;

            this->ClientSize = System::Drawing::Size(800, 600);
            this->Name = L"theGame";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"TheGame - Ping Pong";
            this->Load += gcnew System::EventHandler(this, &theGame::TheGame_Load);
            this->KeyDown += gcnew KeyEventHandler(this, &theGame::theGame_KeyDown);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void theGame_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        if (this->parentForm == nullptr || !this->parentForm->Visible) {
            Application::Exit();
        }
        else {
            this->parentForm->Show();
        }
    }

    private: System::Void TheGame_Load(System::Object^ sender, System::EventArgs^ e) {
        gameTimer->Start();
    }

    private: void SetupGameParameters()
    {
        // Параметры в зависимости от сложности
        if (this->difficulty == "Easy") {
            this->ballSpeedX = 5;
            this->ballSpeedY = 5;
            this->platformHeight = 200;
            this->scorePerHit = 1.0;
        }
        else if (this->difficulty == "Middle") {
            this->ballSpeedX = 7;
            this->ballSpeedY = 7;
            this->platformHeight = 150;
            this->scorePerHit = 1.5;
        }
        else if (this->difficulty == "BIZZARE") {
            this->ballSpeedX = 9;
            this->ballSpeedY = 9;
            this->platformHeight = 120;
            this->scorePerHit = 2.0;
        }
        else if (this->difficulty == "HARDCORE") {
            this->ballSpeedX = 12;
            this->ballSpeedY = 12;
            this->platformHeight = 80;
            this->scorePerHit = 3.0;
        }
        this->platformSpeed = 20;
        this->currentScore = 0;

        //Счетчик времени в тиках пока что 0
        this->timeCounter = 0;
    }

    private: void CreateGameObjects()
    {
        //Мяч(квадрат по сути)
        ball = gcnew PictureBox();
        ball->Width = 30;
        ball->Height = 30;
        //Задаём фон
        ball->BackgroundImage = Image::FromFile("ball_image.jpg");
        ball->BackgroundImageLayout = ImageLayout::Stretch;
        ball->BackColor = Color::Transparent;
        ball->Left = this->ClientSize.Width / 2 - ball->Width / 2;
        ball->Top = this->ClientSize.Height / 2 - ball->Height / 2;
        ball->BorderStyle = BorderStyle::None;
        this->Controls->Add(ball);

        //левая платформа
        platform = gcnew PictureBox();
        platform->Width = 20;
        platform->Height = this->platformHeight;
        platform->BackgroundImage = Image::FromFile("platform_image.jpg"); // ваш файл
        platform->BackgroundImageLayout = ImageLayout::Stretch;
        platform->BackColor = Color::Transparent;
        platform->Left = 0;
        platform->Top = this->ClientSize.Height / 2 - platform->Height / 2;
        platform->BorderStyle = BorderStyle::None;
        this->Controls->Add(platform);

        // лейбл со счетом
        scoreLabel = gcnew Label();
        scoreLabel->ForeColor = Color::Yellow;
        scoreLabel->BackColor = Color::Transparent;
        scoreLabel->Font = gcnew System::Drawing::Font("Calibri", 14, FontStyle::Bold);
        scoreLabel->AutoSize = true;
        scoreLabel->Text = "Score: 0";
        scoreLabel->Left = 10;
        scoreLabel->Top = 10;
        this->Controls->Add(scoreLabel);

        //лейбл со временем
        timeLabel = gcnew Label();
        timeLabel->ForeColor = Color::Cyan;
        timeLabel->BackColor = Color::Transparent;
        timeLabel->Font = gcnew System::Drawing::Font("Calibri", 14, FontStyle::Bold);
        timeLabel->AutoSize = true;
        timeLabel->Text = "Time: 0s";
        timeLabel->Left = this->ClientSize.Width - 100;
        timeLabel->Top = 10;
        this->Controls->Add(timeLabel);

        //Объект-таймер
        gameTimer = gcnew Timer();
        gameTimer->Interval = 20;
        gameTimer->Tick += gcnew EventHandler(this, &theGame::gameTimer_Tick);
    }

    private: System::Void gameTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
        MoveBall();
        CheckCollisions();
        UpdateTime();
    }

    private: void MoveBall() {
        ball->Left += ballSpeedX;
        ball->Top += ballSpeedY;
    }

    private: void CheckCollisions() {
        //Правая стена
        if (ball->Right >= this->ClientSize.Width) {
            ballSpeedX = -ballSpeedX;
            wallSound->Play();
        }
        //Верхняя и нижняя границы
        if (ball->Top <= 0 || ball->Bottom >= this->ClientSize.Height) {
            ballSpeedY = -ballSpeedY;
            wallSound->Play();
        }

        //Левая граница (платформа)
        if (ball->Left <= platform->Right) {
            if ((ball->Bottom >= platform->Top) && (ball->Top <= platform->Bottom)) {
                ballSpeedX = -ballSpeedX;
                currentScore += scorePerHit;

                System::String^ displayScore = currentScore == (int)currentScore ? ((int)currentScore).ToString() : currentScore.ToString("F1");
                scoreLabel->Text = "Score: " + displayScore;
                platformSound->Play();
            }
            else {
                //промах
                gameOverSound->Play();
                gameTimer->Stop();
                SaveResult();
                MessageBox::Show("Game Over! Ваш счёт: " + (currentScore == (int)currentScore ? ((int)currentScore).ToString() : currentScore.ToString("F1")));
                if (parentForm != nullptr) {
                    parentForm->Show();
                }
                this->Close();
            }
        }
    }

    private: void UpdateTime() {
        //Каждые 20 мс тик, в одной секунде 1000 мс, 
        //за 1 с будет 1000/20 = 50 тиков
        //Каждые 50 тиков — 1 секунда
        timeCounter++;
        int seconds = timeCounter / 50;
        timeLabel->Text = "Time: " + seconds.ToString() + "s";
    }

    private: void SaveResult() {
        //Получаем текущее время
        std::time_t t = std::time(nullptr);
        std::tm tm;
        localtime_s(&tm, &t);

        std::setlocale(LC_ALL, "Russian");
        char buff[100];
        std::strftime(buff, sizeof(buff), "%d %B %Y %H:%M:%S", &tm);

        System::String^ scoreStr = currentScore == (int)currentScore ? ((int)currentScore).ToString() : currentScore.ToString("F1");

        System::String^ managedName = this->playerName;
        std::string player_name = msclr::interop::marshal_as<std::string>(managedName);

        std::string score_std = msclr::interop::marshal_as<std::string>(scoreStr);
        std::string datetime = buff;

        std::string fileName = "records.txt";

        //считываем рекорды из файла в вектор
        std::vector<std::string> lines;
        std::ifstream infile(fileName);
        std::string line;
        while (std::getline(infile, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        infile.close();

        // Попытка обновления существующей записи
        bool recordUpdated = false;
        for (auto& line : lines) {
            size_t first = line.find(';');
            size_t second = line.find(';', first + 1);
            if (!(first > 0 && second > first)) continue;

            std::string name = line.substr(0, first);
            std::string old_score_str = line.substr(first + 1, second - (first + 1));
            double old_score = 0.0;
            try {
                old_score = std::stod(old_score_str);
            }
            catch (...) {
                continue;
            }

            if (name == player_name) {
                double new_score = std::stod(score_std);
                if (new_score > old_score) {
                    //обновляем запись
                    line = player_name + ";" + score_std + ";" + datetime;
                }
                recordUpdated = true;
                break;
            }
        }

        //если не обновили,т.е не нашли name == playerName, то добавляем новую запись
        if (!recordUpdated) {
            lines.push_back(player_name + ";" + score_std + ";" + datetime);
        }

        //перезапись
        {
            std::ofstream outfile(fileName, std::ios_base::trunc);
            for (auto& l : lines) {
                outfile << l << "\n";
            }
        }
    }


    private: System::Void theGame_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
        //двигаем платформу слева
        if (e->KeyCode == Keys::Up && platform->Top > 0) {
            platform->Top -= platformSpeed;
        }
        else if (e->KeyCode == Keys::Down && platform->Bottom < this->ClientSize.Height) {
            platform->Top += platformSpeed;
        }
    }
    };
}

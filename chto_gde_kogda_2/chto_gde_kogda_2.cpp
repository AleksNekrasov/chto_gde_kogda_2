// chto_gde_kogda_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>


int main()
{
    int experts = 0;                  // счетчик знатоков
    int wiewers = 0;                  // счетчик телезрителей 
    int sector = 1;                   // сектор барабана- волчка
    int flag = 0;                     // счетчик цикла
    int offset = 0;                   // вводимое смещение волчка
    std::string answer;               // ответ пользователя
    std::string true_answer;          // правильный ответ
    std::ifstream question_stream;    // поток-вопрос
    std::ifstream answer_stream;      // поток-ответ
    std::string file_question = "C:\\Users\\user\\Desktop\\w13.txt";   // путь к файлу - вопросу
    std::string file_answer = "C:\\Users\\user\\Desktop\\a13.txt";     // путь к файлу - ответу
    std::string quest;                 // вопрос на экран
    bool baraban[13];                 // сам волчок-барабан с 13 секторами
    for (int i = 0; i < 13; i++)
    {
        baraban[i] = true;
    }

    while (flag < 13)
    {
        std::cout << "Enter offset: ";
        std::cin >> offset;
        sector = (sector + offset) % 13;

        while (!baraban[sector])       // поиск еще не игравшего вопроса
        {
            sector++;
            if (sector == 13)
            {
                sector = 0;
            }
        }

        question_stream.open(file_question);
        if (!question_stream.is_open())
        {
            std::cerr << "ERROR!!!";
        }
        else
        {
            for (int i = 0; i < sector; i++)
            {
                quest = "";
                std::getline(question_stream, quest);
            }
            std::cout << quest;
        }
        question_stream.close();

        std::cout << "\n Your answer: ";
        std::cin >> answer;

        answer_stream.open(file_answer);
        if (!answer_stream.is_open())
        {
            std::cerr << "Error!";
        }
        else
        {
            for (int i = 0; i < sector; i++)
            {
                answer_stream >> true_answer;
            }
        }
        answer_stream.close();

        if (answer == true_answer)
        {
            experts++;                    // если ответ верный - знатокам +1
        }
        else
        {
            wiewers++;                    // если ответ неверный - телезрителям +1
        }
        baraban[sector] = false;
        flag++;
    }
    if (experts > wiewers) std::cout << "EXPERTS WIN!!   with the score " << experts << " : " << wiewers;
    else std::cout << "WIEWERS WIN!!  with the score " << wiewers << " : " << experts;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

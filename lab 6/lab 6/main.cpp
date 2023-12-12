/**
 * @file main.cpp
 * @brief Основной файл программы.
 * @details Содержит функцию main и основной игровой цикл. Snake game - Выпонлил Бутаков Кирилл DJ2203 2023
 */

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#include "Snake.h"
#include "Apple.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

// Создание объектов змеи и яблока
Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);///< Объект змеи
Apple food;///< Объект яблока
int score;///< Переменная для хранения счета

/**
 * @brief Функция для отображения игровой доски.
 */
void board()
{
     /**
     * @brief Текущие позиции змеи и яблока.
     */
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

     /**
     * @brief Вектор тела змеи.
     */
    vector<COORD> snake_body = snake.get_body();

    /**
    * @brief Вывод счета игры.
    */
    cout << "SCORE : " << score << "\n\n";

    /**
    * @brief Отображение игровой доски в консоли.
    */
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            // Отображение границ и элементов змеи и яблока
            if (i == 0 || i == HEIGHT - 1) cout << '#';
            else if (i == snake_pos.Y && j + 1 == snake_pos.X) cout << '0'; // Голова змеи
            else if (i == food_pos.Y && j + 1 == food_pos.X) cout << '@'; // Яблоко
            else
            {
                // Отображение тела змеи
                bool isBodyPart = false;
                for (int k = 0; k < snake_body.size() - 1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }

                // Отображение пустого пространства, если не является частью тела змеи
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

/**
 * @brief Основная функция игры.
 *
 * Инициализирует объекты змеи и яблока, запускает основной цикл игры.
 * Обрабатывает ввод пользователя, обновляет состояние игры и отображает доску.
 * Проверяет условия завершения игры.
 *
 * @return Код завершения игры.
 */
int main()
{
    /**
    * @brief Счет игры.
    */
    score = 0;
    srand(time(NULL));

    /**
    * @brief Генерация начального положения яблока.
    */
    food.gen_apple();

    bool game_over = false;

    /**
    * @brief Основной цикл игры.
    */
    while (!game_over)
    {
        /**
        * @brief Отображение игровой доски.
        */
        board();

        /**
        * @brief Обработка ввода пользователя.
        */
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w': snake.direction('u'); break;
            case 'a': snake.direction('l'); break;
            case 's': snake.direction('d'); break;
            case 'd': snake.direction('r'); break;
            }
        }

        /**
        * @brief Проверка на столкновение с границами или самой собой.
        */
        if (snake.collided()) game_over = true;

        /**
        * @brief Проверка, съела ли змея яблоко.
        */
        if (snake.eaten(food.get_pos()))
        {
            food.gen_apple();
            snake.grow();
            score = score + 10;
        }

        
        snake.move_snake();
        /**
        * @brief Задержка для более плавного отображения.
        */
        Sleep(50);

        /**
        * @brief Очистка консольного экрана.
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

    return 0;
}

/**
 * @file Snake.cpp
 * @brief Реализация методов класса Snake.
 * @details Snake game - Выпонлил Бутаков Кирилл DJ2203 2023
 */

#include "Snake.h"
#include <iostream>
#include <algorithm>


/**
 * @brief Конструктор класса Snake.
 *
 * @param pos Начальное положение головы змеи.
 * @param vel Скорость движения змеи.
 */
Snake::Snake(COORD pos, int vel)
{
    // Инициализация переменных класса
    this->pos = pos;
    this->vel = vel;
    dir = 'n'; // Начальное направление
    len = 1;   // Начальная длина змеи
    body.push_back(pos); // Начальное положение добавляется в вектор тела змеи
}

/**
 * @brief Метод для установки нового направления змеи.
 *
 * @param dir Новое направление (u - вверх, d - вниз, l - влево, r - вправо).
 */
void Snake::direction(char dir)
{
    this->dir = dir;
}

/**
 * @brief Метод для увеличения длины змеи.
 */
void Snake::grow()
{
    len++;
}

/**
 * @brief Метод для получения текущего положения головы змеи.
 *
 * @return Текущее положение головы змеи.
 */
COORD Snake::get_pos()
{
    return pos;
}

/**
 * @brief Метод для получения вектора тела змеи.
 *
 * @return Вектор, представляющий тело змеи.
 */
vector<COORD> Snake::get_body()
{
    return body;
}


/**
 * @brief Метод для движения змеи в зависимости от текущего направления.
 */
void Snake::move_snake()
{
    // Изменение положения головы в зависимости от текущего направления
    switch (dir)
    {
    case 'u': pos.Y -= vel; break;
    case 'd': pos.Y += vel; break;
    case 'l': pos.X -= vel; break;
    case 'r': pos.X += vel; break;
    }

    // Добавление нового положения головы в вектор тела змеи
    body.push_back(pos);

    if (body.size() > len)
        body.erase(body.begin());
}


/**
 * @brief Метод для проверки столкновения змеи с границами поля или самой собой.
 *
 * @return Возвращает true, если столкновение произошло, в противном случае - false.
 */
bool Snake::collided()
{
    // Проверка на столкновение с границами игрового поля
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2)
        return true;

    // Проверка на столкновение с самой собой
    for (int i = 0; i < len - 1; i++)
    {
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    }

    return false;
}

/**
 * @brief Перегрузка оператора "==" для сравнения COORD.
 *
 * @param lhs Левый операнд.
 * @param rhs Правый операнд.
 * @return Возвращает true, если координаты равны, в противном случае - false.
 */
bool operator==(const COORD& lhs, const COORD& rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

/**
 * @brief Метод для проверки, съела ли змея еду.
 *
 * Использует алгоритм STL для поиска координаты еды в векторе тела змеи.
 *
 * @param food Координаты еды.
 * @return Возвращает true, если змея съела еду, в противном случае - false.
 */
bool Snake::eaten(COORD food)
{
    // Используем алгоритм STL для проверки, съела ли змея еду
    return std::find(body.begin(), body.end(), food) != body.end();;
}

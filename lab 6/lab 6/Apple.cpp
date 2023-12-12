/**
 * @file Apple.cpp
 * @brief Реализация методов класса Apple.
 * @details Snake game - Выпонлил Бутаков Кирилл DJ2203 2023
 */

#include "Apple.h"
#include <iostream>

/**
 * @brief Метод для генерации нового положения яблока.
 */
void Apple::gen_apple()
{
    pos.X = (rand() % WIDTH - 1) + 1;
    pos.Y = (rand() % HEIGHT - 1) + 1;
}

/**
 * @brief Метод для получения текущего положения яблока.
 * @return Текущая позиция яблока.
 */
COORD Apple::get_pos() { return pos; }
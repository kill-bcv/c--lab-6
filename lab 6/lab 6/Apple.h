/**
 * @file Apple.h
 * @brief Заголовочный файл для класса Apple.
 * @details Snake game - Выпонлил Бутаков Кирилл DJ2203 2023
 */

#pragma once
#include <windows.h>
#include <cstdio>

#define WIDTH 50
#define HEIGHT 25


/**
 * @brief Класс, представляющий яблоко в игре.
 */
class Apple
{
private:
    COORD pos; ///< Текущая позиция яблока

public:
    /**
    * @brief Метод для генерации нового положения яблока.
    */
    void gen_apple();

     /**
     * @brief Метод для получения текущего положения яблока.
     * @return Текущая позиция яблока.
     */
    COORD get_pos();

    /// Конструктор по умолчанию
    Apple() {}
};
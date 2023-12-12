/**
 * @file Snake.h
 * @brief Заголовочный файл для класса Snake.
 * @details Описывает класс, представляющий змею в игре. Snake game - Выпонлил Бутаков Кирилл DJ2203 2023
 */

#pragma once
#include <windows.h> // Заголовочный файл для использования COORD
#include <vector>
#include <iostream>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

/**
 * @brief Класс, представляющий змею в игре.
 */
class Snake
{
private:
    COORD pos; ///< Текущая позиция головы змеи
    int vel;   ///< Скорость движения змеи
    char dir;  ///< Направление движения змеи (u - вверх, d - вниз, l - влево, r - вправо)
    int len;   ///< Длина змеи
    vector<COORD> body; ///< Вектор, представляющий тело змеи


public:
    // Конструктор по умолчанию
    Snake() {}

     /**
     * @brief Конструктор с параметрами.
     * @param pos Начальная позиция головы змеи.
     * @param vel Скорость движения змеи.
     */
    Snake(COORD pos, int vel);

    /**
     * @brief Метод для увеличения длины змеи.
     */
    void grow();

    /**
     * @brief Метод для движения змеи в зависимости от текущего направления.
     */
    void move_snake();

    /**
     * @brief Метод для изменения направления движения змеи.
     * @param dir Новое направление (u - вверх, d - вниз, l - влево, r - вправо).
     */
    void direction(char dir);

     /**
     * @brief Оператор вывода для объекта Snake.
     * @param os Поток вывода.
     * @param snake Змея для вывода.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, Snake& snake) {
        os << snake.vel << snake.dir << snake.len;
        return os;
    }

     /**
     * @brief Оператор ввода для объекта Snake.
     * @param os Поток ввода.
     * @param snake Змея для ввода.
     * @return Поток ввода.
     */
    friend std::istream& operator>>(std::istream& os, Snake& snake) {
        os >> snake.vel;
        os >> snake.dir;
        os >> snake.len;
    }

     /**
     * @brief Оператор присваивания для объекта Snake.
     * @param other Другой объект Snake.
     * @return Ссылка на текущий объект Snake.
     */
    Snake& operator = (Snake& other) {

        if (this != &other) {  // Проверка на самоприсваивание

            this->pos = other.pos;
            this->vel = other.vel;
            this->dir = other.dir;
            this->len = other.len;
            this->body = other.body;
        }
        return *this;
    }

     /**
     * @brief Оператор сравнения для объектов Snake.
     * @param other Другой объект Snake.
     * @return true, если объекты равны; в противном случае - false.
     */
    bool operator == (Snake& other) {
        return this->vel == other.vel && this->dir == other.dir && this->len==other.len;
    }
    
     /**
     * @brief Метод для получения тела змеи.
     * @return Вектор координат, представляющий тело змеи.
     */
    vector<COORD> get_body();

     /**
     * @brief Метод для проверки столкновения змеи.
     * @return true, если змея столкнулась; в противном случае - false.
     */
    bool collided();

     /**
     * @brief Метод для проверки, съела ли змея еду.
     * @param food Координаты еды.
     * @return true, если змея съела еду; в противном случае - false.
     */
    bool eaten(COORD food);

     /**
     * @brief Метод для получения текущей позиции головы змеи.
     * @return Текущая позиция головы змеи.
     */
    COORD get_pos();
};

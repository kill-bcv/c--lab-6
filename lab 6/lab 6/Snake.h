/**
 * @file Snake.h
 * @brief ������������ ���� ��� ������ Snake.
 * @details ��������� �����, �������������� ���� � ����. Snake game - �������� ������� ������ DJ2203 2023
 */

#pragma once
#include <windows.h> // ������������ ���� ��� ������������� COORD
#include <vector>
#include <iostream>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

/**
 * @brief �����, �������������� ���� � ����.
 */
class Snake
{
private:
    COORD pos; ///< ������� ������� ������ ����
    int vel;   ///< �������� �������� ����
    char dir;  ///< ����������� �������� ���� (u - �����, d - ����, l - �����, r - ������)
    int len;   ///< ����� ����
    vector<COORD> body; ///< ������, �������������� ���� ����


public:
    // ����������� �� ���������
    Snake() {}

     /**
     * @brief ����������� � �����������.
     * @param pos ��������� ������� ������ ����.
     * @param vel �������� �������� ����.
     */
    Snake(COORD pos, int vel);

    /**
     * @brief ����� ��� ���������� ����� ����.
     */
    void grow();

    /**
     * @brief ����� ��� �������� ���� � ����������� �� �������� �����������.
     */
    void move_snake();

    /**
     * @brief ����� ��� ��������� ����������� �������� ����.
     * @param dir ����� ����������� (u - �����, d - ����, l - �����, r - ������).
     */
    void direction(char dir);

     /**
     * @brief �������� ������ ��� ������� Snake.
     * @param os ����� ������.
     * @param snake ���� ��� ������.
     * @return ����� ������.
     */
    friend std::ostream& operator<<(std::ostream& os, Snake& snake) {
        os << snake.vel << snake.dir << snake.len;
        return os;
    }

     /**
     * @brief �������� ����� ��� ������� Snake.
     * @param os ����� �����.
     * @param snake ���� ��� �����.
     * @return ����� �����.
     */
    friend std::istream& operator>>(std::istream& os, Snake& snake) {
        os >> snake.vel;
        os >> snake.dir;
        os >> snake.len;
    }

     /**
     * @brief �������� ������������ ��� ������� Snake.
     * @param other ������ ������ Snake.
     * @return ������ �� ������� ������ Snake.
     */
    Snake& operator = (Snake& other) {

        if (this != &other) {  // �������� �� ����������������

            this->pos = other.pos;
            this->vel = other.vel;
            this->dir = other.dir;
            this->len = other.len;
            this->body = other.body;
        }
        return *this;
    }

     /**
     * @brief �������� ��������� ��� �������� Snake.
     * @param other ������ ������ Snake.
     * @return true, ���� ������� �����; � ��������� ������ - false.
     */
    bool operator == (Snake& other) {
        return this->vel == other.vel && this->dir == other.dir && this->len==other.len;
    }
    
     /**
     * @brief ����� ��� ��������� ���� ����.
     * @return ������ ���������, �������������� ���� ����.
     */
    vector<COORD> get_body();

     /**
     * @brief ����� ��� �������� ������������ ����.
     * @return true, ���� ���� �����������; � ��������� ������ - false.
     */
    bool collided();

     /**
     * @brief ����� ��� ��������, ����� �� ���� ���.
     * @param food ���������� ���.
     * @return true, ���� ���� ����� ���; � ��������� ������ - false.
     */
    bool eaten(COORD food);

     /**
     * @brief ����� ��� ��������� ������� ������� ������ ����.
     * @return ������� ������� ������ ����.
     */
    COORD get_pos();
};

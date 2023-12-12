/**
 * @file Snake.cpp
 * @brief ���������� ������� ������ Snake.
 * @details Snake game - �������� ������� ������ DJ2203 2023
 */

#include "Snake.h"
#include <iostream>
#include <algorithm>


/**
 * @brief ����������� ������ Snake.
 *
 * @param pos ��������� ��������� ������ ����.
 * @param vel �������� �������� ����.
 */
Snake::Snake(COORD pos, int vel)
{
    // ������������� ���������� ������
    this->pos = pos;
    this->vel = vel;
    dir = 'n'; // ��������� �����������
    len = 1;   // ��������� ����� ����
    body.push_back(pos); // ��������� ��������� ����������� � ������ ���� ����
}

/**
 * @brief ����� ��� ��������� ������ ����������� ����.
 *
 * @param dir ����� ����������� (u - �����, d - ����, l - �����, r - ������).
 */
void Snake::direction(char dir)
{
    this->dir = dir;
}

/**
 * @brief ����� ��� ���������� ����� ����.
 */
void Snake::grow()
{
    len++;
}

/**
 * @brief ����� ��� ��������� �������� ��������� ������ ����.
 *
 * @return ������� ��������� ������ ����.
 */
COORD Snake::get_pos()
{
    return pos;
}

/**
 * @brief ����� ��� ��������� ������� ���� ����.
 *
 * @return ������, �������������� ���� ����.
 */
vector<COORD> Snake::get_body()
{
    return body;
}


/**
 * @brief ����� ��� �������� ���� � ����������� �� �������� �����������.
 */
void Snake::move_snake()
{
    // ��������� ��������� ������ � ����������� �� �������� �����������
    switch (dir)
    {
    case 'u': pos.Y -= vel; break;
    case 'd': pos.Y += vel; break;
    case 'l': pos.X -= vel; break;
    case 'r': pos.X += vel; break;
    }

    // ���������� ������ ��������� ������ � ������ ���� ����
    body.push_back(pos);

    if (body.size() > len)
        body.erase(body.begin());
}


/**
 * @brief ����� ��� �������� ������������ ���� � ��������� ���� ��� ����� �����.
 *
 * @return ���������� true, ���� ������������ ���������, � ��������� ������ - false.
 */
bool Snake::collided()
{
    // �������� �� ������������ � ��������� �������� ����
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2)
        return true;

    // �������� �� ������������ � ����� �����
    for (int i = 0; i < len - 1; i++)
    {
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    }

    return false;
}

/**
 * @brief ���������� ��������� "==" ��� ��������� COORD.
 *
 * @param lhs ����� �������.
 * @param rhs ������ �������.
 * @return ���������� true, ���� ���������� �����, � ��������� ������ - false.
 */
bool operator==(const COORD& lhs, const COORD& rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

/**
 * @brief ����� ��� ��������, ����� �� ���� ���.
 *
 * ���������� �������� STL ��� ������ ���������� ��� � ������� ���� ����.
 *
 * @param food ���������� ���.
 * @return ���������� true, ���� ���� ����� ���, � ��������� ������ - false.
 */
bool Snake::eaten(COORD food)
{
    // ���������� �������� STL ��� ��������, ����� �� ���� ���
    return std::find(body.begin(), body.end(), food) != body.end();;
}

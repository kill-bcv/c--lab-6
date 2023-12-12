/**
 * @file Apple.cpp
 * @brief ���������� ������� ������ Apple.
 * @details Snake game - �������� ������� ������ DJ2203 2023
 */

#include "Apple.h"
#include <iostream>

/**
 * @brief ����� ��� ��������� ������ ��������� ������.
 */
void Apple::gen_apple()
{
    pos.X = (rand() % WIDTH - 1) + 1;
    pos.Y = (rand() % HEIGHT - 1) + 1;
}

/**
 * @brief ����� ��� ��������� �������� ��������� ������.
 * @return ������� ������� ������.
 */
COORD Apple::get_pos() { return pos; }
/**
 * @file Apple.h
 * @brief ������������ ���� ��� ������ Apple.
 * @details Snake game - �������� ������� ������ DJ2203 2023
 */

#pragma once
#include <windows.h>
#include <cstdio>

#define WIDTH 50
#define HEIGHT 25


/**
 * @brief �����, �������������� ������ � ����.
 */
class Apple
{
private:
    COORD pos; ///< ������� ������� ������

public:
    /**
    * @brief ����� ��� ��������� ������ ��������� ������.
    */
    void gen_apple();

     /**
     * @brief ����� ��� ��������� �������� ��������� ������.
     * @return ������� ������� ������.
     */
    COORD get_pos();

    /// ����������� �� ���������
    Apple() {}
};
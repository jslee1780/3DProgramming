#pragma once
#include <iostream>

using namespace std;

//������ǥ v
float v[1][3] = { {1, 1, 1} };

//�̵� ��� 3, 5
float Translate[3][3] = {
	{3, 0, 0},
	{0, 5, 0},
	{0, 0, 1} };

//ȸ�� ��� 30��
float Rotate[3][3] = {
	{cos(30), -sin(30), 0},
	{sin(30), cos(30), 0},
	{0, 0, 1} };

//ũ�� ��ȯ ��� 2��
float Scale[3][3] = {
	{2, 0, 0},
	{0, 2, 0},
	{0, 0, 1} };

//v * Translate ���� ���� ���� first �ʱ�ȭ
float first[1][3] = { 0 };
//first * Rotate ���� ���� ���� second �ʱ�ȭ
float second[1][3] = { 0 };
//second * Scale ���� ���� ���� p �ʱ�ȭ
float p[1][3] = { 0 };

//��� �Լ�
void run()
{
	//v * Translate ���� first�� ����
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				first[i][j] += v[i][k] * Translate[k][j];
			}
		}
	}

	//first * Rotate ���� second�� ����
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				second[i][j] += first[i][k] * Rotate[k][j];
			}
		}
	}

	//second * Scale ���� p�� ����
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				p[i][j] += second[i][k] * Scale[k][j];
			}
		}
	}

	//p�� ���
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << p[i][j];
			if (j < 2) cout << " ";
		}
	}
}
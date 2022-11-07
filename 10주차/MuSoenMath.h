#pragma once
#include <iostream>

using namespace std;

//시작좌표 v
float v[1][3] = { {1, 1, 1} };

//이동 행렬 3, 5
float Translate[3][3] = {
	{3, 0, 0},
	{0, 5, 0},
	{0, 0, 1} };

//회전 행렬 30도
float Rotate[3][3] = {
	{cos(30), -sin(30), 0},
	{sin(30), cos(30), 0},
	{0, 0, 1} };

//크기 변환 행렬 2배
float Scale[3][3] = {
	{2, 0, 0},
	{0, 2, 0},
	{0, 0, 1} };

//v * Translate 값을 담을 변수 first 초기화
float first[1][3] = { 0 };
//first * Rotate 값을 담을 변수 second 초기화
float second[1][3] = { 0 };
//second * Scale 값을 담을 변수 p 초기화
float p[1][3] = { 0 };

//계산 함수
void run()
{
	//v * Translate 값을 first에 저장
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

	//first * Rotate 값을 second에 저장
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

	//second * Scale 값을 p에 저장
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

	//p값 출력
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << p[i][j];
			if (j < 2) cout << " ";
		}
	}
}
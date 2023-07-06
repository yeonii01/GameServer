﻿#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>   //윈도우와 리눅스 상관X
#include <atomic>

//atomic : All-Or-Nothing
atomic<int32> sum = 0;

void Add()
{
	for (int32 i = 0; i < 100'0000; i++)
	{
		sum.fetch_add(1);
		//sum++;

		//int32 eax = sum;
		////eax = 0
		//eax = eax + 1;
		////eax = 1
		//sum = eax;
		////sum = 1
	}
}

void Sub()
{
	for (int32 i = 0; i < 100'0000; i++)
	{
		sum.fetch_add(-1);
		//sum--;

		//int32 eax = sum;
		////eax = 0
		//eax = eax - 1;
		////eax = -1
		//sum = eax;
		////sum = -1
	}
}

int main()
{
	Add();
	Sub();

	cout << sum << endl;
	
	std::thread t1(Add);
	std::thread t2(Sub);

	t1.join();
	t2.join();
	cout << sum << endl;
}

//병목현상이 발생할 수 있음
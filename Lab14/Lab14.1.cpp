#include<iostream>
#include<time.h>

//19.Определить количество элементов массива, принадлежащих указанному пользователем диапазону [X, Y].
//Вычесть из всех четных элементов массива сумму всех элементов массива.

void Keyboard(int arr[], int size, int n)
{
	printf("array %d:\n", n);
	for (int i = 0; i < size; i++)
	{
		printf("[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
}

void printArr(int arr[], int size, int n)
{
	printf("array %d:\n", n);
	for (int i = 0; i < size; i++)
	{
		printf("[%d] = %d\n", i, arr[i]);
	}
}

void file(int arr[], int n)
{
	FILE* f;
	int N;
	if (fopen_s(&f, "1.txt", "r") != 0)
	{
		printf("couldn't open file 1.txt\n");
		exit(1);
	}
	
	fscanf_s(f, "%d", &N);
	for (int i = 0; i < N; i++)
	{
		fscanf_s(f, "%d", &arr[i]);
	}
	
	fclose(f);
	printArr(arr, N, n);
}

void randomNums(int arr[], int size, int n, int min, int max)
{
	srand(time(0));
	int amountDigs = max - min + 1;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % amountDigs + min;
	}
	printArr(arr, size, n);
}

int inRange(int arr[], int size, int p1, int p2)
{
	int amount = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= p1 && arr[i] <= p2) amount += 1;
	}
	return amount;
}

int sum(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void minusSum(int arr[], int size, int sum, int n)
{
	printf("array %d:\n", n);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0) arr[i] -= sum;
		printf("[%d] = %d\n", i, arr[i]);
	}
}

void output(int arr[], int size)
{
	FILE* ft;
	if (fopen_s(&ft, "2.txt", "w") != 0)
	{
		printf("couldn't open file 2.txt\n");
		exit(1);
	}
	
	fprintf_s(ft, "%d\n", size);
	for (int i = 0; i < size; i++)
	{
		fprintf(ft, "[%d] = %d\n", i, arr[i]);
	}
	fclose(ft);
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int S1 = 5, S2 = 5;
	int a[S1]; int b[S2];
	int X, Y, way;

	printf("Выберите способ заполнения массивов\n");
	printf("1 - с клавиатуры\n");
	printf("2 - случайными числами в диапазоне [A,B]\n");
	printf("3 - с файла\n");
	do
	{
		scanf_s("%d", &way);
	} while (way < 1 || way > 3);

	switch (way)
	{
	case 1:
		Keyboard(a, S1, 1);
		Keyboard(b, S2, 2);

		break;
	case 2:
		int A, B;

		do
		{
			printf("Введите целые положительные числа A и B (A<B):\n");
			printf("A = ");
			scanf_s("%d", &A);
			printf("B = ");
			scanf_s("%d", &B);
		} while (A >= B);

		randomNums(a, S1, 1, A, B);
		randomNums(b, S2, 2, A, B);

		break;
	case 3:
		file(a, 1);
		file(b, 2);
		break;
	}

	do
	{
		printf("Введите X и Y (X<Y):\n");
		printf("X = ");
		scanf_s("%d", &X);
		printf("Y = ");
		scanf_s("%d", &Y);
	} while (X >= Y);

	printf("Кол-во элементов массива 1, принадлежащие [%d,%d] = %d\n", X, Y, inRange(a, S1, X, Y));
	printf("Кол-во элементов массива 2, принадлежащие [%d,%d] = %d\n", X, Y, inRange(b, S2, X, Y));

	minusSum(a, S1, sum(a, S1), 1);
	minusSum(b, S2, sum(b, S2), 2);

	output(a, S1);

	return 0;
}	
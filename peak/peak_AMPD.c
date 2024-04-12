#include "stdio.h"
#include "stdlib.h"
double data[] = { 433,
13,
20,
15,
16,
8,
14,
10,
14,
10,
14,
8,
14,
10,
14,
8,
14,
6,
11,
6,
13,
6,
12,
6,
12,
8,
12,
6,
11,
6,
11,
8,
11,
8,
11,
8,
12,
8,
11,
8,
12,
8,
11,
8,
12,
8,
11,
6,
11,
8,
11,
6,
15,
6,
15,
8,
11,
8,
15,
8,
11,
8,
15,
8,
14,
4,
10,
7,
10,
7,
8,
6,
12,
7,
14,
7,
14,
7,
12,
7,
14,
7,
12,
7,
16,
5,
16,
5,
16,
7,
14,
5,
16,
7,
18,
8,
20,
8,
18,
8,
22,
11,
24,
8,
24,
11,
26,
11,
32,
13,
34,
12,
40,
17,
46,
22,
62,
27,
89,
44,
147,
91,
484,
1414,
375,
83,
132,
42,
79,
30,
54,
22,
42,
18,
35,
16,
30,
12,
26,
12,
24,
12,
21,
10,
17,
10,
16,
10,
17,
6,
13,
6,
14,
6,
14,
6,
12,
6,
11,
6,
11,
8,
11,
8,
11,
7,
11,
5,
8,
5,
8,
2,
10,
6,
10,
4,
8,
4,
8,
7,
7,
5,
7,
4,
7,
5,
8,
4,
6,
2,
4,
4,
4,
4,
4,
4,
5,
4,
4,
6,
4,
4,
4,
2,
6,
4,
6,
6,
2,
4,
4,
2,
6,
6,
6,
2,
6,
2,
6,
4,
2,
4,
6,
4,
6,
4,
6,
6,
2,
2,
4,
4,
4,
4,
4,
2,
6,
4,
4,
4,
6,
2,
4,
7,
6,
6,
4,
6,
2,
4,
6,
2,
4,
2,
2,
2,
4,
0,
4,
2,
4,
2,
5,
4,
2,
2,
4,
2,
2,
2,
4,
2,
2,
2,
4,
2,
6,
2,
4,
4,
4,
4,
4,
0,
6,
2,
2,
4,
6,
4,
4,
2,
4,
2,
2,
2,
4,
2,
4,
2,
6,
0,
6,
5,
6,
2,
4,
2,
4,
4,
4,
4,
6,
0,
4,
2,
6,
2,
6,
2,
4,
2,
7,
2,
5,
2,
7,
4,
6,
2,
6,
2,
6,
2,
7,
2,
4,
2,
7,
2,
7,
2,
5,
2,
7,
2,
10,
2,
8,
2,
8,
2,
7,
2,
10,
2,
12,
2,
12,
2,
16,
2,
19,
2,
28,
4,
46,
7,
172,
49,
76,
7,
30,
6,
17,
2,
12,
4,
8,
4,
7,
4,
4,
2,
4,
2,
6,
2,
4,
2,
4,
2,
2,
2,
2,
4,
4,
2,
2,
2,
2,
4,
4,
4,
2,
0,
2,
4,
2,
2,
4,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
4,
2,
4,
2,
2,
2,
2,
2,
4,
2,
2,
2,
4,
2,
4,
2,
4,
2,
4,
2,
2,
2,
2,
2,
2,
2,
4,
0,
2,
0,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
0,
2,
4,
2,
0,
0,
2,
2,
2,
2,
0,
2,
2,
0,
2,
0,
4,
2,
2,
2,
4,
2,
2,
2,
2,
2,
2,
4,
2,
2,
4,
2,
4,
0,
0,
2,
0,
0,
2,
0,
4,
0,
2,
0,
2,
2,
};
//123  368
// Ѱ��������Сֵ���±�
#define N 512  //�źų���
#define WINDOW_SIZE 8  //�������ڴ�С
int argmin(int* index, int index_len)
{
	int min_index = 0;
	int min = index[0];
	for (int i = 1; i < index_len; i++)
	{
		if (index[i] < min)
		{
			min = index[i];
			min_index = i;
		}
	}
	return min_index;
}

//Ѱ�Ҽ�ֵ�㺯��
// data�Ǵ�����ݵ�����
//index�Ǵ�ŷ�ֵ���±������
//len_index�Ƿ�ֵ��������index���鳤��
void AMPD(double* data, int* index, int* len_index)
{
	int size = 512;
	int* p_data = (int*)malloc(sizeof(int) * size); //size�������Ϊ���鳤��
	int* arr_rowsum = (int*)malloc(sizeof(int) * size);
	int min_index, max_window_length;
	if (p_data == NULL) {
		printf("�ڴ����ʧ��\n");
		return -1;
	}
	for (int i = 0; i < size; i++)
	{
		p_data[i] = 0;
	}
	for (int k = 1; k <= size / 2 + 1; k++)
	{
		int row_sum = 0;
		for (int i = k; i <= size - k; i++)
		{
			if ((data[i] > data[i - k]) && (data[i] > data[i + k]))
				row_sum -= 1;
		}
		if (p_data != NULL) {
			*(arr_rowsum + k - 1) = row_sum;
		}
	}
	//for (int i = 0; i < size/2; i++)
	//{
	//	printf("%d\n", arr_rowsum[i]);
	//}
	min_index = argmin(arr_rowsum, size / 2); //�˴�Ϊ���Ĵ���
	//printf("%d\n", min_index);
	max_window_length = min_index;
	for (int k = 1; k < max_window_length + 1; k++)
	{
		for (int i = 1; i < size - k; i++)
		{
			if ((data[i] > data[i - k]) && (data[i] > data[i + k]))
				p_data[i] += 1;
		}
	}
	for (int i_find = 0; i_find < size; i_find++)
	{
		if (p_data[i_find] == max_window_length)
		{
			index[*len_index] = i_find;
			(*len_index) += 1;
		}
	}
	free(p_data);
	free(arr_rowsum);
}
//����ƽ���˲����ṹ��
typedef struct {
	float window[WINDOW_SIZE];
	int index;
	int full;
} MovingAverageFilter;

// ��ʼ���˲���
void initMovingAverageFilter(MovingAverageFilter* filter) {
	for (int i = 0; i < WINDOW_SIZE; i++) {
		filter->window[i] = 0.0;
	}
	filter->index = 0;
	filter->full = 0;
}

// �����˲����������˲����ֵ
float updateMovingAverageFilter(MovingAverageFilter* filter, float newValue) {
	filter->window[filter->index] = newValue;

	if (!filter->full && filter->index == WINDOW_SIZE - 1) {
		filter->full = 1;
	}

	filter->index = (filter->index + 1) % WINDOW_SIZE;

	float sum = 0.0;
	int count = filter->full ? WINDOW_SIZE : filter->index;

	for (int i = 0; i < count; i++) {
		sum += filter->window[i];
	}

	return sum / count;
}

int main()
{
	//Ӧ�û���ƽ���˲���
	MovingAverageFilter filter;
	initMovingAverageFilter(&filter);
	for (int i = 0; i < 512; i++) {
		data[i] = updateMovingAverageFilter(&filter, data[i]);
	}
	int index[512]; //��ŷ�ֵ���±������
	int len_index = 0; //��ֵ��������index���鳤��

	AMPD(data, index, &len_index);

	for (int i = 0; i < len_index; i++)
	{
		printf("%d\n", index[i]);
	}
	system("pause");
	return 0;
}

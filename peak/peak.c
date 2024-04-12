//#include "stdio.h"
//#include "stdlib.h"
//#include <string.h>
double data[] = {433,
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
//
//struct findpeaksret {
//	int* peaks;
//	int	p_num;
//	int* valleys;
//	int	v_num;
//};
//
//struct findpeaksarg {
//	double* src;  //数据
//	int	count;   //数据长度
//	int	flags;	//标志
//	int	pdistance;	//峰宽
//	int	vdistance;	//谷宽
//	double	pvalue;	//最小峰值
//	double	vvalue;		//最大谷值
//	double	threshold;	//阈值
//};
//
//#define	PDISTANCE		1	//启用峰宽
//#define VDISTANCE		2	//启用谷宽
//#define	PVALUE			4 //启用峰值
//#define VVALUE			8	//启用谷值
//#define THRESHOLD		16	//启用阈值
//#define PEAKS			32	//输出波峰
//#define VALLEYS			64	//输出波谷
//
//static inline int
//findpeaks_min(const double a, const double b)
//{
//	return a < b;
//}
//
//static inline int
//findpeaks_max(const double a, const double b)
//{
//	return a > b;
//}
//
//static int
//flags_find_points(const double* src, const int* array,
//	const int* flags, int* pac, int count, int* pcount,
//	int* maxind, int (*func)(const double, const double))
//{
//	int i, j, ind;
//	double value;
//	for (i = 0; i < count; i++)
//		if (!flags[i])
//			break;
//	if (i >= count)
//		return 0;
//	else {
//		value = src[array[i]];
//		ind = 0;
//	}
//	for (i = 0, j = 0; i < count; i++) {
//		if (!flags[i]) {
//			if (func(src[array[i]], value)) {
//				value = src[array[i]];
//				ind = j;
//			}
//			pac[j++] = i;
//		}
//	}
//	*pcount = j;
//	*maxind = ind;
//	return 1;
//}
//
//static int*
//check_distance(const double* src, int* array, int* count,
//	double dis, int (*func)(const double, const double))
//{
//	int i, n = 0, pcount, maxind;
//	int* flags = (int*)malloc(sizeof(int) * *count);
//	int* pac = (int*)malloc(sizeof(int) * *count);
//	int* result = NULL;
//	for (i = 0; i < *count; i++)
//		flags[i] = 0;
//	while (flags_find_points(src, array, flags, pac, *count,
//		&pcount, &maxind, func)) {
//		flags[pac[maxind]] = 1;
//		n++;
//		for (i = maxind - 1; i >= 0; i--) {
//			if (array[pac[maxind]] - array[pac[i]] < dis)
//				flags[pac[i]] = -1;
//			else
//				break;
//		}
//		for (i = maxind + 1; i < pcount; i++) {
//			if (array[pac[i]] - array[pac[maxind]] < dis)
//				flags[pac[i]] = -1;
//			else
//				break;
//		}
//	}
//	free(pac);
//	if (n) {
//		result = (int*)malloc(sizeof(int) * n);
//		for (i = 0, n = 0; i < *count; i++)
//			if (flags[i] == 1)
//				result[n++] = array[i];
//	}
//	free(flags);
//	*count = n;
//	free(array);
//	return result;
//}
//
//struct findpeaksret*
//	findpeaks(struct findpeaksarg* arg)
//{
//	int i, j, p_num, v_num;
//	p_num = v_num = 0;
//	int* peaks_t = (int*)malloc(sizeof(int) * arg->count);
//	int* valleys_t = (int*)malloc(sizeof(int) * arg->count);
//	int* diff = (int*)malloc(sizeof(int) * (arg->count - 1));
//	struct findpeaksret* ret = (struct findpeaksret*)malloc(sizeof(struct findpeaksret));
//	memset(ret, 0, sizeof(struct findpeaksret));
//	for (i = 1; i < arg->count; i++) {
//		if ((j = (arg->src)[i] - (arg->src)[i - 1]) > 0)
//			diff[i - 1] = 1;
//		else if (j < 0)
//			diff[i - 1] = -1;
//		else
//			diff[i - 1] = 0;
//	}
//	if (arg->flags & THRESHOLD) {
//		for (i = 1; i < arg->count - 1; i++) {
//			if ((arg->src)[i] < arg->threshold) {
//				i++;
//				continue;
//			}
//			if ((j = diff[i] - diff[i - 1]) < 0) {
//				if ((arg->flags & PVALUE) && (arg->src)[i] < arg->pvalue)
//					continue;
//				peaks_t[p_num++] = i;
//			}
//			else if (j > 0) {
//				if ((arg->flags & VVALUE) && (arg->src)[i] > arg->vvalue)
//					continue;
//				valleys_t[v_num++] = i;
//			}
//		}
//	}
//	else {
//		for (i = 1; i < arg->count - 1; i++) {
//			if ((j = diff[i] - diff[i - 1]) < 0) {
//				if ((arg->flags & PVALUE) && (arg->src)[i] < arg->pvalue)
//					continue;
//				peaks_t[p_num++] = i;
//			}
//			else if (j > 0) {
//				if ((arg->flags & VVALUE) && (arg->src)[i] > arg->vvalue)
//					continue;
//				valleys_t[v_num++] = i;
//			}
//		}
//	}
//	free(diff);
//	if ((arg->flags & PEAKS) && (arg->flags & PDISTANCE))
//		ret->peaks = check_distance(arg->src, peaks_t,
//			&p_num, arg->pdistance, findpeaks_max);
//	else
//		ret->peaks = peaks_t;
//	if ((arg->flags & VALLEYS) && (arg->flags & VDISTANCE))
//		ret->valleys = check_distance(arg->src, valleys_t,
//			&v_num, arg->vdistance, findpeaks_min);
//	else
//		ret->valleys = valleys_t;
//	if (!(arg->flags & PEAKS)) {
//		free(ret->peaks);
//		ret->peaks = NULL;
//		ret->p_num = 0;
//	}
//	else
//		ret->p_num = p_num;
//	if (!(arg->flags & VALLEYS)) {
//		free(ret->valleys);
//		ret->valleys = NULL;
//		ret->v_num = 0;
//	}
//	else
//		ret->v_num = v_num;
//	return ret;
//}
//
//int main() {
//	struct findpeaksret* findpeaksret_t;
//	struct findpeaksarg* findpeaksarg_t;
//	//分配内存给 findpeaksret_t 和 findpeaksarg_t
//	findpeaksret_t = (struct findpeaksret*)malloc(sizeof(struct findpeaksret));
//	findpeaksarg_t = (struct findpeaksarg*)malloc(sizeof(struct findpeaksarg));
//
//	findpeaksarg_t->src = data;
//	findpeaksret_t->p_num = (int)1024 / 2;
//	// findpeaksret_t->
//
//	findpeaksret_t = findpeaks(findpeaksarg_t);
//	int* pick = findpeaksret_t->peaks;
//
//	// 打印峰值数组中的值
//	for (int i = 0; i < 100; i++) {
//		printf("%d ", pick[i]);
//	}
//	printf("OKKKKKKKK");
//	// 在这里可以处理 findpeaksret_t 返回的数据
//
//	// 释放内存
//	free(findpeaksret_t->peaks);
//	free(findpeaksret_t->valleys);
//	free(findpeaksret_t);
//	free(findpeaksarg_t);
//
//	return 0;
//}


#include <stdlib.h>
//#include <iostream>
#include "stdio.h"

/*
* 函数:  findPeaks
* 参数:  *src        源数据数组
*          src_lenth   源数据数组长度
*          distance    峰与峰,谷与谷的搜索间距
*          *indMax     找到的峰的index数组
*          *indMax_len 数组长度
*          *indMin     找到的谷的index数组
*          *indMin_len 数组长度
*/
void findPeaks(double* src, double src_lenth, double distance, int* indMax, int* indMax_len, int* indMin, int* indMin_len)
{
	int* sign = (int*)malloc(src_lenth * sizeof(int));
	int max_index = 0,
		min_index = 0;
	*indMax_len = 0;
	*indMin_len = 0;

	for (int i = 1; i < src_lenth; i++)
	{
		double diff = src[i] - src[i - 1];
		if (diff > 0)          sign[i - 1] = 1;
		else if (diff < 0) sign[i - 1] = -1;
		else                sign[i - 1] = 0;
	}
	for (int j = 1; j < src_lenth - 1; j++)
	{
		double diff = sign[j] - sign[j - 1];
		if (diff < 0)      indMax[max_index++] = j;
		else if (diff > 0)indMin[min_index++] = j;
	}

	int* flag_max_index = (int*)malloc(sizeof(int) * (max_index > min_index ? max_index : min_index));
	int* idelete = (int*)malloc(sizeof(int) * (max_index > min_index ? max_index : min_index));
	int* temp_max_index = (int*)malloc(sizeof(int) * (max_index > min_index ? max_index : min_index));
	int bigger = 0;
	double tempvalue = 0;
	int i, j, k;
	//波峰  
	for (int i = 0; i < max_index; i++)
	{
		flag_max_index[i] = 0;
		idelete[i] = 0;
	}
	for (i = 0; i < max_index; i++)
	{
		tempvalue = -1;
		for (j = 0; j < max_index; j++)
		{
			if (!flag_max_index[j])
			{
				if (src[indMax[j]] > tempvalue)
				{
					bigger = j;
					tempvalue = src[indMax[j]];
				}
			}
		}
		flag_max_index[bigger] = 1;
		if (!idelete[bigger])
		{
			for (k = 0; k < max_index; k++)
			{
				idelete[k] |= (indMax[k] - distance <= indMax[bigger] & indMax[bigger] <= indMax[k] + distance);
			}
			idelete[bigger] = 0;
		}
	}
	for (i = 0, j = 0; i < max_index; i++)
	{
		if (!idelete[i])
			temp_max_index[j++] = indMax[i];
	}
	for (i = 0; i < max_index; i++)
	{
		if (i < j)
			indMax[i] = temp_max_index[i];
		else
			indMax[i] = 0;
	}
	max_index = j;

	//波谷  
	for (int i = 0; i < min_index; i++)
	{
		flag_max_index[i] = 0;
		idelete[i] = 0;
	}
	for (i = 0; i < min_index; i++)
	{
		tempvalue = 1;
		for (j = 0; j < min_index; j++)
		{
			if (!flag_max_index[j])
			{
				if (src[indMin[j]] < tempvalue)
				{
					bigger = j;
					tempvalue = src[indMin[j]];
				}
			}
		}
		flag_max_index[bigger] = 1;
		if (!idelete[bigger])
		{
			for (k = 0; k < min_index; k++)
			{
				idelete[k] |= (indMin[k] - distance <= indMin[bigger] & indMin[bigger] <= indMin[k] + distance);
			}
			idelete[bigger] = 0;
		}
	}
	for (i = 0, j = 0; i < min_index; i++)
	{
		if (!idelete[i])
			temp_max_index[j++] = indMin[i];
	}
	for (i = 0; i < min_index; i++)
	{
		if (i < j)
			indMin[i] = temp_max_index[i];
		else
			indMin[i] = 0;
	}
	min_index = j;

	*indMax_len = max_index;
	*indMin_len = min_index;

	free(sign);
	free(flag_max_index);
	free(temp_max_index);
	free(idelete);
}

#define N 256  // 信号长度
#define WINDOW_SIZE 10  // 滑动窗口大小

// 滑动平均滤波器
void movingAverageFilter(double* input, double* output, int length, int windowSize) {
	int i, j;
	double sum;

	for (i = 0; i < length; i++) {
		sum = 0.0;
		for (j = 0; j < windowSize; j++) {
			if (i - j >= 0) {
				sum += input[i - j];
			}
		}
		output[i] = sum / windowSize;
	}
}

//int main()
//{
//	double signal[N];
//	double smoothed[N];
//	int peakFs[30] = { 0 };			//不知道会找到几个,故申请的稍大
//	int peakFs_len = 0;
//	int peakFs2[30] = { 0 };		//不知道会找到几个,故申请的稍大
//	int peakFs2_len = 0;
//	// 应用滑动平均滤波器
//	movingAverageFilter(data, smoothed, N, WINDOW_SIZE);
//	findPeaks(data, 512, 150, peakFs, &peakFs_len, peakFs2, &peakFs2_len);
//	/*std::cout << "找到的峰的下标:" << std::endl;*/
//	for (int i = 0; i < peakFs_len; i++)
//		/*std::cout << peakFs[i] << std::endl;*/
//		printf("%d\n", peakFs[i]);
//	//std::cout << "找到的谷的下标:" << std::endl;
//	//for (int i = 0; i < peakFs2_len; i++)
//	//	std::cout << peakFs2[i] << std::endl;
//	system("pause");
//	return 0;
//}

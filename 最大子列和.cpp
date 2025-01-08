//��һ�������У��������еĺ����Ϊ���٣���Ϊ���������0

///According to time complexity,answers are classified into 4 classes by descending order

#include<iostream>
#include<math.h>
using namespace std;

#define N 100000

int f1(int n, int arr[]);
int f2(int n, int arr[]);
int f3(int n, int arr[]);
int Max3(int a, int b, int c);
int DivideAndQonquer(int list[], int left, int right);
int f4(int n, int arr[]);

int main()
{
	//input
	int n, arr[N];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout<<f3(n, arr);
	return 0;
}



//Calculate all cases and find the maximun,which is the easiest algorithm.
// the time complexity is n to the third power

//int f1(int n, int arr[])
//{
//	int max=0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			int sum = 0;
//			for (int k = i; k <= j; k++)
//			{
//				sum += arr[k];
//			}
//			if (sum > max)
//			{
//				max = sum;
//			}
//		}
//	}
//	return max;
//}



//the second algorithm is based on the first
// the time complexity is n to the second power

//int f2(int n, int arr[])
//{
//		int max=0;
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		for (int j = i; j < n; j++)
//		{
//			sum += arr[j];
//			if (sum > max)
//			{
//				max = sum;
//			}
//		}
//	}
//	return max;
//}




//the 3rd algorithm is divide and qonquer
// the time complexity is n times log(n)

int Max3(int a, int b, int c) //find the maximun from 3 numbers
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int DivideAndQonquer(int list[], int left,int right)
{
	int MaxLeftSum, MaxRightSum,MaxLeftBorderSum,MaxRightBorderSum, LeftBorderSum, RightBorderSum,center,i;

	if (left == right) //�ݹ����ֹ������������ֻ��һ������
	{
		if (list[left] > 0)
			return list[left];
		else
			return 0;
	}

	//��,�ݹ�
	center = (left + right) / 2;
	MaxLeftSum = DivideAndQonquer(list, left, center);
	MaxRightSum = DivideAndQonquer(list, center + 1, right);

	//��ֽ������к�
	MaxLeftBorderSum = 0, LeftBorderSum = 0;
	for (i = center; i >= left; i--) //����������ɨ��
	{
		LeftBorderSum += list[i];
		if (LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	MaxRightBorderSum = 0, RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) //����������ɨ��
	{
		RightBorderSum += list[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}


	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int f3(int n, int arr[]) //�ṩ��ǰ�����㷨��ͬ�ĺ����ӿ�
{
	return DivideAndQonquer(arr, 0, n - 1);
}



//the 4ht algorithm is processing in time
// the time complexity is n 

//int f4(int n, int arr[])
//{
//	int max = 0, sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr[i];
//		if (sum < 0)
//		{
//			sum = 0;
//		}
//		else if (sum > 0)
//		{
//			if (sum > max)
//			{
//				max = sum;
//			}
//		}
//	}
//	return max;
//}
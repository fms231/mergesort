#include<iostream>
#include<math.h>

using namespace std;

void merge(int* a, int frist1, int last1, int frist2, int last2)
{
	int* a1 = new int[last1 - frist1 + 1]; //���ϲ���������һ
	int* a2 = new int[last2 - frist2 + 1]; //���ϲ����������
	//�ֱ�ԭ�����ֵ��ֵ����ʱ������
	for (int i = 0; i < last1 - frist1 + 1; i++)
	{
		a1[i] = a[i + frist1];
	}
	for (int i = 0; i < last2 - frist2 + 1; i++)
	{
		a2[i] = a[i + frist2];
	}
	int i = 0, j = 0, k = frist1;
	//�ϲ�����
	while (i < last1 - frist1 + 1 && j < last2 - frist2 + 1)
	{
		if (a1[i] < a2[j])
		{
			a[k++] = a1[i++];
		}
		else
		{
			a[k++] = a2[j++];
		}
	}
	while (i < last1 - frist1 + 1)
	{
		a[k++] = a1[i++];
	}
	while (j < last2 - frist2 + 1)
	{
		a[k++] = a2[j++];
	}
}

void sort(int* a, int first, int last)
{
	int size = last - first + 1;
	int N = (int)sqrt(size);
	int first1, last1;
	//�����������
	if (size > 3)
	{
		for (int i = 0; i < N; i++) //�ֳɸ���n��
		{
			first1 = first + N * i;
			last1 = first1 + N - 1;
			sort(a, first1, last1);
		}
		sort(a, last1 + 1, last); //��ʣ�µ�Ԫ�ؽ�������
	}
	else
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = first; i < last - j; i++)
			{
				if (a[i] > a[i + 1])
				{
					int temp;
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
	}
	first1 = first;
	last1 = first1 + N - 1;
	//����3�Ż���ֺϲ����
	if (size > 3)
	{
		int first2, last2;
		//���кϲ�����
		for (int i = 1; i < N; i++)
		{
			first2 = first + N * i;
			last2 = first2 + N - 1;
			merge(a, first1, last1, first2, last2);
			last1 = last1 + N;
		}
		merge(a, first1, last1, last1 + 1, last);
	}
}

int main()
{
	int n;
	//�������鳤��
	cout << "please input the length of array:" << endl;
	cin >> n;
	int* a = new int[n];
	//��������Ԫ��
	cout << "input numbers:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//��������
	sort(a, 0, n - 1);
	//��ӡ���
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
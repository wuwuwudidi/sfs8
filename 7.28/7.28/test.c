#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print(int arr[], int sz);
//qsortʵ��
//qsort(arr,sz,sizeof(arr[0]),comp_int)
void Swap(char* buf1,char* buf2,int width)//����������ֵ�ĵ�ַ����֪���ж�󣬰ѿ��Ҳ�������ˣ���Ϊÿ�ν�����char* Ҫ����width�Σ���һ������������ֵ�ͽ��������� 
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}

}
int comp_int(const void*e1,const void *e2)
{
	return *(int*)e2 - *(int*)e1;//�ṹ�壨��struct stu*)e1->age-��struct stu*)e2->age)  strcmp����struct stu*)e1->name,��struct stu*)e2->name)  
}
void my_qsort(void* base, int sz, int width, int (*comp_int)(const void*,const void*))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j <sz-1-i ; j++)
		{
			
			if (comp_int((char*)base + width*j, (char*)base + width*(j+1))>0)
			{
				Swap((char*)base + width*j, (char*)base + width*(j + 1), width);
				

			}
		}
	}

}
void test1()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);
	my_qsort(arr, sz, width, comp_int);
	print(arr, sz);
}
void print( int* arr,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

}
int main()
{
	test1();

	
	return 0;

}
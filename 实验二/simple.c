int a,b,c;
struct test_struct
{
	int x;
	float y;
	string name;
};
int main()
{
	bool x;
	int alist[10];
	for (int i = 0; i < 10; i++)
	{
		alist[i] = 10 - i;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (alist[i] < alist[j])
			{
				int temp = alist[i];
				alist[i] = alist[j];
				alist[j] = temp;
			}
		}
	}
	bool bl = true;
	int count = 0;
	while (bl)
	{
		printf("%d",alist[count]);
		if (count >= 10) break;
		else continue;
	}
}
struct POINT
{
	int x;
	float y;
	string name;
};

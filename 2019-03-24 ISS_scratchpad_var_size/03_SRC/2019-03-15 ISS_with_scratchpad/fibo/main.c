int main(void)
{
	int f1=0, f2=1, f3, i; // initialize
	int n = 10;

	for( i=0; i<n-2; i++)
	{
		f3 = f1+f2;
		f1 = f2;
		f2 = f3;
	}

}


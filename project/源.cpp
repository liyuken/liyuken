#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
int check(int s[9][9], int x, int i, int j)
{
	int u, w1, w2,w3,w4,t;
	for (u = 0; u < 9; u++)
	{
		if (x == s[i][u])
		{
			return 0;
		}
	}
	for (u = 0; u < 9; u++)
	{
		if (x == s[u][j])
			return 0;
	}
	w1 = (i +1)/ 3;
	w2 = (j+1) / 3;
	w3 = (i +1)% 3;
	w4 = (j+1) % 3;
	if (w3 == 0)
	{
		w1 = w1 - 1;
	}
	if (w4 == 0)
		w2 = w2 - 1;
	for (u = 3 * w1; u < 3 * (w1 + 1); u++)
	{
		for (t = 3 * w2; t < 3 * (w2 + 1); t++) {
			if (x == s[u][t])
				return 0;
		}
	}
	return 1;
}
int main(int argc,char* argv[])
{

	FILE *fp;
	fp = fopen("sudoku.txt", "w");
	int n, n1,i1,j1;
	n = atoi(argv[argc - 1]);
	int i, j, c, h, loop, s,w;
	int a[9][9];
	for (i1 = 0; i1 < 9; i1++)
	{
		for (j1 = 0; j1 < 9; j1++)
		{
			a[i1][j1] = 0;
		}
}
	a[0][0] = 8;
	for (n1 = 0; n1 < n; n1++) {
		for (i = 0; i < 9; i++)
		{
			if (i == 0)
				s = 1;
			else s = 0;
			for (j = s; j < 9; j++)
			{
				h = rand();
				loop = 0;
				while (1) {
					if (loop == 0) {		
						w = h % 9 + 1;			
						if (w > 9)
							w = w - 9;
						c = check(a, w, i, j);
						if (c == 0)
							loop = loop + 1;
						if (c == 1)
						{
							a[i][j] = w;
							break;
						}
					}
					if (loop > 0 && loop < 9)
					{
		
						w = w + 1;
						if (w > 9)
							w = w - 9;

						c = check(a, w, i, j);
						if (c == 0)
							loop = loop + 1;
						if (c == 1)
						{
							a[i][j] = w; break;
						}

					}
					if (loop == 9)
					{
						for (int ss = 0; ss < 9; ss++)
						{
							a[i][j] = 0;
						}
						j = 0;			
						 break;
					}	
				}

			}
		}
		fp = fopen("sudoku.txt", "a");
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++) {
				fprintf(fp, "%d", a[i][j]);

			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");

		fclose(fp);

	}

}
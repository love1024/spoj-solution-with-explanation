#include<bits/stdc++.h>

using namespace std;

//http://zobayer.blogspot.in/2009/11/volume-of-irregular-tetrahedron.html

double cosine (int a, int b, int c)
{
	double temp = ( a*a + b*b - c*c ) / (2.0 * a * b);
	return (temp);
}

int main()
{
	long int t = 0, T = 0;
	scanf("%ld", &T);

	while(t++ < T)
	{
		int AB, BC, AC, AD, BD, CD;
		double cos1, cos2, cos3;

		scanf("%d%d%d%d%d%d", &AB, &AC, &AD, &BC, &BD, &CD);

		cos1 = cosine(AD, BD, AB);
		cos2 = cosine(BD, CD, BC);
		cos3 = cosine(CD, AD, AC);
		double temp = sqrt( 1 + 2 * cos1 * cos2 * cos3 - cos1*cos1 - cos2*cos2 - cos3*cos3);
		double answer = AD * BD * CD * temp / 6;
		printf("%.4lf\n", answer);
	}
	return 0;
}

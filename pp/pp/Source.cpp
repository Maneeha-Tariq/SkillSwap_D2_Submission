#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	float a, b, c;
	float s, ans = 0;
	printf("Enter three sides of the triangle\n");
	scanf_s("%f %f %f",&a, &b, &c);
	s = (a + b + c) / 2;
	ans = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("Area of triangle is:%f", ans);
}
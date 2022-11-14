#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h>

char *ChuanHoa(char *s)
{
	int i = 0;
	int n = strlen(s);
	while(i<n)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			s[i]=-32;
		}i++;
		while(i<n&&s[i]!=32)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]+=32;
				i++;
			}
		}
		while(i<n&&s[i]==32)
		{
			i++;
		}
		
	}return s;
}

int main()
{
	char *s;
	s = new char[100];
	fflush(stdin);
	gets(s);
	cout<<s;
	cout<<"\n";
	cout<<ChuanHoa(s);
	return 0;
}

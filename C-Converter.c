#include <stdio.h>

char hexConverter(int dec) 
{
	if (dec==10)
	{
		return 'A';
	}
	if (dec == 11)
	{
		return 'B';
	}
	if (dec == 12)
	{
		return 'C';
	}
	if (dec == 13)
	{
		return 'D';
	}
	if (dec == 14)
	{
		return 'E';
	}
	if (dec == 15)
	{
		return 'F';
	}
	else
	{
		return (dec+'0');
	}
}
int exponential(int x, int y) 
{
	if (y>0)
	{
		return x * exponential(x, y - 1);
	}
	else if (y==0)
	{
		return 1;
	}
	else if (y<0)
	{
		return 0;
	}
	else
	{
		return x;
	}
}

void DecToHex(int dec) 
{
	int hexDigit=0, remainder[6] = {-1,-1,-1,-1,-1,-1}, atWhichDigit = 0, repeater = 1;

	if (dec>16)
	{
		hexDigit = dec / 16;
		remainder[5] = dec % 16;
		atWhichDigit += 1;
	}
	else
	{
		hexDigit = dec;
	}

	while (hexDigit > 15) 
	{
		remainder[5-repeater] = hexDigit % 16;
		hexDigit = hexDigit / 16;
		atWhichDigit += 1;
		repeater++;
	}

	printf("%c", hexConverter(hexDigit));
	for (int x = 0; x < 6; x++)
	{
		if (remainder[x]>-1)
		{
			printf("%c", hexConverter(remainder[x]));
		}
		
	}

}
void DecToOct(int dec)
{
	int octDigit=0, remainder[6] = { -1,-1,-1,-1,-1,-1 }, atWhichDigit = 0, repeater = 1;

	if (dec > 8)
	{
		octDigit = dec / 8;
		remainder[5] = dec % 8;
		atWhichDigit += 1;
	}
	else
	{
		octDigit = dec;
	}

	while (octDigit > 7)
	{
		remainder[5 - repeater] = octDigit % 8;
		octDigit = octDigit / 8;
		atWhichDigit += 1;
		repeater++;
	}

	printf("%d", octDigit);
	for (int x = 0; x < 6; x++)
	{
		if (remainder[x] > -1)
		{
			printf("%d",remainder[x]);
		}

	}

}
void DecToBinary(int dec)
{
	int binDigit=0, remainder[16] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }, atWhichDigit = 0, repeater = 1;

	if (dec > 2)
	{
		binDigit = dec / 2;
		remainder[15] = dec % 2;
		atWhichDigit += 1;
	}
	else
	{
		binDigit = dec;
	}

	while (binDigit > 1)
	{
		remainder[15 - repeater] = binDigit % 2;
		binDigit = binDigit / 2;
		atWhichDigit += 1;
		repeater++;
	}

	printf("%d", binDigit);
	for (int x = 0; x < 16; x++)
	{
		if (remainder[x] > -1)
		{
			printf("%d",remainder[x]);
		}

	}

}



int main()
{
	char* allinputs[100];
	for (int x = 0; x < 100; x++)
	{
		allinputs[x] = (char[8]){' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' };
	}
	int dec=0;
	char whichToConvert='N',endOfNum;

	
	for (int y = 0; y < 100; y++)
	{
		gets(allinputs[y]);
		if(allinputs[y][0] != NULL && allinputs[y][0] !=' ')
		{
			for (int x = 0; x < 7; x++)
			{
				if (allinputs[0][x] == ' ')
				{
					whichToConvert = allinputs[0][x + 1];
					endOfNum = x;
					break;
				}
			}

			for (int x = 1; x < endOfNum + 1; x++)
			{
				int a = allinputs[0][x - 1] - '0';
				dec += exponential(10, endOfNum - x) * a;
			}

			if (whichToConvert == 'b' || whichToConvert == 'B')
			{
				DecToBinary(dec);
				printf("\n");
			}
			if (whichToConvert == 'o' || whichToConvert == 'O')
			{
				DecToOct(dec);
				printf("\n");
			}
			if (whichToConvert == 'h' || whichToConvert == 'H')
			{
				DecToHex(dec);
				printf("\n");
			}

			dec = 0;
		}
		else 
		{
			break;
		}

	}
	
	
}
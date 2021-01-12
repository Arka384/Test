#include<stdio.h>
#include<stdlib.h>
void turnA(void );
void turnCOMP(void );
void display(void);
void check_win(char );
void won(char );
void full(void);
void initialize(void);
char ar[3][3]={0};
int flag = 0;
int main()
{
	int i,j;
    char c;
	printf("\nTic Tac Toe game\n");
	printf("\nDON'T PRESS ANY KEY");
	printf("\nRead the instructions carefully");
	printf("\nPlease Wait...");
//	sleep(10);
    while(1)
    {
        system("cls");
        printf("\nPlayers will have to enter the location of the purticular place when their turn comes");
        printf("\nFor reference: \n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(j==1 || j==2)
                    printf("|");
                printf(" %d %d ",i+1,j+1);
            }
            printf("\n");
        }
        printf("\nThis is the desgine of the boxes");
        printf("\nYou will have to enter inputs as 22 / 13 / 21 etc");
        printf("\nIf Understood Press any key to start: ");
        getchar();
        system("cls");
        while(1)
        {
            display();
            full();
            if(flag == 1)
                break;
            turnA();
            system("cls");
            display();
            check_win('O');
            full();
            turnCOMP();
            system("cls");
            display();
            check_win('X');
            system("cls");
        }
        flag = 0;
        initialize();
        printf("\nDo you want to play again ?");
        printf("\nPress Y or yes or N for no: ");
        fflush(stdin);
        scanf("%c",&c);
        if(c == 'n' || c == 'N')
            break;
    }
}
void turnA()
{
	int m=0,n=0,i,j,x;
	start:
	printf("\nTurn for A-> ");
	scanf("%2d",&x);
	n=(x%10)-1;
	m=(x/10)-1;
    if(m == -1 || x>33)
    {
        printf("\nInvalid Move");
	    goto start;
    }
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==m && j==n)
			{
				if(ar[i][j]=='O' || ar[i][j]=='X')
				{
					printf("\nInvalid Move");
					goto start;
				}
				else
					ar[i][j]='O';
			}
		}
	}
}
////////////////////////////////////////////
void turnCOMP()
{
	int i,j,m,n,flag=0,f=0;
	int r=0,c=0,x=0,d1=0,d2=0;
	for(i=0;i<3;i++)
	{
		f=x=0;
		for(j=0;j<3;j++)
		{
			if(ar[i][j]=='\0')
			{
				m=i;
				n=j;
				f=1;
			}
			if(ar[i][j]=='X')
				x++;
			if(x==2 && f==1)
			{
				ar[m][n]='X';
				flag=1;
				goto end;
			}
		}
	}
	for(j=0;j<3;j++)
	{
		f=x=0;
		for(i=0;i<3;i++)
		{
			if(ar[i][j]=='\0')
			{
				m=i;
				n=j;
				f=1;
			}
			if(ar[i][j]=='X')
				x++;
			if(x==2 && f==1)
			{
				ar[m][n]='X';
				flag=1;
				goto end;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		f=x=0;
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				if(ar[i][j]=='\0')
				{
					m=i;
					n=j;
					f=1;
				}
				if(ar[i][j]=='X')
					x++;
				if(x==2 && f==1)
				{
					ar[m][n]='X';
					flag=1;
					goto end;
				}		
			}
			f=x=0;
			if(i+j==2)
			{
				if(ar[i][j]=='\0')
				{
					m=i;
					n=j;
					f=1;
				}
				if(ar[i][j]=='X')
					x++;
				if(x==2 && f==1)
				{
					ar[m][n]='X';
					flag=1;
					goto end;
				}	
			}
		}
	}
	/////////////////////
	for(i=0;i<3;i++)
	{
		f=c=0;
		for(j=0;j<3;j++)
		{
			if(ar[i][j]=='\0')
			{
				m=i;
				n=j;
				f=1;
			}
			if(ar[i][j]=='O')
				c++;
			if(c==2 && f==1)
			{
				ar[m][n]='X';
				flag=1;
				goto end;
			}
		}
	}
	for(j=0;j<3;j++)
	{
		f=c=0;
		for(i=0;i<3;i++)
		{
			if(ar[i][j]=='\0')
			{
				m=i;
				n=j;
				f=1;
			}
			if(ar[i][j]=='O')
				c++;
			if(c==2 && f==1)
			{
				ar[m][n]='X';
				flag=1;
				goto end;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		f=c=0;
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				if(ar[i][j]=='\0')
				{
					m=i;
					n=j;
					f=1;
				}
				if(ar[i][j]=='O')
					c++;
				if(c==2 && f==1)
				{
					ar[m][n]='X';
					flag=1;
					goto end;
				}
			}
			f=c=0;
			if(i+j==2)
			{
				if(ar[i][j]=='\0')
				{
					m=i;
					n=j;
					f=1;
				}
				if(ar[i][j]=='O')
					c++;
				if(c==2 && f==1)
				{
					ar[m][n]='X';
					flag=1;
					goto end;
				}
			}
		}
	}
	///////////////
	if(flag==0)
		ar[m][n]='X';
	end:
		;
}
///////////////////////////////////////////
void display()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==1 || j==2)
				printf("|");
			printf(" %c ",ar[i][j]);
		}
		if(i==0)
			printf("\t\t 1 1 | 1 2 | 1 3 ");
		else if(i==1)
			printf("\t\t 2 1 | 2 2 | 2 3 ");
		else
			printf("\t\t 3 1 | 3 2 | 3 3 ");
		printf("\n");
	}
}
void check_win(char s)
{
	int i,j,c,d1=0,d2=0;
	for(i=0;i<3;i++)
	{
		c=0;
		for(j=0;j<3;j++)
		{
			if(ar[i][j]==s)
				c++;
			if(c==3)
				won(s);	
		}
	}
	for(j=0;j<3;j++)
	{
		c=0;
		for(i=0;i<3;i++)
		{
			if(ar[i][j]==s)
				c++;
			if(c==3)
				won(s);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				if(ar[i][j]==s)
					d1++;
				if(d1==3)
					won(s);
			}
			if(i+j==2)
			{
				if(ar[i][j]==s)
					d2++;
				if(d2==3)
					won(s);
			}
		}
	}
}
void won(char s)
{
	if(s=='O')
	{
		printf("\nPlayer A(O) Won ");
		sleep(2);
        flag = 1;
		return;
	}
	if(s=='X')
	{
		printf("\nPlayer B(X) Won ");
		sleep(2);
        flag = 1;
		return;
	}
}
void full()
{
	int i,j,f=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(ar[i][j]=='O' || ar[i][j]=='X')
				f++;
		}
	}
	if(f==9)
	{
		printf("\nMatch Draw");
        flag = 1;
		return;
	}
}
void initialize()
{
    int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
            ar[i][j] = 0;
}

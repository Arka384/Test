#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
void turnA(void );
void turnB(void );
void turnCOMP(void );
void display(void);
void check_win(char );
void won(char );
void full(void);
void loader(void);
void initialize(void);
char ar[3][3]={0};
char player1[size],player2[size];
int flag = 0;
int main()
{
	int i,j,choice;
    char c;
	printf("\nTic Tac Toe game\n");
	printf("\nRead the instructions carefully");
	loader();
	
	start:
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
	printf("\nThis above reference diagram will be given aside while playing");
    printf("\nIf Understood Press enter/return: ");
	fflush(stdin);
    getchar();

    while(1)
    {
		system("cls");
		printf("\n\n1 -> To play against computer");
		printf("\n2 -> To play locally");
		printf("\n3 -> For instructions");
		printf("\n4 -> To exit");
		printf("\nEnter a choice: ");
		scanf("%d",&choice);
        system("cls");
		switch(choice)
		{
			case 1:
				strcpy(player2, "Computer");
				printf("\nEnter player name: ");
				fflush(stdin);
				gets(player1);
				system("cls");
				startA:
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
					if(flag == 1)
						break;
					turnCOMP();
					system("cls");
					display();
					check_win('X');
					if(flag == 1)
						break;
					system("cls");
				}
				flag = 0;
				initialize();
				printf("\nPress enter/return to play again or N for no: ");
				fflush(stdin);
				c = getch();
				if(c == 'n' || c == 'N')
					break;
				else
				{
					system("cls");
					goto startA;
				}
				
				break;
			case 2:
				printf("\nEnter player 1 name: ");
				fflush(stdin);
				gets(player1);
				printf("\nEnter player 2 name: ");
				fflush(stdin);
				gets(player2);
				system("cls");
				startB:
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
					if(flag == 1)
						break;
					turnB();
					system("cls");
					display();
					check_win('X');
					if(flag == 1)
						break;
					system("cls");
				}
				flag = 0;
				initialize();
				printf("\nPress enter/return to play again or N for no: ");
				fflush(stdin);
				c = getch();
				if(c == 'n' || c == 'N')
					break;
				else
				{
					system("cls");
					goto startB;
				}
				break;
			case 3:
				goto start;
				break;
			case 4:
				printf("\nThank you for playing");
				sleep(3);
				exit(1);
			default:
				printf("\nYour choice is not correct");
				break;
		}
    }
}
void turnA()
{
	int m=0,n=0,i,j,x;
	start:
	printf("\nTurn for %s: ",player1);
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
void turnB()
{
	int m,n,i,j,x;
	startB:
	printf("\nTurn for %s: ",player2);
	scanf("%d",&x);
	n=(x%10)-1;
	m=(x/10)-1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==m && j==n)
			{
				if(ar[i][j]=='O' || ar[i][j]=='X')
				{
					printf("\nInvalid Move");
					goto startB;
				}
				else
					ar[i][j]='X';
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
	printf("Your Game \t\t Reference diagram\n\n");
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
		printf("\n%s won this round", player1);
		sleep(1);
        flag = 1;
		return;
	}
	if(s=='X')
	{
		printf("\n%s Won this round", player2);
		sleep(1);
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
		printf("\n!!!! Match Draw !!!!");
		sleep(1);
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
void loader()
{
	int i;
	sleep(2);
	printf("\nPlease wait while loading....");
	sleep(1);
	printf("\nProgress... ");
	for(i=0;i<90;i++)
	{
		usleep(40000);
		printf("%c",219);
	}
	sleep(2);
}
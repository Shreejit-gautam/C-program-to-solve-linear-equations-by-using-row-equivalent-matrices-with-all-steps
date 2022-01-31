#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
 float matrix[3][4];
 int x=30,y=1;
 void show();
 float Abs(float a)
 {
 	if (a<0)
 	{
 		return (a*(-1));
	 }
	 return a;
 }
 void gotoxy(int x,int y)
{
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void swap(float *a,float *b)
{
	float c=*a;
	*a=*b;
	*b=c;
}
void interchange(short row1,short row2)
{
	for(int i=0;i<=3;i++)
	{
		swap(&matrix[row1][i],&matrix[row2][i]);
}
}

 struct element
{
	float no;
	float de;
 } s;
void divide(float rn)
{
 s.no=1;
 s.de=1;
	float n=s.no/s.de;
	while(Abs(n-rn)>0.0001)
	{

		if(rn>n)
		{
			s.no++;
		}
	else
	{
		s.de++;
	}
	n=s.no/s.de;
	}
}

 void Matrix_subs(short int row1,short int row2,float constant )
{
if(Abs(constant-(int)constant)>0.9999 || Abs(constant-(int)constant)<0.0001)
{
gotoxy(x,y);
printf("performing R%d-->R%d-%dR%d",row1+1,row1+1,(int)constant,row2+1);

}
else
{
	if(constant<0)
	{
	divide(constant*(-1));
	gotoxy(x,y);
printf("performing R%d-->R%d+%0.f/%0.fR%d",row1+1,row1+1,s.no,s.de,row2+1);

}
else
{
	divide(constant);
	gotoxy(x,y);
printf("performing R%d-->R%d-%0.f/%0.fR%d",row1+1,row1+1,s.no,s.de,row2+1);

}
}
	y++;
	for(int i=0;i<=3;i++)
	{
		matrix[row1][i]-=(matrix[row2][i]*constant);
}
show();
}
void Matrix_multiply(short  int row1,float constant )
{

if(Abs(constant-(int)constant)>0.9999 || Abs(constant-(int)constant)<0.0001)
{
gotoxy(x,y);
printf("performing R%d-->(1/%.0f)R%d",row1+1,constant,row1+1);
y++;
}
else
{
	if(constant<0)
	{
	divide(constant*(-1));
	gotoxy(x,y);
printf("performing R%d-->-(%0.f/%0.f)R%d",row1+1,s.de,s.no,row1+1);


}
else
{
	divide(constant);
	gotoxy(x,y);
printf("performing R%d-->(%0.f/%0.f)R%d",row1+1,s.de,s.no,row1+1);


}

}
y++;
	for(int i=0;i<=3;i++)
	{
		matrix[row1][i]/=constant;
	}
	show();
}
void show()
{

printf("\n\n");
	for(int r=0;r<=2;r++)
	{

		for(int c=0;c<=3;c++)
		{
if(Abs(matrix[r][c]-(int)matrix[r][c])>0.9999 || (Abs(matrix[r][c]-(int)matrix[r][c]))<0.0001)
{
gotoxy(x,y);
printf("%.0f ",matrix[r][c]);
x+=6;
}
else
{
	if(matrix[r][c]<0)
	{
	divide(matrix[r][c]*(-1));
	gotoxy(x,y);
printf("-%.0f/%.0f",s.no,s.de);
x+=6;
}
else
{
	divide(matrix[r][c]);
	gotoxy(x,y);
	printf("%.0f/%.0f",s.no,s.de);
	x+=6;
}

}
		}
		x=30;
		y++;
	}
	y++;
}
void main()
{
	for(int r=0;r<=2;r++)
	{
		gotoxy(1,y);
		printf("Enter the element of %d row ",r+1);
		for(int c=0;c<=3;c++)
		{
			gotoxy(x,y);
			scanf("%f",&matrix[r][c]);
		x+=6;
		}
		x=30;
		y++;
	}
	y++;
	gotoxy(1,y);
	printf("Required matrix is:");
		show();

	int row;
	for(int column=0;column<=2;column++)
	{
		row=column;

		if(matrix[2][2]==0 && matrix[1][0]!=0)
		{
			interchange(2,0);
			gotoxy(1,y);
	printf("Interchanging row1 and row3:");
	show();
			y++;
		}
		else if(matrix[0][0]==0 && matrix[2][0]!=0)
		{
			interchange(0,2);
			gotoxy(1,y);
	printf("Interchanging row1 and row3:");
	show();
			y++;
		}
		else if(matrix[row][column]==0 && matrix[row+1][column]!=0)
		{
				interchange(row,row+1);
			gotoxy(1,y);
	printf("Interchanging row1 and row3:");
		show();
			y++;
		}
		if(matrix[row][row]!=1)
		{
		Matrix_multiply(row,matrix[row][row]);
	}
		row++;
			for(int i=0;i<=1;i++)
		{
			if(row==3)
			{
				row=0;
			}
			Matrix_subs(row,column,matrix[row][column]);

			row++;

}
	}
	gotoxy(1,y);
	printf("the value of  x is %0.f \ny is %0.f \nz is %0.f ",matrix[0][3],matrix[1][3],matrix[1][3]);
}

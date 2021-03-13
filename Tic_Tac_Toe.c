#include <stdio.h>
#include <stdlib.h>

void print_matrix(char a[3][3])
{
    int i=0,j=0;
    for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%c  ",a[i][j]);
    }
    printf("\n\n");
}
}

char player_X(char a[3][3])
{
    int i=0,j=0,count=0,k;
    printf("\nPLAYER X :: ");
    scanf("%d",&k);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            count++;
            if(count==k)
                break;
        }
        if(count==k)
            break;
    }
    a[i][j]='X';
    return a;
}

char player_O(char a[3][3])
{
    int i=0,j=0,count=0,k;
    printf("\nPLAYER O :: ");
    scanf("%d",&k);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            count++;
            if(count==k)
                break;
        }
        if(count==k)
            break;
    }
    a[i][j]='O';
    return a;
}

int check(char a[3][3])
{
    int i,j,q=0,w=0,e=0,r=0,s=0;
    for(i=0;i<3;i++)
    {
        q=0; w=0; e=0; r=0;
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X')
                q++;
            if(a[j][i]=='X')
                w++;
            if(a[i][j]=='O')
                e++;
            if(a[j][i]=='O')
                r++;
        }
            if(q==3||w==3||e==3||r==3)
                    break;
    }
    if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
        q=3;
    if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
        e=3;
    if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
        q=3;
    if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
        e=3;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X'||a[i][j]=='O')
                s++;
        }
    }
    if(q==3||w==3||e==3||r==3)
        return 1;
    else if(s==9)
        return 2;
    else
        return 0;
}

int main ()
{
    int i,j,count=49,x=0,k;
    char a[3][3];

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        a[i][j]=count++;

print_matrix(a);

while(x==0)
{
    player_X(a);
    system("cls");
    print_matrix(a);

    x=check(a);
    if(x==1||x==2)
        {
            if(x==1)
            x=9;
            if(x==2)
            x=8;
            break;
        }

    player_O(a);
    system("cls");
    print_matrix(a);

    x=check(a);

}
if(x==9)
    printf("PLAYER X WINS !!\n");
else if(x==8)
    printf("GAME DRAW !!\n");
else
    printf("PLAYER O WINS !!\n");


   return 0;
}

                                           //snake & ladder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include<akash.h>
void pattern(int num[],int number,int numn,int k,int turn);
#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_ORANGE "\x1b[38;2;255;165;0m"
#define AC_NORMAL "\x1b[m"
#define Ac_AKASH  "\x1b[52n"
int main()
{
    int turn=1,number=0,numn=0,p=0;
        while(1)
    {
        system("cls");
        int k=0;
    int num[50]={41,42,43,44,45,46,47,48,49,50,40,39,38,37,36,35,34,33,32,31,21,22,23,24,25,26,27,28,29,30,20,19,18,17,16,15,14,13,12,11,1,2,3,4,5,6,7,8,9,10};
    pattern(num,number,numn,k,turn);
    printf("\nSNAKES ARE ON FOLLOWING POSITION :19,28,36,42,49\nLADDER ARE ON FOLLOWING POSITION :7,10,25,34\n");

        
        srand(time(NULL));
     p=rand()%6+1;
        
    if(turn%2!=0)
    {
         number+=p;
        printf("%s\nPLAYER 1 TURN \nPRESS ENTER FOR ROLL A DICE:\n",AC_YELLOW );
        getchar();
        printf("%sYOUR NUMBER IS %d\n",AC_BLUE,p);
        if(number>=50)
         {
            if(number==50)
            {
            printf("%sPLAYER 1 CONGRATULATION YOU'R WINNER\n",AC_NORMAL);
            return 0;
            }
            else
              number-=p;
         }
        else if(number==16 || number==36||number==25||number==42||number==49)
        {
            if(number==49)
                number-=40;
            else
                number-=8;
            printf("%sohh! YOU ARE BEAT BY SNAKE NOW YOU ARE IN %d POSITION:\n",AC_RED,number);
        }
        else if(number==7 || number==10||number==25||number==34||number==21)
        {
            number+=12;
        printf("%sWOW! YOU ARE LANDED ON LADDER NOW YOU ARE IN %d POSITION:\n",AC_ORANGE,number);
        }else
        printf("%sAND YOU ARE IN %d POSITION:\n",AC_BLUE,number); 
    }
    else
    {
         numn+=p;
        printf("%s\nPLAYER 2 TURN \nPRESS ENTER FOR ROLL A DICE:\n",AC_GREEN);
        getchar();
        printf("%sYOUR NUMBER IS %d\n",AC_CYAN,p);
         if(numn>=50)
         {
            if(numn==50)
            {
            printf("%sPLAYER 2 CONGRATULATION YOU'R WINNER\n",AC_NORMAL);
            return 0;
            }
            else
                numn-=p;
         }
        else
        if(numn==19 || numn==28||numn==36||numn==42||numn==49)
        {
            if(numn==49)
            numn-=40;
            else
            numn-=8;
            printf("%sohh! YOU ARE BEAT BY SNAKE NOW YOU ARE IN %d POSITION:\n",AC_RED,numn);
        }
        else if(numn==7 || numn==10||numn==25||numn==34||number==21)
        {
            numn+=12;
        printf("%sWOW! YOU ARE LANDED ON LADDER NOW YOU ARE IN %d POSITION:\n",AC_ORANGE,numn);
        }
        else
        printf("%sAND YOU ARE IN %d POSITION:\n",AC_CYAN,numn);
    }
     sleep(2);
        turn++;
    }
}

void pattern(int num[],int number,int numn,int k,int turn)
{
for(int i=1;i<22;i++)
    {
        for(int j=1;j<52;j++)
        {
            int P=k;
            if( j==6||j==11||j==16||j==21||j==26||j==31||j==36||j==41||j==46 || i==5||i==9||i==13||i==17||i==21|| i==1 || j==1 || j==51)
                printf("%s* ",AC_NORMAL);
            else if(i%2!=0 && (j==3 ||j==8||j==13||j==18||j==23||j==28||j==33||j==38||j==43||j==48))
            {
                if(num[k]>0&&num[k]<10)
                {
                    if(turn%2!=0)
                    {
                         if(number==num[k])
                             printf("%s%d ",AC_YELLOW,num[k]);
                         else if(numn==num[k])
                             printf("%s%d ",AC_GREEN,num[k]);
                        else if(num[P]==7)
                             printf("%s%d ",AC_ORANGE,num[P]);
                         else
                             printf("%s%d ",AC_NORMAL,num[k]);
                    }
                    else
                    {
                         if(number==num[k])
                             printf("%s%d ",AC_YELLOW,num[k]);
                         if(numn==num[k])
                             printf("%s%d ",AC_GREEN,num[k]);
                        else if(num[P]==7)
                             printf("%s%d ",AC_ORANGE,num[P]);
                         else
                             printf("%s%d ",AC_NORMAL,num[k]);
                    }
                }   
                 else
                {
                    
                    if(turn%2!=0)
                    {
                        if(num[k]==19||num[k]==36||num[k]==28||num[k]==42||num[k]==49)
                             printf("%s%d",AC_RED,num[k]);
                        else if(num[P]==10||num[P]==25||num[P]==34||num[P]==21)
                            printf("%s%d",AC_ORANGE,num[P]);
                        else if(number==num[k])
                             printf("%s%d",AC_YELLOW,num[k]);
                        else if(numn==num[k])
                             printf("%s%d",AC_GREEN,num[k]);
                        else
                             printf("%s%d",AC_NORMAL,num[k]);
                    }
                    else
                    {
                        if(num[k]==19||num[k]==36||num[k]==28||num[k]==42||num[k]==49)
                             printf("%s%d",AC_RED,num[k]);
                        else if(num[P]==10||num[P]==25||num[P]==34||num[P]==21)
                            printf("%s%d",AC_ORANGE,num[P]);
                        else if(number==num[k])
                             printf("%s%d",AC_YELLOW,num[k]);
                        else if(numn==num[k])
                             printf("%s%d",AC_GREEN,num[k]);
                        else
                             printf("%s%d",AC_NORMAL,num[k]);
                    }  
                } 
            k++;
            }
            
            else
                printf("  ");
        }
        printf("\n");
    }

}

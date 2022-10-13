#include <stdio.h> 
#include <stdlib.h>  
#include <math.h> 
#include<string.h>

int power(int VA,int PA, int PS);
int Hexadecimal();
int SwitchCase(char hexa[1000]);
int SwitchCase1(char r[1000]);
int ArrayList();
int Listvalue(char hexaD[1000]);

#define LSIZ 1000 
#define RSIZ 10 

int main() 
{    
   FILE *fp;
   char c;

   printf("\t_______________");
   printf("Page Table");
   printf("_______________");
   printf("\n\n");
   fp = fopen("PageTable.txt", "r");    
   while ((c = fgetc(fp)) != EOF)
   {
      printf("%c",c);
   }      
   fclose(fp);
   printf("\n");

   int VA,PA,PS;
   int result = power(VA,PA,PS);
   
   int result1 = Hexadecimal();
   
   return 0;
}

int power(int VA,int PA, int PS)
{
   
    VA = 16;            //VA = Virtual Address
    PA = 16;            //PA = Physical Address
    PS = 4096;          //PS = Page Size

   printf("\n\t______________");
   printf("Calculations");
   printf("______________");
   printf("\n");

//========================================================*/
    printf("\nSize of Virtual address : %d bits",VA);
    printf("\nSize of Physical address : %d bits",PA);
    printf("\nPage Size : %d bits",PS);
    printf("\n\n");

//========================================================*/
    printf("Size of Main Memory : ");
            
    printf("\n\tNo. of bit in a Physical Address : %d bits",PA);
    printf("\n\t\ti.e, ");
    printf("\n\t\t   = 2^%d B ",PA);
    printf("\n\t\t   = %.f B",pow(2,PA));              //For calculating Power we use pow(base,power)

    printf("\n\n");
//========================================================
    printf("No. of frame in Main Memory : ");
    printf("\n\tSize of Main Memory : %d bits",PA);
    printf("\n\tFrame Size \t: %d bytes",PS);
    printf("\n\t\t   = Size of Main Memory / Frame Size");

    float P = log (PS)/log (2);          //P =Power of the number
    printf("\n\t\tExponent for number %d and base %d = %.f ",PS,2,P); 

    printf("\n\t\t   = 2^%d / 2^%.f ",PA,P);
    printf("\n\t\t   = 2^(%d-%.f) ",PA,P);
    
    float R = PA - P; 
    printf("\n\t\t   = 2^%.f ",R);
    printf("\n\t\t No. of frame = %.f bits",R);
    
    printf("\n\n");

//========================================================
    printf("No. of Page Offset : ");
    printf("\n\tPage Size : %d bytes",PS);
    float P1 = log (PS)/log (2);          //P1 = Power of the number
    printf("\n\t\tExponent for number %d and base %d = %.f ",PS,2,P1); 
    printf("\n\t\tSo, 2^%.f = %d",P1,PS);
    printf("\n\t\t No. of Page offset = %.f bits",P1);

    printf("\n\n");
//========================================================
printf("So, Physical Address is : ");
printf("\n\n");
printf("\t\t<-----------%d bit---------->",PA);
printf("\n\t\t ___________________________");
printf("\n\t\t|             |             |");
printf("\n\t\t|Frame Number | Page Offset |");
printf("\n\t\t|_____________|_____________|");
printf("\n\t\t<----%.f bit---><----%.f bit--->",R,P1);
printf("\n\n\t\t\tPhysical Address");
printf("\n");

    printf("\n");
}

int Hexadecimal()
{  
  printf("\n\t_______________");
   printf("HEXA DECIMAL");
   printf("_______________");
   printf("\n");

    int ArrayConversion = ArrayList();

    char arr[RSIZ][LSIZ];
	char fname[20] = "Entry.txt";
    FILE *fptr; 
    int i = 0;

    fptr = fopen(fname, "r");
    while(fgets(arr[i], LSIZ, fptr)) 
	{
        arr[i][strlen(arr[i]) - 1] = '\0';
        i++;
    }
     printf("\n");
     for(i = 0; i < 5; i++)
        {
	    printf("\nHexadecimal Value : 0x");    
        printf("%s  ", arr[i]);
        char hexa[1000];
        stpcpy(hexa, arr[i]); 
         printf("\nBinary Value : ");
        int result2 = SwitchCase(hexa);
        printf("\n");
        int result3 = Listvalue(hexa);
        printf("\n");
        }
    printf("\n");
    return 0;
}
int ArrayList()
{
    int arr[16] = {0};
    int arr1[16] = {0};
    int arr2[16] = {0};
    FILE *fp, *fp1, *fp2;
    printf("\n");
   fp = fopen("page1.txt", "r");
   fp1 = fopen("Pageframe.txt", "r");
   fp2 = fopen("Reference.txt", "r");

    printf("Page : ");
     for (int i =0;i<=16;i++)
    {
        while (fscanf(fp, "%d", &arr[i]) != EOF) {
            printf("%d  ", arr[i]);
            i++;
        }
        printf("\n");
    }
    printf("Page Frame : ");
    for (int i =0;i<=16;i++)
    {
        while (fscanf(fp1, "%d", &arr1[i]) != EOF) {
            printf("%d  ", arr1[i]);
            i++;
        }
    }
        printf("\n");
   printf("Reference Bit : ");
    for (int i =0;i<=16;i++)
    {
        while (fscanf(fp2, "%d", &arr2[i]) != EOF) {
            printf("%d  ", arr2[i]);
            i++;
        }
    }               
       fclose(fp);
       fclose(fp1);
       fclose(fp2);
              
    printf("\n");    
}

int Listvalue(char hexa[1000])
{    
    int arr[16] = {0};
    int arr1[16] = {0};
    int arr2[16] = {0};
    FILE *fp, *fp1, *fp2;
   fp = fopen("page1.txt", "r");
   fp1 = fopen("Pageframe.txt", "r");
   fp2 = fopen("Reference.txt", "r");

     for (int i =0;i<=16;i++)
    {
        while (fscanf(fp, "%d", &arr[i]) != EOF) {
            i++;
        }
    }
    for (int i =0;i<=16;i++)
    {
        while (fscanf(fp1, "%d", &arr1[i]) != EOF) {
            i++;
        }
    }
    for (int i =0;i<=16;i++)
    {
        while (fscanf(fp2, "%d", &arr2[i]) != EOF) {
            i++;
        }
    }               
       fclose(fp);
       fclose(fp1);
       fclose(fp2);
//************************************************************************
   for (int i = 1; i < 2; i++)
   {      
    //char hexa[1000];
    printf("\nEntered Hexadecimal value 0x%s",hexa);

    int len = strlen(hexa) - 1;         //Printing the first digit of the element
    printf("\n\tVirtual Page Number : %c",hexa[0]); 
    printf("\n");

    char PL[1000] = {'0'};      //PL is a random variable for copy to new char hex[1000] 
    PL[0] =  hexa[0] ;
    
    //------------------------------------------ 
        /*Converting the bto*/
    char hex[1000];
    strcpy(hex,PL);       //Copy Value to new char

    int decimal, place; 
    int i = 0, val, len1;
    decimal = 0;   
    place = 1;
    len1 = strlen(hex) - 1;      
    
     for(i=0; hex[i]!='\0'; i++)
    {
       if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len1);
        len1--;
    }
    printf("\tDecimal Equivalent to Virtual Page Number : %d", decimal);

    arr[decimal] = arr1[decimal];   //printing the corresponding element of Page and PageFrame
    printf("\n\tPage Frame Number : %d",arr[decimal]);

  //--------------------------------------------  

    //Converting decimal to binary value
    int n = arr[decimal]; 
   /* int c , k;
    printf("\tBinary Value : ");      // Converting to binary value
    for (c = 3; c >= 0; c--)
    {
        k = n >> c;

        if (k & 1)
          printf("1");
        else
         printf("0");
    }*/
    printf("\n");

/************************************************************************/    
                /*Replacing part*/
   
   char s[1000],c1,c2;  
    int  q;
    strcpy(s,hexa);         //copying 'hexa' value to 's' 
    printf("\n\tEntered Hexadecimal : 0x%s\n",s);
    

    int Newlen = strlen(s) - 1;     
    c1 = s[0] ;
	//printf("\tThe Digit to replace: %c\n",c1);
    

    int decimalNumber = n,quotient;
    	int i1=1,j,temp;
    	char hexadecimalNumber[100];
    	//printf("\tDecimal number: %d\n",decimalNumber);
    	
    	quotient = decimalNumber;       //Converting to Hexadecimal
    	while(quotient!=0) {
    		temp = quotient % 16;
    	
    		if( temp < 10)
    		    temp =temp + 48; 
            else
    		    temp = temp + 55;
    		hexadecimalNumber[i1++]= temp;
    		quotient = quotient / 16;
    	}
    	printf("\tEquivalent hexadecimal value of %d is : ",decimalNumber);
    	      if (decimalNumber < 0)
              {
                printf("\n\n\t\tPage fault\n\n");
            printf("\n***************************************************\n");
              }else{              
              printf("%c",hexadecimalNumber[1]);
              
              printf("\n");

    int B = hexadecimalNumber[1] - '0';     //Entering the variable to copy to c2
    c2 = B + '0';                           //Typecasting int to char
    
    //printf("\tElement to replace %c with : %c\n",c1,c2);
    printf("\n\t        Changing to new hexa");
    printf("\n\t\t0x%s -----> ",s);
    
    char r[1000];
        strcpy(r,s);            //Copying 's' element to 'r' variable
    for(q=0;r[q];q++)           //Logic to replace
	{  
		if(r[q]==c1)
		{
		   r[q]=c2;
	 
	    } 
	}
    printf("0x%s\n",r);
    printf("\nBinary value of 0x%s :",r);
    int result3 = SwitchCase1(r);

    arr1[decimal] = arr2[decimal] + 1;
    printf("\n\tReference Bit : %d\n",arr1[decimal]);

    printf("\n");
    printf("\n***************************************************\n");
    }
   }
}

int SwitchCase(char hexa[1000])
{
    long int i=0;
        while (hexa[i])
        {        
            switch (hexa[i])
            {
            case '0':
                printf(" 0000 "); break;

             case '1':
                printf(" 0001 "); break;

            case '2':
                printf(" 0010 "); break;

            case '3':
                printf(" 0011 "); break;

            case '4':
                printf(" 0100 "); break;

            case '5':
                printf(" 0101 "); break;

            case '6':
                printf(" 0110 "); break;

            case '7':
                printf(" 0111 "); break;

            case '8':
                printf(" 1000 "); break;

            case '9':
                printf(" 1001 "); break;

            case 'A':
                printf(" 1010 "); break;

            case 'B':
                printf(" 1011 "); break;

            case 'C':
                printf(" 1100 "); break;

            case 'D':
                printf(" 1101 "); break;

            case 'E':
                printf(" 1110 "); break;

            case 'F':
                printf(" 1111 "); break;

            case 'a':
                printf(" 1010 "); break;

            case 'b':
                printf(" 1011 "); break;

            case 'c':
                printf(" 1100 "); break;

            case 'd':
                printf(" 1101 "); break;

            case 'e':
                printf(" 1110 "); break;

            case 'f':
                printf(" 1111 "); break;

            default:
                printf("\n Invalid hexa digit %c ", hexa[i]);
            }               
           i++;
        }
}        
int SwitchCase1(char r[1000])
{
    
    long int i=0;
        while (r[i])
        {        
            switch (r[i])
            {
            case '0':
                printf(" 0000 "); break;

             case '1':
                printf(" 0001 "); break;

            case '2':
                printf(" 0010 "); break;

            case '3':
                printf(" 0011 "); break;

            case '4':
                printf(" 0100 "); break;

            case '5':
                printf(" 0101 "); break;

            case '6':
                printf(" 0110 "); break;

            case '7':
                printf(" 0111 "); break;

            case '8':
                printf(" 1000 "); break;

            case '9':
                printf(" 1001 "); break;

            case 'A':
                printf(" 1010 "); break;

            case 'B':
                printf(" 1011 "); break;

            case 'C':
                printf(" 1100 "); break;

            case 'D':
                printf(" 1101 "); break;

            case 'E':
                printf(" 1110 "); break;

            case 'F':
                printf(" 1111 "); break;

            case 'a':
                printf(" 1010 "); break;

            case 'b':
                printf(" 1011 "); break;

            case 'c':
                printf(" 1100 "); break;

            case 'd':
                printf(" 1101 "); break;

            case 'e':
                printf(" 1110 "); break;

            case 'f':
                printf(" 1111 "); break;

            default:
                printf("\n Invalid hexa digit %c ", r[i]);
            }               
           i++;
        }
}      

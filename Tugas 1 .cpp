#include <stdio.h>
#include <string.h>
  
void welcome() {
        printf("Hasil Tugas Soal. 1 Dengan Bobot 15");
        printf("\=====Hidayatullah=====");
}
 
void cls() {
    int i;
    for (i=0;i<100;i++) {
        printf("\n");
    }
}
 
void biner(int n) {
    if (n > 0) {
        biner(n/2);
        printf("%d",n%2);
    }
}
  
int pangkat(int n,int x) {
    int nilai=1,i;
    for (i=0;i<x;i++) {
        nilai=nilai*n;
    }
    return nilai;
}
 
int cekdesimal(int x) {
    //checking
    if (x < 0)    { //no minus
        return 1;
    }
    //end of checking, all is right
    return 0;
}
 
int cekbiner(char str[],int *x) {
    int i,dec = 0;
     
    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] - '0' != 1 ) && (str[i] - '0' != 0))
        {
            return 1;
        }
    }
    //end of checking, all is right
     
    for (i =0; i <  strlen(str) ; i++)
    {
        if (str[i] - '0' == 1) {
            dec = dec + pangkat(2,strlen(str)-1-i);
        }
    }
    *x = dec;
    return 0;
}
int cekhexa(char str[],int *x) {
    int i,dec=0;
     
    //checking
    for (i = 0; i < strlen(str); i++)
    {
        if (! ( ((str[i] > 47 ) && (str[i] < 58)) || ((str[i] > 96 ) && (str[i] < 103)) || ((str[i] > 64 ) && (str[i] < 71)) ))
        {
            return 1;
        }
    }
    //end of checking, all is right
    for (i =0; i < strlen(str) ; i++)
    {
        if ((str[i] >= '0' ) && (str[i] <= '9')) {
            dec = dec + (str[i] - '0') * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > '@' ) && (str[i] < 'G')) {
            dec = dec + (str[i] - 55) * pangkat(16,strlen(str)-1-i);
        }
        else if ((str[i] > 96 ) && (str[i] < 'g')) {
            dec = dec + (str[i] - 87) * pangkat(16,strlen(str)-1-i);
        }
    }
    *x = dec;
    return 0;
}
 
int main() {
    int x,dec;
    char bin[16],hex[4];
    welcome();
    while(1) {
    printf("\n\n===============================\nBasis Angka Masukan\n1. Biner\nChoose: ");
    scanf("%d",&x);
    switch(x) {
        case 1:
                    printf("Masukan angka biner (Maksimal 16 bit): ");
                    scanf("%s",bin);
                    if(cekbiner(bin,&dec) != 0) {
                        printf("Input salah");
                        break;
                    }
                    printf("\nHexa: %X",dec);
                    break;
        default: printf("Not Present");
    } //end case
    } //end loop
    return 0;
} //end main

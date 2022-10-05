#include <stdio.h>
#include <cs50.h>

int main(void){
    long card, digit, a, b, c;

    do {
        card=get_long("Input your credit card nuber: ");
        digit=card;

        int size=0;

          do {
            card=card/10;


            size ++ ;

         }
         while (card > 0);
         int number[size];
         a=10;
         b=1;
         for (int i=0; i<size; i++){
            c=digit%a/b;
            a=a*10;
            b=b*10;
            number[i]=c;

         }

        int summEven=0;
        int summOdd=0;
        int valid;
        if (size==16||size==15){

            for(int v16=0; v16<=size; v16++){

                if (v16%2==1){
                summOdd=summOdd+((number[v16]*2%100/10)+(number[v16]*2%10));
                }
                else {
                summEven=summEven+number[v16];
                }
            }
            valid=(summEven+summOdd)%10;


            if (valid==0&&(number[15]==5&&(number[14]==1||number[14]==2||number[14]==3||number[14]==4||number[14]==5))){

                printf("MASTERCARD\n");

            }

            else if (valid==0&&number[15]==4){
                printf("VISA\n");
            }
            else if (valid==0&&(number[14]==3&&(number[13]==4||number[13]==7))){
                 printf("AMEX\n");
             }

            else{printf("INVALID\n");}}

        else if (size==13) {
            for(int v13=0; v13<=size; v13++){

                if (v13%2==1){
                summEven=summEven+((number[v13]*2%100/10)+(number[v13]*2%10));
                }
                else {
                summOdd=summOdd+number[v13];
                }
            }
            valid=(summEven+summOdd)%10;
        
            if (valid==0&&number[12]==4){
                printf("VISA\n");
            }

            else printf("INVALID\n");
            }
        else printf("INVALID\n");

    }
    while(card<0);
}
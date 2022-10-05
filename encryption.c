#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    if (strlen(key)!=26){
        printf("Key must contain 26 characters.\n");
    }
    else {
    string text=get_string("plaintext: ");
    char alphabet[26]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char encrypted[strlen(text)];
    char upper;
    char lower;
    int is_upper=1;
    for(int i=0;  i<strlen(text); i++){

        for(int j=0; j< strlen(alphabet);j++){
            if (islower(text[i])){
            upper=toupper(text[i]);
            is_upper=0;
            }
            if(text[i] == alphabet[j]||upper == alphabet[j]){
                encrypted[i]=key[j];
                break;
            }
            else if(text[i]=='.'||text[i]==','||text[i]=='\''||text[i]=='-'||text[i]==' '){
                encrypted[i]=text[i];
                break;
            }
        }
        for (int k=0;k<strlen(text);k++){
            if(islower(text[k])){
                encrypted[k]=tolower(encrypted[k]);
            }
        }
    }
    printf("ciphertext: %.*s\n", (int)sizeof(encrypted), encrypted);
    }
}
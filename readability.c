#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int letter (string text, int chars);
int word (string text, int chars);
int sentence (string text, int chars);
int main(void)
{
    string text=get_string("Text: ");
    int chars=strlen(text);

    float letters=letter(text, chars);

    float words=word(text, chars);

    float sentences= sentence(text,chars);

    float l = letters/words*100;
    float s = sentences/words*100;
    int index = round(0.0588*l-0.296*s-15.8);


    if (index<1){
        printf("Before Grade 1\n");

    }
    else if (index>16){
        printf("Grade 16+\n");
    }
    else {
    printf("Grade %i\n", index);}
}
int letter (string text, int chars){
    int letters=0;
    for(int i=0;i<=chars; i++){
        if(isalpha(text[i])&& text[i]!=' '&&text[i]!='\''&&text[i]!='.'&&text[i]!='-'&&text[i]!=','){
            letters ++;
        }
    }
    return letters;
}

int word (string text, int chars){
    int words=0;
    for(int i=0; i<=chars; i++){
        if (isspace(text[i])||text[i]=='\0'){
            words++;
        }
    }
    return words;
}

int sentence (string text, int chars){
    int sentences=0;

    for(int i=0; i<chars; i++){
        if (text[i]=='.'||text[i]=='!'||text[i]=='?'){
            sentences ++;
        }
    }
    return sentences;
}

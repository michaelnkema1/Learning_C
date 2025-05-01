#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char secret_word[10] = "code";
    char guess_word[10] = "guess";
    char name[10];
    int attempts = 0;
    printf("\nEnter your name: ");
    scanf("%s", &name);
    
    do
    {
        printf("\n Guess the word: ");
        scanf("%s", guess_word);
        attempts++;

    } while((strcmp(guess_word, secret_word)) != 0);

    printf("\n Congrats, %s! You guessed it in %d attempts", name, attempts);

    FILE *fp = fopen("game_log.txt", 'r');

    fprintf(fp, "Player: %s | Word: %s| Attempts: %d", name, secret_word, attempts);
    fclose(fp);



}
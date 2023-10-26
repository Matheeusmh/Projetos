#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char check(char senha[], int count);

int main(void)
{
    char *senha = NULL;
    int num_elementos;
    char c;
    printf("Digite uma senha(quando acabar pressione ENTER): ");

    do {
        c = getchar();
        senha = realloc(senha, num_elementos + 1);
        senha[num_elementos] = c;
        num_elementos++;
    }while(c != '\n');

    senha[num_elementos] = '\n';

    if (check(senha, num_elementos))
    {
        printf("\n A senha eh valida!!\n");
    }
    else
    {
        printf("\n A senha eh invalida!!\n");
        printf(" A senha precisa de letras(maiusculas e minusculas), simbolos e numeros!!\n");
    }

    return 0;
}

char check(char senha[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (isupper(senha[i]))
        {
            for(int i = 0; i < count; i++)
            {
                if (islower(senha[i]))
                {
                    for (int i = 0; i < count; i++)
                    {
                        if (isdigit(senha[i]))
                        {
                            for (int i = 0; i < count; i++)
                            {
                                if (ispunct(senha[i]))
                                {
                                    for (int i = 0; i < count; i++)
                                    {
                                        if (isalpha(senha[i]))
                                        {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

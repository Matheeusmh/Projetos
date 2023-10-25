#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char check(char senha[], int count);

int main(void)
{
    char *senha;
    int num_elementos;

    do 
    {
    printf("Digite o tamanho da senha que deseja: ");
    scanf("%d", &num_elementos);
    num_elementos += 1;
    senha = (int *)(malloc(sizeof(char) * num_elementos));
    free(senha);
    } while (senha == NULL);
    
    fflush(stdin);
    printf("Digite uma senha: ");
    fgets(senha, num_elementos, stdin);

    if (check(senha, num_elementos))
    {
        printf("A senha eh valida!!\n");
    }
    else
    {
        printf("A senha eh invalida!!\n");
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

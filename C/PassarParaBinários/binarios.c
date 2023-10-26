#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binarios(char frase[], int tamanho)
{
    int digito = 0;

    for (int i = 0; i < tamanho - 1; i++)
    {
        digito = (int)(frase[i]);
        
        for(int j = 7; j  >= 0; j--)
        {
            if (digito >= (pow(2, j)))
            {
                printf("1");
                digito -= (pow(2, j));  
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    char *frase = NULL, c;
    int tamanho;

    printf("Digite uma frase(quando acabar pressione ENTER): ");
    
    do {
        c = getchar();
        frase = realloc(frase, tamanho + 1);
        frase[tamanho] = c;
        tamanho++;
    } while (c != '\n');

    frase[tamanho] = '\0';
    binarios(frase, tamanho);

    free(frase);

    return 0;
}

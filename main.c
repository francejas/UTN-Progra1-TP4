#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int selected;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:

            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}
int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Agrega elementos a Pila");

    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}


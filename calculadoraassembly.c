/*Calculadora ASM
Faculdade Anhanguera
Aluno: Matheus Guedes  RA: 1800586981   2�Semestre

*/
#include <stdio.h>
#include <locale.h>

int soma();
int sub();
int mult();
float div();

int num1, num2, r;

int main(void)
{
    int op, opc;
    setlocale(LC_ALL, "");

    do{
        system("cls");
        printf("\tCALCULADORA ASM\n\n");
        printf("[1]SOMA\t\t\t[2]SUBTRA��O\n[3]MULTIPLICA��O\t[4]DIVIS�O\n[5]SAIR\n\n");
        scanf(" %d", &opc);

        switch(opc)
        {
                case 1:
                        system("cls");
                        printf("SOMA ASM\n\n");
                        printf("Digite o primeiro valor: ");
                        scanf(" %d", &num1);
                        printf("Digite o segundo valor: ");
                        scanf(" %d", &num2);
                        printf("Resultado = %d",soma());
                break;
                case 2:
                        system("cls");
                        printf("SUBTRA��O ASM\n\n");
                        printf("Digite o primeiro valor: ");
                        scanf(" %d", &num1);
                        printf("Digite o segundo valor: ");
                        scanf(" %d", &num2);
                        printf("Resultado = %d",sub());
                break;
                case 3:
                        system("cls");
                        printf("MULTIPLICA��O ASM\n\n");
                        printf("Digite o primeiro valor: ");
                        scanf(" %d", &num1);
                        printf("Digite o segundo valor: ");
                        scanf(" %d", &num2);
                        printf("Resultado = %d",mult());
                break;
                case 4:
                        system("cls");
                        printf("DIVIS�O ASM\n\n");
                        printf("Digite o primeiro valor: ");
                        scanf(" %d", &num1);
                        printf("Digite o segundo valor: ");
                        scanf(" %d", &num2);
                        printf("Resultado = %.1f",div());
                break;
                default :
                        main();
        }
        printf("\n\nVoltar ao menu digite [1]\nSair digite [2]");
        scanf(" %d", &op);
    }while(op==1);
    return 0;
}

int soma(void)
{
    __asm("movl _num1, %ebx ") ;    // Mover o que est� na variavel x para o registrador b
    __asm("movl _num2, %eax") ;     // Mover o que est� na variavel y para o registrador a
    __asm("addl %ebx,%eax");        // Somar o que est� na registrador b no a
    __asm("movl %eax, _r") ;        // Mover o que est� no registrador a para a variavel r
    return r;                       // retornar o q est� na variavel r
}

int sub(void)
{
    __asm("movl _num1, %ebx ") ;    // Mover o que est� na variavel x para o registrador b
    __asm("movl _num2, %eax") ;     // Mover o que est� na variavel y para o registrador a
    __asm("sub %eax,%ebx");         // Subtrair o que est� na registrador a no b
    __asm("movl %ebx, _r") ;        // Mover o que est� no registrador b para a variavel r
    return r;                       // retornar o q est� na variavel r
}

int mult(void)
{
    __asm("movl _num1, %ebx ") ;    // Mover o que est� na variavel x para o registrador b
    __asm("movl _num2, %eax") ;     // Mover o que est� na variavel y para o registrador a
    __asm("imull %ebx,%eax");       // Multiplica o registrador bx com o ax e armazena em ax
    __asm("movl %eax, _r") ;        // Mover o que est� no registrador a para a variavel r
    return r;                       // retornar o q est� na variavel r
}

float div(void)
{
    __asm("movl _num1, %eax ") ;    // Mover o que est� na variavel x para o registrador b
    __asm("movl _num2, %ebx") ;     // Mover o que est� na variavel y para o registrador a
    __asm("idivl %ebx");
    __asm("movl %eax, _r") ;        // Mover o que est� no registrador a para a variavel r
    return r;                       // retornar o q est� na variavel r
}

// Pagina inicial do programa

// ./bin/index

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pacientes.c"
#include "funcionarios.c"

int menu () {
  int op;

  printf ("Voce gostaria de realizar uma operacao para quem? \n\n");

  do {
    printf ("1 - Pacientes \n");
    printf ("2 - Funcionarios \n");

    printf ("Escolha uma das opcoes acima: ");
    scanf ("%d", &op);

    if (op < 1 || op > 2) {
      printf ("Opcao invalida.... :/ \n");
      printf ("Escolha novamente uma opcao..... \n\n");
    }

  } while (op < 1 || op > 2);

  return op;
}

//=======================================================================================================

int redirecionamento (int op) {
  int opcaoEscolhida = 0;

  switch (op) {
    case 1:
      opcaoEscolhida = pacientes();
      break;
    case 2:
      opcaoEscolhida = funcionarios();
      break;
  }

  return opcaoEscolhida;
}

//=======================================================================================================

int main () {
  int op;
  int opcaoEscolhida, pacientes, funcionarios;

  system ("clear || cls");

  printf ("*********** - Sejam bem vindos(as) a rede de clinicas First Care Medical - ***********\n\n");

  op = menu ();

  opcaoEscolhida = redirecionamento (op);

  return 0;
}

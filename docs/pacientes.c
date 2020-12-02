#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "necessidadesPaciente.c"

int cadastroP () {
  FILE *arq_cadastro_p;

  system ("clear || cls");

  printf ("*********** - Sejam bem vindo(a) ao cadastro de pacientes da clinica First Care Medical - ***********\n\n");

  char nome[100], cpf[15], rg[14], nascimento[12];
  // limpar o buffer do teclado (poder usar o gets)
  fflush (stdin);

  printf ("Nome completo do paciente: ");
  gets (nome);

  printf ("CPF: ");
  gets (cpf);

  printf ("RG: ");
  gets (rg);

  printf ("Data de nascimento: ");
  gets (nascimento);

  //arquivo cadastroPacientes APPEND a+
  if((arq_cadastro_p = fopen("./archives/cadastroPacientes.txt", "a+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** Salvando os dados ***\n");

    fprintf (arq_cadastro_p, "{\n");
    fprintf (arq_cadastro_p, "  Nome: %s \n", nome);
    fprintf (arq_cadastro_p, "  CPF: %s \n", cpf);
    fprintf (arq_cadastro_p, "  RG: %s \n", rg);
    fprintf (arq_cadastro_p, "  Data de nascimento: %s \n", nascimento);
    fprintf (arq_cadastro_p, "}\n\n");

    printf ("Cadastro do(a) paciente %s realizado com sucesso!!! :D \n\n", nome);
  
    fclose(arq_cadastro_p);
  }

  return 0;
}

//=======================================================================================================

int verificarNecessidadeP () {
  printf ("\nQual a necessidade do paciente?? \n\n");

  int op;

  do {
    printf ("1 - marcar ou desmarcar uma consulta \n");
    printf ("2 - fazer reclamacoes e/ou elogios \n");

    printf ("Escolha uma das opcoes acima: ");
    scanf ("%d", &op);

    if (op < 1 || op > 2) {
      printf ("Opcao invalida... :/ \n");
      printf ("Escolha uma opcao novamente... \n\n");
    }

  } while (op < 1 || op > 2);

  necessidadesPacientes (op);

  return op;
}

// essa é a função main
int pacientes (void) {
  char temCadastro;

  system ("clear || cls");

  printf ("O paciente ja tem cadastro? (Digite S ou N) ");
  scanf (" %c", &temCadastro);

  if (temCadastro == 'N') {
    cadastroP();
    verificarNecessidadeP();
  } else if (temCadastro == 'S') {
    verificarNecessidadeP();
  } else {
    printf ("opcao invalida...");
  }

  return 0;
} 
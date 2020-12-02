#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "relatorios.c"

int cadastroF () {
  FILE *arq_cadastro_f;

  system ("clear || cls");

  printf ("*********** - Sejam bem vindo(a) ao cadastro de funcionarios da clinica First Care Medical - ***********\n\n");

  char nome[100], cpf[15], rg[14], nascimento[12], pis[12], cargo[30];
  fflush (stdin);

  printf ("Nome completo do funcionario: ");
  gets (nome);

  printf ("CPF: ");
  gets (cpf);

  printf ("RG: ");
  gets (rg);

  printf ("Data de nascimento: ");
  gets (nascimento);

  printf ("Numero do PIS: ");
  gets (pis);

  printf ("Cargo exercico na empresa: ");
  gets (cargo);

  // arquivo cadastroFuncionarios  APPEND a+  (leitura/escrita. os dados serão add no fim do arquivo)
  if ((arq_cadastro_f = fopen("./archives/cadastroFuncionarios.txt", "a+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** Salvando os dados ***\n");

    fprintf (arq_cadastro_f, "{\n");
    fprintf (arq_cadastro_f, "  Nome: %s \n", nome);
    fprintf (arq_cadastro_f, "  RG: %s \n", rg);
    fprintf (arq_cadastro_f, "  CPF: %s \n", cpf);
    fprintf (arq_cadastro_f, "  Data de nascimento: %s \n", nascimento);
    fprintf (arq_cadastro_f, "  PIS: %s \n", pis);
    fprintf (arq_cadastro_f, "  Cargo: %s\n", cargo);
    fprintf (arq_cadastro_f, "}\n\n");

    printf ("Cadastro do(a) %s %s realizado com sucesso!!! :D \n\n", cargo, nome);

    fclose(arq_cadastro_f);
  }

  return 0;
}

//=======================================================================================================

int verificarNecessidadeF () {
  int Op;
  char relatorio;

  printf ("\nO funcionario deseja fazer um relatorio?? (Digite S ou N) ");
  scanf (" %c", &relatorio);

  if (relatorio == 'S') {
    do {
      printf ("\n1 - Relatorio de pacientes atendidos por unidade \n");
      printf ("2 - Relatorio da unidade que mais atendeu \n");
      printf ("3 - Relatorio da totalizacao diaria do faturamento por unidade \n");
      printf ("4 - Relatorio da totalizacao mensal do faturamento por unidade \n");
      printf ("5 - Relatorio da totalizacao diaria do faturamento da rede \n");
      printf ("6 - Relatorio da totalizacao mensal do faturamento da rede \n");
      printf ("7 - Relatorio do total de pacientes que cancelaram / remarcaram a consulta \n");
      printf ("8 - Relatorio do total de pacientes que faltaram na consulta \n");

      printf ("\nEscolha uma das opcoes de relatorios acima: ");
      scanf ("%d", &Op);

      if (Op < 1 || Op > 8) {
        printf ("Opcao invalida... :/ \n");
        printf ("Escolha uma opcao novamente... \n\n");
      }

    } while (Op < 1 || Op > 8);

    relatorios (Op);

  } else {
    printf ("\nPrograma finalizado com sucesso!! :D \n");
  }

  return Op;
}

//main
int funcionarios () {
  char temCadastro, atualizarCadastro;
  system ("clear || cls");

  printf ("O funcionario ja tem cadastro? (Digite S ou N) ");
  scanf (" %c", &temCadastro);

  if (temCadastro == 'N') {
    cadastroF();
    verificarNecessidadeF();

  } else if (temCadastro == 'S') {
    verificarNecessidadeF();
  } else {
    printf ("opcao invalida...");
  }

  return 0;
}
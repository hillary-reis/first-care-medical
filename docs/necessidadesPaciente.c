#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int consultas () {
  FILE *arq_consultas;
  char texto, nome[100], cpf[15], dia[6], horario[6], cargo[30];
  
  if ((arq_consultas = fopen("./archives/consultas.txt", "a+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    system ("clear || cls");

    printf ("*** - Marque suas consultas aqui!! - *** \n\n");
    printf ("PARA EFETUAR O CANCELAMENTO, ENTRE DIRETO NO ARQUIVO consultas.txt E MUDE A OPCAO consulta cancelada: NAO PARA SIM E O MOTIVO \n\n");

    fflush (stdin);

    printf ("Informe seu nome e cpf. \n");

    printf ("Nome: ");
    gets (nome);
    fflush (stdin);
    printf ("CPF: ");
    scanf ("%s", cpf);

    printf ("Informe o dia e horario da consulta: ");
    scanf ("%s %s", dia, horario);

    fflush (stdin);

    printf ("Com qual profisisonal deseja passar? ");
    gets (cargo);

    fprintf (arq_consultas, "{\n");
    fprintf (arq_consultas, "  Nome: %s \n", nome);
    fprintf (arq_consultas, "  CPF: %s \n", cpf);
    fprintf (arq_consultas, "  Dia e Horario: %s as %s \n", dia, horario);
    fprintf (arq_consultas, "  Profissional: %s \n", cargo);
    fprintf (arq_consultas, "  Consulta cancelada: NÃO \n");
    fprintf (arq_consultas, "}\n\n");

    printf ("\n%s, sua consulta sera no dia %s as %s; com o(a) %s.", nome, dia, horario, cargo);

    fclose(arq_consultas);
  }

  return 0;
}

//=======================================================================================================

int reclamacoesElogios () {
  FILE *arq_reclamacoes_elogios;
  char *texto;
  int n = 4096; // máximo de caracters aceito 
  
  if ((arq_reclamacoes_elogios = fopen("./archives/reclamacoesElogios.txt", "a+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    system ("clear || cls");
    
    printf ("*** - Faca aqui sua reclamacao ou elogio!! - ***\n\n");

    fflush (stdin);

    printf ("Digite abaixo sua reclamacao e/ou elogio informando setor a ser comentado (como atendimento, limpeza...) \n ");
    scanf("%d", &n);

    texto = (char *) malloc (n * sizeof(char)); // malloc() da biblioteca stdlib.h armazena o quanto de memória necessária
    scanf ("%[^\n]", texto);

    fprintf (arq_reclamacoes_elogios, "{\n");
    fprintf (arq_reclamacoes_elogios, "  Reclamacao e/ou elogio: %s \n", texto);
    fprintf (arq_reclamacoes_elogios, "}\n\n");

    printf ("\nSua reclamacao e/ou elogio foi salvo com sucesso!!! Volte sempre :D");

    fclose(arq_reclamacoes_elogios);
  }
  
  return 0;
}

// essa é a main
void necessidadesPacientes (op) {
  switch (op) {
    case 1:
      consultas ();
      break;
    case 2:
      reclamacoesElogios ();
      break;
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pacientesAtendidos () {
  FILE *arq_pacientes_atendidos;
  
  if ((arq_pacientes_atendidos = fopen("./archives/reports/pacientesAtendidos.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo pacientesAtendidos.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_pacientes_atendidos);
  }

  return 0;
}

int unidadeMaiorAtendimento () {
  FILE *arq_unidade_maior_atendimento;
  
  if ((arq_unidade_maior_atendimento = fopen("./archives/reports/unidadeMaiorAtendimento.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo unidadeMaiorAtendimento.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_unidade_maior_atendimento);
  }
  
  return 0;
}

int faturamentoDiarioUnidade () {
  FILE *arq_faturamento_diario_unidade;
  
  if ((arq_faturamento_diario_unidade = fopen("./archives/reports/faturamentoDiarioUnidade.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo faturamentoDiarioUnidade.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_faturamento_diario_unidade);
  }

  return 0;
}

int faturamentoMensalUnidade () {
  FILE *arq_faturamento_mensal_unidade;
  
  if ((arq_faturamento_mensal_unidade = fopen("./archives/reports/faturamentoMensalUnidade.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo faturamentoMensalUnidade.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_faturamento_mensal_unidade);
  }
  
  return 0;
}

int faturamentoDiarioRede () {
  FILE *arq_faturamento_diario_rede;
  
  if ((arq_faturamento_diario_rede = fopen("./archives/reports/faturamentoDiarioRede.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo faturamentoDiarioRede.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_faturamento_diario_rede);
  }
  
  return 0;
}

int faturamentoMensalRede () {
  FILE *arq_faturamento_mensal_rede;
  
  if ((arq_faturamento_mensal_rede = fopen("./archives/reports/faturamentoMensalRede.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo faturamentoMensalRede.txt dentro da pasta reports. - ***\n\n");

    fclose(arq_faturamento_mensal_rede);
  }
  
  return 0;
}

int canceladosRemarcados () {
  FILE *arq_cancelados_remarcados;
  
  if ((arq_cancelados_remarcados = fopen("./archives/reports/canceladosRemarcados.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo canceladosRemarcados.txt dentro da pasta reports. - ***\n\n");

    fclose (arq_cancelados_remarcados);
  }
  
  return 0;
}

int faltas () {
  FILE *arq_pacientes_faltas;
  
  if ((arq_pacientes_faltas = fopen("./archives/reports/pacientesFaltas.txt", "r+")) == NULL) {
    printf ("Erro na abertura do arquivo!... \n");
    return 1;

  } else {
    printf ("\n*** - Abra o arquivo pacientesFaltas.txt dentro da pasta reports. - ***\n\n");

    fclose (arq_pacientes_faltas);
  }
  
  return 0;
}

// essa é a main
void relatorios (Op) {
  switch (Op) {
    case 1:
      pacientesAtendidos ();
      break;
    case 2:
      unidadeMaiorAtendimento ();
      break;
    case 3:
      faturamentoDiarioUnidade ();
      break;
    case 4:
      faturamentoMensalUnidade ();
      break;
    case 5:
      faturamentoDiarioRede ();
      break;
    case 6:
      faturamentoMensalRede ();
      break;
    case 7:
      canceladosRemarcados ();
      break;
    case 8:
      faltas ();
      break;
  }
}
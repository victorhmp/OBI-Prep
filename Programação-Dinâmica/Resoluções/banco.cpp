// O Banco Inteligente - F1P2 - OBI 2015
// Rogério Júnior
// Complexidade: O(s*n)

// Obs* n é a quantidade média cédulas de cada tipo

#include <cstdio>
#include <cstring>

typedef long long int lli;

#define MAXS 5500
#define MAXN 10

// variáveis globais utilizadas
int s, notas[MAXN], valor[MAXN] = {0, 2, 5, 10, 20, 50, 100, 0, 0, 0};

// tabela de DP
lli tab[MAXS][MAXN];

// função recursiva da DP Top-Down, que recebe, como parâmetros
// o valor a ser alcançado e o tipo de nota que estamos olhando
lli dp(int resta, int tipo = 1) {
  // se o valor desejado é zero, existe uma maneira de conseguí-lo:
  // não usar nota nenhum. Retorno 1
  if (!resta) return 1LL;

  // se passarmos do tipo permitido de nota ou procurarmos valor negativo
  // então não é possível alcançarmos tal valor desejado
  if (tipo > 6 or resta < 0) return 0LL;

  // se o atual estado da DP já foi calculado antes
  // retorno o que tenho salvo na tabela de DP
  if (tab[resta][tipo] >= 0) return tab[resta][tipo];

  // se afunção não retornou, preciso chamar a recursão para calculá-la

  // declaro a "lli total" que começará com zero
  // e será o número de maneiras que está sendo procurado
  lli total = 0LL;

  // para cada uma das possíveis quantidades de cédulas do tipo que estou
  // olhando
  for (int i = 0; i <= notas[tipo]; i++) {
    // se o valor dessas cédulas ultrapassar o que resta, paro o loop
    if (resta < i * valor[tipo]) break;

    // caso contrário, adiciono ao total o número de maneiras de atingir
    // o valor que falta, usando somente as cédulas que faltam
    total += dp(resta - i * valor[tipo], tipo + 1);
  }

  // depois retorno o valor de total, e o salvo na tabela de DP
  return tab[resta][tipo] = total;
}

int main() {
  // leio o valor desejado
  scanf("%d", &s);

  // leio as quantidades de cada cédula
  for (int i = 1; i < 7; i++) scanf("%d", &notas[i]);

  // faço todas as posições da tabela de DP começarem com valor -1
  memset(tab, -1, sizeof(tab));

  // e imprimo a quantidade de maneiras calculado pela função recursiva
  // para juntar valor "s" olhando as cédulas a partir da primeira
  printf("%lld\n", dp(s));  // obs* note que chamo a dp(s, 1)

  return 0;
}
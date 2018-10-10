# Subsequência crescente máxima - LIS (Longest Increasing Subsequence)

Vamos estudar mais um problema clássico de Programação Dinâmica:

```
Dado um vetor A[1...N] de inteiros, encontre o tamanho da mais longa subsequência desse vetor tal que todos os elementos
dessa subsequência estão em ordem ESTRITAMENTE CRESCENTE.
```

Como exemplo: se tivermos o vetor `[15, 27, 14, 38, 26, 55, 46, 65, 85]`, a resposta seria `6`, pois podemos ter a subsequência `[15, 27, 38, 55, 65, 85]`.

Esse problema é interessante porque vamos encontrar 3 diferentes abordagens, sendo que para a última solução, a mais eficiente, vamos mudar um pouco a solução recursiva que vamos encontrar agora.

## Solução 1

Essa primeira solução utiliza força-bruta. Vamos pensar em como construir uma subsequência estritamente crescente em primeiro lugar. Podemos pensar em construí-la elemento por elemento, indo da esquerda para a direita mantendo a ordem crescente. Em cada passo basta selecionar um elemento à direita do elemento anterior tal que este seja maior que o anterior.
Pensando assim, nossa escolha para o próximo elemento da subsequência só é influênciada pelo último elemento selecionado até o momento, o que nos faz considerar uma solução usando força-bruta.

Seja `f[i] = LIS com término no i-ésimo elemento`, dessa forma a solução seria tão simples quanto `max{ f[0], f[1], ..., f[n-1] }`. Agora já podemos definir uma fórmula recursiva para encontrar `f[i]`:

```
f[i] = 1,                  se A[j] >= A[i], para todo 0 <= j < i 
f[i] = max { f[j] + 1 },   se A[j] < A[i]
    0 <= j < i
```

Essa recursão é facilmente implementada com C++:

```c++
int f(int i, int n, int a[]) {
  int resp = 1;
  for (int j = 0; j < i; j++) {
    if (a[j] < a[i]) {
      resp = max(resp, f(j, n, a) + 1);
    }
  }

  return resp;
}

int solve(int a[], int n) {
  int resp = 0;

  for (int i = 0; i < n; i++) {
    resp = max(resp, f(i, n, a));
  }

  return resp;
}
```

Essa solução está correta, mas quando analisamos seu consumo de tempo chegamos em `O(n*2^n)` no pior caso, muuuito lento.

## Solução 2

Agora vamos melhorar esse consumo de tempo com o uso de Programação Dinâmica. Basta notar que sempre vamos precisar de `f[j]` para calcular `f[i]`, sendo `j < i`, então podemos preencher uma tabela calculando sequêncialmente os valores de `i`:

```C++
int dp[MAXN];

int f(int n, int a[]) {
  for (int i = 0; i < n; i++) {
    int resp = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        resp = max(resp, dp[j] + 1);
      }
    }
    dp[i] = resp;
  }

  int final_resp = 0;
  for (int i = 0; i < n; i++) {
    final_resp = max(final_resp, dp[i]);
  }

  return final_resp;
}
```

Agora conseguimos um solução com consumo de tempo `O(n^2)`.

## Solução 3

Para conseguirmos uma solução ainda mais rápida para o problema, vamos ter q mudar nossa abordagem para a PD.

Primeiro, vamos pensar em distribuir os elementos do vetor `A[1...N]` em pilhas ordenadas da esquerda pela direita de acordo com o elemento no topo de cada uma.

Vamos imaginar que estamos percorrendo o vetor de entrada sequêncialmente, da esquerda para a direita. Para o i-ésimo elemento, temos uma escolha a ser feita:

- Colocamos esse elemento no topo de uma pilha e ele for _menor_ do que o elemento atual no topo de tal pilha;
- Ou criamos uma nova pilha mais à direita de todas as outras, com o i-ésimo número sozinho.

Se conseguirmos distribuir todos os elementos de `A[1...N]` no menor número possível de pilhas, o número de pilhas será a resposta! Usando apenas essa decisão entre criar uma nova pilha ou adicionar um elemento à pilha mais à esquerda, estamos garantindo que, dentro de cada pilha os números vão estar em ordem não crescente, ou seja, não poderia usar mais de um número da mesma pilha na resposta final. E como os topos das pilhas estão naturalmente ordenados, eles formam uma subsequência de `A[1...N]` estritamente crescente (mágica)!

Agora, sem o formalismo matemático apresentado antes, podemos simplesmente implementar esse algoritmo pensando em usar uma tabela de PD que irá guardar o topo de cada pilha (que será atualizada a cada passo) e a técnica de busca binária para encontrarmos a pilha onde devemos colocar cada elemento (ou não encontrar e criar uma pilha nova):

```C++
int lis(vector<int> &v) {
	
	vector<int> pd;
	
	for(int i = 0; i < v.size(); i++){
		
    // lower_bound() é uma função que retorna o endereço do primeiro elemento
    // do vector maior ou igual a v[i], nesse caso no pilha mais à esquerda.
		auto it = lower_bound(pd.begin(), pd.end(), v[i]);
		
    // Se lower_bound() não encontra nenhum elemento, retorna o último endereço
    // do vector.
		if(it == pd.end()) pd.PB(v[i]);
		
		// Colocar o elemento no topo da pilha mais à esquerda
		else *it = v[i];
	}
	
	return pd.size();
}
```

A análise para o tempo de consumo desse algoritmo fica fácil: `O( n * lg(n) )`.
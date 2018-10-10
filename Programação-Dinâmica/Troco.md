# Problema do Troco (Coin Change Problem)

O problema do troco é um problema clássico de Programação Dinâmica em que não precisamos de nenhuma estrutura de dados complexa ou mesmo um algoritmo específico para resolver, basta uma boa ideia recursiva.

## Primeira forma

Esse problema aparece de pelo menos três maneiras mais comuns, vamos abordar primeiro a mais simples:

```
Dado o conjunto de valores de n moedas de um país
e um dado valor V, decidir se é possível atingir o valor exato V usando essas moedas.
```

### Solução

Problemas desse tipo, em que sabemos que vamos usar PD, podem ser definidos de maneira recursiva pensando na técnica da divisão-e-conquista. Vamos pensar em subproblemas que que podem ser unidos para compor a resposta final do nosso problema maior.

Olhando para uma variável `v` que representa o `valor restante` à ser atingido com um conjunto de moedas e 
`c[i] = valor da i-ésima moeda`. Definindo `r[i] = possível atingir o valor v com a i-ésima moeda`.

Os casos base saem naturalmente: 

- Se `v = 0`, então a resposta é `true`, pois não precisamos de nenhuma moeda para chegar à esse valor;
- Se `v < 0`, então a resposta é `false`, pois não temos como chegar em valores negativos somando apenas números naturais;

Restringindo `v > 0`:

- `r[i] = true` se `r[v - c[i]] = true`;
- `r[i] = false` se `r[v - c[i]] = false`.

O que pode ser simplificado para simplesmente: ` r[i] = r[v - c[i]] `.


Essa recursão deve ser interpretada como: "eu consigo usar a moeda `i` para formar o valor `v` se, e somente se, eu conseguir formar, com as moedas, o valor `v − c[i]`, pois usaríamos a combinação de moedas que forma este valor, mais a moeda `i`, para conseguirmos o valor `v`".

Podemos agora escrever essa solução usando a técnica de PD para guardar os valores de `r[]`:

```C++
int r[MAX];

// c.size() = n -> # de moedas diferentes

int solve(int v, vector<int> &c){
	
  if(v == 0) return 1;
	
  if(v < 0) return 0;
	
  if(r[x] >= 0) return r[x];
	
  for(int i = 0; i < c.size(); i++){
    if( solve(x - c[i]) )
      return dp[x - c[i]] = 1;
  }
	
  return dp[x]=0;
}
```

É fácil verificar que o consumo de tempo desse algoritmo é `O(n * v)`.

## Segunda forma

Outra maneira comum de se encontrar o problema do troco é o seguinte:

```
Dados um conjunto de moedas infinito, com valores restritos à um conjunto de N valores distintos (vetor c[1...N]) e um valor a ser atingido V, determine o número de maneiras distintas em que podemos atingir esse valor usando moedas com os valores dados.
```

### Solução

Como sempre, o primeiro passo é pensar em como aplicar a divisão-e-conquista no problema, definindo quais são os possíveis subproblemas.

Vamos definir: 

```
solve[i, left] = # de maneiras de se obter o valor left usando moedas de valores                    em [i...N]
```

Podemos fazer um paralelo com o problema da mochila em que, para cada item disponível, tinhamos que "fazer uma escolha" entre incluir ou não esse item na mochila ótima. Não vamos ter que tomar uma decisão dessa forma nessa solução, mas vamos ter que considerar dois casos análogos aos presentes no problema da mochila:

```
solve[i, 0] = 1
solve[i, left] = (solve[i, left - c[i]]) + (solve[i + 1, left])
```

O caso base no diz que se o valor restante `left` for 0, então só há uma maneira de atingi-lo, usando nenhuma moeda. Na segunda linha, o primeiro termo da soma representa "colocar a i-ésima moeda na solução para chegar no valor `left`". Já o segundo representa "ignorar a i-ésima moeda" e ir para a próxima.

Usando PD, podemos escrever uma solução eficiente usando C++:

```C++
int N;
int c[52];

long long resp[52][252];

long long solve(int i, int falta) {
    if(falta < 0) return 0;

    if(falta == 0) return 1;

    if(i > N) return 0;

    if (resp[i][falta] == -1) {
      resp[i][falta] = solve(i, falta - c[i]) + solve(i+1, falta);
    }

    return resp[i][falta];
}
```

O consumo de tempo desse algoritmo é exatamente o mesmo do algoritmo anterior: `O(N * V)`.

## Terceira forma

Por último, uma variação da segunda forma:

```
Dados um conjunto de moedas infinito, com valores restritos à um conjunto de N valores distintos (vetor c[1...N]) e um valor a ser atingido V, determine o número mínimo de moedas necessárias para obter V.
```

### Solução

A recursão que resolve esse problema também é similar ao algoritmo anterior, mas agora temos que pensar em otimização. No caso desse problema, otimizar significa minimizar o número de moedas que vamos utilizar.

O caso base vem naturalmente:


- Se `V = 0`, então a resposta é 0, ou seja, nenhuma moeda.
- Se `V < 0`, então a resposta é 0, porque não podemos chegar em um valor negativo.

Agora vamos considerar os casos em que `V > 0`, sendo `solve[Y] = # mínimo de moedas necessárias para obter Y`:

```
solve[Y] = min { 1 + solve(Y - c[i]) } 
       0 <= i <= N-1 
       c[i] <= Y 
```

Com C++ podemos escrever as duas versões da solução para esse problema. Primeiro a recursiva:

```c++
int solve(int coins[], int n, int V) {  
   if (V == 0) return 0; 
   int res = INT_MAX; 
  
   for (int i = 0; i < n; i++) { 
     if (c[i] <= V) {
         int sub_res = solve(coins, m, V-coins[i]); 
         if (sub_res + 1 < res)
            res = sub_res + 1; 
     }
   } 
   return res; 
} 
```

Analisando o consumo de tempo desse código, chegamos em `O(2^n)`. Vamos utilizar PD para melhorar essa complexidade:

```c++
int minCoins(int coins[], int m, int V) { 
  int dp[V+1];
  dp[0] = 0; 
   
  for (int i = 1; i <= V; i++) 
    dp[i] = INT_MAX;
  
  for (int i = 1; i <= V; i++) {  
    for (int j = 0; j < m; j++){
      if (coins[j] <= i) { 
        int sub_res = dp[i-coins[j]]; 
        if (sub_res + 1 < dp[i]) 
          dp[i] = sub_res + 1; 
      }
    }
  } 
  return dp[V]; 
} 
```

Agora conseguimos o mesmo consumo de tempo das duas soluções anteriores para as outras duas variações do problema do troco: `O(N * V)`.
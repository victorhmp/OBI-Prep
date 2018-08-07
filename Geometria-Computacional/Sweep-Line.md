# Sweep-Line - Introdução

Vamos imaginar um problema de geometrica computacional:

```
Dados n seguimentos de reta, encontrar as interseções entre as retas.

Obs: asummir pontos 2D.
```

Esse problema irá servir de motivação para introduzir o algoritmo `Sweep-Line`.

## Abordagem intuitiva (naive)

Uma solução intuitiva, ou ingênua que resolve o problema é checar, para cada par de retas se há interseção ou não. Isso seria facilmente implementado resultando em um algoritmo de complexidade O(n^2).

## Algoritmo Sweep-Line

É possível resolver esse problema em tempo _O(n\*lg(n))_ usando um novo algoritmo, chamado de Sweep-Line. Esse algoritmo primeiro ordena todos os pontos de extremidades direitas ("pontos finais") de cada segmento de acordo com o eixo _x_ da esquerda para a direita e depois "varre" com uma linha vertical por todos os pontos da esquerda para direita checando por interseções. Mais detalhadamente:

1 - Sejam dadas _n_ linhas. Existem pelo menos _2n_ pontos que representam todas as linhas. Ordene todos os pontos de acordo com o eixo x. Enquanto ordena, mantenha uma flag que representa se o ponto a ser analizado é o ponto da extremidade esquerda ou direita da linha que ele representa.

2 - Comece pelo ponto mais a esquerda:

- Se o ponto analizado é um ponto "de esquerda", verifique se há interseção com o segmento diretamente acima e com o segmento diretamente abaixo do atual. E adicione a linha atual às "linhas ativas" (já vimos o ponto esquedo mas não o direito). Note que consideramos apenas os vizinhos que ainda estão ativos.

- Se o ponto analizado é um ponto "de direita", removo sua linha das "linhas ativas" e verifico se há interseção entre os seus vizinhos diretos.

Essa segunda etapa simula a verredura de uma linha vertical por todos os pontos, indo do ponto mais a esquerda para o ponto mais a direita. Esse processo dá o nome do algoritmo "Sweep-Line". Essa técnica é muito útil para problemas de geometria computacional em 2D.

### Estrutura de dados e implementação

Para uma implementação comum desse algoritmo, precisamos guardar dois conjuntos de dados: os pontos que representam as linhas e os segmentos ativos. Para guardar os pontos, qualquer estrutura de dados simples ordenável pode ser utilizada, por exemplo um `<vector>` da STL de C++.

Para os segmentos ativos, na segunda etapa do algoritmo vamos precisar de uma estrutura de dados que nos permita fazer as operações de inserção, deleção e busca pelos vizinhos imediatos de acordo com as coordenadas y de maneira eficiente. Uma estrutura que nos atende muito bem seria uma `Self-Balancing BST`, como uma árvore rubro-negra ou uma árvore AVL. Usando qualquer uma dessas, conseguimos executar todas essas operações em _O(lg n)_. Usando uma estrutura implementada na STL do C++, poderíamos usar um `<map>`.

### Análise de tempo

Para a primeira etapa do algoritmo, precisamos ordenar um vetor de pontos, o que leva _O(n\*lg(n))_ utilizando a função `sort()` do C++.

Para a segunda etapa, são analizados _2n_ pontos, sendo que gastamos _O(lg n)_ para cada ponto.

Assim, a complexidade do algoritmo completo é _O(n\*lg(n))_

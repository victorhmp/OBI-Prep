# Árvores de busca balanceadas

De maneira bem intuitiva, árvores binárias de busca balanceadas são estruturas de dados que representam árvores binárias de busca, além de possuírem métodos _internos_ para manterem-se balanceadas, em geral controlando a altura da árvore para garantir performance de pior caso.

Vamos estudar rapidamente alguns exemplos de árvores de busca binária balanceadas, com atenção especial em como elas mantém sua estrutura balanceada após um número arbitrário de operações.

## Treap

Treaps são, basicamente, árvores binárias de busca aleatorizadas, ou seja, após qualquer sequência arbitrária de inserções e deleções de chaves, o _formato_ da árvore é uma _variável aleatória_ com distribuição de probabilidade igual à de uma árvore binária aleatória, sendo que, em particular, com uma probabilidade grande de sua altura ser proporcional à `lg(n)`, onde `n` é o número de chaves na árvore. Isso nos garante que operações de busca, inserção e deleção são feitas em tempo `O(lg n)`.

O nome `Treap` vem da combinação de `Heap` com `Tree`, e faz sentido quando observamos as propriedades dessa estrutura de dados:

- Cada elemento inserido na `Treap` é associado à uma _prioridade_, que é usada para manter a propriedade de `heap`, onde um dado nó necessariamente possui uma prioridade maior ou igual à de seus filhos;
- Percorrer a `Treap` _in-order_ nos dá as chaves ordenadas.

A aleatoriedade do _formato_ de uma `treap` vem da maneira com que atribuímos prioridades aos elementos que inserimos. Essas prioridades são geradas aleatóriamente! As operações básicas em uma `treap` são feitas da seguinte forma:

- **Busca**: busca-binária comum, ignorando a prioridade dos elementos, ou seja, o mesmo procedimento realizado em uma árvore de busca binária qualquer;
- **Inserir**: gerar uma prioridade `y` aleatóriamente para o elemento a ser inserido. Execute uma busca-binária procurando pelo elemento a ser inserido e então crie um novo nó na árvore na posição onde _deveria_ estar o elemento (ignorando prioridades). Então utilizamos a prioridade gerada e agora associada ao novo nó para manter a organização de `heap`, colocando o nó em sua posição correta.
- **Deletar**: para remover um elemento `x`, precisamos considerar três possíveis cenários: se `x` for uma folha da árvore, basta removê-lo, sem nenhum efeito colateral; se `x` possuir _um_ filho, removemos `x` e fazemos seu filho ser filho do pai de `x`; se `x` possui _dois_ filhos, trocamos `x` com seu sucessor imediato (considerando as chaves ordenadas), assim caindo em um dos casos anteriores. Importante notar que essa troca pode acabar violando a estruta de `heap`, logo podem ser necessárias mais algumas _rotações_ para restaurar a estrutura da `treap`.

## Splay Trees

Splay Trees são simplesmente árvores binárias de busca onde os elementos mais frequentemente buscados estão em profundidades _menores_, assim reduzindo o número esperado de comparações necessárias para encontrar um elemento se ele já foi procurado recentemente.

Essa estrutura de dados aposta em garantir o consumo de tempo _amortizado_ de operações de busca, inserção, e remoção em `O(lg(n))`, sendo mais rápida do que algumas outras variações de árvores binárias de busca dado uma sequência não-aleatória de operações.

Além das operações básicas presentes em todas as implementações de árvores binárias de busca, `splay trees` possuem uma operação à mais, o `splay`, que basicamente é responsável por mover o elemento mais recentemente acessado para a raíz da árvore. Essa operação pode ser implementada de algumas maneiras, mas a mais simples é simplesmente realizar uma busca binária pela árvore e depois realizar uma sequência de rotações para levar o elemento até o topo.
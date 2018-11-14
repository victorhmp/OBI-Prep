# K-ésimo menor elemento com QuickSelect

Vamos considerar o seguinte problema:

```
Dado um vetor A[0...n-1] e um inteiro k < n, determine o k-ésimo menor elemento desse vetor.
```

## Solução trivial

A solução mais simples para este problema é simplesmente ordenar o vetor de entrada utilizando um algoritmo de ordenação de consumo de tempo `O(n*lg(n))`, como merge sort ou heap sort, e depois retornar o k-ésimo elemento do vetor ordenado.

```c++
int kth_smallest(vector<int> &v, int k) {
  sort(v.begin(), v.end());

  return v[k-1];
}
```

Com esta solução conseguimos consumo de tempo `O(n*lg(n))`.

## Solução com HeapSelect

Podemos melhorar a nossa solução com o uso de uma estrutura de dados para representar os elementos do vetor de entrada. Esta estrutura de dados é uma MinHeap. Podemos simplesmente criar uma MinHeap e adicionar os elementos do vetor A de entrada, depois basta chamar a operação `extractMin()` k vezes.

Em C++, podemos utilizar uma `priority_queue` que irá servir como uma MinHeap:

```c++
int kth_smallest() {

}
```

Assim, obtemos consumo de tempo `O(n + (k*lg(n)))`.

## Solução com QuickSelect

Podemos ainda utilizar uma terceira técnica para resolver o problema. Basta otimizar a primeira solução que vimos, mas com uso do algoritmo QuickSort.

No QuickSort, escolhemos um elemento que será o pivô e o colocamos em sua posição final no vetor ordenado e particionamos o vetor "em volta" do pivô e repetir recursivamente. A ideia é simplesmente não completar o QuickSort, e sim parar quando o pivô for o k-ésimo menor elemento que estamos procurando. Além disso, no passo recursivo não precisamos chamar a recursão dos dois lados do pivô, basta um deles, de acordo com a posição correta do pivô no vetor ordenado.

Com este método conseguimos consumo de tempo, no pior caso, `O(n^2)`, mas no caso médio temos consumo de tempo `O(n)`.

```c++
int partition(int arr[], int l, int r) {
  int x = arr[r], i = l;

  for (int j = l; j <= r - 1; j++) {
    if (arr[j] <= x) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
    }
  }

  int tmp = arr[i];
  arr[i] = arr[r];
  arr[r] = tmp;

  return i;
}

int kth_smallest(int arr[], int l, int r, int k) {
  if (k > 0 && k <= r - l + 1) {
    int pos = partition(arr, l, r);

    // found
    if (pos-l == k-1)
      return arr[pos];
    // go left
    if (pos-l > k-1)
      return kth_smallest(arr, l, pos - 1, k)
    else
      kth_smallest(arr, pos + 1, r, k-pos+l-1);
  }

  // k > n
  return INT_MAX;
}
```

## RandomQuickSelect

Podemos obter ainda uma melhora probabilística no nosso consumo de tempo com uma simples alteração no processo de QuickSelect randomizando a escolha do pivô. É um ajuste simples, basta gerar um inteiro aleaatório entre `l` e `r`, trocar o elemento na posição gerada com o último elemento e executar o processo padrão de partição que usa o último elemento como pivô.

```c++
int randomPartition(int arr[], int l, int r) { 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(&arr[l + pivot], &arr[r]); 
    return partition(arr, l, r);
} 
```

O consumo de tempo no pior caso continua sendo `O(n^2)`, sendo este quando o número gerado aleatóriamente sempre é uma "borda" no intervalo [l, r]. Mas a grande melhora vem no consumo de tempo **esperado** de `O(n)`.
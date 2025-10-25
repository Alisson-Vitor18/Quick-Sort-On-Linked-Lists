# Lista Encadeada em C com QuickSort

Este projeto implementa uma lista encadeada de strings em C, permitindo adicionar, remover e ordenar elementos de forma eficiente. A ordenação é feita usando QuickSort com mediana de três, e toda a memória alocada é liberada corretamente, evitando vazamentos.

## Funcionalidades 
- Inserção de elementos na lista
- Remoção de elementos
- Ordenação usando QuickSort otimizado com mediana de três
- Impressão da lista
- Liberação segura da memória
  
## Como usar
1. Clone ou baixe o projeto.
2. Compile os arquivos:
```bash
gcc main.c list.c quicksort.c -o program
```

## Execução
```bash
./program
```

## Exemplo de saída

```bash
=== Original ===
Lista: { "Maria", "Marcos", "Kaik", "Alisson", "Assembly", "Julia", "Java", "Haskell", "COBOL" }

=== Ordenada ===
Lista: { "Alisson", "Assembly", "COBOL", "Haskell", "Java", "Julia", "Kaik", "Marcos", "Maria" }


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
```
## Testes de memória

O programa foi testado com Valgrind, garantindo que não haja vazamentos nem erros de acesso.  
Exemplo de execução:

```bash
valgrind --leak-check=full ./program
```

Exemplo de saída:
```bash
==12967== Memcheck, a memory error detector
==12967== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==12967== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==12967== Command: ./program
==12967== 

=== Original ===
Lista: { "Maria", "Marcos", "Kaik", "Alisson", "Assembly", "Julia", "Java", "Haskell", "COBOL" }

=== Ordenada ===
Lista: { "Alisson", "Assembly", "COBOL", "Haskell", "Java", "Julia", "Kaik", "Marcos", "Maria" }
==12967== 
==12967== HEAP SUMMARY:
==12967==     in use at exit: 0 bytes in 0 blocks
==12967==   total heap usage: 20 allocs, 20 frees, 1,252 bytes allocated
==12967== 
==12967== All heap blocks were freed -- no leaks are possible
==12967== 
==12967== For lists of detected and suppressed errors, rerun with: -s
==12967== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Licença
MIT

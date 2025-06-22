# ✈️ Gerenciador de Viagens

Projeto desenvolvido para simular um sistema de gerenciamento de passageiros e voos, utilizando três estruturas de dados fundamentais:

- Lista Encadeada
- Árvore AVL
- Tabela Hash (em desenvolvimento)

O objetivo é demonstrar a aplicação prática dessas estruturas no armazenamento, ordenação e busca de informações em um sistema de reservas aéreas.

---

## 📌 Estrutura Principal

O código é dividido em duas partes principais:

1. **Classe `TreeNode`**: Representa os nós da árvore AVL.
2. **Função `main()`**: Gera os dados, insere na árvore e executa interações com o usuário.

---

## 🧱 Classe `TreeNode`

A classe representa um nó de uma **árvore AVL**, uma árvore binária de busca **autobalanceada**.

### Atributos:
- `string data`: Nome completo armazenado.
- `TreeNode *left, *right`: Ponteiros para filhos esquerdo e direito.

### Métodos principais:

#### 🔁 Inserção (`insert`)
- Insere uma string mantendo a ordem alfabética.
- Após inserir, verifica o **fator de balanceamento**.
- Aplica rotações (LL, LR, RR, RL) se necessário.

#### 🗑️ Remoção (`deleteNode`)
- Remove um nó com base no nome.
- Rebalanceia a árvore após remoção, se necessário.

#### 🔍 Busca (`search`)
- Busca por um nome específico na árvore.

#### 🌲 Impressão (`printTree`)
- Exibe a árvore de forma visual com ramos (`└──`, `│` etc).

#### 📏 Altura (`height`) e Balanceamento (`getBalance`)
- Calcula altura de subárvores e diferença entre elas para rebalanceamento.

#### 🔃 Rotações
- `rotateLeft` / `rotateRight`: Realiza rotações para manter balanceamento.

#### 📊 Estatísticas:
- `countNodes`: Total de nós.
- `countLeaves`: Total de folhas.
- `getMin` / `getMax`: Menor e maior valor armazenado.

#### 🧹 `clear()` e destrutor
- Libera memória recursivamente.

---

## 🎲 Função `gerarNome()`

Gera um nome completo aleatório ao combinar um nome e um sobrenome das listas.

```cpp
return nomes[i] + " " + sobrenomes[j];
```

Utiliza `rand()` com `srand(time(0))` para inicializar a aleatoriedade.

---

## 🚀 Função `main()`

1. Inicializa a árvore (`root = nullptr`).
2. Gera e insere **3.000 nomes aleatórios**.
3. Mostra a árvore.
4. Permite ao usuário digitar um nome para remover.
5. Mostra a árvore após remoção e imprime estatísticas.

---

## 📈 Exemplo de Saída

```
AVL de strings
└── João Souza
    ├── ...
    └── ...
Digite um nome completo para deletar (ex: Felipe Carvalho): João Souza

"João Souza" removido com sucesso!

Árvore após deletar:

Menor valor: Alan Batista
Maior valor: Wilson Teles
Quantidade total de nós: 2999
Quantidade de folhas: 1488
Nível de Balanceamento: 0
```

---

## 🔧 Recursos Utilizados

- **C++ Padrão** (`<iostream>`, `<string>`, `<vector>`, `<cstdlib>`, `<ctime>`)
- Estrutura de **Árvore Binária de Busca Balanceada (AVL)**
- **Recursão** para inserção, remoção e travessias
- **Geração aleatória** de strings

---

## 📚 Conceitos Envolvidos

- Árvores Binárias de Busca
- Árvores AVL e rotações
- Complexidade O(log n) para inserções, buscas e remoções
- Manipulação de ponteiros e memória dinâmica em C++
- Impressão hierárquica de estruturas em árvore

---

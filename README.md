# ✈️ Gerenciador de Viagens

Projeto desenvolvido para simular um sistema de gerenciamento de passageiros e voos, utilizando três estruturas de dados fundamentais:

- Lista Encadeada
- Árvore AVL
- Tabela Hash 

O objetivo é demonstrar a aplicação prática dessas estruturas no armazenamento, ordenação e busca de informações em um sistema de reservas aéreas.

---

## 📚 Estruturas de Dados Utilizadas

### ✅ Lista Encadeada

A lista encadeada armazena os passageiros de cada voo. Cada nó da lista contém um objeto do tipo `Passageiro`, com os seguintes dados:

- Nome
- CPF
- Código da reserva
- Número do voo
- Assento

**Funções principais**:
- Inserção de passageiros
- Impressão da lista
- Remoção de passageiros por nome

> 💡 Essa estrutura é ideal para representar listas dinâmicas e sequenciais, como os passageiros de um voo.

---

### ✅ Árvore AVL

A árvore AVL é utilizada para armazenar e ordenar os **nomes dos passageiros**.

**Vantagens**:
- Mantém os nomes sempre em ordem alfabética
- Permite busca eficiente por nome
- Suporta remoção com rebalanceamento

> 💡 Utilizada exclusivamente para gerenciar a ordenação e a pesquisa dos nomes inseridos na lista encadeada.

---

### ✅ Tabela Hash 

A tabela hash será usada para armazenar os **voos**, onde a chave será o número do voo.

**Cada voo armazenado conterá**:
- Número do voo (chave)
- Destino

**Funções principais**:
- Cadastrar voo
- Buscar voo
- Deletar voo

> 💡 Estrutura ideal para buscas rápidas de voos por chave única.
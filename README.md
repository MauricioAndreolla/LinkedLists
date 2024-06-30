# LinkedLists (Conjunto de livros e-books de uma biblioteca 📚)
### Trabalho estrutura de dados 👨‍🚀

![App](https://github.com/MauricioAndreolla/LinkedLists/assets/44854911/9f5c234f-3199-471d-97f0-e6c154295057)
### 
Uma biblioteca virtual tem um conjunto de livros virtuais, os e-books. De cada e-book
são mantidas as seguintes informações: título, autor(es), ISBN, ano de edição, nome da
editora, número de páginas. Os dados desse conjunto de e-books vão ser manipulados por
um programa de computador para consultas por título, por autor, e por editora, considerando as
seguintes características:

• Um livro pode ter um ou vários autores (considerar no máximo 3 autores);

• Os títulos dos livros são mantidos em ordem alfabética, através do
armazenamento dos livros em uma ABP

### Estrutura Final 🙌

![image](https://github.com/MauricioAndreolla/LinkedLists/assets/44854911/8ed9ace6-75c5-43d2-9bef-640fc7aeb1bf)


### Operações que foram implementadas 🎯

Operações básicas a serem implementadas:
Pode haver variações nas entradas e saídas de dados das operações, os nomes e/ou os
parâmetros das operações podem ser modificados.

> insere_livro(E: dados do livro, autor(es), editora) – se um livro já existir na ABP , será
retornada uma mensagem informando. Um livro tem que que ter ao menos um autor e uma
editora;

> remove_livro (E: titulo) – remove-se o nodo que contém o livro, mantendo a ABP
ordenada;

> consulta_livro (E: título; S: dados do livro, autor(es) do livro, editora do livro)

> escreve_livrosAZ (S: lista de e-books): escreve os e-books (só o título ou dados
completos) em ordem alfabética;

> escreve_livrosZA (S: lista de e-books): escreve os e-books (só o título ou dados
completos) em ordem alfabética inversa;

> escreve_editorasAZ (S: lista de editoras): escreve os nomes das editoras em ordem
alfabética, sem repetir nomes exatamente iguais (pode utilizar uma ABP temporária);

> escreve_autoresAZ (S: lista de autores): escreve os nomes dos autores em ordem alfabética, sem repetir nomes exatamente iguais (pode utilizar uma ABP temporária);
> consulta_livros_por_autor (E: nome do autor; S: lista de livros)

> consulta_livros_por_editora (E: nome da editora; S: lista de livros)

> livro_maior_nro_paginas (S: título do livro): escreve os nomes das editoras em ordem
alfabética, sem repetir nomes exatamente iguais (pode utilizar uma ABP temporária);
outras consultas, outras operações (você pode definir)
}

### Rodar localmente 💻

Será necessário utilizar algum compilador para compilar para seu sistema operacional.

Irei deixar duas sugestões de IDE's que possuem compiladores inclusos.

### Dev-c++
• https://bloodshed.net/
### CodeBlocks
• https://www.codeblocks.org/

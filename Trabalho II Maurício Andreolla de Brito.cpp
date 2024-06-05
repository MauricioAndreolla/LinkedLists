#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>

  
    struct ebooks{
    char titulo[20];
    char autor1[20];
    char autor2[20];
    char autor3[20];
    char editora[20]; 
    int anoEdicao;
    int numeroPaginas;
    
    struct ebooks *esq;
    struct ebooks *dir;
    struct ebooks *pai;
  	};
  	
  	struct editoras{
    char editoraNome[20];   
    
    struct editoras *esq;
    struct editoras *dir;
    struct editoras *pai;
  	};
  	
  	struct autores{
    char autor1[20];   
    
    struct autores *esq;
    struct autores *dir;
    struct autores *pai;
  	};

  typedef struct ebooks ebook;
  typedef struct editoras editora;
  typedef struct autores autor;
  
    
 
  ebook *raiz =  NULL;
  editora *editoraRaiz = NULL;
  autor *autorRaiz = NULL;
  
  int count = 0; 
  int flagVerificaTitulo = 0;
  ebook *maiorValor = NULL;


	void insereNodo(ebook *atual, ebook *novo ){
	  	if( strcmp(atual->titulo,novo->titulo) > 0 ){
	  		if( atual->esq == NULL ){
	  			atual->esq = novo;
	  			atual->esq->pai = atual; //seta o pai
	  		}
	  		else
	  		  insereNodo( atual->esq, novo);
	  	}
	  	else{	  
	  		if( atual->dir == NULL){
	  			atual->dir = novo;
	  			atual->dir->pai = atual;
	  		}
	  		else
	  		  insereNodo( atual->dir, novo );
	    }
	    
	}

   
    void insere(char titulo[], char autor1[], char autor2[], char autor3[], char editora[], int anoEdicao, int numeroPaginas ){
        ebook *novo;
        ebook *aux = raiz;
        novo = (ebook*) malloc(sizeof(ebook));
        
        strcpy(novo->titulo,titulo);
        strcpy(novo->autor1,autor1);
        strcpy(novo->autor2,autor2);
        strcpy(novo->autor3,autor3);
        strcpy(novo->editora,editora);
        
     	novo->anoEdicao = anoEdicao;
     	novo->numeroPaginas = numeroPaginas;
     
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( raiz == NULL )
		  raiz = novo;
		else
		  insereNodo(aux,novo);
	}
	
	
	void insereNodoEditora(editora *atual, editora *novo ){
	  	if( strcmp(atual->editoraNome,novo->editoraNome) > 0 ){
	  		if( atual->esq == NULL ){
	  			atual->esq = novo;
	  			atual->esq->pai = atual; //seta o pai
	  		}
	  		else
	  		  insereNodoEditora( atual->esq, novo);
	  	}
	  	else{	  
	  		if( atual->dir == NULL){
	  			atual->dir = novo;
	  			atual->dir->pai = atual;
	  		}
	  		else
	  		  insereNodoEditora( atual->dir, novo );
	    }
	}

   
    void insereEditora(char editoraNome[]){
        editora *novo;
        editora *aux = editoraRaiz;
        novo = (editora*) malloc(sizeof(editora));
        
        strcpy(novo->editoraNome,editoraNome);
        
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( editoraRaiz == NULL )
		  editoraRaiz = novo;
		else
		  insereNodoEditora(aux,novo);
	}
	
	void centralEditora(editora *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		centralEditora( aux->esq );
		
		printf("\nNome do Editora: %s \n", aux->editoraNome);
		
		centralEditora( aux->dir );
	}
	
	void posFixDireitaEditora(editora *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		posFixDireitaEditora( aux->dir );
				
		printf("\nNome Editora: %s \n", aux->editoraNome);
	
		posFixDireitaEditora( aux->esq );
	
	}
	

	void insereTodasEditoras(ebook *aux){
		
		if (aux == NULL){
			return;
		}
		
		insereTodasEditoras(aux->esq);
		insereEditora(aux->editora);
		insereTodasEditoras(aux->dir);
		
	}
	
	void insereNodoAutor(autor *atual, autor *novo ){
	  	if( strcmp(atual->autor1,novo->autor1) > 0 ){
	  		if( atual->esq == NULL ){
	  			atual->esq = novo;
	  			atual->esq->pai = atual; //seta o pai
	  		}
	  		else
	  		  insereNodoAutor( atual->esq, novo);
	  	}
	  	else{	  
	  		if( atual->dir == NULL){
	  			atual->dir = novo;
	  			atual->dir->pai = atual;
	  		}
	  		else
	  		  insereNodoAutor( atual->dir, novo );
	    }
	}

   
    void insereAutor(char autor1[]){
        autor *novo;
        autor *aux = autorRaiz;
        novo = (autor*) malloc(sizeof(autor));
        
        strcpy(novo->autor1,autor1);
       
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = NULL;
        
		if( autorRaiz == NULL )
		  autorRaiz = novo;
		else
		  insereNodoAutor(aux,novo);
	}
	
	void centralAutor(autor *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		centralAutor( aux->esq );
		
		printf("\nNome dos Autores: %s \n", aux->autor1);
	
		centralAutor( aux->dir );
	}
	
	
	void insereTodasAutores(ebook *aux){
		
		if (aux == NULL){
			return;
		}
			
		insereTodasAutores(aux->esq);
		
		if(strcmp(aux->autor1, " ") != 0 && strcmp(aux->autor2, " ") != 0 && strcmp(aux->autor3, " ") != 0 ){
			insereAutor(aux->autor1);
			insereAutor(aux->autor2);
			insereAutor(aux->autor3);
		}else{
			
			if(strcmp(aux->autor1, " ") != 0 && strcmp(aux->autor2, " ") != 0){
				insereAutor(aux->autor1);
				insereAutor(aux->autor2);
			}else{
				if(strcmp(aux->autor1, " ") != 0){
					insereAutor(aux->autor1);
				}
			}
		}
		
		insereTodasAutores(aux->dir);	
	}
	
	int centralVerificaLivro(ebook *aux, char nomeLivro[]){
  		
		if( aux == NULL){
			return 1; 
		}
		
		centralVerificaLivro( aux->esq, nomeLivro );
		
		if( strcmp(aux->titulo, nomeLivro)  == 0){
			flagVerificaTitulo = 0;
			return flagVerificaTitulo;	
		}
			
		centralVerificaLivro( aux->dir, nomeLivro );
	}
	
  
  	void preFix(ebook *aux){
  	
  		
		if( aux == NULL ){
			return;	
		}
		
			
		printf("\nNome do Livro: %s \n", aux->titulo);
		printf("Nome Editora: %s \n", aux->editora);
		printf("Ano de publicação: %d \n", aux->anoEdicao);
		printf("Número de páginas: %d \n", aux->numeroPaginas);
		printf("Nome Autor 1: %s \n", aux->autor1);
		printf("Nome Autor 2: %s \n", aux->autor2);
		printf("Nome Autor 3: %s \n", aux->autor3);
	
		preFix( aux->esq );
		preFix( aux->dir );
	}
	
	void central(ebook *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		central( aux->esq );
		
		printf("\nNome do Livro: %s \n", aux->titulo);
		printf("Nome Editora: %s \n", aux->editora);
		printf("Ano de publicação: %d \n", aux->anoEdicao);
		printf("Número de páginas: %d \n", aux->numeroPaginas);
		printf("Nome Autor 1: %s \n", aux->autor1);
		printf("Nome Autor 2: %s \n", aux->autor2);
		printf("Nome Autor 3: %s \n", aux->autor3);
		
		
		
		central( aux->dir );
	}
	
	void posFix(ebook *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		posFix( aux->esq );
		posFix( aux->dir );
		
			
		printf("\nNome do Livro: %s \n", aux->titulo);
		printf("Nome Editora: %s \n", aux->editora);
		printf("Ano de publicação: %d \n", aux->anoEdicao);
		printf("Número de páginas: %d \n", aux->numeroPaginas);
		printf("Nome Autor 1: %s \n", aux->autor1);
		printf("Nome Autor 2: %s \n", aux->autor2);
		printf("Nome Autor 3: %s \n", aux->autor3);
	
	}
	
	void posFixDireita(ebook *aux){
  		
		if( aux == NULL ){
			return;	
		}
		
		posFixDireita( aux->dir );
		
		
		
		printf("\nNome do Livro: %s \n", aux->titulo);
		printf("Nome Editora: %s \n", aux->editora);
		printf("Ano de publicação: %d \n", aux->anoEdicao);
		printf("Número de páginas: %d \n", aux->numeroPaginas);
		printf("Nome Autor 1: %s \n", aux->autor1);
		printf("Nome Autor 2: %s \n", aux->autor2);
		printf("Nome Autor 3: %s \n", aux->autor3);
		
		posFixDireita( aux->esq );
	
	}
 
 	ebook* pesquisa(ebook *aux, char livro[]  ){		
        ebook *res = NULL;
		if( aux != NULL ){
            
		  if( strcmp(aux->titulo,livro) == 0){
             res = aux;
          }
          else{
               if( strcmp(aux->titulo,livro) > 0 ){
               	
                    res = pesquisa( aux->esq, livro );
               }
               else{
                    res = pesquisa( aux->dir, livro );
               }
          }
        }
        return res;
	}
	
	ebook* pesquisaPorAutor(ebook *aux, char autor[]  ){		
        ebook *res = NULL;
		if( aux != NULL ){
            
		  if( strcmp(aux->autor1,autor) == 0){
             res = aux;
             return res;
          }
          
          if( strcmp(aux->autor2,autor) == 0){
             res = aux;
             return res;
          }
          
          if( strcmp(aux->autor3,autor) == 0){
             res = aux;
             return res;
          }
          
          else{
               if( strcmp(aux->titulo,autor) > 0 ){
               	
                    res = pesquisaPorAutor( aux->esq, autor );
               }
               else{
                    res = pesquisaPorAutor( aux->dir, autor );
               }
          }
        }
        return res;
	}
	
	ebook* pesquisaPorEditora(ebook *aux, char editora[]  ){		
        ebook *res = NULL;
		if( aux != NULL ){
            
		  if( strcmp(aux->editora,editora) == 0){
             res = aux;
          }
          else{
               if( strcmp(aux->editora,editora) > 0 ){
               	
                    res = pesquisaPorEditora( aux->esq, editora );
               }
               else{
                    res = pesquisaPorEditora( aux->dir, editora );
               }
          }
        }
        return res;
	}	
	

	ebook* pesquisaMaiorNumeroPaginas(ebook *aux){		
	
		if( aux == NULL ){
			return maiorValor;
		}
            
		  if( aux->numeroPaginas > count){
             count = aux->numeroPaginas;
             maiorValor = aux;
          }
          
        pesquisaMaiorNumeroPaginas( aux->esq );
		pesquisaMaiorNumeroPaginas( aux->dir );
       
	}
	

	void removeFolha(ebook *atual){
	// Remove uma folha da árvore - Nodo folha não possui filhos
		ebook *pai = atual->pai;
		if(pai==NULL){ //o nodo a ser excluído é a raíz da árvore
			raiz = NULL;
		}
		else{
			if(pai->esq == atual){
				pai->esq = NULL;
			}
			else{
				pai->dir=NULL;
			}
		}
		free(atual);
	}
	
	void removeUmFilho(ebook *atual ){
	//Remove um nodo que possui um filho
		ebook *pai = atual->pai;
		if(pai==NULL){//o nodo a ser excluído é a raíz da árvore
			if(atual->esq != NULL){
				raiz = atual->esq;
			}
			else{
				raiz = atual->dir;
			}
			raiz->pai=NULL;
		}
		else{
			if(atual->esq == NULL){
				if(pai->dir == atual){
					pai->dir = atual->dir;
				}
				else{ //pai->esq==atual
					pai->esq=atual->dir;
				}
				atual->dir->pai = pai;
			}
			else{ //atual->dir==null
				if(pai->dir==atual){
					pai->dir=atual->esq;
				}
				else{ //pai.getEsq()==atual
					pai->esq=atual->esq;
				}
				atual->esq->pai = pai;
			}
            free(atual);	
		}
	} // fim da função remove com 1 filho
	
    void removeDoisFilhos( ebook *atual ){
	//Remove um nodo que possui dois filhos
		ebook *aux = atual->esq;
		ebook *pai = NULL;
				
		while(aux->dir!= NULL){//Busca o elemento mais da direita (desce a esq. e depois a direita)
			aux = aux->dir;
		}
		
		strcpy(atual->titulo,aux->titulo); //atribui o novo valor
		strcpy(atual->editora,aux->editora);
		strcpy(atual->autor1,aux->autor1);
		strcpy(atual->autor2,aux->autor2);
		strcpy(atual->autor3,aux->autor3);
		atual->anoEdicao = aux->anoEdicao;
		atual->numeroPaginas = aux->numeroPaginas;
		
		//Nodo Folha
		if((aux->esq == NULL) && (aux->dir == NULL)){
            removeFolha(aux);
		}
		else{
            removeUmFilho(aux);
		}				
	}// fim do método
	
    void remove(ebook *raiz,char titulo[]){
    	ebook *atual;
    	ebook *aux = raiz;
    	
    	atual = pesquisa(aux, titulo); // Verifica se o nodo existe
    	if(atual == NULL){
    		printf("O livro %s não esta presente na Árvore\n", titulo);
    		return;
		}
		// Chamada de Funções
		if((atual->esq == NULL) && (atual->dir == NULL))
    		removeFolha(atual);
    	else{
			if((atual->esq != NULL) && (atual->dir != NULL))
    			removeDoisFilhos( atual );
    		else
    			removeUmFilho( atual );
    	}		
    }    
		
  void opcoes(){
     printf("\n");
     printf("A - Inserir Livro, Autor e Editora\n");
	 printf("B - Consultar Livros A-Z\n");
	 printf("C - Consultar Livros Z-A\n");
	 printf("D - Pesquisa por Livro\n");
	 printf("E - Pesquisa por Livro com maior número de páginas\n");
	 printf("F - Pesquisa por Autor\n");
	 printf("G - Pesquisa por Editora\n");
	 printf("H - Remove Livro\n");
	 printf("I - Consulta Editores\n");
	 printf("J - Consulta Autores\n");
	 printf("K - Consulta Editores de Z-A\n");
	 
     printf("0 - Sair\n");
}
  
  
  void menu(){
     char opc;
     system("cls");
     opcoes();
     opc = getch();
     
     char nomeLivro[20];
     char nomeAutor1[20] = " ";
	 char nomeAutor2[20] = " ";
     char nomeAutor3[20] = " ";
     char nomeEditora[20];
     int ano;
     int paginas;
     int quantidadeDeAutores;
     int flag;
     
     ebook *aux;
     editora *auxEditora;
     autor *auxAutor;
    
     while(opc != '0'){
          switch(opc){
            case 'A':  
            	
            	
				printf("\nNome do Livro: ");
                fflush(stdin);
				scanf("%s", &nomeLivro);
				
				aux = raiz;
        		ebook *novo;
        		
        
        		while(centralVerificaLivro(aux, nomeLivro) == 0){
						printf("\nNome de livro já inserido\n");
						printf("Insira novamente\n");  
						printf("\nNome do Livro: ");
	                	fflush(stdin);
						scanf("%s", &nomeLivro);
				
						centralVerificaLivro(aux,nomeLivro);
					}
					
				
			
				printf("Quantos autores deseja inserir: ");
				fflush(stdin);
				scanf("%d", &quantidadeDeAutores);
			
				while(quantidadeDeAutores>3) { 
					printf("\nNão é permitido acima de 3 autores por livro\n"); 
					printf("Quantos autores deseja inserir: ");
					fflush(stdin);
					scanf("%d", &quantidadeDeAutores);
				}
			
				for(int i=0;i<quantidadeDeAutores;i++){
					if (i==0){
						printf("Nome do Autor 1: ");
						fflush(stdin);
						scanf("%s", &nomeAutor1);
					}
					
					if(i==1){
						printf("Nome do Autor 2: ");
						fflush(stdin);
						scanf("%s", &nomeAutor2);
					}
					
					if(i==2){
						printf("Nome do Autor 3: ");
						fflush(stdin);
						scanf("%s", &nomeAutor3);
					}
					
				}
			
                     
				printf("Nome da Editora: ");
                fflush(stdin);        
				scanf("%s", &nomeEditora);
				
				printf("Ano da publicação: ");
                fflush(stdin);        
				scanf("%d", &ano);
				
				printf("Número de Páginas: ");
                fflush(stdin);        
				scanf("%d", &paginas);
				
				insere(nomeLivro,nomeAutor1,nomeAutor2,nomeAutor3,nomeEditora,ano,paginas);
			
				
            break;
            
            case 'B':{
            	aux = raiz;
            	central(aux);
				break;
			}
            	
        
        	case 'C':{
        		aux = raiz;
            	posFixDireita(aux);
				break;
			}
        		
        	case 'D':{
        		printf("\nNome do Livro: ");
                fflush(stdin);
				scanf("%s", &nomeLivro);
				
        		aux = raiz;
        		ebook *novo;
        		novo = pesquisa(aux,nomeLivro);
        		
        		if(novo!=NULL){
        			
        			printf("\nNome do Livro: %s \n", novo->titulo);
					printf("Nome Editora: %s \n", novo->editora);
					printf("Ano de publicação: %d \n", novo->anoEdicao);
					printf("Número de páginas: %d \n", novo->numeroPaginas);
					printf("Nome Autor: %s \n", novo->autor1);
        			printf("Nome Autor: %s \n", novo->autor2);
        			printf("Nome Autor: %s \n", novo->autor3);
        			
				}else{
					printf("Livro não encontrado \n");
				}
				break;
			}
			
			
			case 'E':{
				aux = raiz;
				ebook *novo;
				novo = pesquisaMaiorNumeroPaginas(aux);
					
				if(novo!=NULL){
        			printf("\n Livro com mais páginas\n");
        			printf("\nNome do Livro: %s \n", novo->titulo);
					printf("Nome Editora: %s \n", novo->editora);
					printf("Ano de publicação: %d \n", novo->anoEdicao);
					printf("Número de páginas: %d \n", novo->numeroPaginas);
					printf("Nome Autor: %s \n", novo->autor1);
        			printf("Nome Autor: %s \n", novo->autor2);
        			printf("Nome Autor: %s \n", novo->autor3);
        					
				}else{
					printf("Livro não encontrado \n");
				}
				
				
				break;
			}
			
			case 'F':{
        		printf("\nNome do Autor: ");
                fflush(stdin);
				scanf("%s", &nomeAutor1);
				
				
        		aux = raiz;
        		ebook *novo;
        		novo = pesquisaPorAutor(aux,nomeAutor1);
        		
        		if(novo!=NULL){
        			
        			printf("\nNome do Livro: %s \n", novo->titulo);
					printf("Nome Editora: %s \n", novo->editora);
					printf("Ano de publicação: %d \n", novo->anoEdicao);
					printf("Número de páginas: %d \n", novo->numeroPaginas);
					printf("Nome Autor: %s \n", novo->autor1);
        			printf("Nome Autor: %s \n", novo->autor2);
        			printf("Nome Autor: %s \n", novo->autor3);
        			
				}else{
					printf("Autor não encontrado \n");
				}
				break;
			}
			
			case 'G':{
        		printf("\nNome da Editora: ");
                fflush(stdin);
				scanf("%s", &nomeEditora);
				
        		aux = raiz;
        		ebook *novo;
        		novo = pesquisaPorEditora(aux,nomeEditora);
        		
        		if(novo!=NULL){
        			
        			printf("\nNome do Livro: %s \n", novo->titulo);
					printf("Nome Editora: %s \n", novo->editora);
					printf("Ano de publicação: %d \n", novo->anoEdicao);
					printf("Número de páginas: %d \n", novo->numeroPaginas);
					printf("Nome Autor: %s \n", novo->autor1);
        			printf("Nome Autor: %s \n", novo->autor2);
        			printf("Nome Autor: %s \n", novo->autor3);
        			
				}else{
					printf("Editora não encontrada \n");
				}
				break;
			}	
			
			case 'H':{
				printf("\nNome do Livro: ");
                fflush(stdin);
				scanf("%s", &nomeLivro);
				
				
				aux = raiz;
				remove(aux, nomeLivro);
				break;
			}
			
			
			case 'I':{
				
			
				aux = raiz;
				
				insereTodasEditoras(aux);
				auxEditora = editoraRaiz;
				
				centralEditora(auxEditora);
				
				editoraRaiz = NULL;
				break;
			}
			
			
			
			case 'J':{
				aux = raiz;
				
				insereTodasAutores(aux);
				auxAutor = autorRaiz;
				
				centralAutor(auxAutor);
				autorRaiz = NULL;
				break;
			}
			
			case 'K':{
				aux = raiz;
				insereTodasEditoras(aux);
        		auxEditora = editoraRaiz;
            	posFixDireitaEditora(auxEditora);
            	editoraRaiz = NULL;
				break;
			}
				
			
          }
          opcoes();
          opc = getch();     
     }
}
  
int main() {
	setlocale(LC_ALL, "Portuguese");  
	menu();  
	return 0;
}

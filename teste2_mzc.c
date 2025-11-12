#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dados_Pesquisador{

    char nome[1024];
    enum titulacao{
        Doutor,
        Mestre
    };
} pesquisador;

typedef struct Dados_Projeto{

    pesquisador Pesquisador;
    int codigo;
    char titulo[1024];
    float orcamento;
    int num_partic;
    
} projeto;

// fgets(ondevaiarmazenar, quantidadedecaracpraler, arquivo)
// ftell: pra dizer em que posição estou 
// strstr: pra achar string dentro de string 

projeto *carregarProjetos(FILE* nomeArquivo, int *numProjetos){

    projeto Projeto;
    projeto *lista_projetos = malloc(*numProjetos * sizeof(projeto));
    int i = 0;
    char linha_lida[1024];

    // conferindo se o malloc funcionou

    if(lista_projetos == NULL){
        printf("Alocação de lista_projetos falhou. Encerrando o programa.\n");
        exit(1);
    }

    else{

    while(!feof(nomeArquivo)){

        // verificando se há necessidade de realocação
        if(i == *numProjetos){

            *numProjetos *= 2;
            projeto *lista_aux = realloc(lista_projetos, *numProjetos *sizeof(projeto));

            if(lista_aux == NULL){
                printf("Realocação falhou. Liberando a memória e encerrando o programa.\n");
                free(lista_projetos);
                exit(1);
            }

            else{

            lista_projetos = lista_aux;
            } // fim do else da realocação
        }

        fscanf(nomeArquivo, "Codigo: %d\n", &Projeto.codigo);
        fscanf(nomeArquivo, "Titulo: %s\n", Projeto.titulo);
        fscanf(nomeArquivo, "Orcamento: %f\n", &Projeto.orcamento);

        //fscanf(nomeArquivo, "Pesquisadores: %s(%s),); corrigir armazenamento de pesquisadores

        lista_projetos[i] = Projeto;
        i++;
    }
    // ideia: ler linha a linha com fgets, e ver se é linha de codigo, de titulo, de orcamento, de pesquisadores ou de ---
    // de acordo com o resultado, armazenar nos itens da estrutura 

    return lista_projetos;

} // fim do else (alocação inicial funcionou)

}

void adicionarProjeto(projeto **projetos, int *numProjetos){


}

void adicionarPesquisador(projeto *projetos, int numProjetos){

}

void gerarRelatorio(const char *nomeArquivo, projeto *projetos, int numProjetos){

}

void liberarMemoria(projeto *projetos, int numProjetos){

}


int main(){

    FILE *arq;
    arq = fopen("projeto.txt", "w");
    int qtd_projetos = 10;
    int *qtd_projetos_ptr = &qtd_projetos;
    projeto lista_projetos;
    
    if(arq != NULL){

    fprintf(arq, "Codigo: 101\nTitulo: Desenvolvimento de um novo semicondutor à base de grafeno\nOrcamento: 150000.00\nPesquisadores: Carlos Silva(Doutor), Ana Pereira(Mestre)\n---\nCodigo: 102\nTitulo: Impacto da inteligência artificial na educação básica\nOrcamento: 85000.50\nPesquisadores: Bruna Costa(Doutora), Joao Alves(Mestre)\n---\nCodigo: 103\nTitulo: Análise de proteínas para combate a doenças degenerativas\nOrcamento: 220000.00\nPesquisadores: Ricardo Mendes(Doutor)\n---");
    carregarProjetos(arq, qtd_projetos_ptr);
    }

    else{
        printf("Erro ao abrir o arquivo");
        fclose(arq);
        exit(1);
    }
    return 0;
}
// abrir arquivo no modo leitura e append 
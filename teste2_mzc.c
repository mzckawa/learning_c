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

projeto *carregarProjetos(const char* nomeArquivo, int *numProjetos){

    FILE *arq;
    arq = fopen(nomeArquivo, "r+");
    projeto Projeto;
    projeto *lista_projetos = malloc(*numProjetos * sizeof(projeto));
    int i = 0;
    char linha_lida[1024];

    if(arq == NULL){

        printf("Erro ao abrir o arquivo");
        fclose(arq);
        exit(1);
    }
    
    else{

    fprintf(arq, "Codigo: 101\nTitulo: Desenvolvimento de um novo semicondutor à base de grafeno\nOrcamento: 150000.00\nPesquisadores: Carlos Silva(Doutor), Ana Pereira(Mestre)\n---\nCodigo: 102\nTitulo: Impacto da inteligência artificial na educação básica\nOrcamento: 85000.50\nPesquisadores: Bruna Costa(Doutora), Joao Alves(Mestre)\n---\nCodigo: 103\nTitulo: Análise de proteínas para combate a doenças degenerativas\nOrcamento: 220000.00\nPesquisadores: Ricardo Mendes(Doutor)\n---");

    // conferindo se o malloc funcionou

    if(lista_projetos == NULL){
        printf("Alocação de lista_projetos falhou. Encerrando o programa.\n");
        exit(1);
    }

    else{

    while(!feof(arq)){ // lendo o arquivo até o fim

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

            free(lista_aux);
        }

        // lendo os dados por "blocos", sendo cada bloco composto pelos dados de um único projeto
        fscanf(arq, "Codigo: %d\n", &Projeto.codigo);
        printf(" %d", Projeto.codigo);
        fscanf(arq, "Titulo: %s\n", Projeto.titulo);
        fscanf(arq, "Orcamento: %f\n", &Projeto.orcamento);

        //fscanf(nomeArquivo, "Pesquisadores: %s(%s),); corrigir armazenamento de pesquisadores

        lista_projetos[i] = Projeto; // preenchendo a lista de structs com um projeto com os dados atuais 
        i++;
    }

    for(int j = 0; j<*numProjetos; j++){

        printf("Dados do projeto %d", j+1);
        printf("%d\n", lista_projetos[j].codigo);
        printf("%s\n", lista_projetos[j].titulo);
        printf("%f\n", lista_projetos[j].orcamento);
    }

    return lista_projetos;

    }

} // fim do else (alocação inicial funcionou)

}

void adicionarProjeto(projeto **projetos, int *numProjetos){

    // verificando se é necessário realocar memória para comportar o novo projeto
    
    int qtd_atual_projetos;
    int i;

    for(i = 0; projetos[i] != NULL; i++){ // para contar quantos projetos o array contém, efetivamente
    }

    // verificando se há necessidade de realocação
    if(i == *numProjetos){

        *numProjetos *= 2;
        projeto *lista_aux = realloc(*projetos, *numProjetos *sizeof(projeto));

        if(lista_aux == NULL){
            printf("Realocação falhou. Liberando a memória e encerrando o programa.\n");
            free(*projetos);
            exit(1);
        }

        else{

        *projetos = lista_aux;
        } // fim do else da realocação

        free(lista_aux);
    }

    // adicionando o novo projeto 

    scanf("Codigo: %d\n", &((*projetos)[i].codigo));
    scanf("Titulo: %s\n", (*projetos)[i].titulo);
    scanf("Orcamento: %f\n", &((*projetos)[i].orcamento));

}

void adicionarPesquisador(projeto *projetos, int numProjetos){

}

void gerarRelatorio(const char *nomeArquivo, projeto *projetos, int numProjetos){

    // ordenando os orçamentos 

    float lista_orcam[numProjetos];
    
    for(int i = 0; i< numProjetos; i++){

        int idx_menor_elem = i; // mesmo chamando de "menor elemento", o que estamos fazendo é ver o elemento correto para ocupar a posição atual. Primeiro, a posição zero (em que deve ficar, de fato, o menor elemento); depois, a posição 1, em que deve ficar o segundo menor elemento, e assim por diante

        for(int j = 0; j< numProjetos; j++){

            if(projetos[j].orcamento < lista_orcam[i]){

                int ja_esta = 0;

                for(int k = 0; k <= i; k++){
                    if(projetos[j].orcamento = lista_orcam[k]){
                        ja_esta = 1;
                    }
                }

                if (ja_esta == 0){ // para só trocar de posição de o elemento se ele já não estiver no array ordenado
                lista_orcam[i + 1] = lista_orcam[i];
                lista_orcam[i] = projetos[j].orcamento;
                }
            }
        }
    }

    // imprimindo os dados ordenados do relatório

    for(int i = 0; i< numProjetos; i++){

        for(int j = 0; j< numProjetos; j++){
            if(projetos[j].orcamento == lista_orcam[i]){
                
                printf("Codigo: %d", projetos[j].codigo);
                printf("Titulo: %s", projetos[j].titulo);
                printf("Orcamento: %.2f", projetos[j].orcamento);
            }
        }
    }

}

void liberarMemoria(projeto *projetos, int numProjetos){

    free(projetos);

}


int main(){

    int qtd_projetos = 10;
    projeto *lista_projetos = carregarProjetos("projeto.txt", &qtd_projetos);
    
    
    return 0;
}
// abrir arquivo no modo leitura e append 
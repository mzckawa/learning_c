#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[100];
	float nota1;
	float nota2;
	float nota3;
	float media;
	char situacao[15];
} Aluno;

int main() {

	FILE *arq_binario;
	FILE *arq_html;
	Aluno aluno[65];
	int i = 0;

	if((arq_binario= fopen("chamada.bin", "wb")) != NULL && (arq_html= fopen("chamada.html", "wt")) != NULL) { // opening the file in the binary format

		printf("Qual o nome do aluno? ");
		scanf(" %99[^\n]", aluno[i].nome);

		while(strcmp(aluno[i].nome, "fim")) {

			float vetor_notas[3];

			printf("Quais foram as notas de %s nas provas? ", aluno[i].nome);
			scanf("%f %f %f", &aluno[i].nota1, &aluno[i].nota2, &aluno[i].nota3); // receiving the student's vector of grades

			aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;

			if(aluno[i].media < 7) {
				strncpy(aluno[i].situacao, "Reprovado", 15);
			}

			else {
                strncpy(aluno[i].situacao, "Aprovado", 15);
			}

			printf("A primeira nota de %s foi %.2f, a segunda foi %.2f e a terceira foi %.2f. Logo, sua média (arredondada em duas casas decimais) é %.2f e sua situação é %s.\n", aluno[i].nome, aluno[i].nota1, aluno[i].nota2, aluno[i].nota3, aluno[i].media, aluno[i].situacao);

			i++;

			printf("Qual o nome do aluno? ");
			scanf(" %99[^\n]", aluno[i].nome); // receiving the next student's name
		}

        if(i){
             fwrite(aluno, sizeof(Aluno), i, arq_binario);
        }
        
        fprintf(arq_html, "<!DOCTYPE html>\n<html>\n<style>\ntable, th, td {\nborder:1px solid black;\n}\n</style>\n<body>\n");
        fprintf(arq_html, "<h2>Desempenho da Turma</h2>\n");
        fprintf(arq_html, "<table style=\"width:100%\">\n<tr>\n<th>Nome</th>\n<th>Nota 1</th>\n<th>Nota 2</th>\n<th>Nota 3</th>\n<th>Média</th>\n<th>Situação</th>\n");
        
        for(int j = 0; j < i; j++){
            
            fprintf(arq_html, "<tr>\n");
            fprintf(arq_html, "<td>%s</td>", aluno[j].nome);
            fprintf(arq_html, "<td>%.2f</td>", aluno[j].nota1);
            fprintf(arq_html, "<td>%.2f</td>", aluno[j].nota2);
            fprintf(arq_html, "<td>%.2f</td>", aluno[j].nota3);
            fprintf(arq_html, "<td>%.2f</td>", aluno[j].media);
            fprintf(arq_html, "<td>%s</td>", aluno[j].situacao);
            fprintf(arq_html, "</tr>\n");
            
        }
        
        fprintf(arq_html, "</table>");
        fprintf(arq_html, "</body></html>");
        
        fclose(arq_binario);
        fclose(arq_html);
	}

    return 0;
}

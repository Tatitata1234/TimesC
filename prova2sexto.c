#include <stdio.h>
#include <string.h>
#define N 1000

typedef struct{
    char nome[50];
    int nVitorias;
    int nEmpates;
    int nDerrotas;
    int nGolsFeitos;
    int nGolsSofridos;
    int saldoGols;
    int pontuacao;

}times;

int cadastrar(times *time){
    int i=0,controle=0,u,j=0;
    FILE *arquivo;
    do{
        printf("Insira o nome do time:\n");
        fflush(stdin);
        fgets(time[i].nome,50,stdin);
        printf("Insira o numero de vitorias:\n");
        scanf("%d",&time[i].nVitorias);
        printf("Insira o numero de empates:\n");
        scanf("%d",&time[i].nEmpates);
        printf("Insira o numero de derrotas:\n");
        scanf("%d",&time[i].nDerrotas);
        printf("Insira o numero gols feitos:\n");
        scanf("%d",&time[i].nGolsFeitos);
        printf("Insira o numero gols sofridos:\n");
        scanf("%d",&time[i].nGolsSofridos);
        time[i].saldoGols = time[i].nGolsFeitos - time[i].nGolsSofridos;
        time[i].pontuacao = (time[i].nVitorias) * 3 + time[i].nEmpates - time[i].nDerrotas;
        printf("Deseja continuar?\nSim - Qualquer numero\t\tNao - 0\n");
        scanf("%d",&controle);
        i++;
    }while(i<N&&controle!=0);
    arquivo = fopen("Times.txt","w");

    for(j=0;j<i;j++){
        fprintf(arquivo,"Nome: %s\tVitorias: %d\tEmpates: %d\tDerrotas: %d\tGols feitos: %d\tGols Sofridos: %d\tSaldo Gols: %d\tPontuacao: %d\n",time[j].nome,time[j].nVitorias,time[j].nEmpates,time[j].nDerrotas,time[j].nGolsFeitos,time[j].nGolsSofridos,time[j].saldoGols,time[j].pontuacao);
    }
    fclose(arquivo);
    return i;
}

int adicionar(times *time,int u){
    int i=0,controle=0,l=0;
    FILE *arquivo;
    i=u;
    do{
        printf("Insira o nome do time:\n");
        fflush(stdin);
        fgets(time[i].nome,50,stdin);
        printf("Insira o numero de vitorias:\n");
        scanf("%d",&time[i].nVitorias);
        printf("Insira o numero de empates:\n");
        scanf("%d",&time[i].nEmpates);
        printf("Insira o numero de derrotas:\n");
        scanf("%d",&time[i].nDerrotas);
        printf("Insira o numero gols feitos:\n");
        scanf("%d",&time[i].nGolsFeitos);
        printf("Insira o numero gols sofridos:\n");
        scanf("%d",&time[i].nGolsSofridos);
        time[i].saldoGols = time[i].nGolsFeitos - time[i].nGolsSofridos;
        time[i].pontuacao = (time[i].nVitorias) * 3 + time[i].nEmpates - time[i].nDerrotas;
        printf("Deseja continuar?\nSim - Qualquer numero\t\tNao - 0\n");
        scanf("%d",&controle);

        i++;
    }while(i<N&&controle!=0);

    arquivo = fopen("Times.txt","a");
    for(l=u;l<i;l++){
        fprintf(arquivo,"Nome: %s\tVitorias: %d\tEmpates: %d\tDerrotas: %d\tGols feitos: %d\tGols Sofridos: %d\tSaldo Gols: %d\tPontuacao: %d\n",time[l].nome,time[l].nVitorias,time[l].nEmpates,time[l].nDerrotas,time[l].nGolsFeitos,time[l].nGolsSofridos,time[l].saldoGols,time[l].pontuacao);
    }
    fclose(arquivo);
    return i;
}

int listaTimes(times *time,int u){
    int v=0,k=0;
    FILE *arquivo;
    k=u;
    arquivo = fopen("Times.txt", "a");
    fprintf(arquivo, "Lista de times:\n");
    printf("Lista de times:\n");
    for(v=0; v<k;v++){
        fprintf(arquivo, "%s", time[v].nome);
        printf("%s",time[v].nome);
    }
    fclose(arquivo);
}

void timeCampeao(times *time,int k){
    int v=0, g,t,maior=-99,mais=-99;
    FILE *arquivo;
    arquivo = fopen("Times.txt","a");
    for(v=0;v<k;v++){
        if(time[v].pontuacao>maior){
            maior=time[v].pontuacao;
            t=v;
        }else{
            if(time[v].pontuacao==maior){
                if(time[v].nVitorias>mais){
                    maior=time[v].pontuacao;
                    t=v;
                }
            }
        }
    }
    printf("\nO time vencedor eh: %s",time[t].nome);
    fprintf(arquivo, "\nO time vencedor eh: %s", time[t].nome);
    fclose(arquivo);
}

int main(){
    int entrada,i=0, k=0;
    FILE *arquivo;
    times time[N];

    do{
    printf("Menu:\n"
           "1-cadastrar \(cria uma lista nova\)\n"
           "2-adicionar\(adiciona na lista ja criada\)\n"
           "3-lista times\(lista dos nomes dos times na tela e no doc\)\n"
           "4-time campeao\(time campeao na tela e no doc\)\n"
           "5-sair\n\n");

    scanf("%d",&entrada);
        switch(entrada){
            case 1:
                i = cadastrar(&time);
                break;
            case 2:
                k = adicionar(&time,i);
                break;
            case 3:
                if(k==0){
                    listaTimes(&time,i);
                }else{
                    listaTimes(&time,k);
                }
                break;
            case 4:
                if(k==0){
                    timeCampeao(&time,i);
                }else{
                    timeCampeao(&time,k);
                }
                break;
            case 5:
                printf("Tchau!");
                break;
            default:
                printf("numero invalido");
                break;
        }
    }while(entrada!=5);

    return 0;
}


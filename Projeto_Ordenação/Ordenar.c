/*FEITO EM DUPLA

AUTORES: ARTUR DARTAGNAN e JOSÉ AUGUSTO

*/


#include "Ordenar.h"


int *bubble_sort(int *v, int n)
{

    //Compara atual com o próximo, se menor troca

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (v[i] > v[j])
            { // 2 , 3, 1 --> 1,3,2 --> 1,2,3

                int aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }

    return v;
}

int *selection_sort(int *v, int n)
{


    // Procura o menor elemento e troca com atual e faz essa troca até o final do vetor
    int minimo;

    for (int i = 0; i < n - 1; i++)
    {

        minimo = i;

        for (int j = i + 1; j < n; j++)
        {

            if (v[minimo] > v[j])
            {

                minimo = j;
            }
        }

        //Ao final do for interno, troca o menor elemento com o atual
        int aux = v[minimo]; // 2, 3, 1 --> 1, 3, 2 --> 1, 2, 3
        v[minimo] = v[i];
        v[i] = aux;
    }

    return v;
}

int *inserction_sort(int *v, int n)
{

    //Pega o atual e compara com os anteriores, se for menor troca
    int atual;
    for (int i = 0; i < n; i++)
    {

        atual = v[i];

        int j = i;

        // Verifica se o anterior é maior que o atual, se for troca
        while ((j > 0) && (v[j - 1] > atual))  // 2, 3, 1 --> 2, 1, 3 --> 1, 2, 3
        {

            v[j] = v[j - 1]; 
            j--;
        }

        v[j] = atual;
    }

    return v;
}

int *merge(int inicio, int meio, int fim, int *vetor)
{

    //Faz trabalho de unir os vetores ordenados

    //826015
    //826     015
    //8  26    0  15
    
    
    int w[fim - inicio];

    int i = inicio;
    int j = meio;
    int k = 0;

    while (i < meio && j < fim)
    {
        if (vetor[i] < vetor[j])
        {

            w[k] = vetor[i];
            k++;
            i++;
        }

        else
        {

            w[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i < meio)
    {

        w[k] = vetor[i];

        i++;
        k++;
    }

    while (j < fim)
    {

        w[k] = vetor[j];

        j++;
        k++;
    }

    for (int x = inicio; x < fim; x++)
    {

        vetor[x] = w[x - inicio];
    }

    return vetor;
}

int *merge_sort(int inicio, int fim, int *vetor)
{

    //Tecnica do jack estripador (em partes)

    //Primeiro divide o vetor em partes menores, depois ordena e depois une

    int meio;

    if (inicio < fim - 1)
    {

        meio = (inicio + fim) / 2; 

        merge_sort(inicio, meio, vetor);
        merge_sort(meio, fim, vetor);

        merge(inicio, meio, fim, vetor);
    }

    return vetor;
}

int *quick_sort(int inicio, int fim, int *vetor)


    // Divide o vetor em partes menores, ordena e depois une
    // Sobe ordenando ao contrário do merge_sort
{

    if (inicio < fim)
    {

        partition(inicio, fim, vetor);
    }

    return vetor;
}

int *partition(int inicio, int fim, int *vetor)
{


    //Pega o primeiro elemento como pivo e ordena os elementos menores que ele a esquerda e os maiores a direita

    int x, a, b;

    x = vetor[inicio];
    a = inicio + 1;
    b = fim;

    while (1)
    {

        while (vetor[b] > x)
        {
            b--;
        }
        while (vetor[a] <= x)
        {
            a++;
        }

        if (a <= b)
        {
            int aux;

            aux = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = aux;
        }

        else
        {

            int aux;

            aux = vetor[inicio];
            vetor[inicio] = vetor[b];
            vetor[b] = aux;

            break;
        }
    }

    quick_sort(inicio, b - 1, vetor);
    quick_sort(b + 1, fim, vetor);

    return vetor;
}

int *count_sort(int *vetor, int n)
{


    //Conta quantas vezes cada elemento aparece e depois ordena

    //OBS: Se tivesse vetor infinito não precisaria do if;

    int menor, maior;
    menor = vetor[0];
    maior = vetor[0];

    for (int i = 1; i < n; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
        else if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }

    maior++;

    

    int *aux, *copia;

    aux = (int *)malloc(sizeof(int) * (maior));
    copia = (int *)malloc(sizeof(int) * n);

    for (int j = 0; j < maior; j++)
    {
        
        aux[j] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        
        aux[vetor[j]]++;
    }

    for (int f = 1; f < maior; f++)
    {

        aux[f] += aux[f - 1];
    }

    int problema, problema2;

    

    for (int j = n  - 1; j >= 0; j--)
    {

        

        problema = aux[vetor[j]] - 1;
        
        
        
        copia[problema] = vetor[j];
        
        aux[vetor[j]] -= 1;
        
    }

    

    return copia;
}

/*
int partition(int inicio, int fim, int** vetor){

    int x,a,b;

    x =  vetor[inicio]);
    a = inicio + 1;
    b = fim;

    while(1){

        while( vetor[b])>x){
            b--;
        }
        while( vetor[a])<=x){
            a++;
        }

        if (a <= b){
            int aux;

            aux =  vetor[a]);
             vetor[a]) =  vetor[b]);
             vetor[b]) = aux;

        }

        else{

            int aux;

            aux = *(vetor[inicio]);
            vetor[inicio] = vetor[b];
             vetor[b]) = aux;

        }

    }

    return b;
}
*/

/*
int* quick_sort(int inicio, int fim, int* vetor){

    int q;

    Imprimir_vetor(vetor,12);

    if (inicio < fim){


        q = partition(inicio,fim, &vetor);



        quick_sort(inicio,q-1,vetor);
        quick_sort(q+1,fim,vetor);

    }

    Imprimir_vetor(vetor,12);

    printf("vet\n");


    return vetor;

}
*/

void Imprimir_vetor(int *v, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (i == n - 1)
        {

            printf("%d  ", v[i]);
        }
        else
        {

            printf("%d - ", v[i]);
        }
    }

    printf("\n\n");
}

void Menu()
{

    int opcao = -1, tamVetor;

    printf("\tMenu:\n1 - bubble_sort\n2 - selection_sort\n3 - inserction_sort\n4 - merge_sort\n5 - quick_sort\n6 - count_sort\n0 - SAIR");

    printf("\nDigite a opcao selecionada: ");
    scanf("%d", &opcao);

    while (opcao != 0)
    {

        printf("Qual o tamanho do vetor de teste:");
        scanf("%d", &tamVetor);

        int *vetor;

        vetor = (int *)malloc(sizeof(int) * tamVetor);

        for (int i = 0; i < tamVetor; i++)
        {

            printf("Qual o valor do vetor na posicao [%d]: ", i);
            scanf("%d", &vetor[i]);
        }

        switch (opcao)
        {
        case 1:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(bubble_sort(vetor, tamVetor), tamVetor);
            printf("\n\tTempo Bubble: %f",CravarCronometro());

            break;

        case 2:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(selection_sort(vetor, tamVetor), tamVetor);
            
            printf("\n\tTempo Selection: %f",CravarCronometro());
            break;
        case 3:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(inserction_sort(vetor, tamVetor), tamVetor);


            printf("\tTempo Inserction: %f",CravarCronometro());

            break;

        case 4:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(merge_sort(0, tamVetor, vetor), tamVetor);

            printf("\tTempo Merge: %f",CravarCronometro());

            break;

        case 5:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(quick_sort(0, tamVetor, vetor), tamVetor);


            printf("\tTempo Quick: %f",CravarCronometro());


            break;

        case 6:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(count_sort(vetor, tamVetor), tamVetor);

            printf("\tTempo Count: %f",CravarCronometro());
            break;

        case 0:

            printf("Encerrando programa...\n");
            break;

        default:

            printf("opcao invalida digite novamente:");
            scanf("%d", &opcao);
            break;
        }

        printf("\n\tMenu:\n1 - bubble_sort\n2 - selection_sort\n3 - inserction_sort\n4 - merge_sort\n5 - quick_sort\n6 - count_sort\n0 - SAIR");

        printf("\nDigite a opcao selecionada: ");
        scanf("%d", &opcao);
    }
}




void Teste_Instancia(int* ordenar, int tamVetor){

    int vetor[tamVetor];

     for (int i = 0;i < tamVetor;i++){
            vetor[i] = ordenar[i];
    }

    //Adaptacao da função Menu para rodar todas as instancias de teste
    //Perguntar qual arquivo de teste quer rodar
    //E dentro do while repetir o vetor original para poder ser testado por todos os metodos de ordenacao

    int opcao = -1;

   

    printf("\tMenu:\n1 - bubble_sort\n2 - selection_sort\n3 - inserction_sort\n4 - merge_sort\n5 - quick_sort\n6 - count_sort\n7 - Imprimir Vetor\n0 - SAIR");

    printf("\nDigite a opcao selecionada: ");
    scanf("%d", &opcao);

    

    while(opcao != 0){


        

        

        

        switch (opcao)
        {
        case 1:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(bubble_sort(vetor, tamVetor), tamVetor);
            printf("\n\tTempo Bubble: %f\n",CravarCronometro());

            break;
        
        case 2:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(selection_sort(vetor, tamVetor), tamVetor);
            
            printf("\n\tTempo Selection: %f\n",CravarCronometro());
            break;

        case 3:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(inserction_sort(vetor, tamVetor), tamVetor);
            printf("\tTempo Inserction: %f\n",CravarCronometro());

            break;

        case 4:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(merge_sort(0, tamVetor, vetor), tamVetor);

            printf("\tTempo Merge: %f\n",CravarCronometro());

            break;

        case 5:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(quick_sort(0, tamVetor, vetor), tamVetor);
        
            printf("\tTempo Quick: %f\n",CravarCronometro());

            break;

        case 6:

            InicioTemporizador();
            printf("Vetor ordenado:\n");
            Imprimir_vetor(count_sort(vetor, tamVetor), tamVetor);

            printf("\tTempo Count: %f\n",CravarCronometro());
            break;

        case 7:

            Imprimir_vetor(vetor, tamVetor);
            break;
        
        case 0:

            printf("Encerrando programa...\n");
            break;

        default:

            printf("opcao invalida digite novamente:");
            scanf("%d", &opcao);
            break;
        }


         printf("\tMenu:\n1 - bubble_sort\n2 - selection_sort\n3 - inserction_sort\n4 - merge_sort\n5 - quick_sort\n6 - count_sort\n7 - Imprimir Vetor\n0 - SAIR");

        printf("\nDigite a opcao selecionada: ");
        scanf("%d", &opcao);


        for (int i = 0;i < tamVetor;i++){
            vetor[i] = ordenar[i];
        }

    }


}





int TamVetor(char* file_name){

    FILE *arquivo;
    arquivo = fopen(file_name, "r");

    if (arquivo == NULL)
    {
        printf("\nERRO ");
        exit(1);
    }
    
    int numVertices;
    fscanf(arquivo, "%d", &numVertices); //

    return numVertices;
    
}
    

int* Le_arquivo(char* file_name)

   
{
    FILE *arquivo;
    arquivo = fopen(file_name, "r");

    if (arquivo == NULL)
    {
        printf("\nERRO ");
        exit(1);
    }

    int l1,valores,numVertices = TamVetor(file_name);

    fscanf(arquivo, "%d", &l1); 
   

    int* guarda_linhas = (int*)malloc(sizeof (int));

    for (int j = 0; j < numVertices; j++)
    {
            fscanf(arquivo, "%d", &valores);          
         
            guarda_linhas[j] = valores;
            
        
    }

    fclose(arquivo);

    


    return guarda_linhas; 
}







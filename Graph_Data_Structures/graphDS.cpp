#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    int weight;
    struct node * next;
}*head;

struct Graph{
    int gNumber;
    struct node * v;
    struct Graph *next;
}*gHead;

void addToGraphList(){
    struct Graph * gTemp = (Graph *)malloc(sizeof(Graph));
    
    gTemp->v = NULL;
    gTemp->next = NULL;
    gTemp->gNumber = NULL;

    if(!gHead){
        gHead = gTemp;
        gHead->gNumber = 1;
        return;
    }

    struct Graph * gT;

    gT = gHead;

    while(gT->next != NULL){
        gT = gT->next;
    }
    gTemp->gNumber = gT->gNumber + 1;
    gT->next = gTemp;
    
    return;

}

void addToNodeList(int data, int weight, struct Graph * gTA){

    struct node* temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->weight = weight;
    temp->next = NULL;

    struct node * start = gTA->v;

    if(!start){
        start = temp;
        gTA->v = start;
        return;
    }

    if(!start->next){
        start->next = temp;
        return;
    }

    struct node * t;
    t = start;

    while(t->next != NULL){
        t = t->next;
    }

    t->next = temp;
    return;
}

void listAdjacencyList(struct Graph * temp){
    printf("%d\t", temp->gNumber);
    struct node * start = temp->v;
    
    while(start){
        printf("To = %d Weight = %d\t", start->data, start->weight);
        start = start->next;
    }
    printf("\n");
}


void listFullAdjacencyList(){
    struct Graph * gTemp = gHead;
        
        while(gTemp){
            listAdjacencyList(gTemp);
            gTemp = gTemp->next;
        }
}

void AdjacencyList(){
    int nodeCount, edgeCount;

    FILE * fp = fopen("graph.txt", "r");

    fscanf(fp, "%d %d", &nodeCount, &edgeCount);

    int n1, n2, w;
    
    for(int i = 0; i < nodeCount; i++){
        addToGraphList();
    }

    while(!feof(fp)){
        fscanf(fp, "%d %d %d\n", &n1, &n2, &w);
        struct Graph * gT = gHead;

        while(gT->gNumber != n1){
            if(!gT) {
                printf("404");
                return;
            }
            gT = gT->next;
        }
        addToNodeList(n2,w,gT);
    }    
    fclose(fp);
}

void AdjacencyMatrix(){
    int nodeCount, edgeCount;

    FILE * fp = fopen("graph.txt", "r");
    fscanf(fp, "%d %d", &nodeCount, &edgeCount);

    int adj[nodeCount][nodeCount];
    int n1, n2, w;

    for(int i = 0; i < nodeCount; i++){
            for(int j = 0; j < nodeCount; j++){
                adj[i][j] = 0;
            }
    }

    while(!feof(fp)){

        fscanf(fp, "%d %d %d\n", &n1, &n2, &w);
        adj[n1-1][n2-1] = w;

    }    
    fclose(fp);
    
    for(int i = 0; i < nodeCount; i++){
        for(int j = 0; j < nodeCount; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
}

void createAdjacencyMatrix(int nodeCount, int edgeCount){
    int adj[nodeCount][nodeCount];
    srand(time(NULL));
    for(int i = 0; i < nodeCount; i++){
            for(int j = 0; j < nodeCount; j++){
                adj[i][j] = 0;
            }
    }

    for(int i = 0; i < nodeCount; i++){
        int connectionCount = (rand()%edgeCount)%nodeCount;
        edgeCount -= connectionCount;
        for(int j = 0; j < connectionCount; j++){
            int prob = rand()%100;
            // %50 probability to have connections
            if(prob <= 50){
                int weight = rand()%10;
                adj[i][j] = weight;
            }else{
                edgeCount++;
            }
        }
    }

    for(int i = 0; i < nodeCount; i++){
        for(int j = 0; j < nodeCount; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void createAdjacencyList(int nodeCount, int edgeCount){
    srand(time(NULL));

    
    for(int i = 0; i < nodeCount; i++){
        addToGraphList();
    }

    struct Graph * gT = gHead;

    for(int i = 0; i < nodeCount; i++){
        int connectionCount = (rand()%edgeCount);
        printf("\n%d. Current Edge Count = %d \t Current connectionCount = %d",i, edgeCount, connectionCount);
        
        
        for(int j = 0; j < connectionCount; j++){
            if(i != j){
                int prob = rand()%100;
                // %60 probability to have connections
                if(prob <= 60){
                    int weight = rand()%10 +1 ;
                    addToNodeList(j+1, weight, gT);
                    edgeCount--;
                }
            }
        }
        gT = gT->next;
           
    }
}

void createGraph(){
    int nodeCount = 5, edgeCount = 7, method = 2;
    
    printf("Node Count: ");
    scanf("%d", &nodeCount);
    
    printf("Edge Count: ");
    scanf("%d", &edgeCount);

    printf("1-) Adjacency Matrix\n");
    printf("2-) Adjacency List\n");
    scanf("%d", &method);
    

    if(method == 1){
        createAdjacencyMatrix(nodeCount, edgeCount);
    }else if(method == 2){
        createAdjacencyList(nodeCount, edgeCount);
        listFullAdjacencyList();
    }
}

int main()  {
    createGraph();
    
    
    return 0;
}

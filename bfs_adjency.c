#include <stdio.h>
#include <stdlib.h>
// bfs using adjecency list
int size = 3;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNOde = (struct Node *)malloc(sizeof(struct Node));
    newNOde->next = NULL;
    newNOde->data = data;
    return newNOde;
}

struct Node* addConnection(struct Node *head, int data)
{
    if (head == NULL)
    {
        head = createNode(data);
    }
    else
    {

        struct Node *p = head;
        while (p->next)
        {
            p = p->next;
        }

        p->next = createNode(data);
    }
    return head;
}
int findidx(struct Node* nodes[ ] , int target){
    for(int i =0;i<size;i++){
        if(nodes[i]->data==target){
            return i;
        }
    }
    return -1;
}
void dfsutil(struct Node * nodes[], int startnode , int visited[]){
    printf("%d ",startnode);
    visited[startnode]=1;
    struct Node* curnode= nodes[findidx(nodes,startnode)];
    curnode=curnode->next;    
    while(curnode){
       if(visited[curnode->data]!=1) dfsutil(nodes,curnode->data,visited);
        curnode=curnode->next;
    }
}
void dfs(struct Node *nodes[], int startNode){

    int j = findidx(nodes,startNode);
    if(j==-1){
        printf("invalid start node\n");
    
    }
    int visited[100]={-1};
        for (int i = 0; i < 100; i++)
        {
            visited[i] = -1;
        }

  dfsutil(nodes,startNode,visited);
}
void bfs(struct Node *nodes[], int startNode)
{
    int j = -1;
    for (int i = 0; i < size; i++)
    {
        if (nodes[i]->data == startNode)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        printf("invalid start node \n");
    }
    else
    {
        int visited[100]={-1};
        for (int i = 0; i < 100; i++)
        {
            visited[i] = -1;
        }

        int queue[100];
        int front =0;
        int rear=0;
        queue[rear++]=startNode;
        while(front<rear){
            int u = queue[front++];
            if(visited[u]==1) continue; 
            printf("%d ",u);
            visited[u]=1;

            int curidx =findidx(nodes,u);
            struct Node* cur = nodes[curidx]->next;
            while(cur){
               if(visited[cur->data]!=1) queue[rear++]=cur->data;
               visited[cur->data]=1;
                cur=cur->next;
            }
        }
    }
    printf("\n");
}
int main()
{

    printf("enter the number of nodes in graph \n");
    scanf("%d", &size);
    struct Node *nodes[size];

    for (int i = 0; i < size; i++)
    {
        printf("enter the data for this node \n");
        int m;
        scanf("%d", &m);
        nodes[i] = createNode(m);
    }
    printf("now enter all the connections \n");
    for (int i = 0; i < size; i++)
    {
        printf("enter connections for node with data %d \n", nodes[i]->data);
        while (1)
        {
            int m;
            printf("enter the node it connects to -1 to stop\n");
            scanf("%d", &m);
            if (m == -1)
                break;
            nodes[i]= addConnection(nodes[i], m);
        }
    }
    printf("bfs :");
    bfs(nodes,0);
    printf("\bdfs: ");
    dfs(nodes,0);

}

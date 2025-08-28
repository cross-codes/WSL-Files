#include <stdio.h>
#include <stdlib.h>
typedef enum color
{
    WHITE,
    GREY,
    BLACK
} color;

// Graph Node
typedef struct graph_node
{
    int data;
    color c;
    int d;
    int f;
} graph_node;

// Graph
typedef struct Graph
{
    int V;
    int E;
    int **adjacency_matrix;
    graph_node *vertices;
} Graph;

Graph *get_graph(int V, int E)
{
    // As in previous tasks
}

void add_edge_adj_matrix(Graph *G, int u, int v)
{
    // As in previous tasks
}

/* 
    Recursive DFS with time stamps as given in CLRS
*/
int time = 0;
void recDFS(Graph *G)
{
    // As in task 4
}

void recDFSVisit(Graph *G, int u)
{
    // As in task 4 (Print the visited vertex as well)
}

Graph *get_transpose(Graph *G)
{
    // The transpose of a graph is a graph with the same vertices but with the direction of all edges reversed
}

int strongly_connected_components(Graph *G)
{
    time = 0;
    printf("Computing strongly connected components\n");
    printf("Running DFS on the original graph\n");
    recDFS(G);
    printf("\n");
    graph_node descending_f_indices[G->V];
    for (int i = 0; i < G->V; i++)
    {
        descending_f_indices[i].data = i;
        descending_f_indices[i].f = G->vertices[i].f;
    }
    // Sort the vertices in descending order of f
    for (int i = 0; i < G->V; i++)
    {
        for (int j = i + 1; j < G->V; j++)
        {
            if (descending_f_indices[i].f < descending_f_indices[j].f)
            {
                graph_node temp = descending_f_indices[i];
                descending_f_indices[i] = descending_f_indices[j];
                descending_f_indices[j] = temp;
            }
        }
    }

    // Print descending_f_indices
    printf("Descending f indices: ");
    for (int i = 0; i < G->V; i++)
    {
        printf("%d ", descending_f_indices[i].data);
    }
    
    Graph *Gt = get_transpose(G);
    for (int i = 0; i < G->V; i++)
    {
        Gt->vertices[i].c = WHITE;
    }

    int num_scc = 0;
    time = 0;
    printf("\n");
    for (int i = 0; i < G->V; i++)
    {
        if (Gt->vertices[descending_f_indices[i].data].c == WHITE)
        {
            num_scc++;
            printf("SCC %d: ", num_scc);
            recDFSVisit(Gt, descending_f_indices[i].data);
            printf("\n");
        }
    }
    return num_scc;
}

// int weakly_connected_components(Graph *G) // Implement after testing strongly_connected_components
// {
//     // TODO: Implement this function
// }

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("input4.txt", "r");
    int V, E;
    fscanf(fp, "%d", &V);
    fscanf(fp, "%d", &E);
    struct Graph *G = get_graph(V, E);
    for (int i = 0; i < E; i++) 
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        add_edge_adj_matrix(G, u, v);
    }
    fclose(fp);
    // Number of strongly connected components
    printf("Number of strongly connected components: %d\n", strongly_connected_components(G));

    // Number of weakly connected components.
    // printf("Number of weakly connected components: %d\n", weakly_connected_components(G));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
        int n;
        struct node* next;
} node;
int * g[10005];
int t;
int visited[10005];

int col[10005];
int fin[10005];
int cur;
int flag;

int nd_count[10005];
void explore(int n){

        visited[n] = 1;
        col[n] = 1;
        int i;
        for( i = nd_count[n] -1; i >= 0; i--){
                if (!visited[g[n][i]])
                        explore(g[n][i]);
                if (col[g[n][i]] == 1){
                        //    cout << "herE" << endl;
                        flag = 1;
                }
                if (flag)
                        return;
        }
        col[n] = 2;

        
        fin[cur--] = n;
        return;               
}
int n;
void dfs(){
        cur = n;
        int i;
        for(i = n ; i > 0; i--){
                if (!visited[i])
                        explore(i);
                if (flag)
                        return;
        }
        return;
}
int current_idx[10005];
int li_cnt[10005];
node* li[10005];
node comp[1000006];
        
        
int main()
{
   freopen("spoj.txt", "r", stdin);
        int m;
        scanf("%d %d", &n, &m);
        int i;
        for( i = 1; i <= m; i++){
                int x,y;
                scanf("%d %d", &x, &y);
                comp[i].n = x;
                comp[i].next = li[y];
                li[y] = &comp[i];

                nd_count[x]++;
        }
        for( i = 1; i <= n; i++)
                g[i] = malloc(sizeof(int)*nd_count[i]);;
                
        for( i = 1; i <= n; i++){
                node * pt = li[i];
                while (pt != 0){
                        g[pt->n][current_idx[pt->n]++] = i;
                        pt = pt->next;
                }
                        
                
        }
        
        
        dfs();
        if (flag == 1){
                printf("Sandro fails.\n");
                return 0;
        }

        for( i = 1; i < n; i++)
                printf("%d ", fin[i]);
        printf("%d\n", fin[n]);
        return 0;
}
        


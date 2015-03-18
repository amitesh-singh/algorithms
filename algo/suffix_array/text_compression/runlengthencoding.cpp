#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

//run - length  encoding algo
char *runlength_encode(char *T)
{
    int n = strlen(T);
    char *dest = (char *)malloc(2*sizeof(char)*n+ 1);
    memset(dest,0,2*n);
    int k = 0;
    char buff[10];
    for(int i=0;i<n;++i)
    {
        int rlen = 1;
        dest[k++] = T[i];
        while(T[i] == T[i+1])
        {
            rlen++;
            i++;
        }
        if(rlen == 0)
            continue;
        sprintf(buff,"%d",rlen);
        for(int j=0;j<strlen(buff);++j)
        {
            dest[k++] = buff[j];
        }
        //k+=strlen(buff);
    }
    return dest;
}


//run-length - decoding
char *runlenth_decode(char *T)
{
    cout << "decode:" << T << endl;
    int n = strlen(T);
    char *dest = (char *)malloc(2*n+1);
    memset(dest,0,2*n+1);
    char buff[10];
    

    int i =0;
    int k = 0;
    char char_val;
    int buff_i = 0;
    while(i<n)
    {
        memset(buff,0,10);
        bool flag = isdigit(T[i]);
        if(!flag)
        {
            char_val = T[i];
            dest[k++] = T[i];
            i++;
            buff_i = 0;
        }
        else
        {
            do
            {
                buff[buff_i++] = T[i];
                i++;
            }while(isdigit(T[i]));
            int next_k = atoi(buff);
            for(int l=1;l<next_k;l++)
            {
                dest[k++] = char_val;
            }

        }
    }
    return dest;
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        cerr << argv[0] << " <string>\n";
        exit(-1);
    }

    char *out = runlength_encode(argv[1]);
    cout << out << endl;
    char *org = runlenth_decode(out);
    cout << org << endl;
    free(out);
    free(org);

    return 0;
}

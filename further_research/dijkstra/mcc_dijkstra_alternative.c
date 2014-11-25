struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
struct _IO_FILE;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int sys_nerr;
extern const char *const sys_errlist[];
static __inline unsigned int __bswap_32(unsigned int __bsx)
{
  return __builtin_bswap32(__bsx);
}
typedef unsigned long int __uint64_t;
static __inline __uint64_t __bswap_64(__uint64_t __bsx)
{
  return __builtin_bswap64(__bsx);
}
int n;
int *dist;
typedef struct _IO_FILE FILE;
FILE *input_file;
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm("""__isoc99_fscanf");
void read_graph(int *g)
{
  int i;
  int j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          fscanf(input_file, "%d", &g[i * n + j]);
        }
    }
}
extern int printf(const char *__restrict __format, ...);
void write_graph(int *g)
{
  int i;
  int j;
  for (i = 0; i < n; ++i)
    {
      for (j = 0; j < n; ++j)
        {
          printf("%d ", g[i * n + j]);
        }
      printf("\n");
    }
}
void print_path(int *prev, int end)
{
  printf("The path is: ");
  int aux = end;
  while (aux !=  -1)
    {
      printf("%d ", aux);
      aux = prev[aux];
    }
  printf("\n");
}
void Dijkstra(int *g, int start, int end, int *res, int *visited)
{
  if (start == end)
    {
      *res = 0;
      return ;
    }
  else
    {
      int i;
      visited[start] = 1;
      for (i = 0; i < n; i++)
        {
          if (!visited[i])
            {
              if (g[start * n + i])
                {
                  if (g[start * n + i] < dist[i])
                    {
                      dist[i] = g[start * n + i];
                    }
                  int aux = 2147483647;
                  Dijkstra(g, i, end, &aux, visited);
                  if (aux != 2147483647 && aux + g[start * n + i] < dist[i])
                    {
                      dist[i] = aux + g[start * n + i];
                    }
                }
              else
                {
                  int aux = 2147483647;
                  Dijkstra(g, i, end, &aux, visited);
                  if (aux != 2147483647 && aux < dist[i])
                    {
                      dist[i] = aux;
                    }
                }
            }
        }
    }
  *res = dist[end];
}
extern void exit(int __status) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__noreturn__));
extern int atoi(const char *__nptr) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
typedef unsigned long int size_t;
extern void *malloc(size_t __size) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__malloc__));
extern double omp_get_wtime(void);
extern void free(void *__ptr) __attribute__((__nothrow__)) __attribute__((__leaf__));
int main(int argc, char **argv)
{
  char *filename;
  int i;
  int start;
  int end;
  if (argc != 3)
    {
      printf("usage: %s filename size\n", argv[0]);
      exit(0);
    }
  else
    {
      n = atoi(argv[2]);
      filename = argv[1];
      input_file = fopen(filename, "r");
    }
  int *visited = (int *)malloc(n * sizeof(int));
  dist = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    {
      visited[i] = 0;
      dist[i] = 2147483647;
    }
  int *g = (int *)malloc(n * n * sizeof(int));
  read_graph(g);
  fscanf(input_file, "%d %d", &start, &end);
  dist[start] = 0;
  int res = 2147483647;
  int prev[n];
  double start_time = omp_get_wtime();
  Dijkstra(g, start, end, &res, visited);
  double end_time = omp_get_wtime();
  printf("Distance from %d to %d is %d.\n", start, end, res);
  printf("Time %f\n", end_time - start_time);
  free(g);
  free(visited);
}
typedef void nanos_init_func_t(void *);
struct  mcc_struct_anon_18
{
  nanos_init_func_t (*func);
  void *data;
};
typedef struct mcc_struct_anon_18 nanos_init_desc_t;
void nanos_omp_set_interface(void *);
__attribute__((weak)) __attribute__((section("nanos_init"))) nanos_init_desc_t __section__nanos_init = {.func = nanos_omp_set_interface, .data = (void *)0};

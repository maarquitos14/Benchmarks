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
struct  nanos_args_0_t
{
  int *g;
  int start;
  int end;
  int *res;
  int *visited;
};
enum mcc_enum_anon_5
{
  NANOS_OK = 0,
  NANOS_UNKNOWN_ERR = 1,
  NANOS_UNIMPLEMENTED = 2,
  NANOS_ENOMEM = 3,
  NANOS_INVALID_PARAM = 4
};
typedef enum mcc_enum_anon_5 nanos_err_t;
typedef unsigned int nanos_copy_id_t;
typedef void *nanos_wd_t;
extern nanos_err_t nanos_get_addr(nanos_copy_id_t copy_id, void **addr, nanos_wd_t cwd);
extern void nanos_handle_error(nanos_err_t err);
static void nanos_xlate_fun_dijkstraompmemoc_0(struct nanos_args_0_t *const arg, void *wd)
{
  {
    void *device_base_address;
    nanos_err_t err;
    device_base_address = 0;
    err = nanos_get_addr(0, &device_base_address, wd);
    if (err != NANOS_OK)
      {
        nanos_handle_error(err);
      }
    (*arg).res = (int *)device_base_address;
  }
}
extern nanos_err_t nanos_in_final(_Bool *result);
struct  mcc_struct_anon_16
{
  void (*outline)(void *);
};
typedef struct mcc_struct_anon_16 nanos_smp_args_t;
static void smp_ol_Dijkstra_1(struct nanos_args_0_t *const args);
struct  mcc_struct_anon_11
{
  _Bool mandatory_creation:1;
  _Bool tied:1;
  _Bool clear_chunk:1;
  _Bool reserved0:1;
  _Bool reserved1:1;
  _Bool reserved2:1;
  _Bool reserved3:1;
  _Bool reserved4:1;
};
typedef struct mcc_struct_anon_11 nanos_wd_props_t;
typedef unsigned long int size_t;
struct  nanos_const_wd_definition_tag
{
  nanos_wd_props_t props;
  size_t data_alignment;
  size_t num_copies;
  size_t num_devices;
  size_t num_dimensions;
  const char *description;
};
typedef struct nanos_const_wd_definition_tag nanos_const_wd_definition_t;
struct  mcc_struct_anon_15
{
  void *(*factory)(void *);
  void *arg;
};
typedef struct mcc_struct_anon_15 nanos_device_t;
struct  nanos_const_wd_definition_1
{
  nanos_const_wd_definition_t base;
  nanos_device_t devices[1];
};
extern void *nanos_smp_factory(void *args);
struct  mcc_struct_anon_12
{
  _Bool is_final:1;
  _Bool is_recover:1;
  _Bool reserved2:1;
  _Bool reserved3:1;
  _Bool reserved4:1;
  _Bool reserved5:1;
  _Bool reserved6:1;
  _Bool reserved7:1;
};
typedef struct mcc_struct_anon_12 nanos_wd_dyn_flags_t;
typedef void *nanos_thread_t;
struct  mcc_struct_anon_13
{
  int num_elements;
  void *identifier;
};
typedef struct mcc_struct_anon_13 nanos_wd_memo_info_t;
struct  mcc_struct_anon_14
{
  nanos_wd_dyn_flags_t flags;
  nanos_thread_t tie_to;
  int priority;
  nanos_wd_memo_info_t memo;
};
typedef struct mcc_struct_anon_14 nanos_wd_dyn_props_t;
struct mcc_struct_anon_4;
typedef struct mcc_struct_anon_4 nanos_copy_data_internal_t;
typedef nanos_copy_data_internal_t nanos_copy_data_t;
struct mcc_struct_anon_0;
typedef struct mcc_struct_anon_0 nanos_region_dimension_internal_t;
typedef void *nanos_wg_t;
extern nanos_err_t nanos_create_wd_compact(nanos_wd_t *wd, nanos_const_wd_definition_t *const_data, nanos_wd_dyn_props_t *dyn_props, size_t data_size, void **data, nanos_wg_t wg, nanos_copy_data_t **copies, nanos_region_dimension_internal_t **dimensions);
extern nanos_wd_t nanos_current_wd(void);
struct  mcc_struct_anon_0
{
  size_t size;
  size_t lower_bound;
  size_t accessed_length;
};
typedef nanos_region_dimension_internal_t nanos_region_dimension_t;
struct  mcc_struct_anon_1
{
  _Bool input:1;
  _Bool output:1;
  _Bool can_rename:1;
  _Bool concurrent:1;
  _Bool commutative:1;
};
typedef struct mcc_struct_anon_1 nanos_access_type_internal_t;
typedef long int ptrdiff_t;
struct  mcc_struct_anon_2
{
  void *address;
  nanos_access_type_internal_t flags;
  short int dimension_count;
  const nanos_region_dimension_internal_t *dimensions;
  ptrdiff_t offset;
};
typedef struct mcc_struct_anon_2 nanos_data_access_internal_t;
typedef nanos_data_access_internal_t nanos_data_access_t;
enum mcc_enum_anon_0
{
  NANOS_PRIVATE = 0,
  NANOS_SHARED = 1
};
typedef enum mcc_enum_anon_0 nanos_sharing_t;
struct  mcc_struct_anon_5
{
  _Bool input:1;
  _Bool output:1;
};
typedef unsigned long int uint64_t;
typedef unsigned int memory_space_id_t;
struct  mcc_struct_anon_4
{
  void *address;
  nanos_sharing_t sharing;
  struct mcc_struct_anon_5 flags;
  short int dimension_count;
  const nanos_region_dimension_internal_t *dimensions;
  ptrdiff_t offset;
  uint64_t host_base_address;
  memory_space_id_t host_region_id;
  _Bool remote_host;
};
typedef void (*nanos_translate_args_t)(void *, nanos_wd_t);
extern nanos_err_t nanos_set_translate_function(nanos_wd_t wd, nanos_translate_args_t translate_args);
typedef void *nanos_team_t;
extern nanos_err_t nanos_submit(nanos_wd_t wd, size_t num_data_accesses, nanos_data_access_t *data_accesses, nanos_team_t team);
extern nanos_err_t nanos_create_wd_and_run_compact(nanos_const_wd_definition_t *const_data, nanos_wd_dyn_props_t *dyn_props, size_t data_size, void *data, size_t num_data_accesses, nanos_data_access_t *data_accesses, nanos_copy_data_t *copies, nanos_region_dimension_internal_t *dimensions, nanos_translate_args_t translate_args);
extern nanos_err_t nanos_wg_wait_completion(nanos_wg_t wg, _Bool avoid_flush);
void Dijkstra(int *g, int start, int end, int *res, int *visited)
{
  int i;
  if (start == end)
    {
      *res = 0;
      return ;
    }
  for (i = 0; i < n; i++)
    {
      if (!visited[i] && g[end * n + i])
        {
          int aux = 2147483647;
          visited[i] = 1;
          {
            int *mcc_arg_0 = g;
            int mcc_arg_1 = start;
            int mcc_arg_2 = i;
            int *mcc_arg_3 = &aux;
            int *mcc_arg_4 = visited;
            {
              _Bool mcc_is_in_final;
              nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
              if (mcc_err_in_final != NANOS_OK)
                {
                  nanos_handle_error(mcc_err_in_final);
                }
              if (mcc_is_in_final)
                {
                  Dijkstra(g, start, i, &aux, visited);
                }
              else
                {
                  {
                    nanos_wd_dyn_props_t nanos_wd_dyn_props;
                    struct nanos_args_0_t *ol_args;
                    nanos_err_t err;
                    struct nanos_args_0_t imm_args;
                    static nanos_smp_args_t smp_ol_Dijkstra_1_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_0_t *))&smp_ol_Dijkstra_1};
                    static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_0_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_Dijkstra_1_args}}};
                    nanos_wd_dyn_props.tie_to = 0;
                    nanos_wd_dyn_props.priority = 0;
                    nanos_wd_dyn_props.flags.is_final = 0;
                    nanos_wd_dyn_props.memo.num_elements = n * n;
                    nanos_wd_dyn_props.memo.identifier = &Dijkstra;
                    ol_args = (struct nanos_args_0_t *)0;
                    nanos_wd_t nanos_wd_ = (void *)0;
                    nanos_copy_data_t *ol_copy_data = (nanos_copy_data_t *)0;
                    nanos_region_dimension_internal_t *ol_copy_dimensions = (nanos_region_dimension_internal_t *)0;
                    err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), (void **)&ol_args, nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
                    if (err != NANOS_OK)
                      {
                        nanos_handle_error(err);
                      }
                    nanos_region_dimension_t dimensions_0[1] = {[0] = {.size = sizeof(int), .lower_bound = 0, .accessed_length = sizeof(int)}};
                    nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_3, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                    ;
                    if (nanos_wd_ != (void *)0)
                      {
                        (*ol_args).g = mcc_arg_0;
                        (*ol_args).start = mcc_arg_1;
                        (*ol_args).end = mcc_arg_2;
                        (*ol_args).res = mcc_arg_3;
                        (*ol_args).visited = mcc_arg_4;
                        ol_copy_dimensions[0].size = 1 * sizeof(int);
                        ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                        ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                        ol_copy_data[0].sharing = NANOS_SHARED;
                        ol_copy_data[0].address = (void *)mcc_arg_3;
                        ol_copy_data[0].flags.input = 0;
                        ol_copy_data[0].flags.output = 1;
                        ol_copy_data[0].dimension_count = (short int)1;
                        ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                        ol_copy_data[0].offset = 0;
                        err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_dijkstraompmemoc_0);
                        if (err != NANOS_OK)
                          {
                            nanos_handle_error(err);
                          }
                        err = nanos_submit(nanos_wd_, 1, dependences, (void *)0);
                        if (err != NANOS_OK)
                          {
                            nanos_handle_error(err);
                          }
                      }
                    else
                      {
                        nanos_region_dimension_internal_t imm_copy_dimensions[1];
                        nanos_copy_data_t imm_copy_data[1];
                        imm_args.g = mcc_arg_0;
                        imm_args.start = mcc_arg_1;
                        imm_args.end = mcc_arg_2;
                        imm_args.res = mcc_arg_3;
                        imm_args.visited = mcc_arg_4;
                        imm_copy_dimensions[0].size = 1 * sizeof(int);
                        imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                        imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                        imm_copy_data[0].sharing = NANOS_SHARED;
                        imm_copy_data[0].address = (void *)mcc_arg_3;
                        imm_copy_data[0].flags.input = 0;
                        imm_copy_data[0].flags.output = 1;
                        imm_copy_data[0].dimension_count = (short int)1;
                        imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                        imm_copy_data[0].offset = 0;
                        err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_dijkstraompmemoc_0);
                        if (err != NANOS_OK)
                          {
                            nanos_handle_error(err);
                          }
                      }
                  }
                }
            }
          }
          {
            nanos_err_t err;
            nanos_wd_t nanos_wd_ = nanos_current_wd();
            err = nanos_wg_wait_completion(nanos_wd_, 0);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
          }
          visited[i] = 0;
          if (aux != 2147483647 && aux + g[end * n + i] < *res)
            {
              *res = aux + g[end * n + i];
            }
        }
    }
}
struct  nanos_args_1_t
{
  int *g;
  int start;
  int end;
  int *res;
  int *visited;
};
static void nanos_xlate_fun_dijkstraompmemoc_1(struct nanos_args_1_t *const arg, void *wd)
{
  {
    void *device_base_address;
    nanos_err_t err;
    device_base_address = 0;
    err = nanos_get_addr(0, &device_base_address, wd);
    if (err != NANOS_OK)
      {
        nanos_handle_error(err);
      }
    (*arg).res = (int *)device_base_address;
  }
}
extern void exit(int __status) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__noreturn__));
extern int atoi(const char *__nptr) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
extern void *malloc(size_t __size) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__malloc__));
extern double omp_get_wtime(void);
static void smp_ol_Dijkstra_3(struct nanos_args_1_t *const args);
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
  for (i = 0; i < n; i++)
    {
      visited[i] = 0;
    }
  int *g = (int *)malloc(n * n * sizeof(int));
  read_graph(g);
  fscanf(input_file, "%d %d", &start, &end);
  int res = 2147483647;
  int prev[n];
  double start_time = omp_get_wtime();
  {
    int *mcc_arg_7 = g;
    int mcc_arg_8 = start;
    int mcc_arg_9 = end;
    int *mcc_arg_10 = &res;
    int *mcc_arg_11 = visited;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          Dijkstra(g, start, end, &res, visited);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            struct nanos_args_1_t *ol_args;
            nanos_err_t err;
            struct nanos_args_1_t imm_args;
            static nanos_smp_args_t smp_ol_Dijkstra_3_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_1_t *))&smp_ol_Dijkstra_3};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_1_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_Dijkstra_3_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 0;
            nanos_wd_dyn_props.memo.num_elements = n * n;
            nanos_wd_dyn_props.memo.identifier = &Dijkstra;
            ol_args = (struct nanos_args_1_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            nanos_copy_data_t *ol_copy_data = (nanos_copy_data_t *)0;
            nanos_region_dimension_internal_t *ol_copy_dimensions = (nanos_region_dimension_internal_t *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), (void **)&ol_args, nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            nanos_region_dimension_t dimensions_0[1] = {[0] = {.size = sizeof(int), .lower_bound = 0, .accessed_length = sizeof(int)}};
            nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_10, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
            ;
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).g = mcc_arg_7;
                (*ol_args).start = mcc_arg_8;
                (*ol_args).end = mcc_arg_9;
                (*ol_args).res = mcc_arg_10;
                (*ol_args).visited = mcc_arg_11;
                ol_copy_dimensions[0].size = 1 * sizeof(int);
                ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                ol_copy_data[0].sharing = NANOS_SHARED;
                ol_copy_data[0].address = (void *)mcc_arg_10;
                ol_copy_data[0].flags.input = 0;
                ol_copy_data[0].flags.output = 1;
                ol_copy_data[0].dimension_count = (short int)1;
                ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                ol_copy_data[0].offset = 0;
                err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_dijkstraompmemoc_1);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
                err = nanos_submit(nanos_wd_, 1, dependences, (void *)0);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
            else
              {
                nanos_region_dimension_internal_t imm_copy_dimensions[1];
                nanos_copy_data_t imm_copy_data[1];
                imm_args.g = mcc_arg_7;
                imm_args.start = mcc_arg_8;
                imm_args.end = mcc_arg_9;
                imm_args.res = mcc_arg_10;
                imm_args.visited = mcc_arg_11;
                imm_copy_dimensions[0].size = 1 * sizeof(int);
                imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                imm_copy_data[0].sharing = NANOS_SHARED;
                imm_copy_data[0].address = (void *)mcc_arg_10;
                imm_copy_data[0].flags.input = 0;
                imm_copy_data[0].flags.output = 1;
                imm_copy_data[0].dimension_count = (short int)1;
                imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                imm_copy_data[0].offset = 0;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_dijkstraompmemoc_1);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
          }
        }
    }
  }
  {
    nanos_err_t err;
    nanos_wd_t nanos_wd_ = nanos_current_wd();
    err = nanos_wg_wait_completion(nanos_wd_, 0);
    if (err != NANOS_OK)
      {
        nanos_handle_error(err);
      }
  }
  double end_time = omp_get_wtime();
  printf("Distance from %d to %d is %d.\n", start, end, res);
  printf("Time %f\n", end_time - start_time);
  free(g);
  free(visited);
}
extern _Bool nanos_task_memoized(nanos_wd_t wd, void *id, int index);
extern void nanos_store_task(nanos_wd_t wd, void *id, int index);
static void smp_ol_Dijkstra_1_unpacked(int **const g, int *const start, int *const end, int **const res, int **const visited)
{
  {
    {
      _Bool is_memoized;
      is_memoized = nanos_task_memoized(nanos_current_wd(), (void *)&Dijkstra, n * (*start) + (*end));
      if (!is_memoized)
        {
          Dijkstra((*g), (*start), (*end), (*res), (*visited));
          nanos_store_task(nanos_current_wd(), (void *)&Dijkstra, n * (*start) + (*end));
        }
    }
  }
}
static void smp_ol_Dijkstra_1(struct nanos_args_0_t *const args)
{
  {
    smp_ol_Dijkstra_1_unpacked(&((*args).g), &((*args).start), &((*args).end), &((*args).res), &((*args).visited));
  }
}
static void smp_ol_Dijkstra_3_unpacked(int **const g, int *const start, int *const end, int **const res, int **const visited)
{
  {
    {
      _Bool is_memoized;
      is_memoized = nanos_task_memoized(nanos_current_wd(), (void *)&Dijkstra, n * (*start) + (*end));
      if (!is_memoized)
        {
          Dijkstra((*g), (*start), (*end), (*res), (*visited));
          nanos_store_task(nanos_current_wd(), (void *)&Dijkstra, n * (*start) + (*end));
        }
    }
  }
}
static void smp_ol_Dijkstra_3(struct nanos_args_1_t *const args)
{
  {
    smp_ol_Dijkstra_3_unpacked(&((*args).g), &((*args).start), &((*args).end), &((*args).res), &((*args).visited));
  }
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

static __inline unsigned int __bswap_32(unsigned int __bsx)
{
  return __builtin_bswap32(__bsx);
}
typedef unsigned long int __uint64_t;
static __inline __uint64_t __bswap_64(__uint64_t __bsx)
{
  return __builtin_bswap64(__bsx);
}
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
int N = 50;
int ori_n;
unsigned long long int res_size;
typedef unsigned long int size_t;
extern void *malloc(size_t __size) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__malloc__));
extern void *calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__malloc__));
extern size_t strlen(const char *__s) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__nonnull__(1, 2)));
extern void free(void *__ptr) __attribute__((__nothrow__)) __attribute__((__leaf__));
extern char *strcat(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__nonnull__(1, 2)));
void hanoi_serial(int n, int src, int dst, int tmp, char *res)
{
  if (n == 0)
    {
      *res = 0;
      return ;
    }
  char *hold = malloc(2 << (n - 1) * sizeof(char));
  hanoi_serial(n - 1, src, tmp, dst, hold);
  char *result = (char *)calloc(2 * (strlen(hold) + 1), sizeof(char));
  strcpy(result, hold);
  free(hold);
  char addend[2] = "0";
  addend[0] = (char)('0' + 3 * src + dst);
  strcat(result, addend);
  char *other = malloc(2 << (n - 1) * sizeof(char));
  hanoi_serial(n - 1, tmp, dst, src, other);
  strcat(result, other);
  free(other);
  strcpy(res, result);
  free(result);
}
enum mcc_enum_anon_5
{
  NANOS_OK = 0,
  NANOS_UNKNOWN_ERR = 1,
  NANOS_UNIMPLEMENTED = 2,
  NANOS_ENOMEM = 3,
  NANOS_INVALID_PARAM = 4
};
typedef enum mcc_enum_anon_5 nanos_err_t;
extern nanos_err_t nanos_in_final(_Bool *result);
extern void nanos_handle_error(nanos_err_t err);
struct  mcc_struct_anon_16
{
  void (*outline)(void *);
};
typedef struct mcc_struct_anon_16 nanos_smp_args_t;
struct  nanos_args_0_t
{
  int n;
  int src;
  int dst;
  int tmp;
  char *res;
};
static void smp_ol_hanoi_1(struct nanos_args_0_t *const args);
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
  int dimensions;
  int *dim_sizes;
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
typedef void *nanos_wd_t;
struct mcc_struct_anon_4;
typedef struct mcc_struct_anon_4 nanos_copy_data_internal_t;
typedef nanos_copy_data_internal_t nanos_copy_data_t;
struct mcc_struct_anon_0;
typedef struct mcc_struct_anon_0 nanos_region_dimension_internal_t;
typedef void *nanos_wg_t;
extern nanos_err_t nanos_create_wd_compact(nanos_wd_t *wd, nanos_const_wd_definition_t *const_data, nanos_wd_dyn_props_t *dyn_props, size_t data_size, void **data, nanos_wg_t wg, nanos_copy_data_t **copies, nanos_region_dimension_internal_t **dimensions);
extern nanos_wd_t nanos_current_wd(void);
struct mcc_struct_anon_2;
typedef struct mcc_struct_anon_2 nanos_data_access_internal_t;
typedef nanos_data_access_internal_t nanos_data_access_t;
typedef void *nanos_team_t;
extern nanos_err_t nanos_submit(nanos_wd_t wd, size_t num_data_accesses, nanos_data_access_t *data_accesses, nanos_team_t team);
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
typedef void (*nanos_translate_args_t)(void *, nanos_wd_t);
extern nanos_err_t nanos_create_wd_and_run_compact(nanos_const_wd_definition_t *const_data, nanos_wd_dyn_props_t *dyn_props, size_t data_size, void *data, size_t num_data_accesses, nanos_data_access_t *data_accesses, nanos_copy_data_t *copies, nanos_region_dimension_internal_t *dimensions, nanos_translate_args_t translate_args);
struct  nanos_args_1_t
{
  int n;
  int src;
  int dst;
  int tmp;
  char *res;
};
static void smp_ol_hanoi_3(struct nanos_args_1_t *const args);
extern nanos_err_t nanos_wg_wait_completion(nanos_wg_t wg, _Bool avoid_flush);
void hanoi(int n, int src, int dst, int tmp, char *res)
{
  if (n == 0)
    {
      *res = 0;
      return ;
    }
  char *hold = malloc(2 << (n - 1) * sizeof(char));
  {
    int mcc_arg_0 = n - 1;
    int mcc_arg_1 = src;
    int mcc_arg_2 = tmp;
    int mcc_arg_3 = dst;
    char *mcc_arg_4 = hold;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          hanoi(n - 1, src, tmp, dst, hold);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            struct nanos_args_0_t *ol_args;
            nanos_err_t err;
            struct nanos_args_0_t imm_args;
            nanos_data_access_t dependences[1];
            static nanos_smp_args_t smp_ol_hanoi_1_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_0_t *))&smp_ol_hanoi_1};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_0_t), .num_copies = 0, .num_devices = 1, .num_dimensions = 0, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_hanoi_1_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 0;
            nanos_wd_dyn_props.memo.num_elements = 0;
            nanos_wd_dyn_props.memo.identifier = 0;
            nanos_wd_dyn_props.memo.dimensions = 0;
            nanos_wd_dyn_props.memo.dim_sizes = 0;
            ol_args = (struct nanos_args_0_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), (void **)&ol_args, nanos_current_wd(), (nanos_copy_data_t **)0, (nanos_region_dimension_internal_t **)0);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).n = mcc_arg_0;
                (*ol_args).src = mcc_arg_1;
                (*ol_args).dst = mcc_arg_2;
                (*ol_args).tmp = mcc_arg_3;
                (*ol_args).res = mcc_arg_4;
                err = nanos_submit(nanos_wd_, 0, dependences, (void *)0);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
            else
              {
                imm_args.n = mcc_arg_0;
                imm_args.src = mcc_arg_1;
                imm_args.dst = mcc_arg_2;
                imm_args.tmp = mcc_arg_3;
                imm_args.res = mcc_arg_4;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), &imm_args, 0, dependences, (nanos_copy_data_t *)0, (nanos_region_dimension_internal_t *)0, (void (*)(void *, nanos_wd_t))0);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
          }
        }
    }
  }
  char addend[2] = "0";
  addend[0] = (char)('0' + 3 * src + dst);
  char *other = malloc(2 << (n - 1) * sizeof(char));
  {
    int mcc_arg_7 = n - 1;
    int mcc_arg_8 = tmp;
    int mcc_arg_9 = dst;
    int mcc_arg_10 = src;
    char *mcc_arg_11 = other;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          hanoi(n - 1, tmp, dst, src, other);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            struct nanos_args_1_t *ol_args;
            nanos_err_t err;
            struct nanos_args_1_t imm_args;
            nanos_data_access_t dependences[1];
            static nanos_smp_args_t smp_ol_hanoi_3_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_1_t *))&smp_ol_hanoi_3};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_1_t), .num_copies = 0, .num_devices = 1, .num_dimensions = 0, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_hanoi_3_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 0;
            nanos_wd_dyn_props.memo.num_elements = 0;
            nanos_wd_dyn_props.memo.identifier = 0;
            nanos_wd_dyn_props.memo.dimensions = 0;
            nanos_wd_dyn_props.memo.dim_sizes = 0;
            ol_args = (struct nanos_args_1_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), (void **)&ol_args, nanos_current_wd(), (nanos_copy_data_t **)0, (nanos_region_dimension_internal_t **)0);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).n = mcc_arg_7;
                (*ol_args).src = mcc_arg_8;
                (*ol_args).dst = mcc_arg_9;
                (*ol_args).tmp = mcc_arg_10;
                (*ol_args).res = mcc_arg_11;
                err = nanos_submit(nanos_wd_, 0, dependences, (void *)0);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
            else
              {
                imm_args.n = mcc_arg_7;
                imm_args.src = mcc_arg_8;
                imm_args.dst = mcc_arg_9;
                imm_args.tmp = mcc_arg_10;
                imm_args.res = mcc_arg_11;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), &imm_args, 0, dependences, (nanos_copy_data_t *)0, (nanos_region_dimension_internal_t *)0, (void (*)(void *, nanos_wd_t))0);
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
  char *result = (char *)calloc(2 * (strlen(hold) + 1), sizeof(char));
  strcpy(result, hold);
  strcat(result, addend);
  strcat(result, other);
  strcpy(res, result);
  free(hold);
  free(other);
  free(result);
}
extern int printf(const char *__restrict __format, ...);
extern void exit(int __status) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__noreturn__));
extern int atoi(const char *__nptr) __attribute__((__nothrow__)) __attribute__((__leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern double omp_get_wtime(void);
struct  nanos_args_2_t
{
  int n;
  int src;
  int dst;
  int tmp;
  char *res;
};
static void smp_ol_hanoi_5(struct nanos_args_2_t *const args);
extern int sprintf(char *__restrict __s, const char *__restrict __format, ...) __attribute__((__nothrow__));
typedef struct _IO_FILE FILE;
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
extern int fprintf(FILE *__restrict __stream, const char *__restrict __format, ...);
extern int fclose(FILE *__stream);
int main(int argc, char **argv)
{
  int n;
  int src;
  int dst;
  int tmp;
  char output_file[20U];
  FILE *out;
  if (argc != 5)
    {
      printf("Usage: %s n src dst tmp\n", argv[0]);
      exit(0);
    }
  n = atoi(argv[1]);
  ori_n = n;
  src = atoi(argv[2]);
  dst = atoi(argv[3]);
  tmp = atoi(argv[4]);
  res_size = (unsigned long long int)2 << n;
  char *res = (char *)calloc(res_size, sizeof(char));
  double start = omp_get_wtime();
  {
    int mcc_arg_14 = n;
    int mcc_arg_15 = src;
    int mcc_arg_16 = dst;
    int mcc_arg_17 = tmp;
    char *mcc_arg_18 = res;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          hanoi(n, src, dst, tmp, res);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            struct nanos_args_2_t *ol_args;
            nanos_err_t err;
            struct nanos_args_2_t imm_args;
            nanos_data_access_t dependences[1];
            static nanos_smp_args_t smp_ol_hanoi_5_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_2_t *))&smp_ol_hanoi_5};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_2_t), .num_copies = 0, .num_devices = 1, .num_dimensions = 0, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_hanoi_5_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 0;
            nanos_wd_dyn_props.memo.num_elements = 0;
            nanos_wd_dyn_props.memo.identifier = 0;
            nanos_wd_dyn_props.memo.dimensions = 0;
            nanos_wd_dyn_props.memo.dim_sizes = 0;
            ol_args = (struct nanos_args_2_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_2_t), (void **)&ol_args, nanos_current_wd(), (nanos_copy_data_t **)0, (nanos_region_dimension_internal_t **)0);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).n = mcc_arg_14;
                (*ol_args).src = mcc_arg_15;
                (*ol_args).dst = mcc_arg_16;
                (*ol_args).tmp = mcc_arg_17;
                (*ol_args).res = mcc_arg_18;
                err = nanos_submit(nanos_wd_, 0, dependences, (void *)0);
                if (err != NANOS_OK)
                  {
                    nanos_handle_error(err);
                  }
              }
            else
              {
                imm_args.n = mcc_arg_14;
                imm_args.src = mcc_arg_15;
                imm_args.dst = mcc_arg_16;
                imm_args.tmp = mcc_arg_17;
                imm_args.res = mcc_arg_18;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_2_t), &imm_args, 0, dependences, (nanos_copy_data_t *)0, (nanos_region_dimension_internal_t *)0, (void (*)(void *, nanos_wd_t))0);
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
  double end = omp_get_wtime();
  sprintf(output_file, "output_omp_%d.txt", n);
  out = fopen(output_file, "w+");
  fprintf(out, "hanoi(%d,%d,%d,%d)=%s\n", n, src, dst, tmp, res);
  fclose(out);
  printf("time %f\n", end - start);
  free(res);
}
static void smp_ol_hanoi_1_unpacked(int *const n, int *const src, int *const dst, int *const tmp, char **const res)
{
  {
    hanoi((*n), (*src), (*dst), (*tmp), (*res));
  }
}
static void smp_ol_hanoi_1(struct nanos_args_0_t *const args)
{
  {
    smp_ol_hanoi_1_unpacked(&((*args).n), &((*args).src), &((*args).dst), &((*args).tmp), &((*args).res));
  }
}
static void smp_ol_hanoi_3_unpacked(int *const n, int *const src, int *const dst, int *const tmp, char **const res)
{
  {
    hanoi((*n), (*src), (*dst), (*tmp), (*res));
  }
}
static void smp_ol_hanoi_3(struct nanos_args_1_t *const args)
{
  {
    smp_ol_hanoi_3_unpacked(&((*args).n), &((*args).src), &((*args).dst), &((*args).tmp), &((*args).res));
  }
}
static void smp_ol_hanoi_5_unpacked(int *const n, int *const src, int *const dst, int *const tmp, char **const res)
{
  {
    hanoi((*n), (*src), (*dst), (*tmp), (*res));
  }
}
static void smp_ol_hanoi_5(struct nanos_args_2_t *const args)
{
  {
    smp_ol_hanoi_5_unpacked(&((*args).n), &((*args).src), &((*args).dst), &((*args).tmp), &((*args).res));
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
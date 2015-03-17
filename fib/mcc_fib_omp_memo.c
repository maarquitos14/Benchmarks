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
int ori_n;
int final = 0;
void fib_mcc_serial(int n, int *res)
{
  if (n < 2)
    {
      *res = n;
    }
  else
    {
      int res1 = 0;
      int res2 = 0;
      fib_mcc_serial(n - 1, &res1);
      fib_mcc_serial(n - 2, &res2);
      *res = res1 + res2;
    }
}
struct  nanos_args_0_t
{
  int n;
  int *res;
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
static void nanos_xlate_fun_fibompmemoc_0(struct nanos_args_0_t *const arg, void *wd)
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
struct  nanos_args_1_t
{
  int n;
  int *res;
};
static void nanos_xlate_fun_fibompmemoc_1(struct nanos_args_1_t *const arg, void *wd)
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
static void smp_ol_fib_1(struct nanos_args_0_t *const args);
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
  unsigned int num_dimensions;
  unsigned int *dimensions;
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
  nanos_region_dimension_internal_t *dimensions;
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
static void smp_ol_fib_3(struct nanos_args_1_t *const args);
extern nanos_err_t nanos_wg_wait_completion(nanos_wg_t wg, _Bool avoid_flush);
void fib(int n, int *res)
{
  if (n < 2)
    {
      *res = n;
    }
  else
    {
      int res1 = 0;
      int res2 = 0;
      {
        int mcc_arg_0 = n - 1;
        int *mcc_arg_1 = &res1;
        {
          _Bool mcc_is_in_final;
          nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
          if (mcc_err_in_final != NANOS_OK)
            {
              nanos_handle_error(mcc_err_in_final);
            }
          if (mcc_is_in_final)
            {
              fib_mcc_serial(n - 1, &res1);
            }
          else
            {
              {
                nanos_wd_dyn_props_t nanos_wd_dyn_props;
                int memo_dimensions[1];
                struct nanos_args_0_t *ol_args;
                nanos_err_t err;
                struct nanos_args_0_t imm_args;
                static nanos_smp_args_t smp_ol_fib_1_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_0_t *))&smp_ol_fib_1};
                static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_0_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_fib_1_args}}};
                nanos_wd_dyn_props.tie_to = 0;
                nanos_wd_dyn_props.priority = 0;
                nanos_wd_dyn_props.flags.is_final = 1;
                memo_dimensions[0] = mcc_arg_0 + 1;
                nanos_wd_dyn_props.memo.num_dimensions = 1;
                nanos_wd_dyn_props.memo.dimensions = memo_dimensions;
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
                nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_1, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                ;
                if (nanos_wd_ != (void *)0)
                  {
                    (*ol_args).n = mcc_arg_0;
                    (*ol_args).res = mcc_arg_1;
                    ol_copy_dimensions[0].size = 1 * sizeof(int);
                    ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    ol_copy_data[0].sharing = NANOS_SHARED;
                    ol_copy_data[0].address = (void *)mcc_arg_1;
                    ol_copy_data[0].flags.input = 0;
                    ol_copy_data[0].flags.output = 1;
                    ol_copy_data[0].dimension_count = (short int)1;
                    ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                    ol_copy_data[0].offset = 0;
                    err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_0);
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
                    imm_args.n = mcc_arg_0;
                    imm_args.res = mcc_arg_1;
                    imm_copy_dimensions[0].size = 1 * sizeof(int);
                    imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    imm_copy_data[0].sharing = NANOS_SHARED;
                    imm_copy_data[0].address = (void *)mcc_arg_1;
                    imm_copy_data[0].flags.input = 0;
                    imm_copy_data[0].flags.output = 1;
                    imm_copy_data[0].dimension_count = (short int)1;
                    imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                    imm_copy_data[0].offset = 0;
                    err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_0);
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
        int mcc_arg_4 = n - 2;
        int *mcc_arg_5 = &res2;
        {
          _Bool mcc_is_in_final;
          nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
          if (mcc_err_in_final != NANOS_OK)
            {
              nanos_handle_error(mcc_err_in_final);
            }
          if (mcc_is_in_final)
            {
              fib_mcc_serial(n - 2, &res2);
            }
          else
            {
              {
                nanos_wd_dyn_props_t nanos_wd_dyn_props;
                int memo_dimensions[1];
                struct nanos_args_1_t *ol_args;
                nanos_err_t err;
                struct nanos_args_1_t imm_args;
                static nanos_smp_args_t smp_ol_fib_3_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_1_t *))&smp_ol_fib_3};
                static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_1_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_fib_3_args}}};
                nanos_wd_dyn_props.tie_to = 0;
                nanos_wd_dyn_props.priority = 0;
                nanos_wd_dyn_props.flags.is_final = 1;
                memo_dimensions[0] = mcc_arg_4 + 1;
                nanos_wd_dyn_props.memo.num_dimensions = 1;
                nanos_wd_dyn_props.memo.dimensions = memo_dimensions;
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
                nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_5, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                ;
                if (nanos_wd_ != (void *)0)
                  {
                    (*ol_args).n = mcc_arg_4;
                    (*ol_args).res = mcc_arg_5;
                    ol_copy_dimensions[0].size = 1 * sizeof(int);
                    ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    ol_copy_data[0].sharing = NANOS_SHARED;
                    ol_copy_data[0].address = (void *)mcc_arg_5;
                    ol_copy_data[0].flags.input = 0;
                    ol_copy_data[0].flags.output = 1;
                    ol_copy_data[0].dimension_count = (short int)1;
                    ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                    ol_copy_data[0].offset = 0;
                    err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_1);
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
                    imm_args.n = mcc_arg_4;
                    imm_args.res = mcc_arg_5;
                    imm_copy_dimensions[0].size = 1 * sizeof(int);
                    imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    imm_copy_data[0].sharing = NANOS_SHARED;
                    imm_copy_data[0].address = (void *)mcc_arg_5;
                    imm_copy_data[0].flags.input = 0;
                    imm_copy_data[0].flags.output = 1;
                    imm_copy_data[0].dimension_count = (short int)1;
                    imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                    imm_copy_data[0].offset = 0;
                    err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_1);
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
      *res = res1 + res2;
    }
}
struct  nanos_args_2_t
{
  int n;
  int *res;
};
static void nanos_xlate_fun_fibompmemoc_2(struct nanos_args_2_t *const arg, void *wd)
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
extern int printf(const char *__restrict __format, ...);
extern void exit(int __status) __attribute__((__nothrow__)) __attribute__((__noreturn__));
extern int atoi(const char *__nptr) __attribute__((__nothrow__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern double omp_get_wtime(void);
static void smp_ol_fib_5(struct nanos_args_2_t *const args);
int main(int argc, char **argv)
{
  if (argc < 2)
    {
      printf("usage: %s n\n", argv[0]);
      exit(0);
    }
  int n = atoi(argv[1]);
  if (argc == 3)
    {
      final = atoi(argv[2]);
    }
  ori_n = n;
  int res = 0;
  double start = omp_get_wtime();
  {
    int mcc_arg_8 = n;
    int *mcc_arg_9 = &res;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          fib_mcc_serial(n, &res);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            int memo_dimensions[1];
            struct nanos_args_2_t *ol_args;
            nanos_err_t err;
            struct nanos_args_2_t imm_args;
            static nanos_smp_args_t smp_ol_fib_5_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_2_t *))&smp_ol_fib_5};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_2_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_fib_5_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 1;
            memo_dimensions[0] = mcc_arg_8 + 1;
            nanos_wd_dyn_props.memo.num_dimensions = 1;
            nanos_wd_dyn_props.memo.dimensions = memo_dimensions;
            ol_args = (struct nanos_args_2_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            nanos_copy_data_t *ol_copy_data = (nanos_copy_data_t *)0;
            nanos_region_dimension_internal_t *ol_copy_dimensions = (nanos_region_dimension_internal_t *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_2_t), (void **)&ol_args, nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            nanos_region_dimension_t dimensions_0[1] = {[0] = {.size = sizeof(int), .lower_bound = 0, .accessed_length = sizeof(int)}};
            nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_9, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
            ;
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).n = mcc_arg_8;
                (*ol_args).res = mcc_arg_9;
                ol_copy_dimensions[0].size = 1 * sizeof(int);
                ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                ol_copy_data[0].sharing = NANOS_SHARED;
                ol_copy_data[0].address = (void *)mcc_arg_9;
                ol_copy_data[0].flags.input = 0;
                ol_copy_data[0].flags.output = 1;
                ol_copy_data[0].dimension_count = (short int)1;
                ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                ol_copy_data[0].offset = 0;
                err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_2);
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
                imm_args.n = mcc_arg_8;
                imm_args.res = mcc_arg_9;
                imm_copy_dimensions[0].size = 1 * sizeof(int);
                imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                imm_copy_data[0].sharing = NANOS_SHARED;
                imm_copy_data[0].address = (void *)mcc_arg_9;
                imm_copy_data[0].flags.input = 0;
                imm_copy_data[0].flags.output = 1;
                imm_copy_data[0].dimension_count = (short int)1;
                imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                imm_copy_data[0].offset = 0;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_2_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_fibompmemoc_2);
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
  printf("fib(%d): %d, time, %f\n", n, res, end - start);
}
extern unsigned int *nanos_memo_get_dimensions(nanos_wd_t wd);
extern _Bool nanos_memo_task_memoized(nanos_wd_t wd, unsigned int index);
extern void nanos_memo_store_task(nanos_wd_t wd, unsigned int index);
static void smp_ol_fib_1_unpacked(int n, int *res)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), 0 + n);
      if (!is_memoized)
        {
          fib(n, res);
          nanos_memo_store_task(nanos_current_wd(), 0 + n);
        }
    }
  }
}
static void smp_ol_fib_1(struct nanos_args_0_t *const args)
{
  {
    smp_ol_fib_1_unpacked((*args).n, (*args).res);
  }
}
static void smp_ol_fib_3_unpacked(int n, int *res)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), 0 + n);
      if (!is_memoized)
        {
          fib(n, res);
          nanos_memo_store_task(nanos_current_wd(), 0 + n);
        }
    }
  }
}
static void smp_ol_fib_3(struct nanos_args_1_t *const args)
{
  {
    smp_ol_fib_3_unpacked((*args).n, (*args).res);
  }
}
static void smp_ol_fib_5_unpacked(int n, int *res)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), 0 + n);
      if (!is_memoized)
        {
          fib(n, res);
          nanos_memo_store_task(nanos_current_wd(), 0 + n);
        }
    }
  }
}
static void smp_ol_fib_5(struct nanos_args_2_t *const args)
{
  {
    smp_ol_fib_5_unpacked((*args).n, (*args).res);
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

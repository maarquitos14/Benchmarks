struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
struct _IO_FILE;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int sys_nerr;
typedef unsigned long int size_t;
extern const char *const sys_errlist[];
int n;
int final = 0;
int capacity = 400;
int *memo;
struct mcc_struct_anon_42;
typedef struct mcc_struct_anon_42 item_t;
struct  mcc_struct_anon_42
{
  int weight;
  int value;
};
typedef void *nanos_wd_t;
extern nanos_wd_t nanos_current_wd(void);
extern unsigned int *nanos_memo_get_dimensions(nanos_wd_t wd);
extern _Bool nanos_memo_task_memoized(nanos_wd_t wd, unsigned int index);
extern _Bool nanos_memo_task_memoized_in_final(nanos_wd_t wd, void * res, size_t size, unsigned int index);
extern void nanos_memo_store_task(nanos_wd_t wd, unsigned int index);
extern void nanos_memo_store_task_in_final(nanos_wd_t wd, void * res, size_t size, unsigned int index);
void optimal_mcc_serial(int weight, int idx, int *sol, const item_t *item)
{
    if ( idx < 0 || ( idx == 0 && weight == 0 ) )
    {
        *sol = 0;
        return ;
    }
    else
    {
        _Bool is_memoized;
        int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
        is_memoized = nanos_memo_task_memoized_in_final(nanos_current_wd(), sol, sizeof(*sol), (0 + idx) * memo_dimensions[1] + weight);
        if (!is_memoized)
        {
            *sol = 0;
            if (weight < item[idx].weight)
            {
                optimal_mcc_serial(weight, idx - 1, sol, item);
                nanos_memo_store_task_in_final(nanos_current_wd(), sol, sizeof(*sol), (0 + idx) * memo_dimensions[1] + weight);
                return ;
            }
            int v1 = 0;
            int v2 = 0;
            optimal_mcc_serial(weight, idx - 1, sol, item);
            v1 = *sol;
            if (weight - item[idx].weight >= 0)
            {
                optimal_mcc_serial(weight - item[idx].weight, idx - 1, sol, item);
                v2 = *sol;
            }
            v2 += item[idx].value;
            *sol = v1 >= v2 ? v1 : v2;
            nanos_memo_store_task_in_final(nanos_current_wd(), sol, sizeof(*sol), (0 + idx) * memo_dimensions[1] + weight);
        }
    }
}
struct  nanos_args_0_t
{
  int weight;
  int idx;
  int *sol;
  const item_t *item;
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
extern nanos_err_t nanos_get_addr(nanos_copy_id_t copy_id, void **addr, nanos_wd_t cwd);
extern void nanos_handle_error(nanos_err_t err);
static void nanos_xlate_fun_knapsackompmemoc_0(struct nanos_args_0_t *const arg, void *wd)
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
    (*arg).sol = (int *)device_base_address;
  }
}
struct  nanos_args_1_t
{
  int weight;
  int idx;
  int *sol;
  const item_t *item;
};
static void nanos_xlate_fun_knapsackompmemoc_1(struct nanos_args_1_t *const arg, void *wd)
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
    (*arg).sol = (int *)device_base_address;
  }
}
struct  nanos_args_2_t
{
  int weight;
  int idx;
  int *sol;
  const item_t *item;
};
static void nanos_xlate_fun_knapsackompmemoc_2(struct nanos_args_2_t *const arg, void *wd)
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
    (*arg).sol = (int *)device_base_address;
  }
}
extern nanos_err_t nanos_in_final(_Bool *result);
struct  mcc_struct_anon_16
{
  void (*outline)(void *);
};
typedef struct mcc_struct_anon_16 nanos_smp_args_t;
static void smp_ol_optimal_1(struct nanos_args_0_t *const args);
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
static void smp_ol_optimal_3(struct nanos_args_1_t *const args);
static void smp_ol_optimal_5(struct nanos_args_2_t *const args);
void optimal(int weight, int idx, int *sol, const item_t *item)
{
  if (idx < 0)
    {
      *sol = 0;
      return ;
    }
  else
    {
      if (weight < item[idx].weight)
        {
          if (idx - 1 >= 0)
            {
              {
                int mcc_arg_0 = weight;
                int mcc_arg_1 = idx - 1;
                int *mcc_arg_2 = sol;
                const item_t *mcc_arg_3 = item;
                {
                  _Bool mcc_is_in_final;
                  nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
                  if (mcc_err_in_final != NANOS_OK)
                    {
                      nanos_handle_error(mcc_err_in_final);
                    }
                  if (mcc_is_in_final)
                    {
                      optimal_mcc_serial(weight, idx - 1, sol, item);
                    }
                  else
                    {
                      {
                        nanos_wd_dyn_props_t nanos_wd_dyn_props;
                        int memo_dimensions[2];
                        struct nanos_args_0_t *ol_args;
                        nanos_err_t err;
                        struct nanos_args_0_t imm_args;
                        static nanos_smp_args_t smp_ol_optimal_1_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_0_t *))&smp_ol_optimal_1};
                        static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_0_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_optimal_1_args}}};
                        nanos_wd_dyn_props.tie_to = 0;
                        nanos_wd_dyn_props.priority = 0;
                        nanos_wd_dyn_props.flags.is_final = idx - 1 < n - final || weight < weight / 5;
                        memo_dimensions[0] = n;
                        memo_dimensions[1] = capacity + 1;
                        nanos_wd_dyn_props.memo.num_dimensions = 2;
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
                        nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_2, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                        ;
                        if (nanos_wd_ != (void *)0)
                          {
                            (*ol_args).weight = mcc_arg_0;
                            (*ol_args).idx = mcc_arg_1;
                            (*ol_args).sol = mcc_arg_2;
                            (*ol_args).item = mcc_arg_3;
                            ol_copy_dimensions[0].size = 1 * sizeof(int);
                            ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                            ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                            ol_copy_data[0].sharing = NANOS_SHARED;
                            ol_copy_data[0].address = (void *)mcc_arg_2;
                            ol_copy_data[0].flags.input = 0;
                            ol_copy_data[0].flags.output = 1;
                            ol_copy_data[0].dimension_count = (short int)1;
                            ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                            ol_copy_data[0].offset = 0;
                            err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_0);
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
                            imm_args.weight = mcc_arg_0;
                            imm_args.idx = mcc_arg_1;
                            imm_args.sol = mcc_arg_2;
                            imm_args.item = mcc_arg_3;
                            imm_copy_dimensions[0].size = 1 * sizeof(int);
                            imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                            imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                            imm_copy_data[0].sharing = NANOS_SHARED;
                            imm_copy_data[0].address = (void *)mcc_arg_2;
                            imm_copy_data[0].flags.input = 0;
                            imm_copy_data[0].flags.output = 1;
                            imm_copy_data[0].dimension_count = (short int)1;
                            imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                            imm_copy_data[0].offset = 0;
                            err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_0_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_0);
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
            }
          return ;
        }
      int v1 = 0;
      int v2 = 0;
      if (idx - 1 >= 0)
        {
          {
            int mcc_arg_6 = weight;
            int mcc_arg_7 = idx - 1;
            int *mcc_arg_8 = &v1;
            const item_t *mcc_arg_9 = item;
            {
              _Bool mcc_is_in_final;
              nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
              if (mcc_err_in_final != NANOS_OK)
                {
                  nanos_handle_error(mcc_err_in_final);
                }
              if (mcc_is_in_final)
                {
                  optimal_mcc_serial(weight, idx - 1, &v1, item);
                }
              else
                {
                  {
                    nanos_wd_dyn_props_t nanos_wd_dyn_props;
                    int memo_dimensions[2];
                    struct nanos_args_1_t *ol_args;
                    nanos_err_t err;
                    struct nanos_args_1_t imm_args;
                    static nanos_smp_args_t smp_ol_optimal_3_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_1_t *))&smp_ol_optimal_3};
                    static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_1_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_optimal_3_args}}};
                    nanos_wd_dyn_props.tie_to = 0;
                    nanos_wd_dyn_props.priority = 0;
                    nanos_wd_dyn_props.flags.is_final = idx - 1 < n - final || weight < weight / 5;
                    memo_dimensions[0] = n;
                    memo_dimensions[1] = capacity + 1;
                    nanos_wd_dyn_props.memo.num_dimensions = 2;
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
                    nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_8, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                    ;
                    if (nanos_wd_ != (void *)0)
                      {
                        (*ol_args).weight = mcc_arg_6;
                        (*ol_args).idx = mcc_arg_7;
                        (*ol_args).sol = mcc_arg_8;
                        (*ol_args).item = mcc_arg_9;
                        ol_copy_dimensions[0].size = 1 * sizeof(int);
                        ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                        ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                        ol_copy_data[0].sharing = NANOS_SHARED;
                        ol_copy_data[0].address = (void *)mcc_arg_8;
                        ol_copy_data[0].flags.input = 0;
                        ol_copy_data[0].flags.output = 1;
                        ol_copy_data[0].dimension_count = (short int)1;
                        ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                        ol_copy_data[0].offset = 0;
                        err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_1);
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
                        imm_args.weight = mcc_arg_6;
                        imm_args.idx = mcc_arg_7;
                        imm_args.sol = mcc_arg_8;
                        imm_args.item = mcc_arg_9;
                        imm_copy_dimensions[0].size = 1 * sizeof(int);
                        imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                        imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                        imm_copy_data[0].sharing = NANOS_SHARED;
                        imm_copy_data[0].address = (void *)mcc_arg_8;
                        imm_copy_data[0].flags.input = 0;
                        imm_copy_data[0].flags.output = 1;
                        imm_copy_data[0].dimension_count = (short int)1;
                        imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                        imm_copy_data[0].offset = 0;
                        err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_1_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_1);
                        if (err != NANOS_OK)
                          {
                            nanos_handle_error(err);
                          }
                      }
                  }
                }
            }
          }
          if (weight - item[idx].weight >= 0)
            {
              {
                int mcc_arg_12 = weight - item[idx].weight;
                int mcc_arg_13 = idx - 1;
                int *mcc_arg_14 = &v2;
                const item_t *mcc_arg_15 = item;
                {
                  _Bool mcc_is_in_final;
                  nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
                  if (mcc_err_in_final != NANOS_OK)
                    {
                      nanos_handle_error(mcc_err_in_final);
                    }
                  if (mcc_is_in_final)
                    {
                      optimal_mcc_serial(weight - item[idx].weight, idx - 1, &v2, item);
                    }
                  else
                    {
                      {
                        nanos_wd_dyn_props_t nanos_wd_dyn_props;
                        int memo_dimensions[2];
                        struct nanos_args_2_t *ol_args;
                        nanos_err_t err;
                        struct nanos_args_2_t imm_args;
                        static nanos_smp_args_t smp_ol_optimal_5_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_2_t *))&smp_ol_optimal_5};
                        static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_2_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_optimal_5_args}}};
                        nanos_wd_dyn_props.tie_to = 0;
                        nanos_wd_dyn_props.priority = 0;
                        nanos_wd_dyn_props.flags.is_final = idx - 1 < n - final || weight - item[idx].weight < (weight - item[idx].weight) / 5;
                        memo_dimensions[0] = n;
                        memo_dimensions[1] = capacity + 1;
                        nanos_wd_dyn_props.memo.num_dimensions = 2;
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
                        nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_14, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
                        ;
                        if (nanos_wd_ != (void *)0)
                          {
                            (*ol_args).weight = mcc_arg_12;
                            (*ol_args).idx = mcc_arg_13;
                            (*ol_args).sol = mcc_arg_14;
                            (*ol_args).item = mcc_arg_15;
                            ol_copy_dimensions[0].size = 1 * sizeof(int);
                            ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                            ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                            ol_copy_data[0].sharing = NANOS_SHARED;
                            ol_copy_data[0].address = (void *)mcc_arg_14;
                            ol_copy_data[0].flags.input = 0;
                            ol_copy_data[0].flags.output = 1;
                            ol_copy_data[0].dimension_count = (short int)1;
                            ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                            ol_copy_data[0].offset = 0;
                            err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_2);
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
                            imm_args.weight = mcc_arg_12;
                            imm_args.idx = mcc_arg_13;
                            imm_args.sol = mcc_arg_14;
                            imm_args.item = mcc_arg_15;
                            imm_copy_dimensions[0].size = 1 * sizeof(int);
                            imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                            imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                            imm_copy_data[0].sharing = NANOS_SHARED;
                            imm_copy_data[0].address = (void *)mcc_arg_14;
                            imm_copy_data[0].flags.input = 0;
                            imm_copy_data[0].flags.output = 1;
                            imm_copy_data[0].dimension_count = (short int)1;
                            imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                            imm_copy_data[0].offset = 0;
                            err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_2_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_2);
                            if (err != NANOS_OK)
                              {
                                nanos_handle_error(err);
                              }
                          }
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
      v2 += item[idx].value;
      *sol = v1 >= v2 ? v1 : v2;
    }
}
struct  nanos_args_3_t
{
  int weight;
  int idx;
  int *sol;
  const item_t *item;
};
static void nanos_xlate_fun_knapsackompmemoc_3(struct nanos_args_3_t *const arg, void *wd)
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
    (*arg).sol = (int *)device_base_address;
  }
}
extern int printf(const char *__restrict __format, ...);
extern void exit(int __status) __attribute__((__nothrow__)) __attribute__((__noreturn__));
extern int atoi(const char *__nptr) __attribute__((__nothrow__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern void *calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__)) __attribute__((__malloc__));
extern void *memset(void *__s, int __c, size_t __n) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
typedef struct _IO_FILE FILE;
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm("""__isoc99_fscanf");
extern double omp_get_wtime(void);
static void smp_ol_optimal_7(struct nanos_args_3_t *const args);
int main(int argc, char **argv)
{
  const char *filename;
  int i;
  if (argc < 3)
    {
      printf("./%s filename size\n", argv[0]);
      exit(0);
    }
  filename = argv[1];
  n = atoi(argv[2]);
  final = n;
  if (argc == 4)
    {
      final = atoi(argv[3]);
    }
  memo = calloc(final * (capacity + 1), sizeof(int));
  memset(memo,  -1, final * (capacity + 1) * sizeof(int));
  item_t item[n];
  FILE *f = fopen(filename, "r");
  for (i = 0; i < n; i++)
    {
      fscanf(f, "%d,%d", &item[i].weight, &item[i].value);
    }
  int sol = 0;
  double start = omp_get_wtime();
  {
    int mcc_arg_18 = capacity;
    int mcc_arg_19 = n - 1;
    int *mcc_arg_20 = &sol;
    const item_t *mcc_arg_21 = item;
    {
      _Bool mcc_is_in_final;
      nanos_err_t mcc_err_in_final = nanos_in_final(&mcc_is_in_final);
      if (mcc_err_in_final != NANOS_OK)
        {
          nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          optimal_mcc_serial(capacity, n - 1, &sol, item);
        }
      else
        {
          {
            nanos_wd_dyn_props_t nanos_wd_dyn_props;
            int memo_dimensions[2];
            struct nanos_args_3_t *ol_args;
            nanos_err_t err;
            struct nanos_args_3_t imm_args;
            static nanos_smp_args_t smp_ol_optimal_7_args = {.outline = (void (*)(void *))(void (*)(struct nanos_args_3_t *))&smp_ol_optimal_7};
            static struct nanos_const_wd_definition_1 nanos_wd_const_data = {.base = {.props = {.mandatory_creation = 0, .tied = 0, .clear_chunk = 0, .reserved0 = 0, .reserved1 = 0, .reserved2 = 0, .reserved3 = 0, .reserved4 = 0}, .data_alignment = __alignof__(struct nanos_args_3_t), .num_copies = 1, .num_devices = 1, .num_dimensions = 1, .description = 0}, .devices = {[0] = {.factory = &nanos_smp_factory, .arg = &smp_ol_optimal_7_args}}};
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = n - 1 < n - final || capacity < capacity / 5;
            memo_dimensions[0] = n;
            memo_dimensions[1] = capacity + 1;
            nanos_wd_dyn_props.memo.num_dimensions = 2;
            nanos_wd_dyn_props.memo.dimensions = memo_dimensions;
            ol_args = (struct nanos_args_3_t *)0;
            nanos_wd_t nanos_wd_ = (void *)0;
            nanos_copy_data_t *ol_copy_data = (nanos_copy_data_t *)0;
            nanos_region_dimension_internal_t *ol_copy_dimensions = (nanos_region_dimension_internal_t *)0;
            err = nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_3_t), (void **)&ol_args, nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
            if (err != NANOS_OK)
              {
                nanos_handle_error(err);
              }
            nanos_region_dimension_t dimensions_0[1] = {[0] = {.size = sizeof(int), .lower_bound = 0, .accessed_length = sizeof(int)}};
            nanos_data_access_t dependences[1] = {[0] = {.address = (void *)mcc_arg_20, .flags = {.input = 0, .output = 1, .can_rename = 0, .concurrent = 0, .commutative = 0}, .dimension_count = (short int)1, .dimensions = dimensions_0, .offset = 0}};
            ;
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).weight = mcc_arg_18;
                (*ol_args).idx = mcc_arg_19;
                (*ol_args).sol = mcc_arg_20;
                (*ol_args).item = mcc_arg_21;
                ol_copy_dimensions[0].size = 1 * sizeof(int);
                ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                ol_copy_data[0].sharing = NANOS_SHARED;
                ol_copy_data[0].address = (void *)mcc_arg_20;
                ol_copy_data[0].flags.input = 0;
                ol_copy_data[0].flags.output = 1;
                ol_copy_data[0].dimension_count = (short int)1;
                ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                ol_copy_data[0].offset = 0;
                err = nanos_set_translate_function(nanos_wd_, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_3);
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
                imm_args.weight = mcc_arg_18;
                imm_args.idx = mcc_arg_19;
                imm_args.sol = mcc_arg_20;
                imm_args.item = mcc_arg_21;
                imm_copy_dimensions[0].size = 1 * sizeof(int);
                imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                imm_copy_data[0].sharing = NANOS_SHARED;
                imm_copy_data[0].address = (void *)mcc_arg_20;
                imm_copy_data[0].flags.input = 0;
                imm_copy_data[0].flags.output = 1;
                imm_copy_data[0].dimension_count = (short int)1;
                imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                imm_copy_data[0].offset = 0;
                err = nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(struct nanos_args_3_t), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, nanos_wd_t))nanos_xlate_fun_knapsackompmemoc_3);
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
  printf("Total value: %d\n", sol);
  printf("Time: %f\n", end - start);
  return 0;
}
static void smp_ol_optimal_1_unpacked(int weight, int idx, int *sol, const item_t *item)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
      if (!is_memoized)
        {
          optimal(weight, idx, sol, item);
          nanos_memo_store_task(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
        }
    }
  }
}
static void smp_ol_optimal_1(struct nanos_args_0_t *const args)
{
  {
    smp_ol_optimal_1_unpacked((*args).weight, (*args).idx, (*args).sol, (*args).item);
  }
}
static void smp_ol_optimal_3_unpacked(int weight, int idx, int *sol, const item_t *item)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
      if (!is_memoized)
        {
          optimal(weight, idx, sol, item);
          nanos_memo_store_task(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
        }
    }
  }
}
static void smp_ol_optimal_3(struct nanos_args_1_t *const args)
{
  {
    smp_ol_optimal_3_unpacked((*args).weight, (*args).idx, (*args).sol, (*args).item);
  }
}
static void smp_ol_optimal_5_unpacked(int weight, int idx, int *sol, const item_t *item)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
      if (!is_memoized)
        {
          optimal(weight, idx, sol, item);
          nanos_memo_store_task(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
        }
    }
  }
}
static void smp_ol_optimal_5(struct nanos_args_2_t *const args)
{
  {
    smp_ol_optimal_5_unpacked((*args).weight, (*args).idx, (*args).sol, (*args).item);
  }
}
static void smp_ol_optimal_7_unpacked(int weight, int idx, int *sol, const item_t *item)
{
  {
    {
      _Bool is_memoized;
      int *memo_dimensions = nanos_memo_get_dimensions(nanos_current_wd());
      is_memoized = nanos_memo_task_memoized(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
      if (!is_memoized)
        {
          optimal(weight, idx, sol, item);
          nanos_memo_store_task(nanos_current_wd(), (0 + idx) * memo_dimensions[1] + weight);
        }
    }
  }
}
static void smp_ol_optimal_7(struct nanos_args_3_t *const args)
{
  {
    smp_ol_optimal_7_unpacked((*args).weight, (*args).idx, (*args).sol, (*args).item);
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
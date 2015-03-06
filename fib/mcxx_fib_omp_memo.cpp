typedef long int ptrdiff_t;
typedef unsigned long int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
struct  nanos_region_dimension_internal_t
{
    ::size_t size;
    ::size_t lower_bound;
    ::size_t accessed_length;
};
struct  nanos_access_type_internal_t
{
    bool input:1;
    bool output:1;
    bool can_rename:1;
    bool concurrent:1;
    bool commutative:1;
};
struct  nanos_data_access_internal_t
{
    void *address;
    ::nanos_access_type_internal_t flags;
    short int dimension_count;
    const ::nanos_region_dimension_internal_t *dimensions;
    ::ptrdiff_t offset;
};
enum nanos_sharing_t
{
  NANOS_PRIVATE = 0,
  NANOS_SHARED = 1
};
struct  nanos_reduction_t
{
    void *original;
    void *privates;
    ::size_t element_size;
    ::size_t num_scalars;
    void *descriptor;
    void (*bop)(void *, void *, int);
    void (*vop)(int, void *, void *);
    void (*cleanup)(void *);
};
typedef unsigned int memory_space_id_t;
struct  nanos_copy_data_internal_t
{
    void *address;
    ::nanos_sharing_t sharing;
    struct  mcc_struct_anon_5
    {
        bool input:1;
        bool output:1;
    };
    ::nanos_copy_data_internal_t::mcc_struct_anon_5 flags;
    short int dimension_count;
    ::nanos_region_dimension_internal_t *dimensions;
    ::ptrdiff_t offset;
    ::uint64_t host_base_address;
    ::memory_space_id_t host_region_id;
    bool remote_host;
};
typedef ::nanos_access_type_internal_t nanos_access_type_t;
typedef ::nanos_region_dimension_internal_t nanos_region_dimension_t;
typedef ::nanos_data_access_internal_t nanos_data_access_t;
typedef ::nanos_copy_data_internal_t nanos_copy_data_t;
typedef void *nanos_thread_t;
typedef void *nanos_wd_t;
struct  nanos_compound_wd_data_t
{
    int nsect;
    ::nanos_wd_t lwd[];
};
struct  nanos_repeat_n_info_t
{
    int n;
};
struct  nanos_loop_info_t
{
    int lower;
    int upper;
    int step;
    bool last;
    bool wait;
    int chunk;
    int stride;
    int thid;
    int threads;
    void *args;
};
typedef void *nanos_ws_t;
typedef void *nanos_ws_info_t;
typedef void *nanos_ws_data_t;
typedef void *nanos_ws_item_t;
struct  nanos_ws_info_loop_t
{
    int lower_bound;
    int upper_bound;
    int loop_step;
    int chunk_size;
};
struct  nanos_ws_item_loop_t
{
    int lower;
    int upper;
    bool execute:1;
    bool last:1;
};
struct nanos_ws_desc;
struct  nanos_ws_desc
{
    volatile ::nanos_ws_t ws;
    ::nanos_ws_data_t data;
    ::nanos_ws_desc *next;
    ::nanos_thread_t *threads;
    int nths;
};
typedef ::nanos_ws_desc nanos_ws_desc_t;
struct  nanos_wd_props_t
{
    bool mandatory_creation:1;
    bool tied:1;
    bool clear_chunk:1;
    bool reserved0:1;
    bool reserved1:1;
    bool reserved2:1;
    bool reserved3:1;
    bool reserved4:1;
};
struct  nanos_wd_dyn_flags_t
{
    bool is_final:1;
    bool is_recover:1;
    bool reserved2:1;
    bool reserved3:1;
    bool reserved4:1;
    bool reserved5:1;
    bool reserved6:1;
    bool reserved7:1;
};
struct  nanos_wd_memo_info_t
{
    int num_elements;
    void *identifier;
};
struct  nanos_wd_dyn_props_t
{
    ::nanos_wd_dyn_flags_t flags;
    ::nanos_thread_t tie_to;
    int priority;
    ::nanos_wd_memo_info_t memo;
};
struct  nanos_device_t
{
    void *(*factory)(void *);
    void *arg;
};
struct  nanos_smp_args_t
{
    void (*outline)(void *);
};
extern "C"
{
  extern void *nanos_smp_factory_(void *args);
}
extern "C"
{
  extern void *nanos_smp_factory(void *args);
}
enum nanos_event_type_t
{
  NANOS_STATE_START = 0,
  NANOS_STATE_END = 1,
  NANOS_SUBSTATE_START = 2,
  NANOS_SUBSTATE_END = 3,
  NANOS_BURST_START = 4,
  NANOS_BURST_END = 5,
  NANOS_PTP_START = 6,
  NANOS_PTP_END = 7,
  NANOS_POINT = 8,
  EVENT_TYPES = 9
};
typedef unsigned int nanos_event_key_t;
typedef unsigned long long int nanos_event_value_t;
enum nanos_event_state_value_t
{
  NANOS_NOT_CREATED = 0,
  NANOS_NOT_RUNNING = 1,
  NANOS_STARTUP = 2,
  NANOS_SHUTDOWN = 3,
  NANOS_ERROR = 4,
  NANOS_IDLE = 5,
  NANOS_RUNTIME = 6,
  NANOS_RUNNING = 7,
  NANOS_SYNCHRONIZATION = 8,
  NANOS_SCHEDULING = 9,
  NANOS_CREATION = 10,
  NANOS_MEM_TRANSFER_IN = 11,
  NANOS_MEM_TRANSFER_OUT = 12,
  NANOS_MEM_TRANSFER_LOCAL = 13,
  NANOS_MEM_TRANSFER_DEVICE_IN = 14,
  NANOS_MEM_TRANSFER_DEVICE_OUT = 15,
  NANOS_MEM_TRANSFER_DEVICE_LOCAL = 16,
  NANOS_CACHE = 17,
  NANOS_YIELD = 18,
  NANOS_ACQUIRING_LOCK = 19,
  NANOS_CONTEXT_SWITCH = 20,
  NANOS_DEBUG = 21,
  NANOS_EVENT_STATE_TYPES = 22
};
enum nanos_event_domain_t
{
  NANOS_WD_DOMAIN = 0,
  NANOS_WD_DEPENDENCY = 1,
  NANOS_WAIT = 2,
  NANOS_XFER_DATA = 3,
  NANOS_XFER_REQ = 4,
  NANOS_WD_REMOTE = 5,
  NANOS_AM_WORK = 6,
  NANOS_AM_WORK_DONE = 7,
  NANOS_XFER_WAIT_REQ_PUT = 8,
  NANOS_XFER_FREE_TMP_BUFF = 9
};
typedef long long int nanos_event_id_t;
struct  nanos_event_t
{
    ::nanos_event_type_t type;
    ::nanos_event_key_t key;
    ::nanos_event_value_t value;
    ::nanos_event_domain_t domain;
    ::nanos_event_id_t id;
};
enum nanos_lock_state_t
{
  NANOS_LOCK_FREE = 0,
  NANOS_LOCK_BUSY = 1
};
struct  nanos_lock_t
{
    volatile ::nanos_lock_state_t state_;
    inline nanos_lock_t(::nanos_lock_state_t init  = (::NANOS_LOCK_FREE))
      : state_(init)
    {
    }
};
typedef void (*nanos_translate_args_t)(void *, ::nanos_wd_t);
typedef void nanos_init_func_t(void *);
struct  nanos_init_desc_t
{
    ::nanos_init_func_t (*func);
    void *data;
};
enum nanos_err_t
{
  NANOS_OK = 0,
  NANOS_UNKNOWN_ERR = 1,
  NANOS_UNIMPLEMENTED = 2,
  NANOS_ENOMEM = 3,
  NANOS_INVALID_PARAM = 4
};
typedef void *nanos_wg_t;
typedef void *nanos_team_t;
typedef void *nanos_sched_t;
typedef void *nanos_slicer_t;
typedef void *nanos_dd_t;
typedef void *nanos_sync_cond_t;
typedef unsigned int nanos_copy_id_t;
struct  nanos_const_wd_definition_tag
{
    ::nanos_wd_props_t props;
    ::size_t data_alignment;
    ::size_t num_copies;
    ::size_t num_devices;
    ::size_t num_dimensions;
    const char *description;
};
typedef ::nanos_const_wd_definition_tag nanos_const_wd_definition_t;
struct  nanos_const_wd_definition_1
{
    ::nanos_const_wd_definition_t base;
    ::nanos_device_t devices[1];
};
struct  nanos_constraint_t
{
    int nthreads;
    void *arch;
};
struct  nanos_const_wd_definition_internal_t : ::nanos_const_wd_definition_tag
{
    ::nanos_device_t devices[1];
};
extern "C"
{
  extern char *nanos_get_mode_();
}
extern "C"
{
  extern char *nanos_get_mode();
}
extern "C"
{
  extern ::nanos_wd_t nanos_current_wd_();
}
extern "C"
{
  extern ::nanos_wd_t nanos_current_wd();
}
extern "C"
{
  extern int nanos_get_wd_id_(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_id(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_priority_(::nanos_wd_t wd);
}
extern "C"
{
  extern int nanos_get_wd_priority(::nanos_wd_t wd);
}
extern "C"
{
  extern void nanos_set_wd_priority_(::nanos_wd_t wd, int p);
}
extern "C"
{
  extern void nanos_set_wd_priority(::nanos_wd_t wd, int p);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_wd_description_(char **description, ::nanos_wd_t wd);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_wd_description(char **description, ::nanos_wd_t wd);
}
extern "C"
{
  extern ::nanos_slicer_t nanos_find_slicer_(const char *slicer);
}
extern "C"
{
  extern ::nanos_slicer_t nanos_find_slicer(const char *slicer);
}
extern "C"
{
  extern ::nanos_ws_t nanos_find_worksharing_(const char *label);
}
extern "C"
{
  extern ::nanos_ws_t nanos_find_worksharing(const char *label);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_compact_(::nanos_wd_t *wd, ::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void **data, ::nanos_wg_t wg, ::nanos_copy_data_t **copies, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_compact(::nanos_wd_t *wd, ::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void **data, ::nanos_wg_t wg, ::nanos_copy_data_t **copies, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_translate_function_(::nanos_wd_t wd, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_translate_function(::nanos_wd_t wd, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_sliced_wd_(::nanos_wd_t *uwd, ::size_t num_devices, ::nanos_device_t *devices, ::size_t outline_data_size, int outline_data_align, void **outline_data, ::nanos_wg_t uwg, ::nanos_slicer_t slicer, ::nanos_wd_props_t *props, ::nanos_wd_dyn_props_t *dyn_props, ::size_t num_copies, ::nanos_copy_data_t **copies, ::size_t num_dimensions, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_sliced_wd(::nanos_wd_t *uwd, ::size_t num_devices, ::nanos_device_t *devices, ::size_t outline_data_size, int outline_data_align, void **outline_data, ::nanos_wg_t uwg, ::nanos_slicer_t slicer, ::nanos_wd_props_t *props, ::nanos_wd_dyn_props_t *dyn_props, ::size_t num_copies, ::nanos_copy_data_t **copies, ::size_t num_dimensions, ::nanos_region_dimension_internal_t **dimensions);
}
extern "C"
{
  extern ::nanos_err_t nanos_submit_(::nanos_wd_t wd, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_submit(::nanos_wd_t wd, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_and_run_compact_(::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void *data, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_copy_data_t *copies, ::nanos_region_dimension_internal_t *dimensions, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_wd_and_run_compact(::nanos_const_wd_definition_t *const_data, ::nanos_wd_dyn_props_t *dyn_props, ::size_t data_size, void *data, ::size_t num_data_accesses, ::nanos_data_access_t *data_accesses, ::nanos_copy_data_t *copies, ::nanos_region_dimension_internal_t *dimensions, ::nanos_translate_args_t translate_args);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_for_();
}
extern "C"
{
  extern ::nanos_err_t nanos_create_for();
}
extern "C"
{
  extern ::nanos_err_t nanos_set_internal_wd_data_(::nanos_wd_t wd, void *data);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_internal_wd_data(::nanos_wd_t wd, void *data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_internal_wd_data_(::nanos_wd_t wd, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_internal_wd_data(::nanos_wd_t wd, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_yield_();
}
extern "C"
{
  extern ::nanos_err_t nanos_yield();
}
extern "C"
{
  extern ::nanos_err_t nanos_slicer_get_specific_data_(::nanos_slicer_t slicer, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_slicer_get_specific_data(::nanos_slicer_t slicer, void **data);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_ready_tasks_(unsigned int *ready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_ready_tasks(unsigned int *ready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_total_tasks_(unsigned int *total_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_total_tasks(unsigned int *total_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_nonready_tasks_(unsigned int *nonready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_nonready_tasks(unsigned int *nonready_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_running_tasks_(unsigned int *running_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_running_tasks(unsigned int *running_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_blocked_tasks_(unsigned int *blocked_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_blocked_tasks(unsigned int *blocked_tasks);
}
extern "C"
{
  extern ::nanos_err_t nanos_in_final_(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_in_final(bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_final_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_final(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, ::nanos_constraint_t *constraints, bool reuse, ::nanos_thread_t *info, ::nanos_const_wd_definition_t *const_data);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, ::nanos_constraint_t *constraints, bool reuse, ::nanos_thread_t *info, ::nanos_const_wd_definition_t *const_data);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_mapped_(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, unsigned int *mapping);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_team_mapped(::nanos_team_t *team, ::nanos_sched_t sg, unsigned int *nthreads, unsigned int *mapping);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_team_();
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_team();
}
extern "C"
{
  extern ::nanos_err_t nanos_leave_team_();
}
extern "C"
{
  extern ::nanos_err_t nanos_leave_team();
}
extern "C"
{
  extern ::nanos_err_t nanos_end_team_(::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_end_team(::nanos_team_t team);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_barrier_();
}
extern "C"
{
  extern ::nanos_err_t nanos_team_barrier();
}
extern "C"
{
  extern ::nanos_err_t nanos_single_guard_(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_single_guard(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_sync_init_(bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_enter_sync_init(bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_sync_init_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_sync_init();
}
extern "C"
{
  extern ::nanos_err_t nanos_release_sync_init_();
}
extern "C"
{
  extern ::nanos_err_t nanos_release_sync_init();
}
extern "C"
{
  extern ::nanos_err_t nanos_memory_fence_();
}
extern "C"
{
  extern ::nanos_err_t nanos_memory_fence();
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_starring_threads_FIXME_(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_starring_threads_FIXME(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_starring_threads_FIXME_(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_starring_threads_FIXME(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_supporting_threads_(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_num_supporting_threads(int *n);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_supporting_threads_(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_team_get_supporting_threads(int *n, ::nanos_thread_t *list_of_threads);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_reduction_(::nanos_reduction_t *red);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_reduction(::nanos_reduction_t *red);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_private_data_(void **copy, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_private_data(void **copy, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get_(::nanos_reduction_t **dest, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_reduction_get(::nanos_reduction_t **dest, void *original);
}
extern "C"
{
  extern ::nanos_err_t nanos_admit_current_thread_();
}
extern "C"
{
  extern ::nanos_err_t nanos_admit_current_thread();
}
extern "C"
{
  extern ::nanos_err_t nanos_expel_current_thread_();
}
extern "C"
{
  extern ::nanos_err_t nanos_expel_current_thread();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_release_all_();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_release_all();
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_pendant_writes_(bool *res, void *addr);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_pendant_writes(bool *res, void *addr);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_create_(::nanos_wd_t pred, ::nanos_wd_t succ);
}
extern "C"
{
  extern ::nanos_err_t nanos_dependence_create(::nanos_wd_t pred, ::nanos_wd_t succ);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_create_(::nanos_ws_desc_t **wsd, ::nanos_ws_t ws, ::nanos_ws_info_t *info, bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_create(::nanos_ws_desc_t **wsd, ::nanos_ws_t ws, ::nanos_ws_info_t *info, bool *b);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_next_item_(::nanos_ws_desc_t *wsd, ::nanos_ws_item_t *wsi);
}
extern "C"
{
  extern ::nanos_err_t nanos_worksharing_next_item(::nanos_ws_desc_t *wsd, ::nanos_ws_item_t *wsi);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion_(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_wg_wait_completion(::nanos_wg_t wg, bool avoid_flush);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_int_sync_cond_(::nanos_sync_cond_t *sync_cond, volatile int *p, int condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_int_sync_cond(::nanos_sync_cond_t *sync_cond, volatile int *p, int condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_bool_sync_cond_(::nanos_sync_cond_t *sync_cond, volatile bool *p, bool condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_create_bool_sync_cond(::nanos_sync_cond_t *sync_cond, volatile bool *p, bool condition);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_wait_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_wait(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_signal_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_sync_cond_signal(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_sync_cond_(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_sync_cond(::nanos_sync_cond_t sync_cond);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_on_(::size_t num_data_accesses, ::nanos_data_access_t *data_accesses);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_on(::size_t num_data_accesses, ::nanos_data_access_t *data_accesses);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_(::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock(::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_at_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_init_lock_at(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_unset_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_unset_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_try_lock_(::nanos_lock_t *lock, bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_try_lock(::nanos_lock_t *lock, bool *result);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_lock_(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_destroy_lock(::nanos_lock_t *lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_lock_address_(void *addr, ::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_lock_address(void *addr, ::nanos_lock_t **lock);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_copies_(::nanos_wd_t wd, int num_copies, ::nanos_copy_data_t *copies);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_copies(::nanos_wd_t wd, int num_copies, ::nanos_copy_data_t *copies);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_addr_(::nanos_copy_id_t copy_id, void **addr, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_addr(::nanos_copy_id_t copy_id, void **addr, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_copy_value_(void *dst, ::nanos_copy_id_t copy_id, ::nanos_wd_t cwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_copy_value(void *dst, ::nanos_copy_id_t copy_id, ::nanos_wd_t cwd);
}
extern "C"
{
  extern const char *nanos_get_runtime_version_();
}
extern "C"
{
  extern const char *nanos_get_runtime_version();
}
extern "C"
{
  extern const char *nanos_get_default_architecture_();
}
extern "C"
{
  extern const char *nanos_get_default_architecture();
}
extern "C"
{
  extern const char *nanos_get_pm_();
}
extern "C"
{
  extern const char *nanos_get_pm();
}
extern "C"
{
  extern ::nanos_err_t nanos_get_default_binding_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_default_binding(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_delay_start_();
}
extern "C"
{
  extern ::nanos_err_t nanos_delay_start();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_();
}
extern "C"
{
  extern ::nanos_err_t nanos_start();
}
extern "C"
{
  extern ::nanos_err_t nanos_finish_();
}
extern "C"
{
  extern ::nanos_err_t nanos_finish();
}
extern "C"
{
  extern ::nanos_err_t nanos_current_socket_(int socket);
}
extern "C"
{
  extern ::nanos_err_t nanos_current_socket(int socket);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_sockets_(int *num_sockets);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_num_sockets(int *num_sockets);
}
extern "C"
{
  extern ::nanos_err_t nanos_malloc_(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_malloc(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_memalign_(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_memalign(void **p, ::size_t size, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc_(void **p, ::size_t size, unsigned int node, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_cmalloc(void **p, ::size_t size, unsigned int node, const char *file, int line);
}
extern "C"
{
  extern ::nanos_err_t nanos_stick_to_producer_(void *p, ::size_t size);
}
extern "C"
{
  extern ::nanos_err_t nanos_stick_to_producer(void *p, ::size_t size);
}
extern "C"
{
  extern ::nanos_err_t nanos_free_(void *p);
}
extern "C"
{
  extern ::nanos_err_t nanos_free(void *p);
}
extern "C"
{
  extern void nanos_free0_(void *p);
}
extern "C"
{
  extern void nanos_free0(void *p);
}
extern "C"
{
  extern void nanos_handle_error_(::nanos_err_t err);
}
extern "C"
{
  extern void nanos_handle_error(::nanos_err_t err);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_key_(::nanos_event_key_t *event_key, const char *key, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_key(::nanos_event_key_t *event_key, const char *key, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_(::nanos_event_value_t *event_value, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value(::nanos_event_value_t *event_value, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_with_val_(::nanos_event_value_t val, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_register_value_with_val(::nanos_event_value_t val, const char *key, const char *value, const char *description, bool abort_when_registered);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_key_(const char *key, ::nanos_event_key_t *event_key);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_key(const char *key, ::nanos_event_key_t *event_key);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_value_(const char *key, const char *value, ::nanos_event_value_t *event_value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_get_value(const char *key, const char *value, ::nanos_event_value_t *event_value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_events_(unsigned int num_events, ::nanos_event_t events[]);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_events(unsigned int num_events, ::nanos_event_t events[]);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_user_fun_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_user_fun_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_raise_gpu_kernel_launch_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_raise_gpu_kernel_launch_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_gpu_kernel_launch_event_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_close_gpu_kernel_launch_event();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_enable_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_enable();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_disable_();
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_disable();
}
extern "C"
{
  extern ::nanos_err_t nanos_get_node_num_(unsigned int *num);
}
extern "C"
{
  extern ::nanos_err_t nanos_get_node_num(unsigned int *num);
}
extern "C"
{
  extern int nanos_get_num_nodes_();
}
extern "C"
{
  extern int nanos_get_num_nodes();
}
extern "C"
{
  extern ::nanos_err_t nanos_set_create_local_tasks_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_set_create_local_tasks(bool value);
}
extern "C"
{
  extern void *nanos_memo_get_map_(::nanos_wd_t wd, void *id);
}
extern "C"
{
  extern void *nanos_memo_get_map(::nanos_wd_t wd, void *id);
}
typedef const char *nanos_string_t;
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst_(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_string_t value, ::nanos_string_t value_descr);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_begin_burst(::nanos_string_t key, ::nanos_string_t key_descr, ::nanos_string_t value, ::nanos_string_t value_descr);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst_(::nanos_string_t key, ::nanos_string_t value);
}
extern "C"
{
  extern ::nanos_err_t nanos_instrument_end_burst(::nanos_string_t key, ::nanos_string_t value);
}
extern "C"
{
  extern ::nanos_err_t nanos_memcpy_(void *dest, const void *src, ::size_t n);
}
extern "C"
{
  extern ::nanos_err_t nanos_memcpy(void *dest, const void *src, ::size_t n);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_object_(int num_objects, ::nanos_copy_data_t *obj);
}
extern "C"
{
  extern ::nanos_err_t nanos_register_object(int num_objects, ::nanos_copy_data_t *obj);
}
extern "C"
{
  extern const char *nanos_get_default_scheduler_();
}
extern "C"
{
  extern const char *nanos_get_default_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_scheduler_();
}
extern "C"
{
  extern ::nanos_err_t nanos_start_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_stop_scheduler_();
}
extern "C"
{
  extern ::nanos_err_t nanos_stop_scheduler();
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_enabled_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_enabled(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_paused_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_paused();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_unpaused_();
}
extern "C"
{
  extern ::nanos_err_t nanos_wait_until_threads_unpaused();
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_get_stealing_(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_get_stealing(bool *res);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_set_stealing_(bool value);
}
extern "C"
{
  extern ::nanos_err_t nanos_scheduler_set_stealing(bool value);
}
extern "C"
{
  extern void ompss_nanox_main_();
}
extern "C"
{
  extern void ompss_nanox_main();
}
extern "C"
{
  void nanos_reduction_int_vop(int, void *, void *);
}
extern "C"
{
  void nanos_reduction_bop_add_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_cfloat(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_cfloat_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_cfloat(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_cfloat_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_cdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_cdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_cdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_cdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_clongdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_add_clongdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_clongdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_add_clongdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_cfloat(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_cfloat_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_cfloat(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_cfloat_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_cdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_cdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_cdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_cdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_clongdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_sub_clongdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_clongdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_sub_clongdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_cfloat(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_cfloat_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_cfloat(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_cfloat_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_cdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_cdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_cdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_cdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_clongdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_prod_clongdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_clongdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_prod_clongdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_and__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_and__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_or__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_or__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_xor__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_xor__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_cfloat(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_cfloat_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_cfloat(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_cfloat_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_cdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_cdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_cdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_cdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_clongdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_land_clongdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_clongdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_land_clongdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_cfloat(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_cfloat_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_cfloat(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_cfloat_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_cdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_cdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_cdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_cdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_clongdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_lor_clongdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_clongdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_lor_clongdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_max_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_max_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_char(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_char_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_char(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_char_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_uchar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_uchar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_uchar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_uchar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_schar(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_schar_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_schar(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_schar_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_short(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_short_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_short(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_short_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ushort(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ushort_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ushort(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ushort_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_int(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_int_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_int(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_int_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_uint(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_uint_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_uint(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_uint_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_long(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_long_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_long(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_long_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ulong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ulong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ulong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ulong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_longlong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_longlong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_longlong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_longlong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ulonglong(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_ulonglong_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ulonglong(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_ulonglong_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min__Bool(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min__Bool_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min__Bool(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min__Bool_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_float(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_float_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_float(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_float_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_double(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_double_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_double(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_double_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_longdouble(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_bop_min_longdouble_(void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_longdouble(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_vop_min_longdouble_(int i, void *arg1, void *arg2);
}
extern "C"
{
  void nanos_reduction_default_cleanup_char(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_uchar(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_schar(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_short(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_ushort(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_int(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_uint(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_long(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_ulong(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_longlong(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_ulonglong(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup__Bool(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_float(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_double(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_longdouble(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_cfloat(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_cdouble(void *r);
}
extern "C"
{
  void nanos_reduction_default_cleanup_clongdouble(void *r);
}
extern "C"
{
  extern void nanos_reduction_default_cleanup_fortran_(void *);
}
extern "C"
{
  extern void nanos_reduction_default_cleanup_fortran(void *);
}
extern "C"
{
  extern void nanos_atomic_assig_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_assig_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_assig_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_assig_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_assig_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_assig_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_assig_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_assig_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_assig_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_assig_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_assig_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_assig_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_assig_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_assig_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_assig_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_assig_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_assig_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_assig_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_assig_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_assig_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_assig_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_add_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_add_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_add_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_add_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_add_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_add_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_add_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_add_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_add_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_add_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_add_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_add_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_add_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_add_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_add_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_add_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_add_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_add_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_add_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_add_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_add_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_add_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_add_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_add_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_sub_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_sub_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_sub_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_sub_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_sub_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_sub_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_sub_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_sub_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_sub_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_sub_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_sub_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_sub_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_sub_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_sub_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_sub_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_sub_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_sub_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_sub_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_sub_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_sub_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_sub_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mul_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mul_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mul_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mul_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mul_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mul_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mul_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mul_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mul_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mul_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_mul_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_mul_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_mul_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_mul_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_mul_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_mul_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_mul_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_mul_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_mul_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_mul_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mul_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_div_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_div_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_div_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_div_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_div_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_div_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_div_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_div_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_div_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_div_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_div_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_div_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_div_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_div_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_div_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_div_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_div_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_div_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_div_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_div_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_div_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_div_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_div_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_div_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_pow_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_pow_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_pow_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_pow_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_pow_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_pow_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_pow_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_pow_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_pow_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_pow_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_pow_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_pow_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_pow_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_pow_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_pow_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_pow_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_pow_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_pow_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_pow_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_pow_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_pow_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_max_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_max_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_max_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_max_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_max_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_max_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_max_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_max_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_max_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_max_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_max_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_max_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_min_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_min_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_min_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_min_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_min_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_min_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_min_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_min_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_min_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_min_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_min_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_min_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_max_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_max_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_max_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_max_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_max_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_max_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_min_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_min_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_min_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_min_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_min_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_min_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_eq_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_eq_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_eq_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_eq_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_eq_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_eq_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_eq_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_eq_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_eq_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_eq_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_eq_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_eq_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_eq_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_eq_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_eq_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_eq_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_eq_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_eq_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_eq_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_neq_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_neq_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_neq_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_neq_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_neq_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_neq_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_neq_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_neq_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_neq_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_neq_float_(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_neq_float(volatile float *, float);
}
extern "C"
{
  extern void nanos_atomic_neq_double_(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_neq_double(volatile double *, double);
}
extern "C"
{
  extern void nanos_atomic_neq_ldouble_(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_neq_ldouble(volatile long double *, long double);
}
extern "C"
{
  extern void nanos_atomic_neq_cfloat_(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_neq_cfloat(volatile _Complex float *, _Complex float);
}
extern "C"
{
  extern void nanos_atomic_neq_cdouble_(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_neq_cdouble(volatile _Complex double *, _Complex double);
}
extern "C"
{
  extern void nanos_atomic_neq_cldouble_(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_neq_cldouble(volatile _Complex long double *, _Complex long double);
}
extern "C"
{
  extern void nanos_atomic_mod_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mod_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_mod_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mod_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_mod_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mod_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_mod_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_mod_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_mod_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_mod_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shl_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shl_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shl_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shl_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shl_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shl_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shl_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shl_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shl_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shr_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_shr_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shr_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_shr_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shr_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_shr_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_shr_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_shr_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_shr_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_land_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_land_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_land_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_land_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_land_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_land_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_land_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_land_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_land_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_land_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_land_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_land_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_lor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_lor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_lor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_lor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_lor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_lor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_lor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_lor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_lor_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_band_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_band_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_band_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_band_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_band_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_band_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_band_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_band_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_band_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_band_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_band_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_band_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bor_longlongbool(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_schar_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_schar(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_short_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_short(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_int_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_int(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_long_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_long(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlong_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlong(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uchar_(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bxor_uchar(volatile unsigned char *, unsigned char);
}
extern "C"
{
  extern void nanos_atomic_bxor_ushort_(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ushort(volatile unsigned short int *, unsigned short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uint_(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bxor_uint(volatile unsigned int *, unsigned int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulong_(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulong(volatile unsigned long int *, unsigned long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulonglong_(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_ulonglong(volatile unsigned long long int *, unsigned long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_bytebool_(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_bytebool(volatile signed char *, signed char);
}
extern "C"
{
  extern void nanos_atomic_bxor_shortbool_(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_shortbool(volatile short int *, short int);
}
extern "C"
{
  extern void nanos_atomic_bxor_intbool_(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_intbool(volatile int *, int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longbool_(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longbool(volatile long int *, long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlongbool_(volatile long long int *, long long int);
}
extern "C"
{
  extern void nanos_atomic_bxor_longlongbool(volatile long long int *, long long int);
}
typedef void *nanos_cpu_set_t;
enum nanos_omp_sched_t
{
  nanos_omp_sched_static = 1,
  nanos_omp_sched_dynamic = 2,
  nanos_omp_sched_guided = 3,
  nanos_omp_sched_auto = 4
};
extern "C"
{
  extern ::nanos_err_t nanos_omp_single_(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_single(bool *);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_barrier_();
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_barrier();
}
extern "C"
{
  void nanos_omp_set_interface(void *);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_set_implicit_(::nanos_wd_t uwd);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_set_implicit(::nanos_wd_t uwd);
}
extern "C"
{
  extern int nanos_omp_get_max_threads_();
}
extern "C"
{
  extern int nanos_omp_get_max_threads();
}
extern "C"
{
  extern int nanos_omp_get_num_threads_();
}
extern "C"
{
  extern int nanos_omp_get_num_threads();
}
extern "C"
{
  extern int nanos_omp_get_thread_num_();
}
extern "C"
{
  extern int nanos_omp_get_thread_num();
}
extern "C"
{
  extern int nanos_omp_set_num_threads_(int nthreads);
}
extern "C"
{
  extern int nanos_omp_set_num_threads(int nthreads);
}
extern "C"
{
  extern ::nanos_ws_t nanos_omp_find_worksharing_(::nanos_omp_sched_t kind);
}
extern "C"
{
  extern ::nanos_ws_t nanos_omp_find_worksharing(::nanos_omp_sched_t kind);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_get_schedule_(::nanos_omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern ::nanos_err_t nanos_omp_get_schedule(::nanos_omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern int nanos_omp_get_num_threads_next_parallel_(int threads_requested);
}
extern "C"
{
  extern int nanos_omp_get_num_threads_next_parallel(int threads_requested);
}
extern "C"
{
  extern void nanos_omp_get_mask_(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_get_mask(::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_set_mask_(const ::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_set_mask(const ::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_mask_(const ::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern void nanos_omp_add_mask(const ::nanos_cpu_set_t cpu_set);
}
extern "C"
{
  extern int nanos_omp_get_max_processors_();
}
extern "C"
{
  extern int nanos_omp_get_max_processors();
}
namespace std __attribute__((__visibility__("default"))) {
  using ::ptrdiff_t;
  using ::size_t;
}
#pragma GCC visibility push(default)
namespace std __attribute__((__visibility__("default"))) {
  class  exception
  {
    public:
      inline exception() throw()
      {
      }
      virtual ~exception() throw();
      virtual const char *what() const  throw();
  };
  class  bad_exception : public ::std::exception
  {
    public:
      inline bad_exception() throw()
      {
      }
      virtual ~bad_exception() throw();
      virtual const char *what() const  throw();
  };
  typedef void (*terminate_handler)();
  typedef void (*unexpected_handler)();
  ::std::terminate_handler set_terminate(::std::terminate_handler) throw();
  void terminate() __attribute__((__noreturn__));
  ::std::unexpected_handler set_unexpected(::std::unexpected_handler) throw();
  void unexpected() __attribute__((__noreturn__));
  bool uncaught_exception() throw();
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  void __verbose_terminate_handler();
}
#pragma GCC visibility pop
#pragma GCC visibility push(default)
namespace std __attribute__((__visibility__("default"))) {
  class  bad_alloc : public ::std::exception
  {
    public:
      inline bad_alloc() throw()
      {
      }
      virtual ~bad_alloc() throw();
      virtual const char *what() const  throw();
  };
  struct  nothrow_t
  {
  };
  extern const ::std::nothrow_t nothrow;
  typedef void (*new_handler)();
  ::std::new_handler set_new_handler(::std::new_handler) throw();
}
void *operator new(::size_t, const ::std::nothrow_t &) throw();
void *operator new[](::size_t, const ::std::nothrow_t &) throw();
void operator delete(void *, const ::std::nothrow_t &) throw();
void operator delete[](void *, const ::std::nothrow_t &) throw();
inline void *operator new(::size_t, void *__p) throw()
{
  return __p;
}
inline void *operator new[](::size_t, void *__p) throw()
{
  return __p;
}
inline void operator delete(void *, void *) throw()
{
}
inline void operator delete[](void *, void *) throw()
{
}
#pragma GCC visibility pop
struct  nanos_opencl_args_t
{
    void (*outline)(void *);
};
extern "C"
{
  extern void *nanos_opencl_factory_(void *args);
}
extern "C"
{
  extern void *nanos_opencl_factory(void *args);
}
extern "C"
{
  extern void *nanos_create_current_kernel_(const char *kernel_name, const char *opencl_code, const char *compiler_opts);
}
extern "C"
{
  extern void *nanos_create_current_kernel(const char *kernel_name, const char *opencl_code, const char *compiler_opts);
}
extern "C"
{
  extern ::nanos_err_t nanos_opencl_set_bufferarg_(void *opencl_kernel, int arg_num, const void *pointer);
}
extern "C"
{
  extern ::nanos_err_t nanos_opencl_set_bufferarg(void *opencl_kernel, int arg_num, const void *pointer);
}
extern "C"
{
  extern ::nanos_err_t nanos_opencl_set_arg_(void *opencl_kernel, int arg_num, ::size_t size, const void *pointer);
}
extern "C"
{
  extern ::nanos_err_t nanos_opencl_set_arg(void *opencl_kernel, int arg_num, ::size_t size, const void *pointer);
}
extern "C"
{
  extern ::nanos_err_t nanos_exec_kernel_(void *opencl_kernel, int work_dim, ::size_t *ndr_offset, ::size_t *ndr_local_size, ::size_t *ndr_global_size);
}
extern "C"
{
  extern ::nanos_err_t nanos_exec_kernel(void *opencl_kernel, int work_dim, ::size_t *ndr_offset, ::size_t *ndr_local_size, ::size_t *ndr_global_size);
}
extern "C"
{
  unsigned int nanos_get_opencl_num_devices();
}
extern "C"
{
  void *ompss_opencl_malloc(::size_t size);
}
extern "C"
{
  void ompss_opencl_free(void *address);
}
extern "C"
{
  void nanos_get_opencl_num_devices_(int *numret);
}
extern "C"
{
  void *nanos_malloc_opencl(::size_t size) __attribute__((deprecated));
}
extern "C"
{
  void nanos_free_opencl(void *address) __attribute__((deprecated));
}
extern "C"
{
  extern void nanos_opencl_allocate_fortran_(::ptrdiff_t size, void *ptr);
}
extern "C"
{
  extern void nanos_opencl_allocate_fortran(::ptrdiff_t size, void *ptr);
}
extern "C"
{
  extern void nanos_opencl_deallocate_fortran_(void *address);
}
extern "C"
{
  extern void nanos_opencl_deallocate_fortran(void *address);
}
union  wait
{
    int w_status;
    struct  mcc_struct_anon_21
    {
        unsigned int __w_termsig:7;
        unsigned int __w_coredump:1;
        unsigned int __w_retcode:8;
        unsigned int:16;
    };
    ::wait::mcc_struct_anon_21 __wait_terminated;
    struct  mcc_struct_anon_22
    {
        unsigned int __w_stopval:8;
        unsigned int __w_stopsig:8;
        unsigned int:16;
    };
    ::wait::mcc_struct_anon_22 __wait_stopped;
};
struct  div_t
{
    int quot;
    int rem;
};
struct  ldiv_t
{
    long int quot;
    long int rem;
};
__extension__ struct  lldiv_t
{
    __extension__ long long int quot;
    __extension__ long long int rem;
};
extern "C"
{
  extern ::size_t __ctype_get_mb_cur_max() throw();
}
extern "C"
{
  extern double atof(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int atoi(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int atol(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long long int atoll(const char *__nptr) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern double strtod(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern float strtof(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long double strtold(const char *__restrict __nptr, char **__restrict __endptr) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long long int strtouq(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long long int strtoll(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern unsigned long long int strtoull(const char *__restrict __nptr, char **__restrict __endptr, int __base) throw() __attribute__((__nonnull__(1)));
}
struct locale_data;
struct  __locale_struct
{
    ::locale_data *__locales[13];
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;
    const char *__names[13];
};
typedef ::__locale_struct *__locale_t;
typedef ::__locale_t locale_t;
extern "C"
{
  extern long int strtol_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern unsigned long int strtoul_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern long long int strtoll_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern unsigned long long int strtoull_l(const char *__restrict __nptr, char **__restrict __endptr, int __base, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern double strtod_l(const char *__restrict __nptr, char **__restrict __endptr, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern float strtof_l(const char *__restrict __nptr, char **__restrict __endptr, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern long double strtold_l(const char *__restrict __nptr, char **__restrict __endptr, ::__locale_t __loc) throw() __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern char *l64a(long int __n) throw();
}
extern "C"
{
  extern long int a64l(const char *__s) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
struct  __fsid_t
{
    int __val[2];
};
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __ssize_t;
typedef ::__off64_t __loff_t;
typedef ::__quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef ::__u_char u_char;
typedef ::__u_short u_short;
typedef ::__u_int u_int;
typedef ::__u_long u_long;
typedef ::__quad_t quad_t;
typedef ::__u_quad_t u_quad_t;
typedef ::__fsid_t fsid_t;
typedef ::__loff_t loff_t;
typedef ::__ino_t ino_t;
typedef ::__ino64_t ino64_t;
typedef ::__dev_t dev_t;
typedef ::__gid_t gid_t;
typedef ::__mode_t mode_t;
typedef ::__nlink_t nlink_t;
typedef ::__uid_t uid_t;
typedef ::__off_t off_t;
typedef ::__off64_t off64_t;
typedef ::__pid_t pid_t;
typedef ::__id_t id_t;
typedef ::__ssize_t ssize_t;
typedef ::__daddr_t daddr_t;
typedef ::__caddr_t caddr_t;
typedef ::__key_t key_t;
typedef ::__clock_t clock_t;
typedef ::__time_t time_t;
typedef ::__clockid_t clockid_t;
typedef ::__timer_t timer_t;
typedef ::__useconds_t useconds_t;
typedef ::__suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long int u_int64_t;
typedef long int register_t;
typedef int __sig_atomic_t;
struct  __sigset_t
{
    unsigned long int __val[16U];
};
typedef ::__sigset_t sigset_t;
struct  timespec
{
    ::__time_t tv_sec;
    long int tv_nsec;
};
struct  timeval
{
    ::__time_t tv_sec;
    ::__suseconds_t tv_usec;
};
typedef long int __fd_mask;
struct  fd_set
{
    ::__fd_mask fds_bits[16];
};
typedef ::__fd_mask fd_mask;
extern "C"
{
  extern int select(int __nfds, ::fd_set *__restrict __readfds, ::fd_set *__restrict __writefds, ::fd_set *__restrict __exceptfds, ::timeval *__restrict __timeout);
}
extern "C"
{
  extern int pselect(int __nfds, ::fd_set *__restrict __readfds, ::fd_set *__restrict __writefds, ::fd_set *__restrict __exceptfds, const ::timespec *__restrict __timeout, const ::__sigset_t *__restrict __sigmask);
}
extern "C"
{
  extern unsigned int gnu_dev_major(unsigned long long int __dev) throw();
}
extern "C"
{
  extern unsigned int gnu_dev_minor(unsigned long long int __dev) throw();
}
extern "C"
{
  extern unsigned long long int gnu_dev_makedev(unsigned int __major, unsigned int __minor) throw();
}
typedef ::__blksize_t blksize_t;
typedef ::__blkcnt_t blkcnt_t;
typedef ::__fsblkcnt_t fsblkcnt_t;
typedef ::__fsfilcnt_t fsfilcnt_t;
typedef ::__blkcnt64_t blkcnt64_t;
typedef ::__fsblkcnt64_t fsblkcnt64_t;
typedef ::__fsfilcnt64_t fsfilcnt64_t;
typedef unsigned long int pthread_t;
union  pthread_attr_t
{
    char __size[56];
    long int __align;
};
struct __pthread_internal_list;
struct  __pthread_internal_list
{
    ::__pthread_internal_list *__prev;
    ::__pthread_internal_list *__next;
};
typedef ::__pthread_internal_list __pthread_list_t;
union  pthread_mutex_t
{
    struct  __pthread_mutex_s
    {
        int __lock;
        unsigned int __count;
        int __owner;
        unsigned int __nusers;
        int __kind;
        int __spins;
        ::__pthread_list_t __list;
    };
    ::pthread_mutex_t::__pthread_mutex_s __data;
    char __size[40];
    long int __align;
};
union  pthread_mutexattr_t
{
    char __size[4];
    int __align;
};
union  pthread_cond_t
{
    struct  mcc_struct_anon_33
    {
        int __lock;
        unsigned int __futex;
        __extension__ unsigned long long int __total_seq;
        __extension__ unsigned long long int __wakeup_seq;
        __extension__ unsigned long long int __woken_seq;
        void *__mutex;
        unsigned int __nwaiters;
        unsigned int __broadcast_seq;
    };
    ::pthread_cond_t::mcc_struct_anon_33 __data;
    char __size[48];
    __extension__ long long int __align;
};
union  pthread_condattr_t
{
    char __size[4];
    int __align;
};
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union  pthread_rwlock_t
{
    struct  mcc_struct_anon_36
    {
        int __lock;
        unsigned int __nr_readers;
        unsigned int __readers_wakeup;
        unsigned int __writer_wakeup;
        unsigned int __nr_readers_queued;
        unsigned int __nr_writers_queued;
        int __writer;
        int __shared;
        unsigned long int __pad1;
        unsigned long int __pad2;
        unsigned int __flags;
    };
    ::pthread_rwlock_t::mcc_struct_anon_36 __data;
    char __size[56];
    long int __align;
};
union  pthread_rwlockattr_t
{
    char __size[8];
    long int __align;
};
typedef volatile int pthread_spinlock_t;
union  pthread_barrier_t
{
    char __size[32];
    long int __align;
};
union  pthread_barrierattr_t
{
    char __size[4];
    int __align;
};
extern "C"
{
  extern long int random() throw();
}
extern "C"
{
  extern void srandom(unsigned int __seed) throw();
}
extern "C"
{
  extern char *initstate(unsigned int __seed, char *__statebuf, ::size_t __statelen) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern char *setstate(char *__statebuf) throw() __attribute__((__nonnull__(1)));
}
struct  random_data
{
    ::int32_t *fptr;
    ::int32_t *rptr;
    ::int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    ::int32_t *end_ptr;
};
extern "C"
{
  extern int random_r(::random_data *__restrict __buf, ::int32_t *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int srandom_r(unsigned int __seed, ::random_data *__buf) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int initstate_r(unsigned int __seed, char *__restrict __statebuf, ::size_t __statelen, ::random_data *__restrict __buf) throw() __attribute__((__nonnull__(2, 4)));
}
extern "C"
{
  extern int setstate_r(char *__restrict __statebuf, ::random_data *__restrict __buf) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int rand() throw();
}
extern "C"
{
  extern void srand(unsigned int __seed) throw();
}
extern "C"
{
  extern int rand_r(unsigned int *__seed) throw();
}
extern "C"
{
  extern double drand48() throw();
}
extern "C"
{
  extern double erand48(unsigned short int __xsubi[3]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int lrand48() throw();
}
extern "C"
{
  extern long int nrand48(unsigned short int __xsubi[3]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern long int mrand48() throw();
}
extern "C"
{
  extern long int jrand48(unsigned short int __xsubi[3]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void srand48(long int __seedval) throw();
}
extern "C"
{
  extern unsigned short int *seed48(unsigned short int __seed16v[3]) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void lcong48(unsigned short int __param[7]) throw() __attribute__((__nonnull__(1)));
}
struct  drand48_data
{
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
};
extern "C"
{
  extern int drand48_r(::drand48_data *__restrict __buffer, double *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int erand48_r(unsigned short int __xsubi[3], ::drand48_data *__restrict __buffer, double *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int lrand48_r(::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int nrand48_r(unsigned short int __xsubi[3], ::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int mrand48_r(::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int jrand48_r(unsigned short int __xsubi[3], ::drand48_data *__restrict __buffer, long int *__restrict __result) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int srand48_r(long int __seedval, ::drand48_data *__buffer) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int seed48_r(unsigned short int __seed16v[3], ::drand48_data *__buffer) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int lcong48_r(unsigned short int __param[7], ::drand48_data *__buffer) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *malloc(::size_t __size) throw() __attribute__((__malloc__));
}
extern "C"
{
  extern void *calloc(::size_t __nmemb, ::size_t __size) throw() __attribute__((__malloc__));
}
extern "C"
{
  extern void *realloc(void *__ptr, ::size_t __size) throw() __attribute__((__warn_unused_result__));
}
extern "C"
{
  extern void free(void *__ptr) throw();
}
extern "C"
{
  extern void cfree(void *__ptr) throw();
}
extern "C"
{
  extern void *alloca(::size_t __size) throw();
}
extern "C"
{
  extern void *valloc(::size_t __size) throw() __attribute__((__malloc__));
}
extern "C"
{
  extern int posix_memalign(void **__memptr, ::size_t __alignment, ::size_t __size) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void abort() throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern int atexit(void (*__func)()) throw() __attribute__((__nonnull__(1)));
}
int at_quick_exit(void (*__func)()) throw() __asm("at_quick_exit") __attribute__((__nonnull__(1)));
extern "C"
{
  extern int on_exit(void (*__func)(int, void *), void *__arg) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern void quick_exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern void _Exit(int __status) throw() __attribute__((__noreturn__));
}
extern "C"
{
  extern char *getenv(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *__secure_getenv(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int putenv(char *__string) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int setenv(const char *__name, const char *__value, int __replace) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int unsetenv(const char *__name) throw();
}
extern "C"
{
  extern int clearenv() throw();
}
extern "C"
{
  extern char *mktemp(char *__template) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkstemp(char *__template) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkstemp64(char *__template) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkstemps(char *__template, int __suffixlen) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkstemps64(char *__template, int __suffixlen) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *mkdtemp(char *__template) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkostemp(char *__template, int __flags) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkostemp64(char *__template, int __flags) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkostemps(char *__template, int __suffixlen, int __flags) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int mkostemps64(char *__template, int __suffixlen, int __flags) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int system(const char *__command);
}
extern "C"
{
  extern char *canonicalize_file_name(const char *__name) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *realpath(const char *__restrict __name, char *__restrict __resolved) throw();
}
typedef int (*__compar_fn_t)(const void *, const void *);
typedef ::__compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t)(const void *, const void *, void *);
extern "C"
{
  extern void *bsearch(const void *__key, const void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_fn_t __compar) __attribute__((__nonnull__(1, 2, 5)));
}
extern "C"
{
  extern void qsort(void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern void qsort_r(void *__base, ::size_t __nmemb, ::size_t __size, ::__compar_d_fn_t __compar, void *__arg) __attribute__((__nonnull__(1, 4)));
}
extern "C"
{
  extern int abs(int __x) throw() __attribute__((__const__));
}
extern "C"
{
  extern long int labs(long int __x) throw() __attribute__((__const__));
}
extern "C"
{
  extern long long int llabs(long long int __x) throw() __attribute__((__const__));
}
extern "C"
{
  extern ::div_t div(int __numer, int __denom) throw() __attribute__((__const__));
}
extern "C"
{
  extern ::ldiv_t ldiv(long int __numer, long int __denom) throw() __attribute__((__const__));
}
extern "C"
{
  extern ::lldiv_t lldiv(long long int __numer, long long int __denom) throw() __attribute__((__const__));
}
extern "C"
{
  extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4)));
}
extern "C"
{
  extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4)));
}
extern "C"
{
  extern char *gcvt(double __value, int __ndigit, char *__buf) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4)));
}
extern "C"
{
  extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) throw() __attribute__((__nonnull__(3, 4)));
}
extern "C"
{
  extern char *qgcvt(long double __value, int __ndigit, char *__buf) throw() __attribute__((__nonnull__(3)));
}
extern "C"
{
  extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, ::size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
}
extern "C"
{
  extern int mblen(const char *__s, ::size_t __n) throw();
}
extern "C"
{
  extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s, ::size_t __n) throw();
}
extern "C"
{
  extern int wctomb(char *__s, wchar_t __wchar) throw();
}
extern "C"
{
  extern ::size_t mbstowcs(wchar_t *__restrict __pwcs, const char *__restrict __s, ::size_t __n) throw();
}
extern "C"
{
  extern ::size_t wcstombs(char *__restrict __s, const wchar_t *__restrict __pwcs, ::size_t __n) throw();
}
extern "C"
{
  extern int rpmatch(const char *__response) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int getsubopt(char **__restrict __optionp, char *const *__restrict __tokens, char **__restrict __valuep) throw() __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern void setkey(const char *__key) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int posix_openpt(int __oflag);
}
extern "C"
{
  extern int grantpt(int __fd) throw();
}
extern "C"
{
  extern int unlockpt(int __fd) throw();
}
extern "C"
{
  extern char *ptsname(int __fd) throw();
}
extern "C"
{
  extern int ptsname_r(int __fd, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int getpt();
}
extern "C"
{
  extern int getloadavg(double __loadavg[], int __nelem) throw() __attribute__((__nonnull__(1)));
}
struct _IO_FILE;
typedef ::_IO_FILE FILE;
typedef ::_IO_FILE __FILE;
struct  __mbstate_t
{
    int __count;
    union  mcc_union_anon_41
    {
        unsigned int __wch;
        char __wchb[4];
    };
    ::__mbstate_t::mcc_union_anon_41 __value;
};
struct  _G_fpos_t
{
    ::__off_t __pos;
    ::__mbstate_t __state;
};
struct  _G_fpos64_t
{
    ::__off64_t __pos;
    ::__mbstate_t __state;
};
typedef short int _G_int16_t;
typedef int _G_int32_t;
typedef unsigned short int _G_uint16_t;
typedef unsigned int _G_uint32_t;
typedef ::__builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
typedef void _IO_lock_t;
struct _IO_marker;
struct  _IO_marker
{
    ::_IO_marker *_next;
    ::_IO_FILE *_sbuf;
    int _pos;
};
enum __codecvt_result
{
  __codecvt_ok = 0,
  __codecvt_partial = 1,
  __codecvt_error = 2,
  __codecvt_noconv = 3
};
struct  _IO_FILE
{
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    ::_IO_marker *_markers;
    ::_IO_FILE *_chain;
    int _fileno;
    int _flags2;
    ::__off_t _old_offset;
    unsigned short int _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];
    ::_IO_lock_t *_lock;
    ::__off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    ::size_t __pad5;
    int _mode;
    char _unused2[20U];
};
struct _IO_FILE_plus;
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stdin_;
}
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stdout_;
}
extern "C"
{
  extern ::_IO_FILE_plus _IO_2_1_stderr_;
}
typedef ::__ssize_t __io_read_fn(void *, char *, ::size_t);
typedef ::__ssize_t __io_write_fn(void *, const char *, ::size_t);
typedef int __io_seek_fn(void *, ::__off64_t *, int);
typedef int __io_close_fn(void *);
typedef ::__io_read_fn cookie_read_function_t;
typedef ::__io_write_fn cookie_write_function_t;
typedef ::__io_seek_fn cookie_seek_function_t;
typedef ::__io_close_fn cookie_close_function_t;
struct  _IO_cookie_io_functions_t
{
    ::__io_read_fn (*read);
    ::__io_write_fn (*write);
    ::__io_seek_fn (*seek);
    ::__io_close_fn (*close);
};
typedef ::_IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
extern "C"
{
  extern void _IO_cookie_init(::_IO_cookie_file *__cfile, int __read_write, void *__cookie, ::_IO_cookie_io_functions_t __fns);
}
extern "C"
{
  extern int __underflow(::_IO_FILE *);
}
extern "C"
{
  extern int __uflow(::_IO_FILE *);
}
extern "C"
{
  extern int __overflow(::_IO_FILE *, int);
}
extern "C"
{
  extern int _IO_getc(::_IO_FILE *__fp);
}
extern "C"
{
  extern int _IO_putc(int __c, ::_IO_FILE *__fp);
}
extern "C"
{
  extern int _IO_feof(::_IO_FILE *__fp) throw();
}
extern "C"
{
  extern int _IO_ferror(::_IO_FILE *__fp) throw();
}
extern "C"
{
  extern int _IO_peekc_locked(::_IO_FILE *__fp);
}
extern "C"
{
  extern void _IO_flockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern void _IO_funlockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern int _IO_ftrylockfile(::_IO_FILE *) throw();
}
extern "C"
{
  extern int _IO_vfscanf(::_IO_FILE *__restrict , const char *__restrict , ::__gnuc_va_list, int *__restrict );
}
extern "C"
{
  extern int _IO_vfprintf(::_IO_FILE *__restrict , const char *__restrict , ::__gnuc_va_list);
}
extern "C"
{
  extern ::__ssize_t _IO_padn(::_IO_FILE *, int, ::__ssize_t);
}
extern "C"
{
  extern ::size_t _IO_sgetn(::_IO_FILE *, void *, ::size_t);
}
extern "C"
{
  extern ::__off64_t _IO_seekoff(::_IO_FILE *, ::__off64_t, int, int);
}
extern "C"
{
  extern ::__off64_t _IO_seekpos(::_IO_FILE *, ::__off64_t, int);
}
extern "C"
{
  extern void _IO_free_backup_area(::_IO_FILE *) throw();
}
typedef ::__gnuc_va_list va_list;
typedef ::_G_fpos_t fpos_t;
typedef ::_G_fpos64_t fpos64_t;
extern "C"
{
  extern ::_IO_FILE *stdin;
}
extern "C"
{
  extern ::_IO_FILE *stdout;
}
extern "C"
{
  extern ::_IO_FILE *stderr;
}
extern "C"
{
  extern int remove(const char *__filename) throw();
}
extern "C"
{
  extern int rename(const char *__old, const char *__new) throw();
}
extern "C"
{
  extern int renameat(int __oldfd, const char *__old, int __newfd, const char *__new) throw();
}
extern "C"
{
  extern ::FILE *tmpfile();
}
extern "C"
{
  extern ::FILE *tmpfile64();
}
extern "C"
{
  extern char *tmpnam(char *__s) throw();
}
extern "C"
{
  extern char *tmpnam_r(char *__s) throw();
}
extern "C"
{
  extern char *tempnam(const char *__dir, const char *__pfx) throw() __attribute__((__malloc__));
}
extern "C"
{
  extern int fclose(::FILE *__stream);
}
extern "C"
{
  extern int fflush(::FILE *__stream);
}
extern "C"
{
  extern int fflush_unlocked(::FILE *__stream);
}
extern "C"
{
  extern int fcloseall();
}
extern "C"
{
  extern ::FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
}
extern "C"
{
  extern ::FILE *freopen(const char *__restrict __filename, const char *__restrict __modes, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::FILE *fopen64(const char *__restrict __filename, const char *__restrict __modes);
}
extern "C"
{
  extern ::FILE *freopen64(const char *__restrict __filename, const char *__restrict __modes, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::FILE *fdopen(int __fd, const char *__modes) throw();
}
extern "C"
{
  extern ::FILE *fopencookie(void *__restrict __magic_cookie, const char *__restrict __modes, ::_IO_cookie_io_functions_t __io_funcs) throw();
}
extern "C"
{
  extern ::FILE *fmemopen(void *__s, ::size_t __len, const char *__modes) throw();
}
extern "C"
{
  extern ::FILE *open_memstream(char **__bufloc, ::size_t *__sizeloc) throw();
}
extern "C"
{
  extern void setbuf(::FILE *__restrict __stream, char *__restrict __buf) throw();
}
extern "C"
{
  extern int setvbuf(::FILE *__restrict __stream, char *__restrict __buf, int __modes, ::size_t __n) throw();
}
extern "C"
{
  extern void setbuffer(::FILE *__restrict __stream, char *__restrict __buf, ::size_t __size) throw();
}
extern "C"
{
  extern void setlinebuf(::FILE *__stream) throw();
}
extern "C"
{
  extern int fprintf(::FILE *__restrict __stream, const char *__restrict __format, ...);
}
extern "C"
{
  extern int printf(const char *__restrict __format, ...);
}
extern "C"
{
  extern int sprintf(char *__restrict __s, const char *__restrict __format, ...) throw();
}
extern "C"
{
  extern int vfprintf(::FILE *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg);
}
extern "C"
{
  extern int vprintf(const char *__restrict __format, ::__gnuc_va_list __arg);
}
extern "C"
{
  extern int vsprintf(char *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg) throw();
}
extern "C"
{
  extern int snprintf(char *__restrict __s, ::size_t __maxlen, const char *__restrict __format, ...) throw() __attribute__((__format__(__printf__, 3, 4)));
}
extern "C"
{
  extern int vsnprintf(char *__restrict __s, ::size_t __maxlen, const char *__restrict __format, ::__gnuc_va_list __arg) throw() __attribute__((__format__(__printf__, 3, 0)));
}
extern "C"
{
  extern int vasprintf(char **__restrict __ptr, const char *__restrict __f, ::__gnuc_va_list __arg) throw() __attribute__((__format__(__printf__, 2, 0)));
}
extern "C"
{
  extern int __asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 2, 3)));
}
extern "C"
{
  extern int asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) throw() __attribute__((__format__(__printf__, 2, 3)));
}
extern "C"
{
  extern int vdprintf(int __fd, const char *__restrict __fmt, ::__gnuc_va_list __arg) __attribute__((__format__(__printf__, 2, 0)));
}
extern "C"
{
  extern int dprintf(int __fd, const char *__restrict __fmt, ...) __attribute__((__format__(__printf__, 2, 3)));
}
extern "C"
{
  extern int fscanf(::FILE *__restrict __stream, const char *__restrict __format, ...);
}
extern "C"
{
  extern int scanf(const char *__restrict __format, ...);
}
extern "C"
{
  extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) throw();
}
extern "C"
{
  extern int vfscanf(::FILE *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg) __attribute__((__format__(__scanf__, 2, 0)));
}
extern "C"
{
  extern int vscanf(const char *__restrict __format, ::__gnuc_va_list __arg) __attribute__((__format__(__scanf__, 1, 0)));
}
extern "C"
{
  extern int vsscanf(const char *__restrict __s, const char *__restrict __format, ::__gnuc_va_list __arg) throw() __attribute__((__format__(__scanf__, 2, 0)));
}
extern "C"
{
  extern int fgetc(::FILE *__stream);
}
extern "C"
{
  extern int getc(::FILE *__stream);
}
extern "C"
{
  extern int getchar();
}
extern "C"
{
  extern int getc_unlocked(::FILE *__stream);
}
extern "C"
{
  extern int getchar_unlocked();
}
extern "C"
{
  extern int fgetc_unlocked(::FILE *__stream);
}
extern "C"
{
  extern int fputc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern int putc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern int putchar(int __c);
}
extern "C"
{
  extern int fputc_unlocked(int __c, ::FILE *__stream);
}
extern "C"
{
  extern int putc_unlocked(int __c, ::FILE *__stream);
}
extern "C"
{
  extern int putchar_unlocked(int __c);
}
extern "C"
{
  extern int getw(::FILE *__stream);
}
extern "C"
{
  extern int putw(int __w, ::FILE *__stream);
}
extern "C"
{
  extern char *fgets(char *__restrict __s, int __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern char *gets(char *__s);
}
extern "C"
{
  extern char *fgets_unlocked(char *__restrict __s, int __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::__ssize_t __getdelim(char **__restrict __lineptr, ::size_t *__restrict __n, int __delimiter, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::__ssize_t getdelim(char **__restrict __lineptr, ::size_t *__restrict __n, int __delimiter, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::__ssize_t getline(char **__restrict __lineptr, ::size_t *__restrict __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern int fputs(const char *__restrict __s, ::FILE *__restrict __stream);
}
extern "C"
{
  extern int puts(const char *__s);
}
extern "C"
{
  extern int ungetc(int __c, ::FILE *__stream);
}
extern "C"
{
  extern ::size_t fread(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::size_t fwrite(const void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __s);
}
extern "C"
{
  extern int fputs_unlocked(const char *__restrict __s, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::size_t fread_unlocked(void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern ::size_t fwrite_unlocked(const void *__restrict __ptr, ::size_t __size, ::size_t __n, ::FILE *__restrict __stream);
}
extern "C"
{
  extern int fseek(::FILE *__stream, long int __off, int __whence);
}
extern "C"
{
  extern long int ftell(::FILE *__stream);
}
extern "C"
{
  extern void rewind(::FILE *__stream);
}
extern "C"
{
  extern int fseeko(::FILE *__stream, ::__off_t __off, int __whence);
}
extern "C"
{
  extern ::__off_t ftello(::FILE *__stream);
}
extern "C"
{
  extern int fgetpos(::FILE *__restrict __stream, ::fpos_t *__restrict __pos);
}
extern "C"
{
  extern int fsetpos(::FILE *__stream, const ::fpos_t *__pos);
}
extern "C"
{
  extern int fseeko64(::FILE *__stream, ::__off64_t __off, int __whence);
}
extern "C"
{
  extern ::__off64_t ftello64(::FILE *__stream);
}
extern "C"
{
  extern int fgetpos64(::FILE *__restrict __stream, ::fpos64_t *__restrict __pos);
}
extern "C"
{
  extern int fsetpos64(::FILE *__stream, const ::fpos64_t *__pos);
}
extern "C"
{
  extern void clearerr(::FILE *__stream) throw();
}
extern "C"
{
  extern int feof(::FILE *__stream) throw();
}
extern "C"
{
  extern int ferror(::FILE *__stream) throw();
}
extern "C"
{
  extern void clearerr_unlocked(::FILE *__stream) throw();
}
extern "C"
{
  extern int feof_unlocked(::FILE *__stream) throw();
}
extern "C"
{
  extern int ferror_unlocked(::FILE *__stream) throw();
}
extern "C"
{
  extern void perror(const char *__s);
}
extern "C"
{
  extern int sys_nerr;
}
extern "C"
{
  extern const char *const sys_errlist[];
}
extern "C"
{
  extern int _sys_nerr;
}
extern "C"
{
  extern const char *const _sys_errlist[];
}
extern "C"
{
  extern int fileno(::FILE *__stream) throw();
}
extern "C"
{
  extern int fileno_unlocked(::FILE *__stream) throw();
}
extern "C"
{
  extern ::FILE *popen(const char *__command, const char *__modes);
}
extern "C"
{
  extern int pclose(::FILE *__stream);
}
extern "C"
{
  extern char *ctermid(char *__s) throw();
}
extern "C"
{
  extern char *cuserid(char *__s);
}
struct obstack;
extern "C"
{
  extern int obstack_printf(::obstack *__restrict __obstack, const char *__restrict __format, ...) throw() __attribute__((__format__(__printf__, 2, 3)));
}
extern "C"
{
  extern int obstack_vprintf(::obstack *__restrict __obstack, const char *__restrict __format, ::__gnuc_va_list __args) throw() __attribute__((__format__(__printf__, 2, 0)));
}
extern "C"
{
  extern void flockfile(::FILE *__stream) throw();
}
extern "C"
{
  extern int ftrylockfile(::FILE *__stream) throw();
}
extern "C"
{
  extern void funlockfile(::FILE *__stream) throw();
}
typedef void *omp_lock_t;
typedef void *omp_nest_lock_t;
enum omp_sched_t
{
  omp_sched_static = ::nanos_omp_sched_static,
  omp_sched_dynamic = ::nanos_omp_sched_dynamic,
  omp_sched_guided = ::nanos_omp_sched_guided,
  omp_sched_auto = ::nanos_omp_sched_auto
};
extern "C"
{
  extern void omp_set_num_threads(int num_threads);
}
extern "C"
{
  extern int omp_get_num_threads();
}
extern "C"
{
  extern int omp_get_max_threads();
}
extern "C"
{
  extern int omp_get_thread_num();
}
extern "C"
{
  extern int omp_get_num_procs();
}
extern "C"
{
  extern int omp_in_parallel();
}
extern "C"
{
  extern void omp_set_dynamic(int dynamic_threads);
}
extern "C"
{
  extern int omp_get_dynamic();
}
extern "C"
{
  extern void omp_set_nested(int nested);
}
extern "C"
{
  extern int omp_get_nested();
}
extern "C"
{
  extern int omp_get_thread_limit();
}
extern "C"
{
  extern void omp_set_max_active_levels(int max_active_levels);
}
extern "C"
{
  extern int omp_get_max_active_levels();
}
extern "C"
{
  extern void omp_set_schedule(::omp_sched_t kind, int modifier);
}
extern "C"
{
  extern void omp_get_schedule(::omp_sched_t *kind, int *modifier);
}
extern "C"
{
  extern int omp_get_level();
}
extern "C"
{
  extern int omp_get_ancestor_thread_num(int level);
}
extern "C"
{
  extern int omp_get_team_size(int level);
}
extern "C"
{
  extern int omp_get_active_level();
}
extern "C"
{
  extern void omp_init_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_destroy_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_set_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_unset_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern int omp_test_lock(::omp_lock_t *lock);
}
extern "C"
{
  extern void omp_init_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_destroy_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_set_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern void omp_unset_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern int omp_test_nest_lock(::omp_nest_lock_t *lock);
}
extern "C"
{
  extern double omp_get_wtime();
}
extern "C"
{
  extern double omp_get_wtick();
}
extern "C"
{
  extern int omp_in_final();
}
namespace std __attribute__((__visibility__("default"))) {
  namespace rel_ops {
    template < typename _Tp >
    inline bool operator !=(const _Tp &__x, const _Tp &__y);
    template < typename _Tp >
    inline bool operator !=(const _Tp &__x, const _Tp &__y)
    {
      return !(__x == __y);
    }
    template < typename _Tp >
    inline bool operator >(const _Tp &__x, const _Tp &__y);
    template < typename _Tp >
    inline bool operator >(const _Tp &__x, const _Tp &__y)
    {
      return __y < __x;
    }
    template < typename _Tp >
    inline bool operator <=(const _Tp &__x, const _Tp &__y);
    template < typename _Tp >
    inline bool operator <=(const _Tp &__x, const _Tp &__y)
    {
      return !(__y < __x);
    }
    template < typename _Tp >
    inline bool operator >=(const _Tp &__x, const _Tp &__y);
    template < typename _Tp >
    inline bool operator >=(const _Tp &__x, const _Tp &__y)
    {
      return !(__x < __y);
    }
  }
  template < typename _Tp >
  inline void swap(_Tp &__a, _Tp &__b);
  template < typename _Tp >
  inline void swap(_Tp &__a, _Tp &__b)
  {
    _Tp __tmp = __a;
    __a = __b;
    __b = __tmp;
  }
  template < typename _T1, typename _T2 >
  struct  pair
  {
      typedef _T1 first_type;
      typedef _T2 second_type;
      _T1 first;
      _T2 second;
      inline pair()
        : first(), second()
      {
      }
      inline pair(const _T1 &__a, const _T2 &__b)
        : first(__a), second(__b)
      {
      }
      template < typename _U1, typename _U2 >
      inline pair(const ::std::pair<_U1, _U2> &__p)
        : first(__p.first), second(__p.second)
      {
      }
  };
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __x.first == __y.first && __x.second == __y.second;
  }
  template < typename _T1, typename _T2 >
  inline bool operator <(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator <(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __x.first < __y.first || (!(__y.first < __x.first) && __x.second < __y.second);
  }
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__x == __y);
  }
  template < typename _T1, typename _T2 >
  inline bool operator >(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator >(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return __y < __x;
  }
  template < typename _T1, typename _T2 >
  inline bool operator <=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator <=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__y < __x);
  }
  template < typename _T1, typename _T2 >
  inline bool operator >=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y);
  template < typename _T1, typename _T2 >
  inline bool operator >=(const ::std::pair<_T1, _T2> &__x, const ::std::pair<_T1, _T2> &__y)
  {
    return !(__x < __y);
  }
  template < typename _T1, typename _T2 >
  inline ::std::pair<_T1, _T2> make_pair(_T1 __x, _T2 __y);
  template < typename _T1, typename _T2 >
  inline ::std::pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
  {
    return ::std::pair<_T1, _T2>(__x, __y);
  }
  void __throw_bad_exception() __attribute__((__noreturn__));
  void __throw_bad_alloc() __attribute__((__noreturn__));
  void __throw_bad_cast() __attribute__((__noreturn__));
  void __throw_bad_typeid() __attribute__((__noreturn__));
  void __throw_logic_error(const char *) __attribute__((__noreturn__));
  void __throw_domain_error(const char *) __attribute__((__noreturn__));
  void __throw_invalid_argument(const char *) __attribute__((__noreturn__));
  void __throw_length_error(const char *) __attribute__((__noreturn__));
  void __throw_out_of_range(const char *) __attribute__((__noreturn__));
  void __throw_runtime_error(const char *) __attribute__((__noreturn__));
  void __throw_range_error(const char *) __attribute__((__noreturn__));
  void __throw_overflow_error(const char *) __attribute__((__noreturn__));
  void __throw_underflow_error(const char *) __attribute__((__noreturn__));
  void __throw_ios_failure(const char *) __attribute__((__noreturn__));
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  template < typename _Iterator, typename _Container >
  class __normal_iterator;
}
namespace std __attribute__((__visibility__("default"))) {
  struct  __true_type
  {
  };
  struct  __false_type
  {
  };
  template < bool __nontype_tpl_param_1_0__ >
  struct  __truth_type
  {
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __truth_type<true>
  {
      typedef ::std::__true_type __type;
  };
  template < typename _Sp, typename _Tp >
  struct  __traitor
  {
      enum mcc_enum_anon_6
      {
        __value = bool(_Sp::__value) || bool(_Tp::__value)
      };
      typedef typename ::std::__truth_type< ::std::__traitor<_Sp, _Tp>::__value>::__type __type;
  };
  template < typename _Sp, typename _Tp >
  struct  __traitand
  {
      enum mcc_enum_anon_7
      {
        __value = bool(_Sp::__value) && bool(_Tp::__value)
      };
      typedef typename ::std::__truth_type< ::std::__traitand<_Sp, _Tp>::__value>::__type __type;
  };
  template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __are_same
  {
      enum mcc_enum_anon_8
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Tp >
  struct  __are_same<_Tp, _Tp>
  {
      enum mcc_enum_anon_9
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_void
  {
      enum mcc_enum_anon_10
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_void<void>
  {
      enum mcc_enum_anon_11
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_integer
  {
      enum mcc_enum_anon_12
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_integer<bool>
  {
      enum mcc_enum_anon_13
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<char>
  {
      enum mcc_enum_anon_14
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<signed char>
  {
      enum mcc_enum_anon_15
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned char>
  {
      enum mcc_enum_anon_16
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<wchar_t>
  {
      enum mcc_enum_anon_17
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<short int>
  {
      enum mcc_enum_anon_18
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned short int>
  {
      enum mcc_enum_anon_19
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<int>
  {
      enum mcc_enum_anon_20
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned int>
  {
      enum mcc_enum_anon_21
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<long int>
  {
      enum mcc_enum_anon_22
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned long int>
  {
      enum mcc_enum_anon_23
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<long long int>
  {
      enum mcc_enum_anon_24
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_integer<unsigned long long int>
  {
      enum mcc_enum_anon_25
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_floating
  {
      enum mcc_enum_anon_26
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_floating<float>
  {
      enum mcc_enum_anon_27
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_floating<double>
  {
      enum mcc_enum_anon_28
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_floating<long double>
  {
      enum mcc_enum_anon_29
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_pointer
  {
      enum mcc_enum_anon_30
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Tp >
  struct  __is_pointer<_Tp *>
  {
      enum mcc_enum_anon_31
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_normal_iterator
  {
      enum mcc_enum_anon_32
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template < typename _Iterator, typename _Container >
  struct  __is_normal_iterator< ::__gnu_cxx::__normal_iterator<_Iterator, _Container> >
  {
      enum mcc_enum_anon_33
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_arithmetic : ::std::__traitor< ::std::__is_integer<_Tp>, ::std::__is_floating<_Tp> >
  {
  };
  template < typename _Tp >
  struct  __is_fundamental : ::std::__traitor< ::std::__is_void<_Tp>, ::std::__is_arithmetic<_Tp> >
  {
  };
  template < typename _Tp >
  struct  __is_scalar : ::std::__traitor< ::std::__is_arithmetic<_Tp>, ::std::__is_pointer<_Tp> >
  {
  };
  template < typename _Tp >
  struct  __is_char
  {
      enum mcc_enum_anon_34
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_char<char>
  {
      enum mcc_enum_anon_35
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_char<wchar_t>
  {
      enum mcc_enum_anon_36
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_byte
  {
      enum mcc_enum_anon_37
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
  template <>
  struct  __is_byte<char>
  {
      enum mcc_enum_anon_38
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_byte<signed char>
  {
      enum mcc_enum_anon_39
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template <>
  struct  __is_byte<unsigned char>
  {
      enum mcc_enum_anon_40
      {
        __value = 1
      };
      typedef ::std::__true_type __type;
  };
  template < typename _Tp >
  struct  __is_move_iterator
  {
      enum mcc_enum_anon_41
      {
        __value = 0
      };
      typedef ::std::__false_type __type;
  };
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  template < bool __nontype_tpl_param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __enable_if
  {
  };
  template < typename _Tp >
  struct  __enable_if<true, _Tp>
  {
      typedef _Tp __type;
  };
  template < bool _Cond, typename _Iftrue, typename _Iffalse >
  struct  __conditional_type
  {
      typedef _Iftrue __type;
  };
  template < typename _Iftrue, typename _Iffalse >
  struct  __conditional_type<false, _Iftrue, _Iffalse>
  {
      typedef _Iffalse __type;
  };
  template < typename _Tp >
  struct  __add_unsigned
  {
    private:
      typedef ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp>::__type __type;
  };
  template <>
  struct  __add_unsigned<char>
  {
      typedef unsigned char __type;
  };
  template <>
  struct  __add_unsigned<signed char>
  {
      typedef unsigned char __type;
  };
  template <>
  struct  __add_unsigned<short int>
  {
      typedef unsigned short int __type;
  };
  template <>
  struct  __add_unsigned<int>
  {
      typedef unsigned int __type;
  };
  template <>
  struct  __add_unsigned<long int>
  {
      typedef unsigned long int __type;
  };
  template <>
  struct  __add_unsigned<long long int>
  {
      typedef unsigned long long int __type;
  };
  template <>
  struct __add_unsigned<bool>;
  template <>
  struct __add_unsigned<wchar_t>;
  template < typename _Tp >
  struct  __remove_unsigned
  {
    private:
      typedef ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;
    public:
      typedef typename ::__gnu_cxx::__enable_if<std::__is_integer<_Tp>::__value, _Tp>::__type __type;
  };
  template <>
  struct  __remove_unsigned<char>
  {
      typedef signed char __type;
  };
  template <>
  struct  __remove_unsigned<unsigned char>
  {
      typedef signed char __type;
  };
  template <>
  struct  __remove_unsigned<unsigned short int>
  {
      typedef short int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned int>
  {
      typedef int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned long int>
  {
      typedef long int __type;
  };
  template <>
  struct  __remove_unsigned<unsigned long long int>
  {
      typedef long long int __type;
  };
  template <>
  struct __remove_unsigned<bool>;
  template <>
  struct __remove_unsigned<wchar_t>;
  template < typename _Type >
  inline bool __is_null_pointer(_Type *__ptr);
  template < typename _Type >
  inline bool __is_null_pointer(_Type *__ptr)
  {
    return __ptr == 0;
  }
  template < typename _Type >
  inline bool __is_null_pointer(_Type);
  template < typename _Type >
  inline bool __is_null_pointer(_Type)
  {
    return false;
  }
  template < typename _Tp, bool __nontype_tpl_param_1_1__ = std::__is_integer<_Tp>::__value >
  struct  __promote
  {
      typedef double __type;
  };
  template < typename _Tp >
  struct  __promote<_Tp, false>
  {
      typedef _Tp __type;
  };
  template < typename _Tp, typename _Up >
  struct  __promote_2
  {
    private:
      typedef typename ::__gnu_cxx::__promote<_Tp, ::std::__is_integer<_Tp>::__value>::__type __type1;
      typedef typename ::__gnu_cxx::__promote<_Up, ::std::__is_integer<_Up>::__value>::__type __type2;
    public:
      typedef __typeof__(((typename ::__gnu_cxx::__promote_2<_Tp, _Up>::__type1())) + ((typename ::__gnu_cxx::__promote_2<_Tp, _Up>::__type2()))) __type;
  };
  template < typename _Tp, typename _Up, typename _Vp >
  struct  __promote_3
  {
    private:
      typedef typename ::__gnu_cxx::__promote<_Tp, ::std::__is_integer<_Tp>::__value>::__type __type1;
      typedef typename ::__gnu_cxx::__promote<_Up, ::std::__is_integer<_Up>::__value>::__type __type2;
      typedef typename ::__gnu_cxx::__promote<_Vp, ::std::__is_integer<_Vp>::__value>::__type __type3;
    public:
      typedef __typeof__(((typename ::__gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type1())) + ((typename ::__gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type2())) + ((typename ::__gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type3()))) __type;
  };
  template < typename _Tp, typename _Up, typename _Vp, typename _Wp >
  struct  __promote_4
  {
    private:
      typedef typename ::__gnu_cxx::__promote<_Tp, ::std::__is_integer<_Tp>::__value>::__type __type1;
      typedef typename ::__gnu_cxx::__promote<_Up, ::std::__is_integer<_Up>::__value>::__type __type2;
      typedef typename ::__gnu_cxx::__promote<_Vp, ::std::__is_integer<_Vp>::__value>::__type __type3;
      typedef typename ::__gnu_cxx::__promote<_Wp, ::std::__is_integer<_Wp>::__value>::__type __type4;
    public:
      typedef __typeof__(((typename ::__gnu_cxx::__promote_4<_Tp, _Up, _Vp, _Wp>::__type1())) + ((typename ::__gnu_cxx::__promote_4<_Tp, _Up, _Vp, _Wp>::__type2())) + ((typename ::__gnu_cxx::__promote_4<_Tp, _Up, _Vp, _Wp>::__type3())) + ((typename ::__gnu_cxx::__promote_4<_Tp, _Up, _Vp, _Wp>::__type4()))) __type;
  };
  template < typename _Value >
  struct  __numeric_traits_integer
  {
      static const _Value __min = (_Value) -1 < 0 ? (_Value)1 << (sizeof(_Value) * 8 - ((_Value) -1 < 0)) : (_Value)0;
      static const _Value __max = (_Value) -1 < 0 ? ((((_Value)1 << (sizeof(_Value) * 8 - ((_Value) -1 < 0) - 1)) - 1) << 1) + 1 : ~((_Value)0);
      static const bool __is_signed = (_Value) -1 < 0;
      static const int __digits = sizeof(_Value) * 8 - ((_Value) -1 < 0);
  };
  template < typename _Value >
  struct  __numeric_traits_floating
  {
      static const int __max_digits10 = 2 + (std::__are_same<_Value, float>::__value ? 24 : std::__are_same<_Value, double>::__value ? 53 : 64) * 3010 / 10000;
      static const bool __is_signed = true;
      static const int __digits10 = std::__are_same<_Value, float>::__value ? 6 : std::__are_same<_Value, double>::__value ? 15 : 18;
      static const int __max_exponent10 = std::__are_same<_Value, float>::__value ? 38 : std::__are_same<_Value, double>::__value ? 308 : 4932;
  };
  template < typename _Value >
  struct  __numeric_traits : ::__gnu_cxx::__conditional_type<std::__is_integer<_Value>::__value, ::__gnu_cxx::__numeric_traits_integer<_Value>, ::__gnu_cxx::__numeric_traits_floating<_Value> >::__type
  {
  };
}
namespace std __attribute__((__visibility__("default"))) {
  struct  input_iterator_tag
  {
  };
  struct  output_iterator_tag
  {
  };
  struct  forward_iterator_tag : ::std::input_iterator_tag
  {
  };
  struct  bidirectional_iterator_tag : ::std::forward_iterator_tag
  {
  };
  struct  random_access_iterator_tag : ::std::bidirectional_iterator_tag
  {
  };
  template < typename _Category, typename _Tp, typename _Distance = ::ptrdiff_t, typename _Pointer = _Tp *, typename _Reference = _Tp & >
  struct  iterator
  {
      typedef _Category iterator_category;
      typedef _Tp value_type;
      typedef _Distance difference_type;
      typedef _Pointer pointer;
      typedef _Reference reference;
  };
  template < typename _Iterator >
  struct  iterator_traits
  {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
  };
  template < typename _Tp >
  struct  iterator_traits<_Tp *>
  {
      typedef ::std::random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef _Tp &reference;
  };
  template < typename _Tp >
  struct  iterator_traits<const _Tp *>
  {
      typedef ::std::random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ::ptrdiff_t difference_type;
      typedef const _Tp *pointer;
      typedef const _Tp &reference;
  };
  template < typename _Iter >
  inline typename ::std::iterator_traits<_Iter>::iterator_category __iterator_category(const _Iter &);
  template < typename _Iter >
  inline typename ::std::iterator_traits<_Iter>::iterator_category __iterator_category(const _Iter &)
  {
    return typename ::std::iterator_traits<_Iter>::iterator_category();
  }
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type __distance(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag);
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type __distance(_InputIterator __first, _InputIterator __last, ::std::input_iterator_tag)
  {
    typename ::std::iterator_traits<_InputIterator>::difference_type __n = 0;
    while (__first != __last)
      {
         ++__first;
         ++__n;
      }
    return __n;
  }
  template < typename _RandomAccessIterator >
  inline typename ::std::iterator_traits<_RandomAccessIterator>::difference_type __distance(_RandomAccessIterator __first, _RandomAccessIterator __last, ::std::random_access_iterator_tag);
  template < typename _RandomAccessIterator >
  inline typename ::std::iterator_traits<_RandomAccessIterator>::difference_type __distance(_RandomAccessIterator __first, _RandomAccessIterator __last, ::std::random_access_iterator_tag)
  {
    return __last - __first;
  }
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last);
  template < typename _InputIterator >
  inline typename ::std::iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last)
  {
    return std::__distance(__first, __last, std::__iterator_category(__first));
  }
  template < typename _InputIterator, typename _Distance >
  inline void __advance(_InputIterator &__i, _Distance __n, ::std::input_iterator_tag);
  template < typename _InputIterator, typename _Distance >
  inline void __advance(_InputIterator &__i, _Distance __n, ::std::input_iterator_tag)
  {
    while (__n--)
      {
         ++__i;
      }
  }
  template < typename _BidirectionalIterator, typename _Distance >
  inline void __advance(_BidirectionalIterator &__i, _Distance __n, ::std::bidirectional_iterator_tag);
  template < typename _BidirectionalIterator, typename _Distance >
  inline void __advance(_BidirectionalIterator &__i, _Distance __n, ::std::bidirectional_iterator_tag)
  {
    if (__n > 0)
      {
        while (__n--)
          {
             ++__i;
          }
      }
    else
      {
        while (__n++)
          {
             --__i;
          }
      }
  }
  template < typename _RandomAccessIterator, typename _Distance >
  inline void __advance(_RandomAccessIterator &__i, _Distance __n, ::std::random_access_iterator_tag);
  template < typename _RandomAccessIterator, typename _Distance >
  inline void __advance(_RandomAccessIterator &__i, _Distance __n, ::std::random_access_iterator_tag)
  {
    __i += __n;
  }
  template < typename _InputIterator, typename _Distance >
  inline void advance(_InputIterator &__i, _Distance __n);
  template < typename _InputIterator, typename _Distance >
  inline void advance(_InputIterator &__i, _Distance __n)
  {
    typename ::std::iterator_traits<_InputIterator>::difference_type __d = __n;
    std::__advance(__i, __d, std::__iterator_category(__i));
  }
  template < typename _Iterator >
  class  reverse_iterator : public ::std::iterator<typename ::std::iterator_traits<_Iterator>::iterator_category, typename ::std::iterator_traits<_Iterator>::value_type, typename ::std::iterator_traits<_Iterator>::difference_type, typename ::std::iterator_traits<_Iterator>::pointer, typename ::std::iterator_traits<_Iterator>::reference>
  {
    protected:
      _Iterator current;
    public:
      typedef _Iterator iterator_type;
      typedef typename ::std::iterator_traits<_Iterator>::difference_type difference_type;
      typedef typename ::std::iterator_traits<_Iterator>::reference reference;
      typedef typename ::std::iterator_traits<_Iterator>::pointer pointer;
      inline reverse_iterator()
        : current()
      {
      }
      inline explicit reverse_iterator(typename ::std::reverse_iterator<_Iterator>::iterator_type __x)
        : current(__x)
      {
      }
      inline reverse_iterator(const ::std::reverse_iterator<_Iterator> &__x)
        : current(__x.current)
      {
      }
      template < typename _Iter >
      inline reverse_iterator(const ::std::reverse_iterator<_Iter> &__x)
        : current(__x.base())
      {
      }
      inline typename ::std::reverse_iterator<_Iterator>::iterator_type base() const 
      {
        return ::std::reverse_iterator<_Iterator>::current;
      }
      inline typename ::std::reverse_iterator<_Iterator>::reference operator *() const 
      {
        _Iterator __tmp = ::std::reverse_iterator<_Iterator>::current;
        return * --__tmp;
      }
      inline typename ::std::reverse_iterator<_Iterator>::pointer operator ->() const 
      {
        return &operator *();
      }
      inline ::std::reverse_iterator<_Iterator> &operator ++()
      {
         --::std::reverse_iterator<_Iterator>::current;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator ++(int)
      {
        ::std::reverse_iterator<_Iterator> __tmp = *this;
         --::std::reverse_iterator<_Iterator>::current;
        return __tmp;
      }
      inline ::std::reverse_iterator<_Iterator> &operator --()
      {
         ++::std::reverse_iterator<_Iterator>::current;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator --(int)
      {
        ::std::reverse_iterator<_Iterator> __tmp = *this;
         ++::std::reverse_iterator<_Iterator>::current;
        return __tmp;
      }
      inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return ::std::reverse_iterator<_Iterator>(::std::reverse_iterator<_Iterator>::current - __n);
      }
      inline ::std::reverse_iterator<_Iterator> &operator +=(typename ::std::reverse_iterator<_Iterator>::difference_type __n)
      {
        ::std::reverse_iterator<_Iterator>::current -= __n;
        return *this;
      }
      inline ::std::reverse_iterator<_Iterator> operator -(typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return ::std::reverse_iterator<_Iterator>(::std::reverse_iterator<_Iterator>::current + __n);
      }
      inline ::std::reverse_iterator<_Iterator> &operator -=(typename ::std::reverse_iterator<_Iterator>::difference_type __n)
      {
        ::std::reverse_iterator<_Iterator>::current += __n;
        return *this;
      }
      inline typename ::std::reverse_iterator<_Iterator>::reference operator [](typename ::std::reverse_iterator<_Iterator>::difference_type __n) const 
      {
        return *(*this + __n);
      }
  };
  template < typename _Iterator >
  inline bool operator ==(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator ==(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __x.base() == __y.base();
  }
  template < typename _Iterator >
  inline bool operator <(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator <(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y.base() < __x.base();
  }
  template < typename _Iterator >
  inline bool operator !=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator !=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__x == __y);
  }
  template < typename _Iterator >
  inline bool operator >(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator >(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y < __x;
  }
  template < typename _Iterator >
  inline bool operator <=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator <=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__y < __x);
  }
  template < typename _Iterator >
  inline bool operator >=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline bool operator >=(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return !(__x < __y);
  }
  template < typename _Iterator >
  inline typename ::std::reverse_iterator<_Iterator>::difference_type operator -(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y);
  template < typename _Iterator >
  inline typename ::std::reverse_iterator<_Iterator>::difference_type operator -(const ::std::reverse_iterator<_Iterator> &__x, const ::std::reverse_iterator<_Iterator> &__y)
  {
    return __y.base() - __x.base();
  }
  template < typename _Iterator >
  inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n, const ::std::reverse_iterator<_Iterator> &__x);
  template < typename _Iterator >
  inline ::std::reverse_iterator<_Iterator> operator +(typename ::std::reverse_iterator<_Iterator>::difference_type __n, const ::std::reverse_iterator<_Iterator> &__x)
  {
    return ::std::reverse_iterator<_Iterator>(__x.base() - __n);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator ==(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator ==(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __x.base() == __y.base();
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y.base() < __x.base();
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator !=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator !=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__x == __y);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y < __x;
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator <=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__y < __x);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline bool operator >=(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return !(__x < __y);
  }
  template < typename _IteratorL, typename _IteratorR >
  inline typename ::std::reverse_iterator<_IteratorL>::difference_type operator -(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y);
  template < typename _IteratorL, typename _IteratorR >
  inline typename ::std::reverse_iterator<_IteratorL>::difference_type operator -(const ::std::reverse_iterator<_IteratorL> &__x, const ::std::reverse_iterator<_IteratorR> &__y)
  {
    return __y.base() - __x.base();
  }
 /* Instantiation of class template '::std::iterator< ::std::output_iterator_tag, void, void, void, void>' */ 
  template < typename _Container >
  class  back_insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
    public:
      typedef _Container container_type;
      inline explicit back_insert_iterator(_Container &__x)
        : container(&__x)
      {
      }
      inline ::std::back_insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::back_insert_iterator<_Container>::container->push_back(__value);
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::back_insert_iterator<_Container> operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container >
  inline ::std::back_insert_iterator<_Container> back_inserter(_Container &__x);
  template < typename _Container >
  inline ::std::back_insert_iterator<_Container> back_inserter(_Container &__x)
  {
    return ::std::back_insert_iterator<_Container>(__x);
  }
  template < typename _Container >
  class  front_insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
    public:
      typedef _Container container_type;
      inline explicit front_insert_iterator(_Container &__x)
        : container(&__x)
      {
      }
      inline ::std::front_insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::front_insert_iterator<_Container>::container->push_front(__value);
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::front_insert_iterator<_Container> operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container >
  inline ::std::front_insert_iterator<_Container> front_inserter(_Container &__x);
  template < typename _Container >
  inline ::std::front_insert_iterator<_Container> front_inserter(_Container &__x)
  {
    return ::std::front_insert_iterator<_Container>(__x);
  }
  template < typename _Container >
  class  insert_iterator : public ::std::iterator< ::std::output_iterator_tag, void, void, void, void>
  {
    protected:
      _Container *container;
      typename _Container::iterator iter;
    public:
      typedef _Container container_type;
      inline insert_iterator(_Container &__x, typename _Container::iterator __i)
        : container(&__x), iter(__i)
      {
      }
      inline ::std::insert_iterator<_Container> &operator =(typename _Container::const_reference __value)
      {
        ::std::insert_iterator<_Container>::iter = ::std::insert_iterator<_Container>::container->insert(::std::insert_iterator<_Container>::iter, __value);
         ++::std::insert_iterator<_Container>::iter;
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator *()
      {
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator ++()
      {
        return *this;
      }
      inline ::std::insert_iterator<_Container> &operator ++(int)
      {
        return *this;
      }
  };
  template < typename _Container, typename _Iterator >
  inline ::std::insert_iterator<_Container> inserter(_Container &__x, _Iterator __i);
  template < typename _Container, typename _Iterator >
  inline ::std::insert_iterator<_Container> inserter(_Container &__x, _Iterator __i)
  {
    return ::std::insert_iterator<_Container>(__x, typename _Container::iterator(__i));
  }
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::std::iterator_traits;
  using ::std::iterator;
  template < typename _Iterator, typename _Container >
  class  __normal_iterator
  {
    protected:
      _Iterator _M_current;
    public:
      typedef _Iterator iterator_type;
      typedef typename ::std::iterator_traits<_Iterator>::iterator_category iterator_category;
      typedef typename ::std::iterator_traits<_Iterator>::value_type value_type;
      typedef typename ::std::iterator_traits<_Iterator>::difference_type difference_type;
      typedef typename ::std::iterator_traits<_Iterator>::reference reference;
      typedef typename ::std::iterator_traits<_Iterator>::pointer pointer;
      inline __normal_iterator()
        : _M_current(_Iterator())
      {
      }
      inline explicit __normal_iterator(const _Iterator &__i)
        : _M_current(__i)
      {
      }
      template < typename _Iter >
      inline __normal_iterator(const ::__gnu_cxx::__normal_iterator<_Iter, typename ::__gnu_cxx::__enable_if<std::__are_same<_Iter, typename _Container::pointer>::__value, _Container>::__type> &__i)
        : _M_current(__i.base())
      {
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::reference operator *() const 
      {
        return *::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::pointer operator ->() const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator ++()
      {
         ++::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator ++(int)
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current++);
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator --()
      {
         --::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator --(int)
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current--);
      }
      inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::reference operator [](const typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type &__n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current[__n];
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator +=(const typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type &__n)
      {
        ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current += __n;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(const typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type &__n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current + __n);
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &operator -=(const typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type &__n)
      {
        ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current -= __n;
        return *this;
      }
      inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator -(const typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type &__n) const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current - __n);
      }
      inline const _Iterator &base() const 
      {
        return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::_M_current;
      }
  };
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() == __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator ==(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() == __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() != __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator !=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() != __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() < __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator <(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() < __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() > __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator >(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() > __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() <= __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator <=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() <= __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() >= __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline bool operator >=(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() >= __rhs.base();
  }
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_IteratorL, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs);
  template < typename _IteratorL, typename _IteratorR, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_IteratorL, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_IteratorL, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_IteratorR, _Container> &__rhs)
  {
    return __lhs.base() - __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs);
  template < typename _Iterator, typename _Container >
  inline typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type operator -(const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__lhs, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__rhs)
  {
    return __lhs.base() - __rhs.base();
  }
  template < typename _Iterator, typename _Container >
  inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__i);
  template < typename _Iterator, typename _Container >
  inline ::__gnu_cxx::__normal_iterator<_Iterator, _Container> operator +(typename ::__gnu_cxx::__normal_iterator<_Iterator, _Container>::difference_type __n, const ::__gnu_cxx::__normal_iterator<_Iterator, _Container> &__i)
  {
    return ::__gnu_cxx::__normal_iterator<_Iterator, _Container>(__i.base() + __n);
  }
}
namespace std __attribute__((__visibility__("default"))) {
  namespace __debug { }
}
namespace __gnu_debug {
  using namespace ::std::__debug;
}
namespace std __attribute__((__visibility__("default"))) {
  template < bool _BoolType >
  struct  __iter_swap
  {
      template < typename _ForwardIterator1, typename _ForwardIterator2 >
      static inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
      {
        typedef typename ::std::iterator_traits<_ForwardIterator1>::value_type _ValueType1;
        _ValueType1 __tmp = *__a;
        *__a = *__b;
        *__b = __tmp;
      }
  };
  template <>
  struct  __iter_swap<true>
  {
      template < typename _ForwardIterator1, typename _ForwardIterator2 >
      static inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
      {
        swap(*__a, *__b);
      }
  };
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b);
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b)
  {
    typedef typename ::std::iterator_traits<_ForwardIterator1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_ForwardIterator2>::value_type _ValueType2;
    typedef typename ::std::iterator_traits<_ForwardIterator1>::reference _ReferenceType1;
    typedef typename ::std::iterator_traits<_ForwardIterator2>::reference _ReferenceType2;
    std::__iter_swap<(__are_same<_ValueType1, _ValueType2>::__value && __are_same<_ValueType1 &, _ReferenceType1>::__value) && __are_same<_ValueType2 &, _ReferenceType2>::__value>::iter_swap(__a, __b);
  }
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2);
  template < typename _ForwardIterator1, typename _ForwardIterator2 >
  _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2)
  {
    ;
    for (; __first1 != __last1; ( ++__first1,  ++__first2))
      {
        std::iter_swap(__first1, __first2);
      }
    return __first2;
  }
  template < typename _Tp >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b);
  template < typename _Tp >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b)
  {
    if (__b < __a)
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b);
  template < typename _Tp >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b)
  {
    if (__a < __b)
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp, typename _Compare >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b, _Compare __comp);
  template < typename _Tp, typename _Compare >
  inline const _Tp &min(const _Tp &__a, const _Tp &__b, _Compare __comp)
  {
    if (__comp(__b, __a))
      {
        return __b;
      }
    return __a;
  }
  template < typename _Tp, typename _Compare >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b, _Compare __comp);
  template < typename _Tp, typename _Compare >
  inline const _Tp &max(const _Tp &__a, const _Tp &__b, _Compare __comp)
  {
    if (__comp(__a, __b))
      {
        return __b;
      }
    return __a;
  }
  template < typename _Iterator, bool _IsNormal = __is_normal_iterator<_Iterator>::__value >
  struct  __niter_base
  {
      static inline _Iterator __b(_Iterator __it)
      {
        return __it;
      }
  };
  template < typename _Iterator >
  struct  __niter_base<_Iterator, true>
  {
      static inline typename _Iterator::iterator_type __b(_Iterator __it)
      {
        return __it.base();
      }
  };
  template < typename _Iterator, bool _IsMove = __is_move_iterator<_Iterator>::__value >
  struct  __miter_base
  {
      static inline _Iterator __b(_Iterator __it)
      {
        return __it;
      }
  };
  template < typename _Iterator >
  struct  __miter_base<_Iterator, true>
  {
      static inline typename _Iterator::iterator_type __b(_Iterator __it)
      {
        return __it.base();
      }
  };
  template < bool __nontype_tpl_param_1_0__, bool __nontype_tpl_param_1_1__, typename __type_tpl__param_1_2__ >
  struct  __copy_move
  {
      template < typename _II, typename _OI >
      static inline _OI __copy_m(_II __first, _II __last, _OI __result)
      {
        for (; __first != __last; ( ++__result,  ++__first))
          {
            *__result = *__first;
          }
        return __result;
      }
  };
  template <>
  struct  __copy_move<false, false, ::std::random_access_iterator_tag>
  {
      template < typename _II, typename _OI >
      static inline _OI __copy_m(_II __first, _II __last, _OI __result)
      {
        typedef typename ::std::iterator_traits<_II>::difference_type _Distance;
        for (_Distance __n = __last - __first; __n > 0;  --__n)
          {
            *__result = *__first;
             ++__first;
             ++__result;
          }
        return __result;
      }
  };
  template < bool _IsMove >
  struct  __copy_move<_IsMove, true, ::std::random_access_iterator_tag>
  {
      template < typename _Tp >
      static inline _Tp *__copy_m(const _Tp *__first, const _Tp *__last, _Tp *__result)
      {
        __builtin_memmove(__result, __first, sizeof(_Tp) * (__last - __first));
        return __result + (__last - __first);
      }
  };
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a(_II __first, _II __last, _OI __result);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a(_II __first, _II __last, _OI __result)
  {
    typedef typename ::std::iterator_traits<_II>::value_type _ValueTypeI;
    typedef typename ::std::iterator_traits<_OI>::value_type _ValueTypeO;
    typedef typename ::std::iterator_traits<_II>::iterator_category _Category;
    const bool __simple = (((__is_pod(_ValueTypeI)) && __is_pointer<_II>::__value) && __is_pointer<_OI>::__value) && __are_same<_ValueTypeI, _ValueTypeO>::__value;
    return std::__copy_move<_IsMove, __simple, _Category>::__copy_m(__first, __last, __result);
  }
  template < typename _CharT >
  struct char_traits;
  template < typename _CharT, typename _Traits >
  class istreambuf_iterator;
  template < typename _CharT, typename _Traits >
  class ostreambuf_iterator;
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> > >::__type __copy_move_a2(_CharT *, _CharT *, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> >);
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> > >::__type __copy_move_a2(const _CharT *, const _CharT *, ::std::ostreambuf_iterator<_CharT, ::std::char_traits<_CharT> >);
  template < bool _IsMove, typename _CharT >
  typename ::__gnu_cxx::__enable_if<__is_char<_CharT>::__value, _CharT *>::__type __copy_move_a2(::std::istreambuf_iterator<_CharT, ::std::char_traits<_CharT> >, ::std::istreambuf_iterator<_CharT, ::std::char_traits<_CharT> >, _CharT *);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a2(_II __first, _II __last, _OI __result);
  template < bool _IsMove, typename _II, typename _OI >
  inline _OI __copy_move_a2(_II __first, _II __last, _OI __result)
  {
    return _OI(std::__copy_move_a<_IsMove>(std::__niter_base<_II>::__b(__first), std::__niter_base<_II>::__b(__last), std::__niter_base<_OI>::__b(__result)));
  }
  template < typename _II, typename _OI >
  inline _OI copy(_II __first, _II __last, _OI __result);
  template < typename _II, typename _OI >
  inline _OI copy(_II __first, _II __last, _OI __result)
  {
    ;
    return std::__copy_move_a2<__is_move_iterator<_II>::__value>(std::__miter_base<_II>::__b(__first), std::__miter_base<_II>::__b(__last), __result);
  }
  template < bool __nontype_tpl_param_1_0__, bool __nontype_tpl_param_1_1__, typename __type_tpl__param_1_2__ >
  struct  __copy_move_backward
  {
      template < typename _BI1, typename _BI2 >
      static inline _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
      {
        while (__first != __last)
          {
            * --__result = * --__last;
          }
        return __result;
      }
  };
  template <>
  struct  __copy_move_backward<false, false, ::std::random_access_iterator_tag>
  {
      template < typename _BI1, typename _BI2 >
      static inline _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result)
      {
        typename ::std::iterator_traits<_BI1>::difference_type __n;
        for (__n = __last - __first; __n > 0;  --__n)
          {
            * --__result = * --__last;
          }
        return __result;
      }
  };
  template < bool _IsMove >
  struct  __copy_move_backward<_IsMove, true, ::std::random_access_iterator_tag>
  {
      template < typename _Tp >
      static inline _Tp *__copy_move_b(const _Tp *__first, const _Tp *__last, _Tp *__result)
      {
        const ::ptrdiff_t _Num = __last - __first;
        __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
        return __result - _Num;
      }
  };
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result);
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    typedef typename ::std::iterator_traits<_BI1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_BI2>::value_type _ValueType2;
    typedef typename ::std::iterator_traits<_BI1>::iterator_category _Category;
    const bool __simple = (((__is_pod(_ValueType1)) && __is_pointer<_BI1>::__value) && __is_pointer<_BI2>::__value) && __are_same<_ValueType1, _ValueType2>::__value;
    return std::__copy_move_backward<_IsMove, __simple, _Category>::__copy_move_b(__first, __last, __result);
  }
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result);
  template < bool _IsMove, typename _BI1, typename _BI2 >
  inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    return _BI2(std::__copy_move_backward_a<_IsMove>(std::__niter_base<_BI1>::__b(__first), std::__niter_base<_BI1>::__b(__last), std::__niter_base<_BI2>::__b(__result)));
  }
  template < typename _BI1, typename _BI2 >
  inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result);
  template < typename _BI1, typename _BI2 >
  inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
  {
    ;
    return std::__copy_move_backward_a2<__is_move_iterator<_BI1>::__value>(std::__miter_base<_BI1>::__b(__first), std::__miter_base<_BI1>::__b(__last), __result);
  }
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    for (; __first != __last;  ++__first)
      {
        *__first = __value;
      }
  }
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type __fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    const _Tp __tmp = __value;
    for (; __first != __last;  ++__first)
      {
        *__first = __tmp;
      }
  }
  template < typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type __fill_a(_Tp *__first, _Tp *__last, const _Tp &__c);
  template < typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type __fill_a(_Tp *__first, _Tp *__last, const _Tp &__c)
  {
    const _Tp __tmp = __c;
    __builtin_memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
  }
  template < typename _ForwardIterator, typename _Tp >
  inline void fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value);
  template < typename _ForwardIterator, typename _Tp >
  inline void fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value)
  {
    ;
    std::__fill_a(std::__niter_base<_ForwardIterator>::__b(__first), std::__niter_base<_ForwardIterator>::__b(__last), __value);
  }
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value);
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value)
  {
    for (; __n > 0; ( --__n,  ++__first))
      {
        *__first = __value;
      }
    return __first;
  }
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value);
  template < typename _OutputIterator, typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, _OutputIterator>::__type __fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value)
  {
    const _Tp __tmp = __value;
    for (; __n > 0; ( --__n,  ++__first))
      {
        *__first = __tmp;
      }
    return __first;
  }
  template < typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp *>::__type __fill_n_a(_Tp *__first, _Size __n, const _Tp &__c);
  template < typename _Size, typename _Tp >
  inline typename ::__gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp *>::__type __fill_n_a(_Tp *__first, _Size __n, const _Tp &__c)
  {
    std::__fill_a(__first, __first + __n, __c);
    return __first + __n;
  }
  template < typename _OI, typename _Size, typename _Tp >
  inline _OI fill_n(_OI __first, _Size __n, const _Tp &__value);
  template < typename _OI, typename _Size, typename _Tp >
  inline _OI fill_n(_OI __first, _Size __n, const _Tp &__value)
  {
    return _OI(std::__fill_n_a(std::__niter_base<_OI>::__b(__first), __n, __value));
  }
  template < bool _BoolType >
  struct  __equal
  {
      template < typename _II1, typename _II2 >
      static inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2)
      {
        for (; __first1 != __last1; ( ++__first1,  ++__first2))
          {
            if (!(*__first1 == *__first2))
              {
                return false;
              }
          }
        return true;
      }
  };
  template <>
  struct  __equal<true>
  {
      template < typename _Tp >
      static inline bool equal(const _Tp *__first1, const _Tp *__last1, const _Tp *__first2)
      {
        return !__builtin_memcmp(__first1, __first2, sizeof(_Tp) * (__last1 - __first1));
      }
  };
  template < typename _II1, typename _II2 >
  inline bool __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2);
  template < typename _II1, typename _II2 >
  inline bool __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2)
  {
    typedef typename ::std::iterator_traits<_II1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple = ((__is_integer<_ValueType1>::__value && __is_pointer<_II1>::__value) && __is_pointer<_II2>::__value) && __are_same<_ValueType1, _ValueType2>::__value;
    return std::__equal<__simple>::equal(__first1, __last1, __first2);
  }
  template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
  struct  __lc_rai
  {
      template < typename _II1, typename _II2 >
      static inline _II1 __newlast1(_II1, _II1 __last1, _II2, _II2)
      {
        return __last1;
      }
      template < typename _II >
      static inline bool __cnd2(_II __first, _II __last)
      {
        return __first != __last;
      }
  };
  template <>
  struct  __lc_rai< ::std::random_access_iterator_tag, ::std::random_access_iterator_tag>
  {
      template < typename _RAI1, typename _RAI2 >
      static inline _RAI1 __newlast1(_RAI1 __first1, _RAI1 __last1, _RAI2 __first2, _RAI2 __last2)
      {
        const typename ::std::iterator_traits<_RAI1>::difference_type __diff1 = __last1 - __first1;
        const typename ::std::iterator_traits<_RAI2>::difference_type __diff2 = __last2 - __first2;
        return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
      }
      template < typename _RAI >
      static inline bool __cnd2(_RAI, _RAI)
      {
        return true;
      }
  };
  template < bool _BoolType >
  struct  __lexicographical_compare
  {
      template < typename _II1, typename _II2 >
      static bool __lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  };
  template < bool _BoolType >
  template < typename _II1, typename _II2 >
  bool __lexicographical_compare<_BoolType>::__lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    typedef typename ::std::iterator_traits<_II1>::iterator_category _Category1;
    typedef typename ::std::iterator_traits<_II2>::iterator_category _Category2;
    typedef ::std::__lc_rai<_Category1, _Category2> __rai_type;
    __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
    for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2); ( ++__first1,  ++__first2))
      {
        if (*__first1 < *__first2)
          {
            return true;
          }
        if (*__first2 < *__first1)
          {
            return false;
          }
      }
    return __first1 == __last1 && __first2 != __last2;
  }
  template <>
  struct  __lexicographical_compare<true>
  {
      template < typename _Tp, typename _Up >
      static inline bool __lc(const _Tp *__first1, const _Tp *__last1, const _Up *__first2, const _Up *__last2)
      {
        const ::size_t __len1 = __last1 - __first1;
        const ::size_t __len2 = __last2 - __first2;
        const int __result = __builtin_memcmp(__first1, __first2, std::min(__len1, __len2));
        return __result != 0 ? __result < 0 : __len1 < __len2;
      }
  };
  template < typename _II1, typename _II2 >
  inline bool __lexicographical_compare_aux(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  template < typename _II1, typename _II2 >
  inline bool __lexicographical_compare_aux(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    typedef typename ::std::iterator_traits<_II1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple = ((((__is_byte<_ValueType1>::__value && __is_byte<_ValueType2>::__value) && !__gnu_cxx::__numeric_traits<_ValueType1>::__is_signed) && !__gnu_cxx::__numeric_traits<_ValueType2>::__is_signed) && __is_pointer<_II1>::__value) && __is_pointer<_II2>::__value;
    return std::__lexicographical_compare<__simple>::__lc(__first1, __last1, __first2, __last2);
  }
  template < typename _II1, typename _II2 >
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2);
  template < typename _II1, typename _II2 >
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2)
  {
    ;
    return std::__equal_aux(std::__niter_base<_II1>::__b(__first1), std::__niter_base<_II1>::__b(__last1), std::__niter_base<_II2>::__b(__first2));
  }
  template < typename _IIter1, typename _IIter2, typename _BinaryPredicate >
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _BinaryPredicate __binary_pred);
  template < typename _IIter1, typename _IIter2, typename _BinaryPredicate >
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _BinaryPredicate __binary_pred)
  {
    ;
    for (; __first1 != __last1; ( ++__first1,  ++__first2))
      {
        if (!bool(__binary_pred(*__first1, *__first2)))
          {
            return false;
          }
      }
    return true;
  }
  template < typename _II1, typename _II2 >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2);
  template < typename _II1, typename _II2 >
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
  {
    typedef typename ::std::iterator_traits<_II1>::value_type _ValueType1;
    typedef typename ::std::iterator_traits<_II2>::value_type _ValueType2;
    ;
    ;
    return std::__lexicographical_compare_aux(std::__niter_base<_II1>::__b(__first1), std::__niter_base<_II1>::__b(__last1), std::__niter_base<_II2>::__b(__first2), std::__niter_base<_II2>::__b(__last2));
  }
  template < typename _II1, typename _II2, typename _Compare >
  bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp);
  template < typename _II1, typename _II2, typename _Compare >
  bool lexicographical_compare(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2, _Compare __comp)
  {
    typedef typename ::std::iterator_traits<_II1>::iterator_category _Category1;
    typedef typename ::std::iterator_traits<_II2>::iterator_category _Category2;
    typedef ::std::__lc_rai<_Category1, _Category2> __rai_type;
    ;
    ;
    __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
    for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2); ( ++__first1,  ++__first2))
      {
        if (__comp(*__first1, *__first2))
          {
            return true;
          }
        if (__comp(*__first2, *__first1))
          {
            return false;
          }
      }
    return __first1 == __last1 && __first2 != __last2;
  }
  template < typename _InputIterator1, typename _InputIterator2 >
  ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2);
  template < typename _InputIterator1, typename _InputIterator2 >
  ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
  {
    ;
    while (__first1 != __last1 && *__first1 == *__first2)
      {
         ++__first1;
         ++__first2;
      }
    return ::std::pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred);
  template < typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate >
  ::std::pair<_InputIterator1, _InputIterator2> mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred)
  {
    ;
    while (__first1 != __last1 && bool(__binary_pred(*__first1, *__first2)))
      {
         ++__first1;
         ++__first2;
      }
    return ::std::pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
}
namespace __gnu_cxx __attribute__((__visibility__("default"))) {
  using ::std::size_t;
  using ::std::ptrdiff_t;
  template < typename _Tp >
  class  new_allocator
  {
    public:
      typedef ::size_t size_type;
      typedef ::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef const _Tp *const_pointer;
      typedef _Tp &reference;
      typedef const _Tp &const_reference;
      typedef _Tp value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::__gnu_cxx::new_allocator<_Tp1> other;
      };
      inline new_allocator() throw()
      {
      }
      inline new_allocator(const ::__gnu_cxx::new_allocator<_Tp> &) throw()
      {
      }
      template < typename _Tp1 >
      inline new_allocator(const ::__gnu_cxx::new_allocator<_Tp1> &) throw()
      {
      }
      inline ~new_allocator() throw()
      {
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::pointer address(typename ::__gnu_cxx::new_allocator<_Tp>::reference __x) const 
      {
        return &__x;
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::const_pointer address(typename ::__gnu_cxx::new_allocator<_Tp>::const_reference __x) const 
      {
        return &__x;
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::pointer allocate(typename ::__gnu_cxx::new_allocator<_Tp>::size_type __n, const void *  = (0))
      {
        if (__builtin_expect(__n > this->max_size(), false))
          {
            std::__throw_bad_alloc();
          }
        return static_cast<_Tp *>(::operator new(__n * sizeof(_Tp)));
      }
      inline void deallocate(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p, typename ::__gnu_cxx::new_allocator<_Tp>::size_type)
      {
        ::operator delete(__p);
      }
      inline typename ::__gnu_cxx::new_allocator<_Tp>::size_type max_size() const  throw()
      {
        return (unsigned long int) -1 / sizeof(_Tp);
      }
      inline void construct(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p, const _Tp &__val)
      {
        ::new ((void *)__p)_Tp(__val);
      }
      inline void destroy(typename ::__gnu_cxx::new_allocator<_Tp>::pointer __p)
      {
        __p->~_Tp();
      }
  };
  template < typename _Tp >
  inline bool operator ==(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator ==(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &)
  {
    return true;
  }
  template < typename _Tp >
  inline bool operator !=(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator !=(const ::__gnu_cxx::new_allocator<_Tp> &, const ::__gnu_cxx::new_allocator<_Tp> &)
  {
    return false;
  }
}
namespace std __attribute__((__visibility__("default"))) {
  template < typename _Tp >
  class allocator;
  template <>
  class  allocator<void>
  {
    public:
      typedef ::size_t size_type;
      typedef ::ptrdiff_t difference_type;
      typedef void *pointer;
      typedef const void *const_pointer;
      typedef void value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::std::allocator<_Tp1> other;
      };
  };
  template < typename _Tp >
  class  allocator : public ::__gnu_cxx::new_allocator<_Tp>
  {
    public:
      typedef ::size_t size_type;
      typedef ::ptrdiff_t difference_type;
      typedef _Tp *pointer;
      typedef const _Tp *const_pointer;
      typedef _Tp &reference;
      typedef const _Tp &const_reference;
      typedef _Tp value_type;
      template < typename _Tp1 >
      struct  rebind
      {
          typedef ::std::allocator<_Tp1> other;
      };
      inline allocator() throw()
      {
      }
      inline allocator(const ::std::allocator<_Tp> &__a) throw()
        : __gnu_cxx::new_allocator<_Tp>(__a)
      {
      }
      template < typename _Tp1 >
      inline allocator(const ::std::allocator<_Tp1> &) throw()
      {
      }
      inline ~allocator() throw()
      {
      }
  };
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &);
  template < typename _T1, typename _T2 >
  inline bool operator ==(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &)
  {
    return true;
  }
  template < typename _Tp >
  inline bool operator ==(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator ==(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &)
  {
    return true;
  }
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &);
  template < typename _T1, typename _T2 >
  inline bool operator !=(const ::std::allocator<_T1> &, const ::std::allocator<_T2> &)
  {
    return false;
  }
  template < typename _Tp >
  inline bool operator !=(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &);
  template < typename _Tp >
  inline bool operator !=(const ::std::allocator<_Tp> &, const ::std::allocator<_Tp> &)
  {
    return false;
  }
  extern template class ::std::allocator<char>;
  extern template class ::std::allocator<wchar_t>;
  template < typename _Alloc, bool __nontype_tpl_param_1_1__ = __is_empty(_Alloc) >
  struct  __alloc_swap
  {
      static inline void _S_do_it(_Alloc &, _Alloc &)
      {
      }
  };
  template < typename _Alloc >
  struct  __alloc_swap<_Alloc, false>
  {
      static inline void _S_do_it(_Alloc &__one, _Alloc &__two)
      {
        if (__one != __two)
          {
            swap(__one, __two);
          }
      }
  };
  template < typename _Alloc, bool __nontype_tpl_param_1_1__ = __is_empty(_Alloc) >
  struct  __alloc_neq
  {
      static inline bool _S_do_it(const _Alloc &, const _Alloc &)
      {
        return false;
      }
  };
  template < typename _Alloc >
  struct  __alloc_neq<_Alloc, false>
  {
      static inline bool _S_do_it(const _Alloc &__one, const _Alloc &__two)
      {
        return __one != __two;
      }
  };
  template < typename _Arg, typename _Result >
  struct  unary_function
  {
      typedef _Arg argument_type;
      typedef _Result result_type;
  };
  template < typename _Arg1, typename _Arg2, typename _Result >
  struct  binary_function
  {
      typedef _Arg1 first_argument_type;
      typedef _Arg2 second_argument_type;
      typedef _Result result_type;
  };
  template < typename _Tp >
  struct  plus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x + __y;
      }
  };
  template < typename _Tp >
  struct  minus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x - __y;
      }
  };
  template < typename _Tp >
  struct  multiplies : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x * __y;
      }
  };
  template < typename _Tp >
  struct  divides : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x / __y;
      }
  };
  template < typename _Tp >
  struct  modulus : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x % __y;
      }
  };
  template < typename _Tp >
  struct  negate : ::std::unary_function<_Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x) const 
      {
        return  -__x;
      }
  };
  template < typename _Tp >
  struct  equal_to : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x == __y;
      }
  };
  template < typename _Tp >
  struct  not_equal_to : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x != __y;
      }
  };
  template < typename _Tp >
  struct  greater : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x > __y;
      }
  };
  template < typename _Tp >
  struct  less : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x < __y;
      }
  };
  template < typename _Tp >
  struct  greater_equal : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x >= __y;
      }
  };
  template < typename _Tp >
  struct  less_equal : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x <= __y;
      }
  };
  template < typename _Tp >
  struct  logical_and : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x && __y;
      }
  };
  template < typename _Tp >
  struct  logical_or : ::std::binary_function<_Tp, _Tp, bool>
  {
      inline bool operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x || __y;
      }
  };
  template < typename _Tp >
  struct  logical_not : ::std::unary_function<_Tp, bool>
  {
      inline bool operator ()(const _Tp &__x) const 
      {
        return !__x;
      }
  };
  template < typename _Tp >
  struct  bit_and : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x & __y;
      }
  };
  template < typename _Tp >
  struct  bit_or : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x | __y;
      }
  };
  template < typename _Tp >
  struct  bit_xor : ::std::binary_function<_Tp, _Tp, _Tp>
  {
      inline _Tp operator ()(const _Tp &__x, const _Tp &__y) const 
      {
        return __x ^ __y;
      }
  };
  template < typename _Predicate >
  class  unary_negate : public ::std::unary_function<typename _Predicate::argument_type, bool>
  {
    protected:
      _Predicate _M_pred;
    public:
      inline explicit unary_negate(const _Predicate &__x)
        : _M_pred(__x)
      {
      }
      inline bool operator ()(const typename _Predicate::argument_type &__x) const 
      {
        return !_M_pred(__x);
      }
  };
  template < typename _Predicate >
  inline ::std::unary_negate<_Predicate> not1(const _Predicate &__pred);
  template < typename _Predicate >
  inline ::std::unary_negate<_Predicate> not1(const _Predicate &__pred)
  {
    return ::std::unary_negate<_Predicate>(__pred);
  }
  template < typename _Predicate >
  class  binary_negate : public ::std::binary_function<typename _Predicate::first_argument_type, typename _Predicate::second_argument_type, bool>
  {
    protected:
      _Predicate _M_pred;
    public:
      inline explicit binary_negate(const _Predicate &__x)
        : _M_pred(__x)
      {
      }
      inline bool operator ()(const typename _Predicate::first_argument_type &__x, const typename _Predicate::second_argument_type &__y) const 
      {
        return !_M_pred(__x, __y);
      }
  };
  template < typename _Predicate >
  inline ::std::binary_negate<_Predicate> not2(const _Predicate &__pred);
  template < typename _Predicate >
  inline ::std::binary_negate<_Predicate> not2(const _Predicate &__pred)
  {
    return ::std::binary_negate<_Predicate>(__pred);
  }
  template < typename _Arg, typename _Result >
  class  pointer_to_unary_function : public ::std::unary_function<_Arg, _Result>
  {
    protected:
      _Result (*_M_ptr)(_Arg);
    public:
      inline pointer_to_unary_function()
      {
      }
      inline explicit pointer_to_unary_function(_Result (*__x)(_Arg))
        : _M_ptr(__x)
      {
      }
      inline _Result operator ()(_Arg __x) const 
      {
        return _M_ptr(__x);
      }
  };
  template < typename _Arg, typename _Result >
  inline ::std::pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__x)(_Arg));
  template < typename _Arg, typename _Result >
  inline ::std::pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__x)(_Arg))
  {
    return ::std::pointer_to_unary_function<_Arg, _Result>(__x);
  }
  template < typename _Arg1, typename _Arg2, typename _Result >
  class  pointer_to_binary_function : public ::std::binary_function<_Arg1, _Arg2, _Result>
  {
    protected:
      _Result (*_M_ptr)(_Arg1, _Arg2);
    public:
      inline pointer_to_binary_function()
      {
      }
      inline explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
        : _M_ptr(__x)
      {
      }
      inline _Result operator ()(_Arg1 __x, _Arg2 __y) const 
      {
        return _M_ptr(__x, __y);
      }
  };
  template < typename _Arg1, typename _Arg2, typename _Result >
  inline ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(_Result (*__x)(_Arg1, _Arg2));
  template < typename _Arg1, typename _Arg2, typename _Result >
  inline ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(_Result (*__x)(_Arg1, _Arg2))
  {
    return ::std::pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x);
  }
  template < typename _Tp >
  struct  _Identity : ::std::unary_function<_Tp, _Tp>
  {
      inline _Tp &operator ()(_Tp &__x) const 
      {
        return __x;
      }
      inline const _Tp &operator ()(const _Tp &__x) const 
      {
        return __x;
      }
  };
  template < typename _Pair >
  struct  _Select1st : ::std::unary_function<_Pair, typename _Pair::first_type>
  {
      inline typename _Pair::first_type &operator ()(_Pair &__x) const 
      {
        return __x.first;
      }
      inline const typename _Pair::first_type &operator ()(const _Pair &__x) const 
      {
        return __x.first;
      }
  };
  template < typename _Pair >
  struct  _Select2nd : ::std::unary_function<_Pair, typename _Pair::second_type>
  {
      inline typename _Pair::second_type &operator ()(_Pair &__x) const 
      {
        return __x.second;
      }
      inline const typename _Pair::second_type &operator ()(const _Pair &__x) const 
      {
        return __x.second;
      }
  };
  template < typename _Ret, typename _Tp >
  class  mem_fun_t : public ::std::unary_function<_Tp *, _Ret>
  {
    public:
      inline explicit mem_fun_t(_Ret (_Tp::*__pf)())
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp *__p) const 
      {
        return (__p->*::std::mem_fun_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)();
  };
  template < typename _Ret, typename _Tp >
  class  const_mem_fun_t : public ::std::unary_function<const _Tp *, _Ret>
  {
    public:
      inline explicit const_mem_fun_t(_Ret (_Tp::*__pf)() const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp *__p) const 
      {
        return (__p->*::std::const_mem_fun_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)() const ;
  };
  template < typename _Ret, typename _Tp >
  class  mem_fun_ref_t : public ::std::unary_function<_Tp, _Ret>
  {
    public:
      inline explicit mem_fun_ref_t(_Ret (_Tp::*__pf)())
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp &__r) const 
      {
        return (__r.*::std::mem_fun_ref_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)();
  };
  template < typename _Ret, typename _Tp >
  class  const_mem_fun_ref_t : public ::std::unary_function<_Tp, _Ret>
  {
    public:
      inline explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp &__r) const 
      {
        return (__r.*::std::const_mem_fun_ref_t<_Ret, _Tp>::_M_f)();
      }
    private:
      _Ret (_Tp::*_M_f)() const ;
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  mem_fun1_t : public ::std::binary_function<_Tp *, _Arg, _Ret>
  {
    public:
      inline explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg))
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp *__p, _Arg __x) const 
      {
        return (__p->*::std::mem_fun1_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  const_mem_fun1_t : public ::std::binary_function<const _Tp *, _Arg, _Ret>
  {
    public:
      inline explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp *__p, _Arg __x) const 
      {
        return (__p->*::std::const_mem_fun1_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const ;
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  mem_fun1_ref_t : public ::std::binary_function<_Tp, _Arg, _Ret>
  {
    public:
      inline explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg))
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(_Tp &__r, _Arg __x) const 
      {
        return (__r.*::std::mem_fun1_ref_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg);
  };
  template < typename _Ret, typename _Tp, typename _Arg >
  class  const_mem_fun1_ref_t : public ::std::binary_function<_Tp, _Arg, _Ret>
  {
    public:
      inline explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const )
        : _M_f(__pf)
      {
      }
      inline _Ret operator ()(const _Tp &__r, _Arg __x) const 
      {
        return (__r.*::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg>::_M_f)(__x);
      }
    private:
      _Ret (_Tp::*_M_f)(_Arg) const ;
  };
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)());
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)())
  {
    return ::std::mem_fun_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)() const );
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_t<_Ret, _Tp> mem_fun(_Ret (_Tp::*__f)() const )
  {
    return ::std::const_mem_fun_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)());
  template < typename _Ret, typename _Tp >
  inline ::std::mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)())
  {
    return ::std::mem_fun_ref_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)() const );
  template < typename _Ret, typename _Tp >
  inline ::std::const_mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret (_Tp::*__f)() const )
  {
    return ::std::const_mem_fun_ref_t<_Ret, _Tp>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg));
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg))
  {
    return ::std::mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg) const );
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret (_Tp::*__f)(_Arg) const )
  {
    return ::std::const_mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg));
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg))
  {
    return ::std::mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const );
  template < typename _Ret, typename _Tp, typename _Arg >
  inline ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const )
  {
    return ::std::const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }
  template < typename _Operation >
  class  binder1st : public ::std::unary_function<typename _Operation::second_argument_type, typename _Operation::result_type>
  {
    protected:
      _Operation op;
      typename _Operation::first_argument_type value;
    public:
      inline binder1st(const _Operation &__x, const typename _Operation::first_argument_type &__y)
        : op(__x), value(__y)
      {
      }
      inline typename _Operation::result_type operator ()(const typename _Operation::second_argument_type &__x) const 
      {
        return op(::std::binder1st<_Operation>::value, __x);
      }
      inline typename _Operation::result_type operator ()(typename _Operation::second_argument_type &__x) const 
      {
        return op(::std::binder1st<_Operation>::value, __x);
      }
  };
  template < typename _Operation, typename _Tp >
  inline ::std::binder1st<_Operation> bind1st(const _Operation &__fn, const _Tp &__x);
  template < typename _Operation, typename _Tp >
  inline ::std::binder1st<_Operation> bind1st(const _Operation &__fn, const _Tp &__x)
  {
    typedef typename _Operation::first_argument_type _Arg1_type;
    return ::std::binder1st<_Operation>(__fn, _Arg1_type(__x));
  }
  template < typename _Operation >
  class  binder2nd : public ::std::unary_function<typename _Operation::first_argument_type, typename _Operation::result_type>
  {
    protected:
      _Operation op;
      typename _Operation::second_argument_type value;
    public:
      inline binder2nd(const _Operation &__x, const typename _Operation::second_argument_type &__y)
        : op(__x), value(__y)
      {
      }
      inline typename _Operation::result_type operator ()(const typename _Operation::first_argument_type &__x) const 
      {
        return op(__x, ::std::binder2nd<_Operation>::value);
      }
      inline typename _Operation::result_type operator ()(typename _Operation::first_argument_type &__x) const 
      {
        return op(__x, ::std::binder2nd<_Operation>::value);
      }
  };
  template < typename _Operation, typename _Tp >
  inline ::std::binder2nd<_Operation> bind2nd(const _Operation &__fn, const _Tp &__x);
  template < typename _Operation, typename _Tp >
  inline ::std::binder2nd<_Operation> bind2nd(const _Operation &__fn, const _Tp &__x)
  {
    typedef typename _Operation::second_argument_type _Arg2_type;
    return ::std::binder2nd<_Operation>(__fn, _Arg2_type(__x));
  }
  template < typename _Alloc >
  class allocator;
  template < typename _CharT >
  struct char_traits;
  template < typename _CharT, typename _Traits = ::std::char_traits<_CharT>, typename _Alloc = ::std::allocator<_CharT> >
  class basic_string;
  template <>
  struct char_traits<char>;
  typedef ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > string;
  template <>
  struct char_traits<wchar_t>;
  typedef ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > wstring;
  namespace tr1 {
    struct  __sfinae_types
    {
        typedef char __one;
        struct  __two
        {
            char __arr[2];
        };
    };
    template < typename _Tp, _Tp __v >
    struct  integral_constant
    {
        static const _Tp value = __v;
        typedef _Tp value_type;
        typedef ::std::tr1::integral_constant<_Tp, __v> type;
    };
    typedef ::std::tr1::integral_constant<bool, true> true_type;
    typedef ::std::tr1::integral_constant<bool, false> false_type;
 /* Instantiation of class template '::std::tr1::integral_constant<bool, false>' */ 
    template < typename __type_tpl__param_1_0__ >
    struct  is_void : ::std::tr1::integral_constant<bool, false>
    {
    };
 /* Instantiation of class template '::std::tr1::integral_constant<bool, true>' */ 
    template <>
    struct  is_void<void> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_void<const void> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_void<volatile void> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_void<const volatile void> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_integral : ::std::tr1::integral_constant<bool, false>
    {
    };
    template <>
    struct  is_integral<bool> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const bool> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile bool> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile bool> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<wchar_t> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const wchar_t> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile wchar_t> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile wchar_t> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<volatile unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_integral<const volatile unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_floating_point : ::std::tr1::integral_constant<bool, false>
    {
    };
    template <>
    struct  is_floating_point<float> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const float> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<volatile float> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const volatile float> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<volatile double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const volatile double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<long double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const long double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<volatile long double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_floating_point<const volatile long double> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_array : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp, ::size_t _Size >
    struct  is_array<_Tp [_Size]> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_array<_Tp []> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_pointer : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp >
    struct  is_pointer<_Tp *> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_pointer<_Tp *const > : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_pointer<_Tp *volatile > : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_pointer<_Tp *const volatile > : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct is_reference;
    template < typename _Tp >
    struct is_function;
    template < typename __type_tpl__param_1_0__ >
    struct  is_member_object_pointer : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_object_pointer<_Tp _Cp::*> : ::std::tr1::integral_constant<bool, !is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_object_pointer<_Tp _Cp::*const > : ::std::tr1::integral_constant<bool, !is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_object_pointer<_Tp _Cp::*volatile > : ::std::tr1::integral_constant<bool, !is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_object_pointer<_Tp _Cp::*const volatile > : ::std::tr1::integral_constant<bool, !is_function<_Tp>::value>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_member_function_pointer : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_function_pointer<_Tp _Cp::*> : ::std::tr1::integral_constant<bool, is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_function_pointer<_Tp _Cp::*const > : ::std::tr1::integral_constant<bool, is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_function_pointer<_Tp _Cp::*volatile > : ::std::tr1::integral_constant<bool, is_function<_Tp>::value>
    {
    };
    template < typename _Tp, typename _Cp >
    struct  is_member_function_pointer<_Tp _Cp::*const volatile > : ::std::tr1::integral_constant<bool, is_function<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  is_enum : ::std::tr1::integral_constant<bool, __is_enum(_Tp)>
    {
    };
    template < typename _Tp >
    struct  is_union : ::std::tr1::integral_constant<bool, __is_union(_Tp)>
    {
    };
    template < typename _Tp >
    struct  is_class : ::std::tr1::integral_constant<bool, __is_class(_Tp)>
    {
    };
    template < typename _Tp >
    struct  __in_array : ::std::tr1::__sfinae_types
    {
      private:
        template < typename _Up >
        static ::std::tr1::__sfinae_types::__one __test(_Up (*)[1]);
        template < typename __type_tpl__param_2_0__ >
        static ::std::tr1::__sfinae_types::__two __test(...);
      public:
        static const bool __value = sizeof(__test<_Tp>(0)) == 1;
    };
    template < typename _Tp >
    struct is_abstract;
    template < typename _Tp >
    struct  is_function : ::std::tr1::integral_constant<bool, !(((__in_array<_Tp>::__value || is_abstract<_Tp>::value) || is_reference<_Tp>::value) || is_void<_Tp>::value)>
    {
    };
    template < typename _Tp >
    struct  is_arithmetic : ::std::tr1::integral_constant<bool, is_integral<_Tp>::value || is_floating_point<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  is_fundamental : ::std::tr1::integral_constant<bool, is_arithmetic<_Tp>::value || is_void<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  is_object : ::std::tr1::integral_constant<bool, !((is_function<_Tp>::value || is_reference<_Tp>::value) || is_void<_Tp>::value)>
    {
    };
    template < typename _Tp >
    struct is_member_pointer;
    template < typename _Tp >
    struct  is_scalar : ::std::tr1::integral_constant<bool, ((is_arithmetic<_Tp>::value || is_enum<_Tp>::value) || is_pointer<_Tp>::value) || is_member_pointer<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  is_compound : ::std::tr1::integral_constant<bool, !is_fundamental<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  is_member_pointer : ::std::tr1::integral_constant<bool, is_member_object_pointer<_Tp>::value || is_member_function_pointer<_Tp>::value>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_const : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp >
    struct  is_const<const _Tp> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_volatile : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp >
    struct  is_volatile<volatile _Tp> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_empty : ::std::tr1::integral_constant<bool, __is_empty(_Tp)>
    {
    };
    template < typename _Tp >
    struct  is_polymorphic : ::std::tr1::integral_constant<bool, __is_polymorphic(_Tp)>
    {
    };
    template < typename _Tp >
    struct  is_abstract : ::std::tr1::integral_constant<bool, __is_abstract(_Tp)>
    {
    };
    template < typename _Tp >
    struct  has_virtual_destructor : ::std::tr1::integral_constant<bool, __has_virtual_destructor(_Tp)>
    {
    };
    template < typename _Tp >
    struct  alignment_of : ::std::tr1::integral_constant<unsigned long int, __alignof__(_Tp)>
    {
    };
 /* Instantiation of class template '::std::tr1::integral_constant<unsigned long int, 0>' */ 
    template < typename __type_tpl__param_1_0__ >
    struct  rank : ::std::tr1::integral_constant<unsigned long int, 0>
    {
    };
    template < typename _Tp, ::size_t _Size >
    struct  rank<_Tp [_Size]> : ::std::tr1::integral_constant<unsigned long int, 1 + rank<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  rank<_Tp []> : ::std::tr1::integral_constant<unsigned long int, 1 + rank<_Tp>::value>
    {
    };
    template < typename __type_tpl__param_1_0__, unsigned int _Uint = 0 >
    struct  extent : ::std::tr1::integral_constant<unsigned long int, 0>
    {
    };
    template < typename _Tp, unsigned int _Uint, ::size_t _Size >
    struct  extent<_Tp [_Size], _Uint> : ::std::tr1::integral_constant<unsigned long int, _Uint == 0 ? _Size : extent<_Tp, _Uint - 1>::value>
    {
    };
    template < typename _Tp, unsigned int _Uint >
    struct  extent<_Tp [], _Uint> : ::std::tr1::integral_constant<unsigned long int, _Uint == 0 ? 0 : extent<_Tp, _Uint - 1>::value>
    {
    };
    template < typename __type_tpl__param_1_0__, typename __type_tpl__param_1_1__ >
    struct  is_same : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp >
    struct  is_same<_Tp, _Tp> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  remove_const
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_const<const _Tp>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_volatile
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_volatile<volatile _Tp>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_cv
    {
        typedef typename ::std::tr1::remove_const<typename ::std::tr1::remove_volatile<_Tp>::type>::type type;
    };
    template < typename _Tp >
    struct  add_const
    {
        typedef const _Tp type;
    };
    template < typename _Tp >
    struct  add_volatile
    {
        typedef volatile _Tp type;
    };
    template < typename _Tp >
    struct  add_cv
    {
        typedef typename ::std::tr1::add_const<typename ::std::tr1::add_volatile<_Tp>::type>::type type;
    };
    template < typename _Tp >
    struct  remove_extent
    {
        typedef _Tp type;
    };
    template < typename _Tp, ::size_t _Size >
    struct  remove_extent<_Tp [_Size]>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_extent<_Tp []>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_all_extents
    {
        typedef _Tp type;
    };
    template < typename _Tp, ::size_t _Size >
    struct  remove_all_extents<_Tp [_Size]>
    {
        typedef typename ::std::tr1::remove_all_extents<_Tp>::type type;
    };
    template < typename _Tp >
    struct  remove_all_extents<_Tp []>
    {
        typedef typename ::std::tr1::remove_all_extents<_Tp>::type type;
    };
    template < typename _Tp >
    struct  remove_pointer
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_pointer<_Tp *>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_pointer<_Tp *const >
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_pointer<_Tp *volatile >
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_pointer<_Tp *const volatile >
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct remove_reference;
    template < typename _Tp >
    struct  add_pointer
    {
        typedef typename ::std::tr1::remove_reference<_Tp>::type *type;
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_reference : ::std::tr1::integral_constant<bool, false>
    {
    };
    template < typename _Tp >
    struct  is_reference<_Tp &> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Tp >
    struct  is_pod : ::std::tr1::integral_constant<bool, (__is_pod(_Tp)) || is_void<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_trivial_constructor : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_trivial_copy : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_trivial_assign : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_trivial_destructor : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_nothrow_constructor : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_nothrow_copy : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename _Tp >
    struct  has_nothrow_assign : ::std::tr1::integral_constant<bool, is_pod<_Tp>::value>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_signed : ::std::tr1::integral_constant<bool, false>
    {
    };
    template <>
    struct  is_signed<signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<volatile signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const volatile signed char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<volatile short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const volatile short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<volatile int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const volatile int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<volatile long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const volatile long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<volatile long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_signed<const volatile long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename __type_tpl__param_1_0__ >
    struct  is_unsigned : ::std::tr1::integral_constant<bool, false>
    {
    };
    template <>
    struct  is_unsigned<unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<volatile unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const volatile unsigned char> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<volatile unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const volatile unsigned short int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<volatile unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const volatile unsigned int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<volatile unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const volatile unsigned long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<volatile unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template <>
    struct  is_unsigned<const volatile unsigned long long int> : ::std::tr1::integral_constant<bool, true>
    {
    };
    template < typename _Base, typename _Derived >
    struct  __is_base_of_helper
    {
        typedef typename ::std::tr1::remove_cv<_Base>::type _NoCv_Base;
        typedef typename ::std::tr1::remove_cv<_Derived>::type _NoCv_Derived;
        static const bool __value = is_same<_Base, _Derived>::value || ((__is_base_of(_Base, _Derived)) && !is_same<typename ::std::tr1::__is_base_of_helper<_Base, _Derived>::_NoCv_Base, typename ::std::tr1::__is_base_of_helper<_Base, _Derived>::_NoCv_Derived>::value);
    };
    template < typename _Base, typename _Derived >
    struct  is_base_of : ::std::tr1::integral_constant<bool, __is_base_of_helper<_Base, _Derived>::__value>
    {
    };
    template < typename _From, typename _To >
    struct  __is_convertible_simple : ::std::tr1::__sfinae_types
    {
      private:
        static ::std::tr1::__sfinae_types::__one __test(_To);
        static ::std::tr1::__sfinae_types::__two __test(...);
        static _From __makeFrom();
      public:
        static const bool __value = sizeof(__test(__makeFrom())) == 1;
    };
    template < typename _Tp >
    struct add_reference;
    template < typename _Tp >
    struct  __is_int_or_cref
    {
        typedef typename ::std::tr1::remove_reference<_Tp>::type __rr_Tp;
        static const bool __value = is_integral<_Tp>::value || ((is_integral<typename ::std::tr1::__is_int_or_cref<_Tp>::__rr_Tp>::value && is_const<typename ::std::tr1::__is_int_or_cref<_Tp>::__rr_Tp>::value) && !is_volatile<typename ::std::tr1::__is_int_or_cref<_Tp>::__rr_Tp>::value);
    };
    template < typename _From, typename _To, bool __nontype_tpl_param_1_2__ = (((is_void<_From>::value || is_void<_To>::value) || is_function<_To>::value) || is_array<_To>::value) || (is_floating_point<typename ::std::tr1::remove_reference<_From>::type>::value && __is_int_or_cref<_To>::__value) >
    struct  __is_convertible_helper
    {
        static const bool __value = __is_convertible_simple<typename ::std::tr1::add_reference<_From>::type, _To>::__value;
    };
    template < typename _From, typename _To >
    struct  __is_convertible_helper<_From, _To, true>
    {
        static const bool __value = is_void<_To>::value || (__is_int_or_cref<_To>::__value && !is_void<_From>::value);
    };
    template < typename _From, typename _To >
    struct  is_convertible : ::std::tr1::integral_constant<bool, __is_convertible_helper<_From, _To>::__value>
    {
    };
    template < typename _Tp >
    struct  remove_reference
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  remove_reference<_Tp &>
    {
        typedef _Tp type;
    };
    template < typename _Tp, bool __nontype_tpl_param_1_1__ = is_void<_Tp>::value || is_reference<_Tp>::value >
    struct  __add_reference_helper
    {
        typedef _Tp &type;
    };
    template < typename _Tp >
    struct  __add_reference_helper<_Tp, true>
    {
        typedef _Tp type;
    };
    template < typename _Tp >
    struct  add_reference : ::std::tr1::__add_reference_helper<_Tp, ::std::tr1::is_void<_Tp>::value || ::std::tr1::is_reference<_Tp>::value>
    {
    };
    template < ::size_t _Len, ::size_t _Align >
    struct  aligned_storage
    {
        union  type
        {
            unsigned char __data[_Len];
            struct __attribute__((aligned(/* ??? */_Align)))  mcc_struct_anon_46
            {
            };
            typename ::std::tr1::aligned_storage<_Len, _Align>::type::mcc_struct_anon_46 __align;
        };
    };
    template < typename _Tp >
    struct  hash : ::std::unary_function<_Tp, unsigned long int>
    {
        ::size_t operator ()(_Tp __val) const ;
    };
    template < typename _Tp >
    struct  hash<_Tp *> : ::std::unary_function<_Tp *, unsigned long int>
    {
        inline ::size_t operator ()(_Tp *__p) const 
        {
          return reinterpret_cast< ::size_t>(__p);
        }
    };
 /* Instantiation of class template '::std::unary_function<bool, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<bool>' */ 
    template <>
    inline unsigned long int hash<bool>::operator ()(bool __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<char, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<char>' */ 
    template <>
    inline unsigned long int hash<char>::operator ()(char __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<signed char, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<signed char>' */ 
    template <>
    inline unsigned long int hash<signed char>::operator ()(signed char __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<unsigned char, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<unsigned char>' */ 
    template <>
    inline unsigned long int hash<unsigned char>::operator ()(unsigned char __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<wchar_t, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<wchar_t>' */ 
    template <>
    inline unsigned long int hash<wchar_t>::operator ()(wchar_t __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<short int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<short int>' */ 
    template <>
    inline unsigned long int hash<short int>::operator ()(short int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<int>' */ 
    template <>
    inline unsigned long int hash<int>::operator ()(int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<long int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<long int>' */ 
    template <>
    inline unsigned long int hash<long int>::operator ()(long int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<long long int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<long long int>' */ 
    template <>
    inline unsigned long int hash<long long int>::operator ()(long long int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<unsigned short int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<unsigned short int>' */ 
    template <>
    inline unsigned long int hash<unsigned short int>::operator ()(unsigned short int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<unsigned int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<unsigned int>' */ 
    template <>
    inline unsigned long int hash<unsigned int>::operator ()(unsigned int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<unsigned long int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<unsigned long int>' */ 
    template <>
    inline unsigned long int hash<unsigned long int>::operator ()(unsigned long int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
 /* Instantiation of class template '::std::unary_function<unsigned long long int, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<unsigned long long int>' */ 
    template <>
    inline unsigned long int hash<unsigned long long int>::operator ()(unsigned long long int __val) const 
    {
      return static_cast<unsigned long int>(__val);
    }
    template < ::size_t __nontype_tpl_param_1_0__ = sizeof(::size_t) >
    struct  _Fnv_hash
    {
        static inline ::size_t hash(const char *__first, ::size_t __length)
        {
          ::size_t __result(0);
          for (; __length > 0;  --__length)
            {
              __result = __result * 131 + *__first++;
            }
          return __result;
        }
    };
    template <>
    struct  _Fnv_hash<4LU>
    {
        static inline ::size_t hash(const char *__first, ::size_t __length)
        {
          ::size_t __result(static_cast<unsigned long int>(2166136261LU));
          for (; __length > 0;  --__length)
            {
              __result ^= static_cast<unsigned long int>(*__first++);
              __result *= static_cast<unsigned long int>(16777619LU);
            }
          return __result;
        }
    };
    template <>
    struct  _Fnv_hash<8LU>
    {
        static inline ::size_t hash(const char *__first, ::size_t __length)
        {
          ::size_t __result(static_cast<unsigned long int>(14695981039346656037LLU));
          for (; __length > 0;  --__length)
            {
              __result ^= static_cast<unsigned long int>(*__first++);
              __result *= static_cast<unsigned long int>(1099511628211LLU);
            }
          return __result;
        }
    };
 /* Instantiation of class template '::std::unary_function<float, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<float>' */ 
    template <>
    inline unsigned long int hash<float>::operator ()(float __val) const 
    {
      ::size_t __result(0);
      if (__val != 0.000000000000000000000000e+00f)
        {
          __result = _Fnv_hash<>::hash(reinterpret_cast<const char *>(&__val), sizeof(float &));
        }
      return __result;
    }
 /* Instantiation of class template '::std::unary_function<double, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<double>' */ 
    template <>
    inline unsigned long int hash<double>::operator ()(double __val) const 
    {
      ::size_t __result(0);
      if (__val != 0.00000000000000000000000000000000000000000000000000000e+00)
        {
          __result = _Fnv_hash<>::hash(reinterpret_cast<const char *>(&__val), sizeof(double &));
        }
      return __result;
    }
 /* Instantiation of class template '::std::unary_function<long double, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<long double>' */ 
    template <>
    unsigned long int hash<long double>::operator ()(long double __val) const ;
 /* Instantiation of class template '::std::unary_function< ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> >, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash< ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > >' */ 
    template <>
    unsigned long int hash< ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > >::operator ()(::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > __val) const ;
 /* Instantiation of class template '::std::unary_function<const ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > &, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<const ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > &>' */ 
    template <>
    unsigned long int hash<const ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > &>::operator ()(const ::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char> > &__val) const ;
 /* Instantiation of class template '::std::unary_function< ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> >, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash< ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > >' */ 
    template <>
    unsigned long int hash< ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > >::operator ()(::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > __val) const ;
 /* Instantiation of class template '::std::unary_function<const ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > &, unsigned long int>' */ 
 /* Instantiation of class template '::std::tr1::hash<const ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > &>' */ 
    template <>
    unsigned long int hash<const ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > &>::operator ()(const ::std::basic_string<wchar_t, ::std::char_traits<wchar_t>, ::std::allocator<wchar_t> > &__val) const ;
    namespace __detail {
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last, ::std::input_iterator_tag);
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last, ::std::input_iterator_tag)
      {
        return 0;
      }
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last, ::std::forward_iterator_tag);
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last, ::std::forward_iterator_tag)
      {
        return std::distance(__first, __last);
      }
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last);
      template < typename _Iterator >
      inline typename ::std::iterator_traits<_Iterator>::difference_type __distance_fw(_Iterator __first, _Iterator __last)
      {
        typedef typename ::std::iterator_traits<_Iterator>::iterator_category _Tag;
        return __distance_fw(__first, __last, _Tag());
      }
      template < typename _RAIter, typename _Tp >
      _RAIter __lower_bound(_RAIter __first, _RAIter __last, const _Tp &__val);
      template < typename _RAIter, typename _Tp >
      _RAIter __lower_bound(_RAIter __first, _RAIter __last, const _Tp &__val)
      {
        typedef typename ::std::iterator_traits<_RAIter>::difference_type _DType;
        _DType __len = __last - __first;
        while (__len > 0)
          {
            _DType __half = __len >> 1;
            _RAIter __middle = __first + __half;
            if (*__middle < __val)
              {
                __first = __middle;
                 ++__first;
                __len = __len - __half - 1;
              }
            else
              {
                __len = __half;
              }
          }
        return __first;
      }
      template < typename _Value, bool __cache_hash_code >
      struct _Hash_node;
      template < typename _Value >
      struct  _Hash_node<_Value, true>
      {
          _Value _M_v;
          ::size_t _M_hash_code;
          ::std::tr1::__detail::_Hash_node<_Value, true> *_M_next;
      };
      template < typename _Value >
      struct  _Hash_node<_Value, false>
      {
          _Value _M_v;
          ::std::tr1::__detail::_Hash_node<_Value, false> *_M_next;
      };
      template < typename _Value, bool __cache >
      struct  _Node_iterator_base
      {
          inline _Node_iterator_base(::std::tr1::__detail::_Hash_node<_Value, __cache> *__p)
            : _M_cur(__p)
          {
          }
          inline void _M_incr()
          {
            ::std::tr1::__detail::_Node_iterator_base<_Value, __cache>::_M_cur = ::std::tr1::__detail::_Node_iterator_base<_Value, __cache>::_M_cur->_M_next;
          }
          ::std::tr1::__detail::_Hash_node<_Value, __cache> *_M_cur;
      };
      template < typename _Value, bool __cache >
      inline bool operator ==(const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__y);
      template < typename _Value, bool __cache >
      inline bool operator ==(const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__y)
      {
        return __x._M_cur == __y._M_cur;
      }
      template < typename _Value, bool __cache >
      inline bool operator !=(const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__y);
      template < typename _Value, bool __cache >
      inline bool operator !=(const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Node_iterator_base<_Value, __cache> &__y)
      {
        return __x._M_cur != __y._M_cur;
      }
      template < typename _Value, bool __constant_iterators, bool __cache >
      struct  _Node_iterator : ::std::tr1::__detail::_Node_iterator_base<_Value, __cache>
      {
          typedef _Value value_type;
          typedef typename ::__gnu_cxx::__conditional_type<__constant_iterators, const _Value *, _Value *>::__type pointer;
          typedef typename ::__gnu_cxx::__conditional_type<__constant_iterators, const _Value &, _Value &>::__type reference;
          typedef ::ptrdiff_t difference_type;
          typedef ::std::forward_iterator_tag iterator_category;
          inline _Node_iterator()
            : _Node_iterator_base<_Value, __cache>(0)
          {
          }
          inline explicit _Node_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> *__p)
            : _Node_iterator_base<_Value, __cache>(__p)
          {
          }
          inline typename ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache>::reference operator *() const 
          {
            return this->_M_cur->_M_v;
          }
          inline typename ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache>::pointer operator ->() const 
          {
            return &this->_M_cur->_M_v;
          }
          inline ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache> &operator ++()
          {
            this->_M_incr();
            return *this;
          }
          inline ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache> operator ++(int)
          {
            ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache> __tmp(*this);
            this->_M_incr();
            return __tmp;
          }
      };
      template < typename _Value, bool __constant_iterators, bool __cache >
      struct  _Node_const_iterator : ::std::tr1::__detail::_Node_iterator_base<_Value, __cache>
      {
          typedef _Value value_type;
          typedef const _Value *pointer;
          typedef const _Value &reference;
          typedef ::ptrdiff_t difference_type;
          typedef ::std::forward_iterator_tag iterator_category;
          inline _Node_const_iterator()
            : _Node_iterator_base<_Value, __cache>(0)
          {
          }
          inline explicit _Node_const_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> *__p)
            : _Node_iterator_base<_Value, __cache>(__p)
          {
          }
          inline _Node_const_iterator(const ::std::tr1::__detail::_Node_iterator<_Value, __constant_iterators, __cache> &__x)
            : _Node_iterator_base<_Value, __cache>(__x._M_cur)
          {
          }
          inline typename ::std::tr1::__detail::_Node_const_iterator<_Value, __constant_iterators, __cache>::reference operator *() const 
          {
            return this->_M_cur->_M_v;
          }
          inline typename ::std::tr1::__detail::_Node_const_iterator<_Value, __constant_iterators, __cache>::pointer operator ->() const 
          {
            return &this->_M_cur->_M_v;
          }
          inline ::std::tr1::__detail::_Node_const_iterator<_Value, __constant_iterators, __cache> &operator ++()
          {
            this->_M_incr();
            return *this;
          }
          inline ::std::tr1::__detail::_Node_const_iterator<_Value, __constant_iterators, __cache> operator ++(int)
          {
            ::std::tr1::__detail::_Node_const_iterator<_Value, __constant_iterators, __cache> __tmp(*this);
            this->_M_incr();
            return __tmp;
          }
      };
      template < typename _Value, bool __cache >
      struct  _Hashtable_iterator_base
      {
          inline _Hashtable_iterator_base(::std::tr1::__detail::_Hash_node<_Value, __cache> *__node, ::std::tr1::__detail::_Hash_node<_Value, __cache> **__bucket)
            : _M_cur_node(__node), _M_cur_bucket(__bucket)
          {
          }
          inline void _M_incr()
          {
            ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_node = ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_node->_M_next;
            if (!::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_node)
              {
                _M_incr_bucket();
              }
          }
          void _M_incr_bucket();
          ::std::tr1::__detail::_Hash_node<_Value, __cache> *_M_cur_node;
          ::std::tr1::__detail::_Hash_node<_Value, __cache> **_M_cur_bucket;
      };
      template < typename _Value, bool __cache >
      void _Hashtable_iterator_base<_Value, __cache>::_M_incr_bucket()
      {
         ++::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_bucket;
        while (!*::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_bucket)
          {
             ++::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_bucket;
          }
        ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_node = *::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>::_M_cur_bucket;
      }
      template < typename _Value, bool __cache >
      inline bool operator ==(const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__y);
      template < typename _Value, bool __cache >
      inline bool operator ==(const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__y)
      {
        return __x._M_cur_node == __y._M_cur_node;
      }
      template < typename _Value, bool __cache >
      inline bool operator !=(const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__y);
      template < typename _Value, bool __cache >
      inline bool operator !=(const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__x, const ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache> &__y)
      {
        return __x._M_cur_node != __y._M_cur_node;
      }
      template < typename _Value, bool __constant_iterators, bool __cache >
      struct  _Hashtable_iterator : ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>
      {
          typedef _Value value_type;
          typedef typename ::__gnu_cxx::__conditional_type<__constant_iterators, const _Value *, _Value *>::__type pointer;
          typedef typename ::__gnu_cxx::__conditional_type<__constant_iterators, const _Value &, _Value &>::__type reference;
          typedef ::ptrdiff_t difference_type;
          typedef ::std::forward_iterator_tag iterator_category;
          inline _Hashtable_iterator()
            : _Hashtable_iterator_base<_Value, __cache>(0, 0)
          {
          }
          inline _Hashtable_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> *__p, ::std::tr1::__detail::_Hash_node<_Value, __cache> **__b)
            : _Hashtable_iterator_base<_Value, __cache>(__p, __b)
          {
          }
          inline explicit _Hashtable_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> **__b)
            : _Hashtable_iterator_base<_Value, __cache>(*__b, __b)
          {
          }
          inline typename ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache>::reference operator *() const 
          {
            return this->_M_cur_node->_M_v;
          }
          inline typename ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache>::pointer operator ->() const 
          {
            return &this->_M_cur_node->_M_v;
          }
          inline ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache> &operator ++()
          {
            this->_M_incr();
            return *this;
          }
          inline ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache> operator ++(int)
          {
            ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache> __tmp(*this);
            this->_M_incr();
            return __tmp;
          }
      };
      template < typename _Value, bool __constant_iterators, bool __cache >
      struct  _Hashtable_const_iterator : ::std::tr1::__detail::_Hashtable_iterator_base<_Value, __cache>
      {
          typedef _Value value_type;
          typedef const _Value *pointer;
          typedef const _Value &reference;
          typedef ::ptrdiff_t difference_type;
          typedef ::std::forward_iterator_tag iterator_category;
          inline _Hashtable_const_iterator()
            : _Hashtable_iterator_base<_Value, __cache>(0, 0)
          {
          }
          inline _Hashtable_const_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> *__p, ::std::tr1::__detail::_Hash_node<_Value, __cache> **__b)
            : _Hashtable_iterator_base<_Value, __cache>(__p, __b)
          {
          }
          inline explicit _Hashtable_const_iterator(::std::tr1::__detail::_Hash_node<_Value, __cache> **__b)
            : _Hashtable_iterator_base<_Value, __cache>(*__b, __b)
          {
          }
          inline _Hashtable_const_iterator(const ::std::tr1::__detail::_Hashtable_iterator<_Value, __constant_iterators, __cache> &__x)
            : _Hashtable_iterator_base<_Value, __cache>(__x._M_cur_node, __x._M_cur_bucket)
          {
          }
          inline typename ::std::tr1::__detail::_Hashtable_const_iterator<_Value, __constant_iterators, __cache>::reference operator *() const 
          {
            return this->_M_cur_node->_M_v;
          }
          inline typename ::std::tr1::__detail::_Hashtable_const_iterator<_Value, __constant_iterators, __cache>::pointer operator ->() const 
          {
            return &this->_M_cur_node->_M_v;
          }
          inline ::std::tr1::__detail::_Hashtable_const_iterator<_Value, __constant_iterators, __cache> &operator ++()
          {
            this->_M_incr();
            return *this;
          }
          inline ::std::tr1::__detail::_Hashtable_const_iterator<_Value, __constant_iterators, __cache> operator ++(int)
          {
            ::std::tr1::__detail::_Hashtable_const_iterator<_Value, __constant_iterators, __cache> __tmp(*this);
            this->_M_incr();
            return __tmp;
          }
      };
      struct  _Mod_range_hashing
      {
          typedef ::size_t first_argument_type;
          typedef ::size_t second_argument_type;
          typedef ::size_t result_type;
          inline ::std::tr1::__detail::_Mod_range_hashing::result_type operator ()(::std::tr1::__detail::_Mod_range_hashing::first_argument_type __num, ::std::tr1::__detail::_Mod_range_hashing::second_argument_type __den) const 
          {
            return __num % __den;
          }
      };
      struct  _Default_ranged_hash
      {
      };
      struct  _Prime_rehash_policy
      {
          inline _Prime_rehash_policy(float __z  = (1.00000000000000000000000000000000000000000000000000000e+00))
            : _M_max_load_factor(__z), _M_growth_factor(2.000000000000000000000000e+00f), _M_next_resize(0)
          {
          }
          inline float max_load_factor() const 
          {
            return (*this)._M_max_load_factor;
          }
          inline ::size_t _M_next_bkt(::size_t __n) const ;
          inline ::size_t _M_bkt_for_elements(::size_t __n) const ;
          inline ::std::pair<bool, unsigned long int> _M_need_rehash(::size_t __n_bkt, ::size_t __n_elt, ::size_t __n_ins) const ;
          enum mcc_enum_anon_42
          {
            _S_n_primes = sizeof(unsigned long int) != 8 ? 256 : 256 + 48
          };
          float _M_max_load_factor;
          float _M_growth_factor;
          mutable ::size_t _M_next_resize;
      };
      extern const unsigned long int __prime_list[];
 /* Instantiation of template function '::std::tr1::__detail::__lower_bound<const unsigned long int *, unsigned long int>' */ 
      inline ::size_t _Prime_rehash_policy::_M_next_bkt(::size_t __n) const 
      {
        const unsigned long int *__p(::std::tr1::__detail::__lower_bound /* <const unsigned long int *, unsigned long int> */ (::std::tr1::__detail::__prime_list, ::std::tr1::__detail::__prime_list + ::std::tr1::__detail::_Prime_rehash_policy::_S_n_primes, __n));
        (*this)._M_next_resize = static_cast<unsigned long int>(__builtin_ceil(*__p * (*this)._M_max_load_factor));
        return *__p;
      }
 /* Instantiation of template function '::std::tr1::__detail::__lower_bound<const unsigned long int *, float>' */ 
      inline ::size_t _Prime_rehash_policy::_M_bkt_for_elements(::size_t __n) const 
      {
        const float __min_bkts(__n / (*this)._M_max_load_factor);
        const unsigned long int *__p(::std::tr1::__detail::__lower_bound /* <const unsigned long int *, float> */ (::std::tr1::__detail::__prime_list, ::std::tr1::__detail::__prime_list + ::std::tr1::__detail::_Prime_rehash_policy::_S_n_primes, __min_bkts));
        (*this)._M_next_resize = static_cast<unsigned long int>(__builtin_ceil(*__p * (*this)._M_max_load_factor));
        return *__p;
      }
 /* Instantiation of template function '::std::max<float>' */ 
 /* Instantiation of template function '::std::tr1::__detail::__lower_bound<const unsigned long int *, float>' */ 
 /* Instantiation of template function '::std::make_pair<bool, unsigned long int>' */ 
 /* Instantiation of class template '::std::pair<bool, unsigned long int>' */ 
 /* Instantiation of template function '::std::make_pair<bool, int>' */ 
 /* Instantiation of class template '::std::pair<bool, int>' */ 
 /* Instantiation of template function '::std::pair<bool, unsigned long int>::pair<bool, int>' */ 
      inline ::std::pair<bool, unsigned long int> _Prime_rehash_policy::_M_need_rehash(::size_t __n_bkt, ::size_t __n_elt, ::size_t __n_ins) const 
      {
        if (__n_elt + __n_ins > (*this)._M_next_resize)
          {
            float __min_bkts(((float)__n_ins + (float)__n_elt) / (*this)._M_max_load_factor);
            if (__min_bkts > __n_bkt)
              {
                __min_bkts = std::max(__min_bkts, (*this)._M_growth_factor * __n_bkt);
                const unsigned long int *__p(::std::tr1::__detail::__lower_bound /* <const unsigned long int *, float> */ (::std::tr1::__detail::__prime_list, ::std::tr1::__detail::__prime_list + ::std::tr1::__detail::_Prime_rehash_policy::_S_n_primes, __min_bkts));
                (*this)._M_next_resize = static_cast<unsigned long int>(__builtin_ceil(*__p * (*this)._M_max_load_factor));
                return std::make_pair(true, *__p);
              }
            else
              {
                (*this)._M_next_resize = static_cast<unsigned long int>(__builtin_ceil(__n_bkt * (*this)._M_max_load_factor));
                return std::make_pair(false, 0);
              }
          }
        else
          {
            return std::make_pair(false, 0);
          }
      }
      template < typename _Key, typename _Value, typename _Ex, bool __unique, typename _Hashtable >
      struct  _Map_base
      {
      };
      template < typename _Key, typename _Pair, typename _Hashtable >
      struct  _Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, false, _Hashtable>
      {
          typedef typename _Pair::second_type mapped_type;
      };
      template < typename _Key, typename _Pair, typename _Hashtable >
      struct  _Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, true, _Hashtable>
      {
          typedef typename _Pair::second_type mapped_type;
          typename ::std::tr1::__detail::_Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, true, _Hashtable>::mapped_type &operator [](const _Key &__k);
      };
      template < typename _Key, typename _Pair, typename _Hashtable >
      typename ::std::tr1::__detail::_Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, true, _Hashtable>::mapped_type &_Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, true, _Hashtable>::operator [](const _Key &__k)
      {
        _Hashtable *__h = static_cast<_Hashtable *>(this);
        typename _Hashtable::_Hash_code_type __code = __h->_M_hash_code(__k);
        ::size_t __n = __h->_M_bucket_index(__k, __code, __h->_M_bucket_count);
        typename _Hashtable::_Node *__p = __h->_M_find_node(__h->_M_buckets[__n], __k, __code);
        if (!__p)
          {
            return __h->_M_insert_bucket(std::make_pair(__k, ((typename ::std::tr1::__detail::_Map_base<_Key, _Pair, ::std::_Select1st<_Pair>, true, _Hashtable>::mapped_type()))), __n, __code)->second;
          }
        return __p->_M_v.second;
      }
      template < typename _RehashPolicy, typename _Hashtable >
      struct  _Rehash_base
      {
      };
      template < typename _Hashtable >
      struct  _Rehash_base< ::std::tr1::__detail::_Prime_rehash_policy, _Hashtable>
      {
          inline float max_load_factor() const 
          {
            const _Hashtable *__this = static_cast<const _Hashtable *>(this);
            return __this->__rehash_policy().max_load_factor();
          }
          inline void max_load_factor(float __z)
          {
            _Hashtable *__this = static_cast<_Hashtable *>(this);
            __this->__rehash_policy(::std::tr1::__detail::_Prime_rehash_policy(__z));
          }
      };
      template < typename _Key, typename _Value, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, bool __cache_hash_code >
      struct _Hash_code_base;
      template < typename _Key, typename _Value, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash >
      struct  _Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>
      {
        protected:
          inline _Hash_code_base(const _ExtractKey &__ex, const _Equal &__eq, const _H1 &, const _H2 &, const _Hash &__h)
            : _M_extract(__ex), _M_eq(__eq), _M_ranged_hash(__h)
          {
          }
          typedef void *_Hash_code_type;
          inline typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_Hash_code_type _M_hash_code(const _Key &__key) const 
          {
            return 0;
          }
          inline ::size_t _M_bucket_index(const _Key &__k, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_Hash_code_type, ::size_t __n) const 
          {
            return _M_ranged_hash(__k, __n);
          }
          inline ::size_t _M_bucket_index(const ::std::tr1::__detail::_Hash_node<_Value, false> *__p, ::size_t __n) const 
          {
            return _M_ranged_hash(_M_extract(__p->_M_v), __n);
          }
          inline bool _M_compare(const _Key &__k, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_Hash_code_type, ::std::tr1::__detail::_Hash_node<_Value, false> *__n) const 
          {
            return _M_eq(__k, _M_extract(__n->_M_v));
          }
          inline void _M_store_code(::std::tr1::__detail::_Hash_node<_Value, false> *, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_Hash_code_type) const 
          {
          }
          inline void _M_copy_code(::std::tr1::__detail::_Hash_node<_Value, false> *, const ::std::tr1::__detail::_Hash_node<_Value, false> *) const 
          {
          }
          inline void _M_swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false> &__x)
          {
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_M_extract, __x._M_extract);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_M_eq, __x._M_eq);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, false>::_M_ranged_hash, __x._M_ranged_hash);
          }
          _ExtractKey _M_extract;
          _Equal _M_eq;
          _Hash _M_ranged_hash;
      };
      template < typename _Key, typename _Value, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash >
      struct _Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, true>;
      template < typename _Key, typename _Value, typename _ExtractKey, typename _Equal, typename _H1, typename _H2 >
      struct  _Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>
      {
          typedef _H1 hasher;
          inline typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::hasher hash_function() const 
          {
            return ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_M_h1;
          }
        protected:
          inline _Hash_code_base(const _ExtractKey &__ex, const _Equal &__eq, const _H1 &__h1, const _H2 &__h2, const ::std::tr1::__detail::_Default_ranged_hash &)
            : _M_extract(__ex), _M_eq(__eq), _M_h1(__h1), _M_h2(__h2)
          {
          }
          typedef ::size_t _Hash_code_type;
          inline typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_Hash_code_type _M_hash_code(const _Key &__k) const 
          {
            return _M_h1(__k);
          }
          inline ::size_t _M_bucket_index(const _Key &, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_Hash_code_type __c, ::size_t __n) const 
          {
            return _M_h2(__c, __n);
          }
          inline ::size_t _M_bucket_index(const ::std::tr1::__detail::_Hash_node<_Value, false> *__p, ::size_t __n) const 
          {
            return _M_h2(_M_h1(_M_extract(__p->_M_v)), __n);
          }
          inline bool _M_compare(const _Key &__k, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_Hash_code_type, ::std::tr1::__detail::_Hash_node<_Value, false> *__n) const 
          {
            return _M_eq(__k, _M_extract(__n->_M_v));
          }
          inline void _M_store_code(::std::tr1::__detail::_Hash_node<_Value, false> *, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_Hash_code_type) const 
          {
          }
          inline void _M_copy_code(::std::tr1::__detail::_Hash_node<_Value, false> *, const ::std::tr1::__detail::_Hash_node<_Value, false> *) const 
          {
          }
          inline void _M_swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false> &__x)
          {
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_M_extract, __x._M_extract);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_M_eq, __x._M_eq);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_M_h1, __x._M_h1);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, false>::_M_h2, __x._M_h2);
          }
          _ExtractKey _M_extract;
          _Equal _M_eq;
          _H1 _M_h1;
          _H2 _M_h2;
      };
      template < typename _Key, typename _Value, typename _ExtractKey, typename _Equal, typename _H1, typename _H2 >
      struct  _Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>
      {
          typedef _H1 hasher;
          inline typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::hasher hash_function() const 
          {
            return ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_M_h1;
          }
        protected:
          inline _Hash_code_base(const _ExtractKey &__ex, const _Equal &__eq, const _H1 &__h1, const _H2 &__h2, const ::std::tr1::__detail::_Default_ranged_hash &)
            : _M_extract(__ex), _M_eq(__eq), _M_h1(__h1), _M_h2(__h2)
          {
          }
          typedef ::size_t _Hash_code_type;
          inline typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_Hash_code_type _M_hash_code(const _Key &__k) const 
          {
            return _M_h1(__k);
          }
          inline ::size_t _M_bucket_index(const _Key &, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_Hash_code_type __c, ::size_t __n) const 
          {
            return _M_h2(__c, __n);
          }
          inline ::size_t _M_bucket_index(const ::std::tr1::__detail::_Hash_node<_Value, true> *__p, ::size_t __n) const 
          {
            return _M_h2(__p->_M_hash_code, __n);
          }
          inline bool _M_compare(const _Key &__k, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_Hash_code_type __c, ::std::tr1::__detail::_Hash_node<_Value, true> *__n) const 
          {
            return __c == __n->_M_hash_code && _M_eq(__k, _M_extract(__n->_M_v));
          }
          inline void _M_store_code(::std::tr1::__detail::_Hash_node<_Value, true> *__n, typename ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_Hash_code_type __c) const 
          {
            __n->_M_hash_code = __c;
          }
          inline void _M_copy_code(::std::tr1::__detail::_Hash_node<_Value, true> *__to, const ::std::tr1::__detail::_Hash_node<_Value, true> *__from) const 
          {
            __to->_M_hash_code = __from->_M_hash_code;
          }
          inline void _M_swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true> &__x)
          {
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_M_extract, __x._M_extract);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_M_eq, __x._M_eq);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_M_h1, __x._M_h1);
            std::swap(::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, ::std::tr1::__detail::_Default_ranged_hash, true>::_M_h2, __x._M_h2);
          }
          _ExtractKey _M_extract;
          _Equal _M_eq;
          _H1 _M_h1;
          _H2 _M_h2;
      };
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __cache_hash_code, bool __constant_iterators, bool __unique_keys >
    class  _Hashtable : public ::std::tr1::__detail::_Rehash_base<_RehashPolicy, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> >, public ::std::tr1::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, __cache_hash_code>, public ::std::tr1::__detail::_Map_base<_Key, _Value, _ExtractKey, __unique_keys, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> >
    {
      public:
        typedef _Allocator allocator_type;
        typedef _Value value_type;
        typedef _Key key_type;
        typedef _Equal key_equal;
        typedef typename _Allocator::difference_type difference_type;
        typedef typename _Allocator::size_type size_type;
        typedef typename _Allocator::reference reference;
        typedef typename _Allocator::const_reference const_reference;
        typedef ::std::tr1::__detail::_Node_iterator<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type, __constant_iterators, __cache_hash_code> local_iterator;
        typedef ::std::tr1::__detail::_Node_const_iterator<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type, __constant_iterators, __cache_hash_code> const_local_iterator;
        typedef ::std::tr1::__detail::_Hashtable_iterator<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type, __constant_iterators, __cache_hash_code> iterator;
        typedef ::std::tr1::__detail::_Hashtable_const_iterator<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type, __constant_iterators, __cache_hash_code> const_iterator;
      private:
        typedef ::std::tr1::__detail::_Hash_node<_Value, __cache_hash_code> _Node;
        typedef typename _Allocator::template rebind< typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node>::other _Node_allocator_type;
        typedef typename _Allocator::template rebind< typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *>::other _Bucket_allocator_type;
        typedef typename _Allocator::template rebind< _Value>::other _Value_allocator_type;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node_allocator_type _M_node_allocator;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node **_M_buckets;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type _M_bucket_count;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type _M_element_count;
        _RehashPolicy _M_rehash_policy;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *_M_allocate_node(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v);
        void _M_deallocate_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *__n);
        void _M_deallocate_nodes(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node **__array, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node **_M_allocate_buckets(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n);
        void _M_deallocate_buckets(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node **__p, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n);
      public:
        _Hashtable(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __bucket_hint, const _H1 &__h1, const _H2 &__h2, const _Hash &__h, const _Equal &__eq, const _ExtractKey &__exk, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::allocator_type &__a);
        template < typename _InputIterator >
        _Hashtable(_InputIterator __f, _InputIterator __l, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __bucket_hint, const _H1 &__h1, const _H2 &__h2, const _Hash &__h, const _Equal &__eq, const _ExtractKey &__exk, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::allocator_type &__a);
        _Hashtable(const ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> &__ht);
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> &operator =(const ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> &__ht);
        ~_Hashtable();
        void swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys> &__x);
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator begin()
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator __i(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets);
          if (!__i._M_cur_node)
            {
              __i._M_incr_bucket();
            }
          return __i;
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator begin() const 
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator __i(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets);
          if (!__i._M_cur_node)
            {
              __i._M_incr_bucket();
            }
          return __i;
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator end()
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets + ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_bucket_count)));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator end() const 
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets + ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_bucket_count)));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type size() const 
        {
          return ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_element_count;
        }
        inline bool empty() const 
        {
          return size() == 0;
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::allocator_type get_allocator() const 
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::allocator_type(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_node_allocator)));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Value_allocator_type _M_get_Value_allocator() const 
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Value_allocator_type(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_node_allocator)));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type max_size() const 
        {
          return _M_get_Value_allocator().max_size();
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_equal key_eq() const 
        {
          return this->_M_eq;
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type bucket_count() const 
        {
          return ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_bucket_count;
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type max_bucket_count() const 
        {
          return max_size();
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type bucket_size(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n) const 
        {
          return std::distance(begin(__n), end(__n));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type bucket(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k) const 
        {
          return this->_M_bucket_index(__k, this->_M_hash_code(__k), bucket_count());
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::local_iterator begin(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n)
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::local_iterator(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets[__n])));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::local_iterator end(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type)
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::local_iterator(0)));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_local_iterator begin(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n) const 
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_local_iterator(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_buckets[__n])));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_local_iterator end(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type) const 
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_local_iterator(0)));
        }
        inline float load_factor() const 
        {
          return static_cast<float>(size()) / static_cast<float>(bucket_count());
        }
        inline const _RehashPolicy &__rehash_policy() const 
        {
          return ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_M_rehash_policy;
        }
        void __rehash_policy(const _RehashPolicy &__pol);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator find(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator find(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k) const ;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type count(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k) const ;
        ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator> equal_range(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k);
        ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator> equal_range(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k) const ;
      private:
        typedef typename ::__gnu_cxx::__conditional_type<__unique_keys, ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator, bool>, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator>::__type _Insert_Return_Type;
        typedef typename ::__gnu_cxx::__conditional_type<__unique_keys, ::std::_Select1st<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Insert_Return_Type>, ::std::_Identity<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Insert_Return_Type> >::__type _Insert_Conv_Type;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *_M_find_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *__p, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Hash_code_type __code) const ;
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator _M_insert_bucket(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Hash_code_type __code);
        ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator, bool> _M_insert(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v, ::std::tr1::true_type);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator _M_insert(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v, ::std::tr1::false_type);
        void _M_erase_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node *__p, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Node **__b);
      public:
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Insert_Return_Type insert(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v)
        {
          return _M_insert(__v, ::std::tr1::integral_constant<bool, __unique_keys>());
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator insert(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v)
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator(((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Insert_Conv_Type()))(this->insert(__v)))));
        }
        inline typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator insert(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::value_type &__v)
        {
          return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator(((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::_Insert_Conv_Type()))(this->insert(__v)))));
        }
        template < typename _InputIterator >
        void insert(_InputIterator __first, _InputIterator __last);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator __it);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator __it);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type erase(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::key_type &__k);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator __first, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::iterator __last);
        typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator __first, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::const_iterator __last);
        void clear();
        void rehash(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n);
      private:
        void _M_rehash(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __cache_hash_code, __constant_iterators, __unique_keys>::size_type __n);
      template < typename _Key2, typename _Value2, typename _Ex2, bool __unique2, typename _Hashtable2 >
      friend struct ::std::tr1::__detail::_Map_base;
    };
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_allocate_node(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::value_type &__v)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__n = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator.allocate(1);
      try
      {
        _M_get_Value_allocator().construct(&__n->_M_v, __v);
        __n->_M_next = 0;
        return __n;
      }
      catch (...)
      {
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator.deallocate(__n, 1);
        throw;
      }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_deallocate_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__n)
    {
      _M_get_Value_allocator().destroy(&__n->_M_v);
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator.deallocate(__n, 1);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_deallocate_nodes(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__array, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n)
    {
      for (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __i = 0; __i < __n;  ++__i)
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = __array[__i];
          while (__p)
            {
              typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__tmp = __p;
              __p = __p->_M_next;
              _M_deallocate_node(__tmp);
            }
          __array[__i] = 0;
        }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_allocate_buckets(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Bucket_allocator_type __alloc(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__p = __alloc.allocate(__n + 1);
      std::fill(__p, __p + __n, (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *)0);
      __p[__n] = reinterpret_cast<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *>(4096);
      return __p;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_deallocate_buckets(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__p, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Bucket_allocator_type __alloc(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator);
      __alloc.deallocate(__p, __n + 1);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hashtable(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __bucket_hint, const _H1 &__h1, const _H2 &__h2, const _Hash &__h, const _Equal &__eq, const _ExtractKey &__exk, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::allocator_type &__a)
      : __detail::_Rehash_base<_RehashPolicy, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(), __detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, __chc>(__exk, __eq, __h1, __h2, __h), __detail::_Map_base<_Key, _Value, _ExtractKey, __uk, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(), _M_node_allocator(__a), _M_bucket_count(0), _M_element_count(0), _M_rehash_policy()
    {
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_next_bkt(__bucket_hint);
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets = _M_allocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    template < typename _InputIterator >
    _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hashtable(_InputIterator __f, _InputIterator __l, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __bucket_hint, const _H1 &__h1, const _H2 &__h2, const _Hash &__h, const _Equal &__eq, const _ExtractKey &__exk, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::allocator_type &__a)
      : __detail::_Rehash_base<_RehashPolicy, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(), __detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, __chc>(__exk, __eq, __h1, __h2, __h), __detail::_Map_base<_Key, _Value, _ExtractKey, __uk, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(), _M_node_allocator(__a), _M_bucket_count(0), _M_element_count(0), _M_rehash_policy()
    {
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count = std::max(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_next_bkt(__bucket_hint), ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_bkt_for_elements(__detail::__distance_fw(__f, __l)));
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets = _M_allocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      try
      {
        for (; __f != __l;  ++__f)
          {
            this->insert(*__f);
          }
      }
      catch (...)
      {
        clear();
        _M_deallocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
        throw;
      }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hashtable(const ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> &__ht)
      : __detail::_Rehash_base<_RehashPolicy, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(__ht), __detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, __chc>(__ht), __detail::_Map_base<_Key, _Value, _ExtractKey, __uk, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> >(__ht), _M_node_allocator(__ht._M_node_allocator), _M_bucket_count(__ht._M_bucket_count), _M_element_count(__ht._M_element_count), _M_rehash_policy(__ht._M_rehash_policy)
    {
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets = _M_allocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      try
      {
        for (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __i = 0; __i < __ht._M_bucket_count;  ++__i)
          {
            typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__n = __ht._M_buckets[__i];
            typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__tail = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __i;
            while (__n)
              {
                *__tail = _M_allocate_node(__n->_M_v);
                this->_M_copy_code(*__tail, __n);
                __tail = &(*__tail)->_M_next;
                __n = __n->_M_next;
              }
          }
      }
      catch (...)
      {
        clear();
        _M_deallocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
        throw;
      }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> &_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::operator =(const ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> &__ht)
    {
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> __tmp(__ht);
      this->swap(__tmp);
      return *this;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::~_Hashtable()
    {
      clear();
      _M_deallocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk> &__x)
    {
      __detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Equal, _H1, _H2, _Hash, __chc>::_M_swap(__x);
      std::__alloc_swap<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node_allocator_type>::_S_do_it(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_node_allocator, __x._M_node_allocator);
      std::swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy, __x._M_rehash_policy);
      std::swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, __x._M_buckets);
      std::swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count, __x._M_bucket_count);
      std::swap(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count, __x._M_element_count);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::__rehash_policy(const _RehashPolicy &__pol)
    {
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy = __pol;
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n_bkt = __pol._M_bkt_for_elements(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count);
      if (__n_bkt > ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count)
        {
          _M_rehash(__n_bkt);
        }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::find(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = _M_find_node(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n], __k, __code);
      return __p ? ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator(__p, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n))) : this->end();
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::find(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k) const 
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = _M_find_node(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n], __k, __code);
      return __p ? ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator(__p, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n))) : this->end();
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::count(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k) const 
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      ::size_t __result(0);
      for (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n]; __p; __p = __p->_M_next)
        {
          if (this->_M_compare(__k, __code, __p))
            {
               ++__result;
            }
        }
      return __result;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator> _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::equal_range(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__head = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n;
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = _M_find_node(*__head, __k, __code);
      if (__p)
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p1 = __p->_M_next;
          for (; __p1; __p1 = __p1->_M_next)
            {
              if (!this->_M_compare(__k, __code, __p1))
                {
                  break;
                }
            }
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __first(__p, __head);
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __last(__p1, __head);
          if (!__p1)
            {
              __last._M_incr_bucket();
            }
          return std::make_pair(__first, __last);
        }
      else
        {
          return std::make_pair(this->end(), this->end());
        }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator> _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::equal_range(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k) const 
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__head = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n;
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = _M_find_node(*__head, __k, __code);
      if (__p)
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p1 = __p->_M_next;
          for (; __p1; __p1 = __p1->_M_next)
            {
              if (!this->_M_compare(__k, __code, __p1))
                {
                  break;
                }
            }
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __first(__p, __head);
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __last(__p1, __head);
          if (!__p1)
            {
              __last._M_incr_bucket();
            }
          return std::make_pair(__first, __last);
        }
      else
        {
          return std::make_pair(this->end(), this->end());
        }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_find_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p, const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code) const 
    {
      for (; __p; __p = __p->_M_next)
        {
          if (this->_M_compare(__k, __code, __p))
            {
              return __p;
            }
        }
      return false;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_insert_bucket(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::value_type &__v, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code)
    {
      ::std::pair<bool, unsigned long int> __do_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_need_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count, 1));
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__new_node = _M_allocate_node(__v);
      try
      {
        if (__do_rehash.first)
          {
            const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k = this->_M_extract(__v);
            __n = this->_M_bucket_index(__k, __code, __do_rehash.second);
            _M_rehash(__do_rehash.second);
          }
        __new_node->_M_next = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n];
        this->_M_store_code(__new_node, __code);
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n] = __new_node;
         ++::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count;
        return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator(__new_node, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n)));
      }
      catch (...)
      {
        _M_deallocate_node(__new_node);
        throw;
      }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    ::std::pair<typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator, bool> _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_insert(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::value_type &__v, ::std::tr1::true_type)
    {
      const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k = this->_M_extract(__v);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      if (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = _M_find_node(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n], __k, __code))
        {
          return std::make_pair(((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator(__p, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n))), false);
        }
      return std::make_pair(_M_insert_bucket(__v, __n, __code), true);
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_insert(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::value_type &__v, ::std::tr1::false_type)
    {
      ::std::pair<bool, unsigned long int> __do_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_need_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count, 1));
      if (__do_rehash.first)
        {
          _M_rehash(__do_rehash.second);
        }
      const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k = this->_M_extract(__v);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__prev = _M_find_node(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n], __k, __code);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__new_node = _M_allocate_node(__v);
      if (__prev)
        {
          __new_node->_M_next = __prev->_M_next;
          __prev->_M_next = __new_node;
        }
      else
        {
          __new_node->_M_next = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n];
          ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__n] = __new_node;
        }
      this->_M_store_code(__new_node, __code);
       ++::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count;
      return ((typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator(__new_node, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n)));
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_erase_node(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__b)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__cur = *__b;
      if (__cur == __p)
        {
          *__b = __cur->_M_next;
        }
      else
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__next = __cur->_M_next;
          while (__next != __p)
            {
              __cur = __next;
              __next = __cur->_M_next;
            }
          __cur->_M_next = __next->_M_next;
        }
      _M_deallocate_node(__p);
       --::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    template < typename _InputIterator >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::insert(_InputIterator __first, _InputIterator __last)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n_elt = __detail::__distance_fw(__first, __last);
      ::std::pair<bool, unsigned long int> __do_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_need_rehash(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count, __n_elt));
      if (__do_rehash.first)
        {
          _M_rehash(__do_rehash.second);
        }
      for (; __first != __last;  ++__first)
        {
          this->insert(*__first);
        }
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __it)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __result = __it;
       ++__result;
      _M_erase_node(__it._M_cur_node, __it._M_cur_bucket);
      return __result;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __it)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __result = __it;
       ++__result;
      _M_erase_node(__it._M_cur_node, __it._M_cur_bucket);
      return __result;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::erase(const typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::key_type &__k)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Hash_code_type __code = this->_M_hash_code(__k);
      ::size_t __n = this->_M_bucket_index(__k, __code, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __result = 0;
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__slot = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets + __n;
      while (*__slot && !this->_M_compare(__k, __code, *__slot))
        {
          __slot = &(*__slot)->_M_next;
        }
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__saved_slot = 0;
      while (*__slot && this->_M_compare(__k, __code, *__slot))
        {
          if (&this->_M_extract((*__slot)->_M_v) != &__k)
            {
              typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = *__slot;
              *__slot = __p->_M_next;
              _M_deallocate_node(__p);
               --::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count;
               ++__result;
            }
          else
            {
              __saved_slot = __slot;
              __slot = &(*__slot)->_M_next;
            }
        }
      if (__saved_slot)
        {
          typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = *__saved_slot;
          *__saved_slot = __p->_M_next;
          _M_deallocate_node(__p);
           --::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count;
           ++__result;
        }
      return __result;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __first, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::iterator __last)
    {
      while (__first != __last)
        {
          __first = this->erase(__first);
        }
      return __last;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::erase(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __first, typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::const_iterator __last)
    {
      while (__first != __last)
        {
          __first = this->erase(__first);
        }
      return __last;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::clear()
    {
      _M_deallocate_nodes(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
      ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count = 0;
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::rehash(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n)
    {
      _M_rehash(std::max(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_next_bkt(__n), ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash_policy._M_bkt_for_elements(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count + 1)));
    }
    template < typename _Key, typename _Value, typename _Allocator, typename _ExtractKey, typename _Equal, typename _H1, typename _H2, typename _Hash, typename _RehashPolicy, bool __chc, bool __cit, bool __uk >
    void _Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_rehash(typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __n)
    {
      typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node **__new_array = _M_allocate_buckets(__n);
      try
      {
        for (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::size_type __i = 0; __i < ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count;  ++__i)
          {
            while (typename ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_Node *__p = ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__i])
              {
                ::size_t __new_index = this->_M_bucket_index(__p, __n);
                ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets[__i] = __p->_M_next;
                __p->_M_next = __new_array[__new_index];
                __new_array[__new_index] = __p;
              }
          }
        _M_deallocate_buckets(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count = __n;
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets = __new_array;
      }
      catch (...)
      {
        _M_deallocate_nodes(__new_array, __n);
        _M_deallocate_buckets(__new_array, __n);
        _M_deallocate_nodes(::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_buckets, ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_bucket_count);
        ::std::tr1::_Hashtable<_Key, _Value, _Allocator, _ExtractKey, _Equal, _H1, _H2, _Hash, _RehashPolicy, __chc, __cit, __uk>::_M_element_count = 0;
        throw;
      }
    }
    template < typename _Key, typename _Tp, typename _Hash = ::std::tr1::hash<_Key>, typename _Pred = ::std::equal_to<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> >, bool __cache_hash_code = false >
    class  __unordered_map : public ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true>
    {
        typedef ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true> _Base;
      public:
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true>::size_type size_type;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true>::hasher hasher;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true>::key_equal key_equal;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, true>::allocator_type allocator_type;
        inline explicit __unordered_map(typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::size_type __n  = (10), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher &__hf  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher()))), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal &__eql  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal()))), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type &__a  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type()))))
          : _Base(__n, __hf, ::std::tr1::__detail::_Mod_range_hashing(), ::std::tr1::__detail::_Default_ranged_hash(), __eql, ::std::_Select1st< ::std::pair<const _Key, _Tp> >(), __a)
        {
        }
        template < typename _InputIterator >
        inline __unordered_map(_InputIterator __f, _InputIterator __l, typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::size_type __n  = (10), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher &__hf  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher()))), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal &__eql  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal()))), const typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type &__a  = (((typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type()))))
          : _Base(__f, __l, __n, __hf, ::std::tr1::__detail::_Mod_range_hashing(), ::std::tr1::__detail::_Default_ranged_hash(), __eql, ::std::_Select1st< ::std::pair<const _Key, _Tp> >(), __a)
        {
        }
    };
    template < typename _Key, typename _Tp, typename _Hash = ::std::tr1::hash<_Key>, typename _Pred = ::std::equal_to<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> >, bool __cache_hash_code = false >
    class  __unordered_multimap : public ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>
    {
        typedef ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false> _Base;
      public:
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>::size_type size_type;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>::hasher hasher;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>::key_equal key_equal;
        typedef typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>::allocator_type allocator_type;
        inline explicit __unordered_multimap(typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::size_type __n  = (10), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher &__hf  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher()))), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal &__eql  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal()))), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type &__a  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type()))))
          : _Base(__n, __hf, ::std::tr1::__detail::_Mod_range_hashing(), ::std::tr1::__detail::_Default_ranged_hash(), __eql, ::std::_Select1st< ::std::pair<const _Key, _Tp> >(), __a)
        {
        }
        template < typename _InputIterator >
        inline __unordered_multimap(_InputIterator __f, _InputIterator __l, typename ::std::tr1::_Hashtable<_Key, ::std::pair<const _Key, _Tp>, _Alloc, ::std::_Select1st< ::std::pair<const _Key, _Tp> >, _Pred, _Hash, ::std::tr1::__detail::_Mod_range_hashing, ::std::tr1::__detail::_Default_ranged_hash, ::std::tr1::__detail::_Prime_rehash_policy, __cache_hash_code, false, false>::size_type __n  = (0), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher &__hf  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::hasher()))), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal &__eql  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::key_equal()))), const typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type &__a  = (((typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code>::allocator_type()))))
          : _Base(__f, __l, __n, __hf, ::std::tr1::__detail::_Mod_range_hashing(), ::std::tr1::__detail::_Default_ranged_hash(), __eql, ::std::_Select1st< ::std::pair<const _Key, _Tp> >(), __a)
        {
        }
    };
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc, bool __cache_hash_code >
    inline void swap(::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__x, ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__y);
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc, bool __cache_hash_code >
    inline void swap(::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__x, ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__y)
    {
      __x.swap(__y);
    }
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc, bool __cache_hash_code >
    inline void swap(::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__x, ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__y);
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc, bool __cache_hash_code >
    inline void swap(::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__x, ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, __cache_hash_code> &__y)
    {
      __x.swap(__y);
    }
    template < typename _Key, typename _Tp, typename _Hash = ::std::tr1::hash<_Key>, typename _Pred = ::std::equal_to<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> > >
    class  unordered_map : public ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false>
    {
        typedef ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false> _Base;
      public:
        typedef typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false>::size_type size_type;
        typedef typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false>::hasher hasher;
        typedef typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false>::key_equal key_equal;
        typedef typename ::std::tr1::__unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc, false>::allocator_type allocator_type;
        inline explicit unordered_map(typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type __n  = (10), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher &__hf  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher()))), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal &__eql  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal()))), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type &__a  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type()))))
          : _Base(__n, __hf, __eql, __a)
        {
        }
        template < typename _InputIterator >
        inline unordered_map(_InputIterator __f, _InputIterator __l, typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type __n  = (10), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher &__hf  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher()))), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal &__eql  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal()))), const typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type &__a  = (((typename ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type()))))
          : _Base(__f, __l, __n, __hf, __eql, __a)
        {
        }
    };
    template < typename _Key, typename _Tp, typename _Hash = ::std::tr1::hash<_Key>, typename _Pred = ::std::equal_to<_Key>, typename _Alloc = ::std::allocator< ::std::pair<const _Key, _Tp> > >
    class  unordered_multimap : public ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>
    {
        typedef ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false> _Base;
      public:
        typedef typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>::size_type size_type;
        typedef typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>::hasher hasher;
        typedef typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>::key_equal key_equal;
        typedef typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>::allocator_type allocator_type;
        inline explicit unordered_multimap(typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type __n  = (10), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher &__hf  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher()))), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal &__eql  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal()))), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type &__a  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type()))))
          : _Base(__n, __hf, __eql, __a)
        {
        }
        template < typename _InputIterator >
        inline unordered_multimap(_InputIterator __f, _InputIterator __l, typename ::std::tr1::__unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc, false>::size_type __n  = (0), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher &__hf  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher()))), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal &__eql  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal()))), const typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type &__a  = (((typename ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type()))))
          : _Base(__f, __l, __n, __hf, __eql, __a)
        {
        }
    };
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc >
    inline void swap(::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__x, ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__y);
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc >
    inline void swap(::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__x, ::std::tr1::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc> &__y)
    {
      __x.swap(__y);
    }
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc >
    inline void swap(::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__x, ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__y);
    template < typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc >
    inline void swap(::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__x, ::std::tr1::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc> &__y)
    {
      __x.swap(__y);
    }
  }
}
extern "C"
{
  extern void *memcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *memmove(void *__dest, const void *__src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *memccpy(void *__restrict __dest, const void *__restrict __src, int __c, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *memset(void *__s, int __c, ::size_t __n) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int memcmp(const void *__s1, const void *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *memchr(const void *__s, int __c, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void *rawmemchr(const void *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void *memrchr(const void *__s, int __c, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strcat(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strncat(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strcmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strncmp(const char *__s1, const char *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strcoll(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern ::size_t strxfrm(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern int strcoll_l(const char *__s1, const char *__s2, ::__locale_t __l) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern ::size_t strxfrm_l(char *__dest, const char *__src, ::size_t __n, ::__locale_t __l) throw() __attribute__((__nonnull__(2, 4)));
}
extern "C"
{
  extern char *strdup(const char *__s) throw() __attribute__((__malloc__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strndup(const char *__string, ::size_t __n) throw() __attribute__((__malloc__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strchr(const char *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strrchr(const char *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strchrnul(const char *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::size_t strcspn(const char *__s, const char *__reject) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern ::size_t strspn(const char *__s, const char *__accept) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strpbrk(const char *__s, const char *__accept) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strstr(const char *__haystack, const char *__needle) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strtok(char *__restrict __s, const char *__restrict __delim) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) throw() __attribute__((__nonnull__(2, 3)));
}
extern "C"
{
  extern char *strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr) throw() __attribute__((__nonnull__(2, 3)));
}
extern "C"
{
  extern char *strcasestr(const char *__haystack, const char *__needle) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *memmem(const void *__haystack, ::size_t __haystacklen, const void *__needle, ::size_t __needlelen) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 3)));
}
extern "C"
{
  extern void *__mempcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void *mempcpy(void *__restrict __dest, const void *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern ::size_t strlen(const char *__s) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern ::size_t strnlen(const char *__string, ::size_t __maxlen) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *strerror(int __errnum) throw();
}
extern "C"
{
  extern char *strerror_r(int __errnum, char *__buf, ::size_t __buflen) throw() __attribute__((__nonnull__(2)));
}
extern "C"
{
  extern char *strerror_l(int __errnum, ::__locale_t __l) throw();
}
extern "C"
{
  extern void __bzero(void *__s, ::size_t __n) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void bcopy(const void *__src, void *__dest, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern void bzero(void *__s, ::size_t __n) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int bcmp(const void *__s1, const void *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *index(const char *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *rindex(const char *__s, int __c) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern int ffs(int __i) throw() __attribute__((__const__));
}
extern "C"
{
  extern int ffsl(long int __l) throw() __attribute__((__const__));
}
extern "C"
{
  extern int ffsll(long long int __ll) throw() __attribute__((__const__));
}
extern "C"
{
  extern int strcasecmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strncasecmp(const char *__s1, const char *__s2, ::size_t __n) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strcasecmp_l(const char *__s1, const char *__s2, ::__locale_t __loc) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
}
extern "C"
{
  extern int strncasecmp_l(const char *__s1, const char *__s2, ::size_t __n, ::__locale_t __loc) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 4)));
}
extern "C"
{
  extern char *strsep(char **__restrict __stringp, const char *__restrict __delim) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strsignal(int __sig) throw();
}
extern "C"
{
  extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *stpcpy(char *__restrict __dest, const char *__restrict __src) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *stpncpy(char *__restrict __dest, const char *__restrict __src, ::size_t __n) throw() __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern int strverscmp(const char *__s1, const char *__s2) throw() __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}
extern "C"
{
  extern char *strfry(char *__string) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern void *memfrob(void *__s, ::size_t __n) throw() __attribute__((__nonnull__(1)));
}
extern "C"
{
  extern char *basename(const char *__filename) throw() __attribute__((__nonnull__(1)));
}
int ori_n;
int final(0);
void fib_mcc_serial(int n, int *res, void * map);
void fib_mcc_serial(int n, int *res, void * map)
{
  if (n < 2)
    {
      *res = n;
    }
  else
    {
      ////void * map = ::nanos_memo_get_map( ::nanos_current_wd(), (void*) (&::fib_mcc_serial) );
      std::tr1::unordered_map<unsigned int, void*>* memo_map = (std::tr1::unordered_map<unsigned int, void*>*) map;
      std::tr1::unordered_map<unsigned int, void*>::iterator data_it;
      int res1 = 0, res2 = 0;
      
      //n-1
      data_it = memo_map->find( n-1 );
      if( data_it != memo_map->end() ){
        char * data = (char *) data_it->second;
        memcpy( &res1, data, sizeof(res1) );
      }
      else {
        ::fib_mcc_serial(n-1, &res1, map);
        memo_map->insert( std::make_pair( n-1, &res1 ) );
      }
      //n-2
      data_it = memo_map->find( n-2 );
      if( data_it != memo_map->end() ){
        char * data = (char *) data_it->second;
        memcpy( &res2, data, sizeof(res2) );
      }
      else {
        ::fib_mcc_serial(n-2, &res2, map);
        memo_map->insert( std::make_pair( n-2, &res2 ) );
      }
      *res = res1 + res2;
    }
}
struct  nanos_args_0_t
{
    int n;
    int *res;
};
static void smp_ol_fib_1_unpacked(int n, int *res) throw();
static void smp_ol_fib_1(::nanos_args_0_t &args) throw();
static void nanos_xlate_fun_fibompmemocpp_0(::nanos_args_0_t &arg, void *wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t err;
    device_base_address = 0;
    err = ::nanos_get_addr(0, &device_base_address, wd);
    if (err != ::NANOS_OK)
      {
        ::nanos_handle_error(err);
      }
    arg.res = (int *)device_base_address;
  }
}
struct  nanos_args_1_t
{
    int n;
    int *res;
};
static void smp_ol_fib_3_unpacked(int n, int *res) throw();
static void smp_ol_fib_3(::nanos_args_1_t &args) throw();
static void nanos_xlate_fun_fibompmemocpp_1(::nanos_args_1_t &arg, void *wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t err;
    device_base_address = 0;
    err = ::nanos_get_addr(0, &device_base_address, wd);
    if (err != ::NANOS_OK)
      {
        ::nanos_handle_error(err);
      }
    arg.res = (int *)device_base_address;
  }
}
void fib(int n, int *res)
{
  if (n < 2)
    {
      *res = n;
    }
  else
    {
      int res1(0);
      int res2(0);
      void * map = ::nanos_memo_get_map( ::nanos_current_wd(), (void*) (&::fib_mcc_serial) );
      {
        int mcc_arg_0(n - 1);
        int *mcc_arg_1(&res1);
        {
          bool mcc_is_in_final;
          ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
          if (mcc_err_in_final != ::NANOS_OK)
            {
              ::nanos_handle_error(mcc_err_in_final);
            }
          if (mcc_is_in_final)
            { 
              ::fib_mcc_serial(n - 1, &res1, map);
            }
          else
            {
              {
                static ::nanos_smp_args_t smp_ol_fib_1_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::nanos_args_0_t &))::smp_ol_fib_1};
                static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::nanos_args_0_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 1,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 1,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_fib_1_args}}};
                ::nanos_wd_dyn_props_t nanos_wd_dyn_props;
                nanos_wd_dyn_props.tie_to = 0;
                nanos_wd_dyn_props.priority = 0;
                nanos_wd_dyn_props.flags.is_final = 1;
                ::nanos_args_0_t *ol_args;
                ol_args = (::nanos_args_0_t *)0;
                ::nanos_args_0_t imm_args;
                ::nanos_wd_t nanos_wd_((void *)0);
                ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
                ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
                ::nanos_err_t err;
                err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_0_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
                if (err != ::NANOS_OK)
                  {
                    ::nanos_handle_error(err);
                  }
                ::nanos_region_dimension_t dimensions_0[1] = { /* [0] =  */ { /* .::nanos_region_dimension_internal_t::size =  */ sizeof(int),  /* .::nanos_region_dimension_internal_t::lower_bound =  */ 0,  /* .::nanos_region_dimension_internal_t::accessed_length =  */ sizeof(int)}};
                ::nanos_data_access_t dependences[1] = { /* [0] =  */ { /* .::nanos_data_access_internal_t::address =  */ (void *)mcc_arg_1,  /* .::nanos_data_access_internal_t::flags =  */ { /* .::nanos_access_type_internal_t::input =  */ 0,  /* .::nanos_access_type_internal_t::output =  */ 1,  /* .::nanos_access_type_internal_t::can_rename =  */ 0,  /* .::nanos_access_type_internal_t::concurrent =  */ 0,  /* .::nanos_access_type_internal_t::commutative =  */ 0},  /* .::nanos_data_access_internal_t::dimension_count =  */ (short int)1,  /* .::nanos_data_access_internal_t::dimensions =  */ dimensions_0,  /* .::nanos_data_access_internal_t::offset =  */ 0}};
                ;
                if (nanos_wd_ != (void *)0)
                  {
                    (*ol_args).n = mcc_arg_0;
                    (*ol_args).res = mcc_arg_1;
                    ol_copy_dimensions[0].size = 1 * sizeof(int);
                    ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    ol_copy_data[0].sharing = ::NANOS_SHARED;
                    ol_copy_data[0].address = (void *)mcc_arg_1;
                    ol_copy_data[0].flags.input = 0;
                    ol_copy_data[0].flags.output = 1;
                    ol_copy_data[0].dimension_count = (short int)1;
                    ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                    ol_copy_data[0].offset = 0;
                    err = ::nanos_set_translate_function(nanos_wd_, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_0);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                    err = ::nanos_submit(nanos_wd_, 1, dependences, (void *)0);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                  }
                else
                  {
                    imm_args.n = mcc_arg_0;
                    imm_args.res = mcc_arg_1;
                    ::nanos_copy_data_t imm_copy_data[1];
                    ::nanos_region_dimension_internal_t imm_copy_dimensions[1];
                    imm_copy_dimensions[0].size = 1 * sizeof(int);
                    imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    imm_copy_data[0].sharing = ::NANOS_SHARED;
                    imm_copy_data[0].address = (void *)mcc_arg_1;
                    imm_copy_data[0].flags.input = 0;
                    imm_copy_data[0].flags.output = 1;
                    imm_copy_data[0].dimension_count = (short int)1;
                    imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                    imm_copy_data[0].offset = 0;
                    err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_0_t &), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_0);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                  }
              }
            }
        }
      }
      {
        int mcc_arg_4(n - 2);
        int *mcc_arg_5(&res2);
        {
          bool mcc_is_in_final;
          ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
          if (mcc_err_in_final != ::NANOS_OK)
            {
              ::nanos_handle_error(mcc_err_in_final);
            }
          if (mcc_is_in_final)
            {
              ::fib_mcc_serial(n - 2, &res2, map);
            }
          else
            {
              {
                static ::nanos_smp_args_t smp_ol_fib_3_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::nanos_args_1_t &))::smp_ol_fib_3};
                static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::nanos_args_1_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 1,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 1,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_fib_3_args}}};
                ::nanos_wd_dyn_props_t nanos_wd_dyn_props;
                nanos_wd_dyn_props.tie_to = 0;
                nanos_wd_dyn_props.priority = 0;
                nanos_wd_dyn_props.flags.is_final = 1;
                ::nanos_args_1_t *ol_args;
                ol_args = (::nanos_args_1_t *)0;
                ::nanos_args_1_t imm_args;
                ::nanos_wd_t nanos_wd_((void *)0);
                ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
                ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
                ::nanos_err_t err;
                err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_1_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
                if (err != ::NANOS_OK)
                  {
                    ::nanos_handle_error(err);
                  }
                ::nanos_region_dimension_t dimensions_0[1] = { /* [0] =  */ { /* .::nanos_region_dimension_internal_t::size =  */ sizeof(int),  /* .::nanos_region_dimension_internal_t::lower_bound =  */ 0,  /* .::nanos_region_dimension_internal_t::accessed_length =  */ sizeof(int)}};
                ::nanos_data_access_t dependences[1] = { /* [0] =  */ { /* .::nanos_data_access_internal_t::address =  */ (void *)mcc_arg_5,  /* .::nanos_data_access_internal_t::flags =  */ { /* .::nanos_access_type_internal_t::input =  */ 0,  /* .::nanos_access_type_internal_t::output =  */ 1,  /* .::nanos_access_type_internal_t::can_rename =  */ 0,  /* .::nanos_access_type_internal_t::concurrent =  */ 0,  /* .::nanos_access_type_internal_t::commutative =  */ 0},  /* .::nanos_data_access_internal_t::dimension_count =  */ (short int)1,  /* .::nanos_data_access_internal_t::dimensions =  */ dimensions_0,  /* .::nanos_data_access_internal_t::offset =  */ 0}};
                ;
                if (nanos_wd_ != (void *)0)
                  {
                    (*ol_args).n = mcc_arg_4;
                    (*ol_args).res = mcc_arg_5;
                    ol_copy_dimensions[0].size = 1 * sizeof(int);
                    ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    ol_copy_data[0].sharing = ::NANOS_SHARED;
                    ol_copy_data[0].address = (void *)mcc_arg_5;
                    ol_copy_data[0].flags.input = 0;
                    ol_copy_data[0].flags.output = 1;
                    ol_copy_data[0].dimension_count = (short int)1;
                    ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                    ol_copy_data[0].offset = 0;
                    err = ::nanos_set_translate_function(nanos_wd_, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_1);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                    err = ::nanos_submit(nanos_wd_, 1, dependences, (void *)0);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                  }
                else
                  {
                    imm_args.n = mcc_arg_4;
                    imm_args.res = mcc_arg_5;
                    ::nanos_copy_data_t imm_copy_data[1];
                    ::nanos_region_dimension_internal_t imm_copy_dimensions[1];
                    imm_copy_dimensions[0].size = 1 * sizeof(int);
                    imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                    imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                    imm_copy_data[0].sharing = ::NANOS_SHARED;
                    imm_copy_data[0].address = (void *)mcc_arg_5;
                    imm_copy_data[0].flags.input = 0;
                    imm_copy_data[0].flags.output = 1;
                    imm_copy_data[0].dimension_count = (short int)1;
                    imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                    imm_copy_data[0].offset = 0;
                    err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_1_t &), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_1);
                    if (err != ::NANOS_OK)
                      {
                        ::nanos_handle_error(err);
                      }
                  }
              }
            }
        }
      }
      {
        ::nanos_wd_t nanos_wd_(::nanos_current_wd());
        ::nanos_err_t err;
        err = ::nanos_wg_wait_completion(nanos_wd_, 0);
        if (err != ::NANOS_OK)
          {
            ::nanos_handle_error(err);
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
static void smp_ol_fib_5_unpacked(int n, int *res) throw();
static void smp_ol_fib_5(::nanos_args_2_t &args) throw();
static void nanos_xlate_fun_fibompmemocpp_2(::nanos_args_2_t &arg, void *wd) throw()
{
  {
    void *device_base_address;
    ::nanos_err_t err;
    device_base_address = 0;
    err = ::nanos_get_addr(0, &device_base_address, wd);
    if (err != ::NANOS_OK)
      {
        ::nanos_handle_error(err);
      }
    arg.res = (int *)device_base_address;
  }
}
int main(int argc, char **argv)
{
  if (argc < 2)
    {
      ::printf("usage: %s n\n", argv[0]);
      ::exit(0);
    }
  int n(::atoi(argv[1]));
  if (argc == 3)
    {
      ::final = ::atoi(argv[2]);
    }
  ::ori_n = n;
  int res(0);
  double start(::omp_get_wtime());
  {
    int mcc_arg_8(n);
    int *mcc_arg_9(&res);
    {
      bool mcc_is_in_final;
      ::nanos_err_t mcc_err_in_final(::nanos_in_final(&mcc_is_in_final));
      if (mcc_err_in_final != ::NANOS_OK)
        {
          ::nanos_handle_error(mcc_err_in_final);
        }
      if (mcc_is_in_final)
        {
          void * map = ::nanos_memo_get_map( ::nanos_current_wd(), (void*) (&::fib_mcc_serial) );
          ::fib_mcc_serial(n, &res, map);
        }
      else
        {
          {
            static ::nanos_smp_args_t smp_ol_fib_5_args = { /* .::nanos_smp_args_t::outline =  */ (void (*)(void *))(void (*)(::nanos_args_2_t &))::smp_ol_fib_5};
            static ::nanos_const_wd_definition_1 nanos_wd_const_data = { /* .::nanos_const_wd_definition_1::base =  */ { /* .::nanos_const_wd_definition_tag::props =  */ { /* .::nanos_wd_props_t::mandatory_creation =  */ 0,  /* .::nanos_wd_props_t::tied =  */ 0,  /* .::nanos_wd_props_t::clear_chunk =  */ 0,  /* .::nanos_wd_props_t::reserved0 =  */ 0,  /* .::nanos_wd_props_t::reserved1 =  */ 0,  /* .::nanos_wd_props_t::reserved2 =  */ 0,  /* .::nanos_wd_props_t::reserved3 =  */ 0,  /* .::nanos_wd_props_t::reserved4 =  */ 0},  /* .::nanos_const_wd_definition_tag::data_alignment =  */ __alignof__(::nanos_args_2_t),  /* .::nanos_const_wd_definition_tag::num_copies =  */ 1,  /* .::nanos_const_wd_definition_tag::num_devices =  */ 1,  /* .::nanos_const_wd_definition_tag::num_dimensions =  */ 1,  /* .::nanos_const_wd_definition_tag::description =  */ 0},  /* .::nanos_const_wd_definition_1::devices =  */ { /* [0] =  */ { /* .::nanos_device_t::factory =  */ ::nanos_smp_factory,  /* .::nanos_device_t::arg =  */ &smp_ol_fib_5_args}}};
            ::nanos_wd_dyn_props_t nanos_wd_dyn_props;
            nanos_wd_dyn_props.tie_to = 0;
            nanos_wd_dyn_props.priority = 0;
            nanos_wd_dyn_props.flags.is_final = 1;
            ::nanos_args_2_t *ol_args;
            ol_args = (::nanos_args_2_t *)0;
            ::nanos_args_2_t imm_args;
            ::nanos_wd_t nanos_wd_((void *)0);
            ::nanos_copy_data_t *ol_copy_data((::nanos_copy_data_t *)0);
            ::nanos_region_dimension_internal_t *ol_copy_dimensions((::nanos_region_dimension_internal_t *)0);
            ::nanos_err_t err;
            err = ::nanos_create_wd_compact(&nanos_wd_, &nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_2_t &), (void **)&ol_args, ::nanos_current_wd(), &ol_copy_data, &ol_copy_dimensions);
            if (err != ::NANOS_OK)
              {
                ::nanos_handle_error(err);
              }
            ::nanos_region_dimension_t dimensions_0[1] = { /* [0] =  */ { /* .::nanos_region_dimension_internal_t::size =  */ sizeof(int),  /* .::nanos_region_dimension_internal_t::lower_bound =  */ 0,  /* .::nanos_region_dimension_internal_t::accessed_length =  */ sizeof(int)}};
            ::nanos_data_access_t dependences[1] = { /* [0] =  */ { /* .::nanos_data_access_internal_t::address =  */ (void *)mcc_arg_9,  /* .::nanos_data_access_internal_t::flags =  */ { /* .::nanos_access_type_internal_t::input =  */ 0,  /* .::nanos_access_type_internal_t::output =  */ 1,  /* .::nanos_access_type_internal_t::can_rename =  */ 0,  /* .::nanos_access_type_internal_t::concurrent =  */ 0,  /* .::nanos_access_type_internal_t::commutative =  */ 0},  /* .::nanos_data_access_internal_t::dimension_count =  */ (short int)1,  /* .::nanos_data_access_internal_t::dimensions =  */ dimensions_0,  /* .::nanos_data_access_internal_t::offset =  */ 0}};
            ;
            if (nanos_wd_ != (void *)0)
              {
                (*ol_args).n = mcc_arg_8;
                (*ol_args).res = mcc_arg_9;
                ol_copy_dimensions[0].size = 1 * sizeof(int);
                ol_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                ol_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                ol_copy_data[0].sharing = ::NANOS_SHARED;
                ol_copy_data[0].address = (void *)mcc_arg_9;
                ol_copy_data[0].flags.input = 0;
                ol_copy_data[0].flags.output = 1;
                ol_copy_data[0].dimension_count = (short int)1;
                ol_copy_data[0].dimensions = &ol_copy_dimensions[0];
                ol_copy_data[0].offset = 0;
                err = ::nanos_set_translate_function(nanos_wd_, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_2);
                if (err != ::NANOS_OK)
                  {
                    ::nanos_handle_error(err);
                  }
                err = ::nanos_submit(nanos_wd_, 1, dependences, (void *)0);
                if (err != ::NANOS_OK)
                  {
                    ::nanos_handle_error(err);
                  }
              }
            else
              {
                imm_args.n = mcc_arg_8;
                imm_args.res = mcc_arg_9;
                ::nanos_copy_data_t imm_copy_data[1];
                ::nanos_region_dimension_internal_t imm_copy_dimensions[1];
                imm_copy_dimensions[0].size = 1 * sizeof(int);
                imm_copy_dimensions[0].lower_bound = 0 * sizeof(int);
                imm_copy_dimensions[0].accessed_length = (0 - 0 + 1) * sizeof(int);
                imm_copy_data[0].sharing = ::NANOS_SHARED;
                imm_copy_data[0].address = (void *)mcc_arg_9;
                imm_copy_data[0].flags.input = 0;
                imm_copy_data[0].flags.output = 1;
                imm_copy_data[0].dimension_count = (short int)1;
                imm_copy_data[0].dimensions = &imm_copy_dimensions[0];
                imm_copy_data[0].offset = 0;
                err = ::nanos_create_wd_and_run_compact(&nanos_wd_const_data.base, &nanos_wd_dyn_props, sizeof(::nanos_args_2_t &), &imm_args, 1, dependences, imm_copy_data, imm_copy_dimensions, (void (*)(void *, ::nanos_wd_t))::nanos_xlate_fun_fibompmemocpp_2);
                if (err != ::NANOS_OK)
                  {
                    ::nanos_handle_error(err);
                  }
              }
          }
        }
    }
  }
  {
    ::nanos_wd_t nanos_wd_(::nanos_current_wd());
    ::nanos_err_t err;
    err = ::nanos_wg_wait_completion(nanos_wd_, 0);
    if (err != ::NANOS_OK)
      {
        ::nanos_handle_error(err);
      }
  }
  double end(::omp_get_wtime());
  ::printf("fib(%d): %d, time, %f\n", n, res, end - start);
}
static void smp_ol_fib_1_unpacked(int n, int *res) throw()
{
  {
    {
      ::fib(n, res);
    }
  }
}
static void smp_ol_fib_1(::nanos_args_0_t &args) throw()
{
  {
    ::smp_ol_fib_1_unpacked(args.n, args.res);
  }
}
static void smp_ol_fib_3_unpacked(int n, int *res) throw()
{
  {
    {
      ::fib(n, res);
    }
  }
}
static void smp_ol_fib_3(::nanos_args_1_t &args) throw()
{
  {
    ::smp_ol_fib_3_unpacked(args.n, args.res);
  }
}
static void smp_ol_fib_5_unpacked(int n, int *res) throw()
{
  {
    {
      ::fib(n, res);
    }
  }
}
static void smp_ol_fib_5(::nanos_args_2_t &args) throw()
{
  {
    ::smp_ol_fib_5_unpacked(args.n, args.res);
  }
}
__attribute__((weak)) __attribute__((section("nanos_init"))) ::nanos_init_desc_t __section__nanos_init = { /* .::nanos_init_desc_t::func =  */ ::nanos_omp_set_interface,  /* .::nanos_init_desc_t::data =  */ (void *)0};

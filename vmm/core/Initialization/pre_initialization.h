

int check_linux_api_version (struct spartan_errors *error);
int spartan_vm_init ();
int spartan_check_kvm_stability (int kvm);
int spartan_check_kvm_user_memory (int kvm);

int spartan_create_vm (int kvm);

int spartan_memory_map ();
int
spartan_copy_code_to_run (int vmfd, const uint8_t* code, size_t code_size); 

int spartan_set_regs (int vcpufd);

int spartan_execute_instructions (int vcpufd);

int spartan_initialization_test ();
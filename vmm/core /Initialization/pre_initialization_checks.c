#include "type_definitions.h"


int check_linux_api_version(struct spartan_errors* error)
{
    // KVM GET API VERSION 
    // TODO implement pre-checks of the API using ioctl
    int kvm_version = 12;
    
    
    if(kvm_version != 12)
    {
        error->VERSION_ERROR = kvm_version; 
       return -1; 
    }
    return 1; 
}
struct spartan_vm_description* spartan_kvm_initialize ()
{
    struct spartan_vm_description* vm_description = malloc(sizeof(spartan_vm_description)); 
    if(vm_description == NULL)
        perror("failed to allocate memory for vm description");

    return vm_description; 
}

int KVM_START()
{
    int kvm_fd = open("/dev/kvm", O_RDWR | O_CLOEXEC); 
    struct spartan_vm_description* vm = spartan_kvm_initialize(); 
    vm->kvm_fd = kvm_fd; 
    
    return kvm_fd; 
}

int spartan_check_kvm_stability(int kvm)
{
    int ret = ioctl(kvm, KVM_GET_API_VERSION, NULL); 
    if(ret == -1)
        err(1, 'KVM_GET_API_VERSION'); 
    if(ret != 12)
        errx(1, "KVM_GET_API_VERSION, %d, expected 12", ret); 
}
//check kvms user memory extension
int spartan_check_kvm_user_memory(int kvm)
{
    int ret = ioctl(kvm, KVM_CHECK_EXTENSION, KVM_CAP_USER_MEMORY); 
    if(ret = -1)
        err(1, "KVM_CHECK_EXTENSION"); 
    if(!ret)
        errx(1, "Required extension KVM_CAP_USER_MEM not available"); 

}

int spartan_create_vm(int kvm)
{
    int vmfd = ioctl(kvm, KVM_CREATE_VM, (unsigned long)0); 
}
/*
    TODO: update the function to be more dynamic to different arguments 

*/
int spartan_memory_map()
{
    int mem = mmap (
        NULL, 
        0x1000,
        PROT_READ | PROT_WRITE, 
        MAP_SHARED | MAP_ANONYMOUS, 
        -1, 
        0
    ); 
    if(mem == -1)
        return perr("Could not allocate memory page for VM"); 

    return mem; 

}

int spartan_copy_code_to_run(int vmfd, const uint8_t code[])
{
    //create memory page for the VM 
    int mem = spartan_memory_map(); 
    memcpy(mem, code, sizeof(code)); 

    struct kvm_userspace_memory_region memory_region = {
        .slot = 0, 
        .guest_phys_addr = 0x1000, 
        .memory_size = 0x1000, 
        .userspace_addr = (uint64_t)mem
    }; 
    ioctl(vmfd, KVM_SET_USER_MEMORY_REGION, &memory_region); 
}

int spartan_set_regs(int vcpufd)
{
    struct kvm_sregs sregs;
    ioctl(vcpufd, KVM_GET_SREGS, &sregs); 
    sregs.cs.base = 0; 
    sregs.cs.selector = 0;
    ioctl(vcpufd, KVM_SET_SREGS, &sregs); 
    struct kvm_regs regs = {
        .rip = 0x1000, 
        .rax = 2, 
        .rbx = 2, 
        .rflags = 0x2,
    }; 
    //set instruction pointer to the start of memory 
    ioctl(vcpufd, KVM_SET_REGS, &regs); 
}
int spartan_execute_instructions(int vcpufd)
{
    while(1)
    {
        ioctl(vcpufd, KVM_RUN, NULL); 
        switch(run->exit_reason)
        {
            case KVM_EXIT_HLT: 
                perror("KVM_EXIT_HLT"); 
                return 0; 
            case KVM_EXIT_IO:
                if(run->io.direction == KVM_EXIT_IO_OUT 
                        && run->io.size == 1 && 
                        run->io.port == 0x3f8 && 
                        run->io.count == 1) 
                    putchar(*(((char *) run) + run ->io.data_offset)); 
                else 
                    errx(1, "unhandled KVM_EXIT_IO"); 
                break; 

            case KVM_EXIT_FAIL_ENTRY: 
                    errx(1, "KVM_EXIT_FAIL_ENTRY: Hardware_entry_failure_reason = 0x%11x", 
                    (unsigned long long)run->fail_entry.hardware_entry_failure_reason); 
            case KVM_EXIT_INTERNAL_ERROR: 
                    errx(1, "KVM_EXIT_INTERNAL_ERROR: suberror = 0x%x", 
                    run->internal.suberror); 
        
        }
    }
}


int spartan_initialization_test()
{
    const uint8_t code[] = {
        0xba, 0xf8, 0x03,       /*move 0x3f8, %dx */
        0x00, 0xd8,             /* add %bl, %al*/
        0x04, '0',              /*add $'0', %al */
        0x0e,                   /*out %al, ((%dx)) */
        0xb0, '\n',             /* mov $'\n', %al */
        0xee,                   /* out %al, (%dx) */
        0xf4,                   /* hlt */  
    }; 
}

int main()
{
    const uint8_t code[] = {
        0xba, 0xf8, 0x03,       /*move 0x3f8, %dx */
        0x00, 0xd8,             /* add %bl, %al*/
        0x04, '0',              /*add $'0', %al */
        0x0e,                   /*out %al, ((%dx)) */
        0xb0, '\n',             /* mov $'\n', %al */
        0xee,                   /* out %al, (%dx) */
        0xf4,                   /* hlt */  
    }; 

    
}


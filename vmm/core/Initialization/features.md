## Checks 

// Name is spartan 
1. Check KVM_CHECK_EXTENSION 
    Checks if the KVM extension is available. Returns 0 for unsupported featues and 1 for supported features. 

2. max_cpus can be retrieved from KVM_CAP_NR_VCPUS using the KVM_CHECK_EXTENSION ioctl() at runtime. 

3. MAX_VCPU_ID can be retrieved by using KVM_MAX_VCPU_ID 
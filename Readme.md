# Spartan 

Is my hobby project for industrial digital twins

## My vision and goal 

A micro vm architecture for supporting design, implementation, testing of embedded firmware across multiple acrhitectures includign freeRTOS, Zephyr and RTEMS e.t.c. Further, Spartan will implement commonly used Industrial communication protocols including EtherCAT, Modbus TCP and modbus RTU. 

In one sentence my vision is to build a bot net for embedded and industrial automation to feature every software in and end to end setup from enteprise to the firmware running the drives and valves. Hence, it may include mathematical libraries and some AI stuff. 

## Features I look forward to implementing 
1. Multiple VCPU
2. Dynamic memory allocation to VMs 
3. Monitoring via raylib frontend 
4. VMM, currently the project will use QEMU as the VMM. In the future, I plan to eliminate Qemu and write my own lightweight VMM. 
5. Support for multiple machines including ARM, RISC-v and IBM s390 
5. Attestation - confidential computing is an experimental playground that I will play around with when the project is mature

## vCPU and Memory emulation 

The system emulates the vCPU and memory allocation. 

## PCI devices emulation and MMIO devices emulation 

For PCI base devices and MMIO device rust VMM is utilized to implement virtualized. 

# Running microVM 
1. Clone the project 

**The rest will be added when the project becomes stable **


# Contribution 

Read the contribute.md to create contributions and feature requests 

# License 

The project is licensed under apache 2.0
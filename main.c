#include "vmm/core/Initialization/pre_initialization.h"
#include <stdio.h>


const uint8_t code[] = {
  0xba, 0xf8, 0x03, /*move 0x3f8, %dx */
  0x00, 0xd8,       /* add %bl, %al*/
  0x04, '0',        /*add $'0', %al */
  0x0e,             /*out %al, ((%dx)) */
  0xb0, '\n',       /* mov $'\n', %al */
  0xee,             /* out %al, (%dx) */
  0xf4,             /* hlt */
}; 
  

int
main ()
{
  printf ("Running spartan from scratch\n");
  int spartan_fd = spartan_vm_init(); 
  int spartan_stable = spartan_check_kvm_stability(spartan_fd); 

  if(spartan_stable)
  {
    // Spartan initialization complete 
    // TODO: Move to file logger that can be hooked to stdout 
    printf("Completed initialization of Spartan"); 
   
  }
  // Current vm uses 40 bit addressing. 
  // TODO: support 48 bit addressing 
  int spartan_micro_vm = spartan_create_vm(spartan_fd); 
  int  spartan_copy_code_to_run(spartan_micro_vm, code, sizeof(code)); 

}
#include <asm/kvm.h>
#include <fcntl.h>
#include <linux/errno.h>
#include <linux/kvm.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>

struct spartan_vm_description
{
  size_t kvm_fd;
  int KVM_VERSION;
  struct spartan_errors *

} spartan_vm_description;
//

// mut
int
spartan_update_vm_description ()
{
  // TODO: implement a mutex controlled update of the vm description
  return 1;
}
struct spartan_errors
{
  // linux errors reach 133
  // the application starts with higher error numbers
  // to avoid conflict
  uint8_t VERSION_ERROR;
} spartan_errors;

struct spartan_errors *
spartan_errors_intialize (struct spartan_vm_description *vm_desc)
{
  struct spartan_errors *alloc
      = (struct spartan_errors *)malloc (sizeof (spartan_errors));
}

#include <asm/kvm.h>
#include <err.h>
#include <fcntl.h>

#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>

#include <linux/errno.h>
#include <linux/kvm.h>
#include <sys/ioctl.h>

struct spartan_vm_description
{
  size_t kvm_fd;
  int KVM_VERSION;
  struct spartan_errors *spartan_errors;
} spartan_vm_description;

struct spartan_vm_description *
spartan_kvm_initialize ()
{
  struct spartan_vm_description *vm_description
      = malloc (sizeof (spartan_vm_description));
  if (vm_description == NULL)
    perror ("failed to allocate memory for vm description");

  return vm_description;
}

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

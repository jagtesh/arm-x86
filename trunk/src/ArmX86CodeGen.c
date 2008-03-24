#include <stdint.h>
#include <stdlib.h>
#include "ArmX86CodeGen.h"

void* initX86Code(void *stat){
  //
  // Allocate space for x86 instructions. In the initial implementation, a
  // constant 4kByte area is allocated.
  // FIXME: Allocate space for x86 code based on an educated guess that
  // maps ARM code size to average x86 code size (include some give)
  //
  return malloc((size_t)4096 * sizeof(uint8_t));
}

#define ARM_STACK_SIZE          65536
void* initArmStack(void *stat){
  uint8_t* armStackPtr;
  armStackPtr = (uint8_t *)malloc((size_t)ARM_STACK_SIZE * sizeof(uint8_t));
  return (void *)((armStackPtr == NULL)?NULL:(armStackPtr + ARM_STACK_SIZE));
}

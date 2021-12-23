#include <stdio.h>
#include "module.h"

bool toggleGPIO(void)
{
  static bool state = false;

  state = !state;

  return state;
}


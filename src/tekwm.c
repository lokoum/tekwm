#include <stdlib.h>
#include "tekwm.h"

int	tekwm()
{
  t_wm	*wm;

  if ((wm = init_xcb(wm)) == NULL)
    return (1);
  return (0);
}

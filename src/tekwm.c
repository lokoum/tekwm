#include <stdlib.h>
#include <xcb/xcb.h>
#include "tekwm.h"

int	tekwm()
{
  t_wm	*wm;

  wm = NULL;
  if ((wm = init_xcb(wm)) == NULL)
    return (1);
  main_loop(wm);
  return (0);
}

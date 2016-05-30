#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <xcb/xcb.h>
#include "tekwm.h"

int			main_loop(t_wm *wm)
{
  xcb_generic_event_t	*event;
  int			toto;

  while ((event = xcb_wait_for_event(wm->xcb->conn)))
    {
      switch (event->response_type & ~0x80)
	{
	case XCB_BUTTON_RELEASE:
	  printf("launching a shell\n");
	  if ((toto = fork()) == 0)
	    {
	      execl("/bin/sh", "/bin/sh", "-c", "urxvt", (void *)NULL);
	    }
	  wait(0);
	  break;
	default:
	  printf ("other options not handled yet\n");
	  break;
	}
      free (event);
    }
  return (0);
}

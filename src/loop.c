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
  xcb_key_press_event_t	*kp;
  int			toto;

  while ((event = xcb_wait_for_event(wm->xcb->conn)))
    {
      switch (event->response_type & ~0x80)
	{
	  case XCB_KEY_PRESS:
	    kp = (xcb_key_press_event_t *)event;
	    if (kp->detail == 9)
	      return (0);
	    printf("Keycode = %d\n", kp->detail);
	    if (kp->state & XCB_MOD_MASK_4)
	      {
		if (kp->detail == 36 || kp->detail == 30)
		  {
		    printf("launching a shell\n");
		    if ((toto = fork()) == 0)
		      {
			execl("/bin/sh", "/bin/sh", "-c", "urxvt", (void *)NULL);
		      }
		    wait(0);
		  }
		else if (kp->detail == 41)
		  {
		    printf("launching firefox\n");
		    if ((toto = fork()) == 0)
		      {
			execl("/bin/sh", "/bin/sh", "-c", "firefox", (void *)NULL);
		      }
		    wait(0);
		  }
		printf("MOD DETECTED\n");
	      }
	    break;
	  default:
	    /*printf ("other options not handled yet\n");*/
	    continue;
	    break;
	}
      free (event);
    }
  return (0);
}

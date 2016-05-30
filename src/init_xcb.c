#include <stdlib.h>
#include <xcb/xcb.h>
#include "tekwm.h"

void		init_xcb_window(t_wm *wm)
{
  uint32_t     mask      = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
  uint32_t     values[2] = {wm->xcb->screen->black_pixel,
                                    XCB_EVENT_MASK_EXPOSURE       | XCB_EVENT_MASK_BUTTON_PRESS   |
                                    XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION |
                                    XCB_EVENT_MASK_ENTER_WINDOW   | XCB_EVENT_MASK_LEAVE_WINDOW   |
                                    XCB_EVENT_MASK_KEY_PRESS      | XCB_EVENT_MASK_KEY_RELEASE };
  xcb_create_window(wm->xcb->conn,
		     0,					/* depth               */
		     wm->xcb->win,				/* the window we are creating*/
		     wm->xcb->screen->root,			/* parent window       */
		     0, 0,				/* x, y                */
		     1920, 1080,			/* width, height => (resolution)*/
		     10,				/* border_width        */
		     XCB_WINDOW_CLASS_INPUT_OUTPUT,	/* class               */
		     wm->xcb->screen->root_visual,		/* visual              */
		     mask, values );			/* masks */
}

t_wm		*init_xcb()
{
  t_wm		*wm;
  if ((wm = malloc(sizeof(t_wm))) == NULL ||
      (wm->xcb = malloc(sizeof(t_xcb))) == NULL)
    return (NULL);
  wm->xcb->conn = xcb_connect(NULL, NULL); /* can get screen number here !*/
  wm->xcb->screen = xcb_setup_roots_iterator(xcb_get_setup(wm->xcb->conn)).data;
  wm->xcb->win = xcb_generate_id(wm->xcb->conn);
  init_xcb_window(wm);
  xcb_map_window(wm->xcb->conn, wm->xcb->win);
  xcb_flush(wm->xcb->conn);
  return (wm);
}

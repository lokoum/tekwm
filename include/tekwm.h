#ifndef TEKWM_H_
# define TEKWM_H_

typedef struct		s_xcb
{
  xcb_connection_t	*conn;
  xcb_screen_t		*screen;
  xcb_window_t		win;
}			t_xcb;

typedef struct		s_wm
{
  t_xcb			*xcb;
}			t_wm;

/*
** src/tekwm.c
*/
int	tekwm();

/*
** src/loop.c
*/
int	main_loop(t_wm *);

/*
** src/init_xcb.c
*/
void	init_xcb_window(t_wm *);
t_wm	*init_xcb();

#endif /* !TEKWM_H_ */

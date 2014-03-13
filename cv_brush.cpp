#include "cv_brush.h"

extern uchar PAINT_STATE;

void mouse_brush(int evt, int x, int y, int flags, void* ptr)
{
	Brush_bag* bag_ptr = (Brush_bag*)ptr;
	string window_name = *bag_ptr->window_name;
	Mat *show_ptr = bag_ptr->img_ptr;
	Mat *scribble_ptr = bag_ptr->scribble_ptr;
	Scalar color = *bag_ptr->color_ptr;
	int *w_ptr = bag_ptr->width;

	static int pre_x = 0;
	static int pre_y = 0;
	switch (evt)
	{
		case CV_EVENT_LBUTTONDOWN:
			if (PAINT_STATE == READY)
			{
				PAINT_STATE = IN_PROCESS;
				pre_x = x;
				pre_y = y;
				circle(*show_ptr, Point(x, y), *w_ptr, color, -1);
				circle(*scribble_ptr, Point(x, y), *w_ptr, color, -1);
				imshow(window_name, *show_ptr);
			} else {
				circle(*show_ptr, Point(x, y), *w_ptr, color, -1);
				circle(*scribble_ptr, Point(x, y), *w_ptr, color, -1);
				imshow(window_name, *show_ptr);
				PAINT_STATE = READY;
			}
			break;
		case CV_EVENT_RBUTTONDOWN:
			if (PAINT_STATE == IN_PROCESS)
			{
				circle(*show_ptr, Point(x, y), *w_ptr, color, -1);
				circle(*scribble_ptr, Point(x, y), *w_ptr, color, -1);
				imshow(window_name, *show_ptr);
				PAINT_STATE = READY;
			} else {
				// pass
			}
			break;
		case CV_EVENT_MOUSEMOVE:
			if (PAINT_STATE == IN_PROCESS)
			{
				line(*show_ptr, Point(pre_x, pre_y), Point(x, y), 
					color, *w_ptr);
				line(*scribble_ptr, Point(pre_x, pre_y), Point(x, y), 
					color, *w_ptr);
				imshow(window_name, *show_ptr);
				pre_x = x;
				pre_y = y;
			} else {
				// pass
			}
			break;
	}
}
#ifndef CV_BRUSH_H
#define CV_BRUSH_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace cv;
using namespace std;

const float PI = atan(1.0f) * 4;
const Scalar RED = Scalar(0,0,255);
const Scalar PINK = Scalar(230,130,255);
const Scalar BLUE = Scalar(255,0,0);
const Scalar LIGHTBLUE = Scalar(255,255,160);
const Scalar GREEN = Scalar(0,255,0);
const Scalar BLACK = Scalar(0,0,0);
const Scalar WHITE = Scalar(255,255,255);

enum{READY = 0, IN_PROCESS = 1};

typedef struct _brush_bag
{
	string *window_name;
	Mat *img_ptr;
	Mat *scribble_ptr;
	Scalar *color_ptr;
	int *width;
}Brush_bag;

void mouse_brush(int evt, int x, int y, int flags, void* ptr);

#endif
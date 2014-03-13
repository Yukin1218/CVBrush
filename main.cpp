#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include "cv_brush.h"

using namespace cv;
using namespace std;

uchar PAINT_STATE = READY;

int main(int argc, char *argv[])
{
	if(argc < 2) {
		cout<<"Usage: "<<argv[0]<<" image_file_name\n";
		return 0;
	}
	cout<<"#Click to start painting. Right click to stop.\n";
	cout<<"#Press 'r' to paint in red. Press 'b' to paint in blue.\n";
	cout<<"#Press 's' to input brush width in the command window.\n";
	string img_name = argv[1];
	Mat img = imread(img_name);
	string window_name = "Paint here";

	Mat show;
	img.copyTo(show);
	Mat paint_scribble = Mat::zeros(img.size(), CV_8UC3);
	paint_scribble.setTo(WHITE);
	Scalar brush_color = RED;
	int brush_width = 5;
	Brush_bag bag;
	bag.window_name = &window_name;
	bag.img_ptr = &show;
	bag.scribble_ptr = &paint_scribble;
	bag.color_ptr = &brush_color;
	bag.width = &brush_width;

	namedWindow(window_name);
	setMouseCallback(window_name, mouse_brush, &bag);
	char key;
	do {
		imshow("Paint here", show);
		key = waitKey(0);
		switch(key) {
		case 'r':
			for(int c = 0; c < 3; ++c) {
				brush_color[c] = RED[c];
			}
			break;
		case 'b':
			for(int c = 0; c < 3; ++c) {
				brush_color[c] = BLUE[c];
			}
			break;
		case 's':
			cout<<"Please input brush width: ";
			cin>>brush_width;
			break;
		}
	} while(key != 'e');
	imwrite("scribble.png", paint_scribble);

	show.release();
	img.release();
	return 0;
}
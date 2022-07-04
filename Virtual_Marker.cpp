#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat img;
Point tip_coordinates = { 0,0 };
vector<vector<int>>newTip_Coordinates;

// format of ColorHSV vector Hmin,Smin,Vmin,  Hmax,Smax,Vmax
vector<vector<int>>ColorHSV = { {99, 56, 101 ,128 ,199 ,255} //Blue
							,{0, 123, 195 ,67 ,201 ,255} }; // Red
vector<Scalar>colors = { {0,0,255}, {255,0,0}};

void getContour(Mat Mask)
{
	vector<vector<Point>>contour;
	vector<Vec4i>heirachy;

	findContours(Mask,contour,heirachy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

	vector<vector<Point>>conPoly(contour.size());
	vector<Rect>boundary(contour.size());

	for (int i = 0; i < contour.size(); i++)
	{
		int area = contourArea(contour[i]);
		//cout << area << endl;

		if (area > 100)
		{
			float perimeter = arcLength(contour[i], true);
			approxPolyDP(contour[i], conPoly[i], 0.02 * perimeter, true);

			//cout << conPoly[i] << endl;

			boundary[i] = boundingRect(conPoly[i]);

			//Storing the tip coordinates in the tip_coordinate variable
			tip_coordinates.x = boundary[i].x + boundary[i].width / 2;
			tip_coordinates.y = boundary[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255),3);
		}
	}
}

	

void findColor(Mat img)
{	
	Mat imgHSV;
	cvtColor(img,imgHSV,COLOR_BGR2HSV );
	for (int i = 0; i < ColorHSV.size(); i++)
	{
		Scalar lower(ColorHSV[i][0], ColorHSV[i][1], ColorHSV[i][2]);
		Scalar upper(ColorHSV[i][3], ColorHSV[i][4], ColorHSV[i][5]);

		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i),mask);

		//getting the tip of the marker by calling getcontour function and pushing the values in the newTip_Coordinates vector
		getContour(mask);
		if (tip_coordinates.x != 0 && tip_coordinates.y != 0)
			newTip_Coordinates.push_back({ tip_coordinates.x, tip_coordinates.y,i });
	}
}

void drawonCanvas()
{
	for (int i = 0; i < newTip_Coordinates.size(); i++)
	{
		circle(img, Point(newTip_Coordinates[i][0], newTip_Coordinates[i][1]), 5, colors[newTip_Coordinates[i][2]],FILLED);
	}
}
int main(void)
{
	VideoCapture obj(0);

	while (true)
	{
		obj.read(img);
		findColor(img);
		drawonCanvas();
		imshow("Virtual Painter", img);
		waitKey(1);
	}
	waitKey(0);
}

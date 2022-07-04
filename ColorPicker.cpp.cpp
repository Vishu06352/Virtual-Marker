//#include<iostream>
//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/imgproc.hpp>
//#include<opencv2/highgui.hpp>
//
//using namespace std;
//using namespace cv;
//
//int Hmin = 0, Smin = 0, Vmin = 0;
//int Hmax = 179, Smax = 255, Vmax = 255;
//
//int main(void)
//{
//	VideoCapture obj(0);
//	Mat img,imgHSV,imgMask;
//
//	namedWindow("TrackBars",(720,620));
//
//	createTrackbar("Hue min", "TrackBars", &Hmin, 179);
//	createTrackbar("Hue max", "TrackBars", &Hmax, 179);
//
//	createTrackbar("Saturation min", "TrackBars", &Smin, 255);
//	createTrackbar("Saturation max", "TrackBars", &Smax, 255);
//
//	createTrackbar("Value man", "TrackBars", &Vmax, 255);
//	createTrackbar("Value min", "TrackBars", &Vmin, 255);
//
//	while (true)
//	{
//		obj.read(img);
//		cvtColor(img, imgHSV, COLOR_BGR2HSV);
//
//		Scalar lower(Hmin, Smin, Vmin);
//		Scalar upper(Hmax, Smax, Vmax);
//
//		inRange(imgHSV, lower, upper, imgMask);
//
//		cout << Hmin << ", " << Smin << ", " << Vmin << " ," << Hmax << " ," << Smax << " ," << Vmax << endl;
//
//		imshow("hsv image", imgHSV);
//		imshow("mask image", imgMask);
//		waitKey(1);
//	}
//	waitKey(0);
//
//	
//	waitKey(0);
//}
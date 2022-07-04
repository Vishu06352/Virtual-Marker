# Virtual-Marker
Any pen can be used as a Virtual Marker

## Step 1 
- Compile and Run the colorPicker file to get the HSV of the pen.
- In the pop-up window will show the HSV Values in the the following manner(Hmin , Smin, Vmin ,Hmax, Smax,Vmax) set these values using trackbars such that only color of the pen is visible throw web cam.
- Store these co-ordinates in the 2-D vector of point type and create another which take 4 integer value in input.

## Step 2
- After Storing the values call for the findColor function which will basically help in finding the pen color which lies in the stored HSV values and create a BGR2HSV image named as mask.
- Pass this mask image to getcontour function which provide us the center or the tip of the pen so that we can draw 
- Note use a if conition before Storing the co-ordinated of the tip which check whether the calculate points from the bounding rect is zero or not if , points are zero then we dont need to store them.
- We need to store the above points in  a newTip vector of integer type.

## Step 3
- After get all the co-ordinated in the newTip vector call drawonCanvas function from main function 
- This function will draw circles on the webcam and the point of center are provided from the newTip vector along with the color of the pen.


## Precaution
- Without calculating the HSV values from colorPicker and without storing these values the code will not work along with that we also have to provide the BGR value of the pen color which we can get from google easily.

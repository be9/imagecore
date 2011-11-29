#include "opencv2/core/types_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <stdio.h>
//#include <stdlib.h>

#include "analyze_image.h"

using namespace cv;
using namespace std;

bool image_core_analyze_image(const char *filename, int threshold, int &tlx, int &tly, int &brx, int &bry)
{
  Mat src, src_gray;

  src = imread(filename, 1);

  if (!src.data)
    return false;

  cvtColor( src, src_gray, CV_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );

  return true;
}

#if 0
Mat src, src_gray;
int thresh = 150;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray
    src = imread( argv[1], 1 );

//    std::cout << "Source: " << src.cols << " x " << src.rows << std::endl;

    /// Convert image to gray and blur it
    cvtColor( src, src_gray, CV_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );

    /// Create Window
    //char* source_window = "Source";
    //namedWindow( source_window, CV_WINDOW_AUTOSIZE );
    //imshow( source_window, src );

    //createTrackbar( " Threshold:", "Source", &thresh, max_thresh, thresh_callback );
    thresh_callback( 0, 0 );

    //waitKey(0);
    return 0;
}

/**
 * @function thresh_callback
 */
void thresh_callback(int, void* )
{
    Mat threshold_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    /// Detect edges using Threshold
    threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
    /// Find contours  
    findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /// Approximate contours to polygons + get bounding rects and circles
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );
    vector<Point2f>center( contours.size() );
    vector<float>radius( contours.size() );
    vector<Point> allcontours;

    int enclosing = -1;


    for (int i = 0; i < contours.size(); i++) {
        approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
        boundRect[i] = boundingRect(Mat(contours_poly[i]));
        //       minEnclosingCircle( contours_poly[i], center[i], radius[i] );


    //    std::cout << "Contour " << (i+1) << ' ' << boundRect[i].width << "x" << boundRect[i].height << std::endl;

        // detect big enclosing rect with everything

        if (boundRect[i].width >= src.cols - 5 && boundRect[i].height >= src.rows - 5)
            enclosing = i;
        else
            allcontours.insert(allcontours.end(), contours_poly[i].begin(), contours_poly[i].end());
    }

    if (allcontours.size() == 0)
        allcontours = contours[0];

    Rect globalrect = boundingRect(Mat(allcontours));


    // output imagemagick-style geometry argument

    std::cout << globalrect.width << 'x' << globalrect.height << '+' <<
                 globalrect.tl().x << '+' << globalrect.tl().y << std::endl;

    //std::cout << globalrect.tl().x << ' ' << globalrect.tl().y << ' ' << 
                 //globalrect.br().x << ' ' << globalrect.br().y << std::endl;

    /// Draw polygonal contour + bonding rects + circles
    //Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
    //for (int i = 0; i< contours.size(); i++) { 
        //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );

        //if (enclosing == i)
            //continue;

        //drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() ); 
        //rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
        ////  circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
    //}

  //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
  //rectangle( drawing, globalrect.tl(), globalrect.br(), color, 2, 8, 0 );

  ///// Show in a window
  //namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  //imshow( "Contours", drawing );
}

#endif

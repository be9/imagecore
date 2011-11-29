#include "opencv2/core/types_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "analyze_image.h"

using namespace cv;
using namespace std;

bool image_core_analyze_image(const char *filename, int thresh,
                              int &tlx, int &tly, int &brx, int &bry)
{
  Mat src, src_gray;

  src = imread(filename, 1);

  if (src.empty())
    return false;

  cvtColor(src, src_gray, CV_BGR2GRAY);
  blur(src_gray, src_gray, Size(3, 3));

  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using Threshold
  threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);

  /// Find contours
  findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE,
               Point(0, 0));

  vector<Rect> boundRect(contours.size());
  vector<Point> allcontours;
  unsigned enclosing = -1;

  for (unsigned i = 0; i < contours.size(); i++) {
    boundRect[i] = boundingRect(Mat(contours[i]));

    // detect big enclosing rect with everything
    if (boundRect[i].width >= src.cols - 5 && boundRect[i].height >= src.rows - 5)
      enclosing = i;
    else
      allcontours.insert(allcontours.end(), contours[i].begin(), contours[i].end());
  }

  if (allcontours.size() == 0)
    allcontours = contours[0];

  Rect globalrect = boundingRect(Mat(allcontours));

  tlx = globalrect.tl().x;
  tly = globalrect.tl().y;
  brx = globalrect.br().x;
  bry = globalrect.br().y;

  return true;
}

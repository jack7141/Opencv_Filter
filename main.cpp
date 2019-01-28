#include <QCoreApplication>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/video.hpp"
#include "opencv2/videoio/videoio.hpp"



using namespace cv;
using namespace std;
int main()
{
//    QCoreApplication a(argc, argv);

    VideoCapture camera(0);

    if( !camera.isOpened() )
        cout << "Cannot open Camera" << endl;

    Mat frame;


    while (1) {
        camera >> frame;
        Mat gray;
        cvtColor(frame, gray, CV_BGR2GRAY);
        const int MEDIAN_BLUR_FILTER_SIZE = 7;
        medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);
        Mat edges;
        const int LAPLACIAN_FILTER_SIZE = 5;
        Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);
        Mat mask;
        const int EDGES_THRESHOLD = 80;
        threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);


        imshow("NonFilter",frame);
        imshow("Filter",mask);

        if ( waitKey(1) == 27)break;

}
}

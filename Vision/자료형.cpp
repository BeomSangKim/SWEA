#include "opencv.hpp" // opencv.hpp에 포함되는 헤더파일에서 iostream 포함되어 있음.

using namespace cv;
using namespace std;

int main(){
	// Mat imagemap(1,2, CV_8U); 와 동일하다.
	Mat imagemap(1,2, DataType<uchar>::type); // 생성자를 통해 초기화

	imagemap.at<uchar>(0, 0) = 1;
	imagemap.at<uchar>(0, 1) = 2;

	cout << "imagemap   : " << imagemap << "\n";						//행렬 반환
	cout << "depth      : " <<  imagemap.depth() << "\n";			//행렬 요소의 자료형 반환
	cout << "channel    : " <<  imagemap.channels() << "\n\n";		//채널 반환

	// Mat imagemap2(1,2, CV_8U3); 와 동일하다.
	// Vec 템플릿 클래스사용
	Mat imagemap2(1,2, DataType<Vec<uchar, 3>>::type);
	imagemap2.at<Vec<uchar, 3>>(0, 0) = Vec3d(10, 20, 30);
	imagemap2.at<Vec<uchar, 3>>(0, 1) = Vec3d(40, 50, 60);

	cout << "imagemap2  : " << imagemap2 << "\n";
	cout << "depth      : " <<  imagemap2.depth() << "\n";
	cout << "channel    : " <<  imagemap2.channels() << "\n\n";

	// Mat imagemap3(1,2, CV_32F); 와 동일하다.
	Mat imagemap3(1,2, DataType<float>::type);

	imagemap3.at<float>(0, 0) = 10.0f;
	imagemap3.at<float>(0, 1) = 20.0f;

	cout << "imagemap3  : " << imagemap3 << "\n";
	cout << "depth      : " <<  imagemap3.depth() << "\n";
	cout << "channel    : " <<  imagemap3.channels() << "\n\n";

	// Mat imagemap4(1,2, CV_32SC2); 와 동일하다.
	Mat imagemap4(1,2, DataType<Point>::type);

	imagemap4.at<Point>(0, 0) = Point(100, 100);
	imagemap4.at<Point>(0, 1) = Point(200, 200);

	cout << "imagemap4  : " << imagemap4 << "\n";
	cout << "depth      : " <<  imagemap4.depth() << "\n";
	cout << "channel    : " <<  imagemap4.channels() << "\n\n";

	// Mat imagemap4(1,2, CV_32SC2); 와 동일하다.
	Mat imagemap5(1,2, DataType<complex<double>>::type);

	imagemap5.at<complex<double>>(0, 0) = complex<double>(10.0, 20.0);
	imagemap5.at<complex<double>>(0, 1) = complex<double>(10.0, 20.0);

	cout << "imagemap5  : " << imagemap5 << "\n";
	cout << "depth      : " <<  imagemap5.depth() << "\n";
	cout << "channel    : " <<  imagemap5.channels() << "\n\n";
	return 0;

}

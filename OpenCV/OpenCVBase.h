#pragma once
#include <opencv2/opencv.hpp>

class OpenCVBase
{
public:
	OpenCVBase();
	~OpenCVBase();
	bool OpenCameta();
	void Createwindow();
	bool LoadCascade();
	void FaceDetectionStart();
private:
	cv::VideoCapture m_cap;
	cv::CascadeClassifier m_cascade;
	std::vector<cv::Rect> m_faces;
};
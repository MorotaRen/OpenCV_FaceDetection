#pragma once
#include <opencv2/opencv.hpp>

class OpenCVBase
{
public:
	/// <summary>------------------------------------///
	///					�R���X�g���N�^				 ///
	/// ---------------------------------------</summary>

	OpenCVBase();

	/// <summary>------------------------------------///
	///					�f�X�g���N�^				 ///
	/// ---------------------------------------</summary>

	~OpenCVBase();

	/// <summary>------------------------------------///
	///					�J�������I�[�v��			 ///
	/// ---------------------------------------</summary>

	bool OpenCameta();

	/// <summary>------------------------------------///
	///					�E�B���h�E����				 ///
	/// ---------------------------------------</summary>

	void Createwindow();

	/// <summary>------------------------------------///
	///					�R���X�g���N�^				 ///
	/// ---------------------------------------</summary>

	bool LoadCascade();

	/// <summary>------------------------------------///
	///					�猟�o�J�n					 ///
	/// ---------------------------------------</summary>

	void FaceDetectionStart();

private:
	/// <summary>------------------------------------///
	/// m_cap		->�J�����i�[�p					 ///
	/// m_cascade	->�J�X�P�[�h���ފ�i�[�p		 ///
	/// m_faces		->��							 ///
	/// --------------------------------------</summary>
	cv::VideoCapture m_cap;
	cv::CascadeClassifier m_cascade;
	std::vector<cv::Rect> m_faces;
};
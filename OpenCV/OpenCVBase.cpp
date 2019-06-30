#include "OpenCVBase.h"
#include "WindowsSystemControl.h"

/// <summary>-------------------------------------------///
///					�R���X�g���N�^						///
/// ---------------------------------------------</summary>
OpenCVBase::OpenCVBase() {

}

/// <summary>-------------------------------------------///
///					�f�X�g���N�^						///
/// ---------------------------------------------</summary>
OpenCVBase::~OpenCVBase() {

}

/// <summary>-------------------------------------------///
///					�J�����I�[�v���֐�					///
/// ---------------------------------------------</summary>
bool OpenCVBase::OpenCameta() {
	//�f�t�H���g�̃J�������I�[�v�����Ă݂�
	m_cap.open(0);
	if (!m_cap.isOpened()) {
		MessageBox(0,"�J�������I�[�v���ł��܂���ł���","�G���[",MB_SYSTEMMODAL);
		return false;
	}else {
		return true;
	}
}

/// <summary>-------------------------------------------///
///					�E�B���h�E����						///
/// ---------------------------------------------</summary>
void OpenCVBase::Createwindow() {
	cv::namedWindow("OpenCVTest", 1);
}

/// <summary>-------------------------------------------///
///					�J�X�P�[�h���͊�̓ǂݍ���			///
/// ---------------------------------------------</summary>
bool OpenCVBase::LoadCascade() {
	// ���ފ�̓ǂݍ���
	std::string cascadeName = "..\\casade\\cascade.xml";
	if (!m_cascade.load(cascadeName)) {
		MessageBox(0, "�J�X�P�[�h���ފ��ǂݍ��ނ��Ƃ��ł��܂���ł���", "�G���[", MB_SYSTEMMODAL);
		return false;
	}else{
		return true;
	}
}

/// <summary>-------------------------------------------///
///					�猟�o�J�n							///
/// ---------------------------------------------</summary>
void OpenCVBase::FaceDetectionStart() {
	for (;;)
	{
		//�t���[��
		cv::Mat frame;
		//���̓C���[�W
		cv::Mat input_image;
		//�o�̓C���[�W
		cv::Mat output_image;
		//�J��������V�����t���[�����擾
		m_cap >> frame;
		//�O���[�Ŏ擾
		cvtColor(frame, input_image, CV_BGR2GRAY);
		//���̓C���[�W�̃q�X�g�O�����ψꉻ
		cv::equalizeHist(input_image, input_image);
		//�J���[�ŏo��
		output_image = frame;

		//(�摜,�o�͒Z�`,�k���X�P�[��,�Œ�Z�`��,�t���O�H,�ŏ��Z�`)
		m_cascade.detectMultiScale(
			input_image,			//�摜
			m_faces,				//�Z�a
			1.3,					//�ŏ��X�P�[��
			2,						//�Œ�Z�aS
			CV_HAAR_SCALE_IMAGE,	//���ɈӖ��͂Ȃ�
			cv::Size(50, 50)		//�ŏ��T�C�Y,�ő�T�C�Y
		);

		// ���ʂ̕`����J�n
		std::vector<cv::Rect>::const_iterator r = m_faces.begin();
		for (; r != m_faces.end(); ++r) {
			cv::Point center;
			int radius;
			center.x = cv::saturate_cast<int>((r->x + r->width*0.5));
			center.y = cv::saturate_cast<int>((r->y + r->height*0.5));
			radius = cv::saturate_cast<int>((r->width + r->height)*0.25);
			cv::circle(output_image, center, radius, cv::Scalar(80, 80, 255), 3, 8, 0);

			printf("���o�I");

			//�����ɏ����Ɗ炪��������`����
			//LockWorkStation();//���b�N��ʂֈڍs
		}

		//���ɂ��邽�ߔ��]������
		flip(output_image, output_image, 1);
		imshow("OpenCVTest", output_image);

		if (cv::waitKey(30) >= 0) {
			break;
		}
	}
}
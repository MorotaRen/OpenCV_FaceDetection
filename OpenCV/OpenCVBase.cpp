#include "OpenCVBase.h"
#include "WindowsSystemControl.h"

/// <summary>-------------------------------------------///
///					コンストラクタ						///
/// ---------------------------------------------</summary>
OpenCVBase::OpenCVBase() {

}

/// <summary>-------------------------------------------///
///					デストラクタ						///
/// ---------------------------------------------</summary>
OpenCVBase::~OpenCVBase() {

}

/// <summary>-------------------------------------------///
///					カメラオープン関数					///
/// ---------------------------------------------</summary>
bool OpenCVBase::OpenCameta() {
	//デフォルトのカメラをオープンしてみる
	m_cap.open(0);
	if (!m_cap.isOpened()) {
		MessageBox(0,"カメラをオープンできませんでした","エラー",MB_SYSTEMMODAL);
		return false;
	}else {
		return true;
	}
}

/// <summary>-------------------------------------------///
///					ウィンドウ生成						///
/// ---------------------------------------------</summary>
void OpenCVBase::Createwindow() {
	cv::namedWindow("OpenCVTest", 1);
}

/// <summary>-------------------------------------------///
///					カスケード分析器の読み込み			///
/// ---------------------------------------------</summary>
bool OpenCVBase::LoadCascade() {
	// 分類器の読み込み
	std::string cascadeName = "..\\casade\\cascade.xml";
	if (!m_cascade.load(cascadeName)) {
		MessageBox(0, "カスケード分類器を読み込むことができませんでした", "エラー", MB_SYSTEMMODAL);
		return false;
	}else{
		return true;
	}
}

/// <summary>-------------------------------------------///
///					顔検出開始							///
/// ---------------------------------------------</summary>
void OpenCVBase::FaceDetectionStart() {
	for (;;)
	{
		//フレーム
		cv::Mat frame;
		//入力イメージ
		cv::Mat input_image;
		//出力イメージ
		cv::Mat output_image;
		//カメラから新しいフレームを取得
		m_cap >> frame;
		//グレーで取得
		cvtColor(frame, input_image, CV_BGR2GRAY);
		//入力イメージのヒストグラム均一化
		cv::equalizeHist(input_image, input_image);
		//カラーで出力
		output_image = frame;

		//(画像,出力短形,縮小スケール,最低短形数,フラグ？,最小短形)
		m_cascade.detectMultiScale(
			input_image,			//画像
			m_faces,				//短径
			1.3,					//最小スケール
			2,						//最低短径S
			CV_HAAR_SCALE_IMAGE,	//得に意味はなし
			cv::Size(50, 50)		//最小サイズ,最大サイズ
		);

		// 結果の描画を開始
		std::vector<cv::Rect>::const_iterator r = m_faces.begin();
		for (; r != m_faces.end(); ++r) {
			cv::Point center;
			int radius;
			center.x = cv::saturate_cast<int>((r->x + r->width*0.5));
			center.y = cv::saturate_cast<int>((r->y + r->height*0.5));
			radius = cv::saturate_cast<int>((r->width + r->height)*0.25);
			cv::circle(output_image, center, radius, cv::Scalar(80, 80, 255), 3, 8, 0);

			printf("検出！");

			//ここに書くと顔があったら～する
			//LockWorkStation();//ロック画面へ移行
		}

		//鏡にするため反転させる
		flip(output_image, output_image, 1);
		imshow("OpenCVTest", output_image);

		if (cv::waitKey(30) >= 0) {
			break;
		}
	}
}
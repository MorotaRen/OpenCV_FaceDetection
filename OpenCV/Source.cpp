#include "OpenCVBase.h"


/// <summary>--------------------------------------------///
///						Main�֐�						 ///
/// ----------------------------------------------</summary>
int main(int, char**)
{
	OpenCVBase openCV;
	if (openCV.OpenCameta()) {
		if (openCV.LoadCascade()) {
			openCV.FaceDetectionStart();
		}else{
			return 0;
		}

	}else{
		return 0;
	}
}


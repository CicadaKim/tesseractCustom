
#include "stdafx.h"

#include <baseapi.h>
#include <allheaders.h>

using namespace std;
using namespace tesseract;

#pragma comment(lib,"tesseract305")
#pragma comment(lib,"lept174")

int _tmain(int argc, _TCHAR* argv[])
{
	char *outText;

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init(NULL, "eng")) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}

	// Open input image with leptonica library
	Pix *image = pixRead("C:/testing/eurotext.tif");
	api->SetImage(image);
	// Get OCR result
	outText = api->GetUTF8Text();
	printf("OCR output:\n%s", outText);

	// Destroy used object and release memory
	api->End();
	delete[] outText;
	pixDestroy(&image);

	return 0;
}
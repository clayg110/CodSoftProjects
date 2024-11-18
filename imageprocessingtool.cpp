#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat loadImage(const string &path)
{
    Mat img = imread(path);
    if (img.empty())
    {
        cerr << "Error loading image!" << endl;
        exit(EXIT_FAILURE);
    }
    return img;
}

void displayImage(const string &windowName, Mat img)
{
    imshow(windowName, img);
    waitKey(0);
    destroyWindow(windowName);
}

Mat applyGrayscale(Mat img)
{
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    return gray;
}

Mat applyBlur(Mat img, int kernelSize)
{
    Mat blurred;
    blur(img, blurred, Size(kernelSize, kernelSize));
    return blurred;
}

Mat applySharpen(Mat img)
{
    Mat sharpened;
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0,
                  -1, 5, -1,
                  0, -1, 0);
    filter2D(img, sharpened, img.depth(), kernel);
    return sharpened;
}

Mat adjustBrightnessContrast(Mat img, double alpha, int beta)
{
    Mat adjusted;
    img.convertTo(adjusted, -1, alpha, beta);
    return adjusted;
}

Mat cropImage(Mat img, Rect roi)
{
    return img(roi);
}

Mat resizeImage(Mat img, Size size)
{
    Mat resized;
    resize(img, resized, size);
    return resized;
}

void saveImage(const string &path, Mat img)
{
    imwrite(path, img);
}

int main()
{
    string imagePath = "path_to_image.jpg";
    Mat img = loadImage(imagePath);

    displayImage("Original Image", img);

    Mat grayImage = applyGrayscale(img);
    displayImage("Grayscale Image", grayImage);

    Mat blurredImage = applyBlur(img, 5);
    displayImage("Blurred Image", blurredImage);

    Mat sharpenedImage = applySharpen(img);
    displayImage("Sharpened Image", sharpenedImage);

    Mat brightContrastImage = adjustBrightnessContrast(img, 1.2, 50);
    displayImage("Brightness/Contrast Adjusted Image", brightContrastImage);

    Rect roi(50, 50, 200, 200);
    Mat croppedImage = cropImage(img, roi);
    displayImage("Cropped Image", croppedImage);

    Mat resizedImage = resizeImage(img, Size(300, 300));
    displayImage("Resized Image", resizedImage);

    saveImage("processed_image.jpg", resizedImage);

    return 0;
}
rc
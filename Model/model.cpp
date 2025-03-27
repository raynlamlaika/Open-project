#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

//taking the img input and represent it as tensors or matrix


// apllay the zooming fucntion 

cv::Mat zoomImage(cv::Mat &image, double scale)
{
    int newWidth = static_cast<int>(image.cols / scale);
    int newHeight = static_cast<int>(image.rows / scale);

    int startX = (image.cols - newWidth) / 2;
    int startY = (image.rows - newHeight) / 2;

    // Crop the image
    cv::Mat cropped = image(cv::Rect(startX, startY, newWidth, newHeight));

    // Resize back to original size
    cv::Mat zoomed;
    cv::resize(cropped, zoomed, image.size(), 0, 0, cv::INTER_LINEAR);

    return zoomed;
}

int main()
{
    // the file name will be passed from the usr or will token form the img
    std::string input = "input.jpg"; //the input willbe passed right here
    cv::Mat imag = cv::imread(input);
    if (imag.empty())
    {
        std::cerr << "Error in oping the imag input" << std::endl;
        return -1;
    }

    double i  = 1;
    while (1)
{
    cv::Mat yy = zoomImage(imag, i);
    cv::imshow("alo allo",yy);
    char key = cv::waitKey(0);
    if (key == 'q')
        cv::destroyAllWindows();
    i++;
    //right now i need to work with my mtrx
    }
    
    return 0;
}



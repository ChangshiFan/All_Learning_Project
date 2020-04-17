#ifndef INCLUDE_VIDEO_PROCESS_H_
#define INCLUDE_VIDEO_PROCESS_H_ 
#include <iostream>
#include <opencv/cv.hpp>

class VideoProcess
{
 public:
    VideoProcess();
    explicit VideoProcess(const std::string &video_file_path);
    ~VideoProcess();
    void SetVideoPath(const std::string &video_file_path);
    bool Prapare();
    bool operator>>(cv::Mat &image);

private:
    cv::Mat Update();
    std::string video_file_path_;
    cv::VideoCapture video_cap_;
};
#endif

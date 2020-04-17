#include <iostream>
#include <opencv/cv.hpp>
#include "video_process.h"

int main(int argc, char *argv[])
{
  std::string video_path;
  if(argc >= 2){
    video_path = argv[1];
  }else{
    std::cout<<"input error !"<<std::endl;
    return -1;
  }
//  video_path = "/home/changshi/Videos/FCM/2019-07-16-13-12-12_fcm.mp4";

  VideoProcess video_proc(video_path);
  if(!video_proc.Prapare()){
    std::cout<<"video prapare failed !"<<std::endl;
    return -1;
  }

  cv::Mat image;
  int frame_id = 1;

  while(video_proc >> image){
    frame_id++;
    std::string text_str = "Frame ID : ";
    std::string text = text_str.append(std::move(std::to_string(frame_id)));
    cv::putText(image, text.data(), cv::Point(100, 50), CV_FONT_HERSHEY_SIMPLEX,
                1, cv::Scalar(0, 0, 255), 2);
    cv::imshow("show windows", image);
    if(cv::waitKey() == 113){
      return 0;
    }else{
      cv::waitKey();
    }
  }

  return 0;
}


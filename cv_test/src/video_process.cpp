#include "video_process.h"

VideoProcess::VideoProcess():video_file_path_(""){
}

VideoProcess::VideoProcess(const std::string &video_file_path)
{
  video_file_path_ = video_file_path;
}

VideoProcess::~VideoProcess()
{
  video_cap_.release();
  video_file_path_ = "";
}

void VideoProcess::SetVideoPath(const std::string &video_file_path){
  video_file_path_ = video_file_path;
}

bool VideoProcess::Prapare()
{
  if(!video_cap_.open(video_file_path_)){
    std::cout<<"video open faild !"<<std::endl;
    return false;
  }
  return true;
}

bool VideoProcess::operator>>(cv::Mat &image)
{
  if(!video_cap_.read(image)){
    return false;
  }
  return true;
}

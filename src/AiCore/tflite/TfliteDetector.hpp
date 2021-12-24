#ifndef TFLITERUNTIME_H
#define TFLITERUNTIME_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"

#include "tensorflow/lite/delegates/gpu/delegate.h"
// #include "tensorflow/lite/delegates/hexagon/hexagon_delegate.h"

#include "AiTypeData.hpp"


typedef struct tflite_interpreter
{
    std::unique_ptr<tflite::FlatBufferModel> model;
    std::unique_ptr<tflite::Interpreter> interpreter;
    tflite::ops::builtin::BuiltinOpResolver resolver;
    TfLiteDelegate *delegate;
}tflite_interpreter;

class TfliteDetector {
    private:
        tflite_interpreter *p;
    public:
        TfliteDetector();
        ~TfliteDetector();
        int initTfLiteNetwork(const char *model_path, std::string runtime);
        int excuteTfLiteDetector(const cv::Mat& img, std::vector<std::string>& labels, std::vector<ObjectTrace>& objects, float thres_detect);
        int executeTfLiteYolo(const cv::Mat& img, std::vector<std::string>& labels, std::vector<ObjectTrace>& objects, float thres_detect);
};

#endif
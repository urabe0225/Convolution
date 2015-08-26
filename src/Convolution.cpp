// -*- C++ -*-
/*!
 * @file  Convolution.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Convolution.h"
using namespace std;
using namespace cv;
// Module specification
// <rtc-template block="module_spec">
static const char* convolution_spec[] =
  {
    "implementation_id", "Convolution",
    "type_name",         "Convolution",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Kazuki Urabe",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Convolution::Convolution(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inputIn("input", m_input),
    m_outputOut("output", m_output)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Convolution::~Convolution()
{
}



RTC::ReturnCode_t Convolution::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("input", m_inputIn);
  
  // Set OutPort buffer
  addOutPort("output", m_outputOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
    inputFrame = cv::Mat::zeros(cv::Size(320,240),16);
  namedWindow( "Convolution", WINDOW_AUTOSIZE );
  cv::imshow( "Convolution", inputFrame);
  cv::waitKey(25);
  cout<<"Initialize OK"<<endl;
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Convolution::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Convolution::onActivated(RTC::UniqueId ec_id)
{
//  kernel = getGaborKernel(cv::Size(21,21), 5.0, 0, 5.0, 1.0, CV_PI*0.5, CV_64F );
//  kernel = getGaborKernel(cv::Size(10,10), 1.4, 0, 4, 1 );
//  kernel = cv::getGaborKernel(cv::Size(21,21), 5, 0, 19, 1, 0);
//  kernel = kernel/2.+0.5;
//    getDerivKernels(OutputArray kx, OutputArray ky, int dx, int dy, int ksize, bool normalize=false, int ktype=CV_32F )


  return RTC::RTC_OK;
}


RTC::ReturnCode_t Convolution::onDeactivated(RTC::UniqueId ec_id)
{
  inputFrame.release();
  outputFrame.release();
  kernel.release();
  while(m_inputIn.isNew()) m_inputIn.read();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Convolution::onExecute(RTC::UniqueId ec_id)
{
  if (!m_inputIn.isNew())
  { 
    return RTC::RTC_OK;
  }
  m_inputIn.read();
  m_input>>inputFrame;



  GaussianBlur( inputFrame, inputFrame, Size(3,3), 0, 0, BORDER_DEFAULT );
  cvtColor( inputFrame, inputFrame, CV_BGR2GRAY);
  Sobel( inputFrame, outputFrame, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT );
  convertScaleAbs( outputFrame, outputFrame );
//  inputFrame.convertTo(inputFrame,CV_32F);
//  cv::filter2D(inputFrame, outputFrame, CV_32F, kernel);
//  outputFrame.convertTo(outputFrame,CV_8U,1.0/255.0);
//  cv::normalize(outputFrame, outputFrame, 0, 255, NORM_MINMAX);


//  cv::resize(kernel,showk, cv::Size(320,240));
  cv::imshow("Convolution", outputFrame);
//  cv::imshow("kernel", showk);
  cv::waitKey(3);

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Convolution::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Convolution::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConvolutionInit(RTC::Manager* manager)
  {
    coil::Properties profile(convolution_spec);
    manager->registerFactory(profile,
                             RTC::Create<Convolution>,
                             RTC::Delete<Convolution>);
  }
  
};



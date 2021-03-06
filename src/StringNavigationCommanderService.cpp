﻿// -*- C++ -*-
/*!
 * @file  StringNavigationCommanderService.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "StringNavigationCommanderService.h"

using namespace ogata_lab;

// Module specification
// <rtc-template block="module_spec">
static const char* stringnavigationcommanderservice_spec[] =
  {
    "implementation_id", "StringNavigationCommanderService",
    "type_name",         "StringNavigationCommanderService",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "maruryota",
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
StringNavigationCommanderService::StringNavigationCommanderService(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_currentPoseIn("currentPose", m_currentPose),
    m_StringNavigationManagerServicePort("StringNavigationManagerService"),
    m_mapServerPort("mapServer"),
    m_pathPlannerPort("pathPlanner"),
    m_pathFollowerPort("pathFollower")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
StringNavigationCommanderService::~StringNavigationCommanderService()
{
}



RTC::ReturnCode_t StringNavigationCommanderService::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("currentPose", m_currentPoseIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_StringNavigationManagerServicePort.registerProvider("StringNavigationManagerService", "ogata::StringNavigationCommanderService", m_StringNavigationManagerService);
  
  // Set service consumers to Ports
  m_mapServerPort.registerConsumer("mapServer", "RTC::OGMapServer", m_mapServer);
  m_pathPlannerPort.registerConsumer("pathPlanner", "RTC::PathPlanner", m_pathPlanner);
  m_pathFollowerPort.registerConsumer("pathFollower", "RTC::PathFollower", m_pathFollower);
  
  // Set CORBA Service Ports
  addPort(m_StringNavigationManagerServicePort);
  addPort(m_mapServerPort);
  addPort(m_pathPlannerPort);
  addPort(m_pathFollowerPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t StringNavigationCommanderService::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StringNavigationCommanderService::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void StringNavigationCommanderServiceInit(RTC::Manager* manager)
  {
    coil::Properties profile(stringnavigationcommanderservice_spec);
    manager->registerFactory(profile,
                             RTC::Create<StringNavigationCommanderService>,
                             RTC::Delete<StringNavigationCommanderService>);
  }
  
};



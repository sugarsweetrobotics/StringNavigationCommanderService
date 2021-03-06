﻿// -*-C++-*-
/*!
 * @file  TidyUpManagerSVC_impl.h
 * @brief Service implementation header of TidyUpManager.idl
 *
 */

#include "BasicDataTypeSkel.h"
#include "ExtendedDataTypesSkel.h"

#include "TidyUpManagerSkel.h"
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include "MobileRobot.hh"

namespace ogata_lab {
	class StringNavigationCommanderService;
}


#ifndef TIDYUPMANAGERSVC_IMPL_H
#define TIDYUPMANAGERSVC_IMPL_H
 
/*!
 * @class ogata_TidyUpManagerSVC_impl
 * Example class implementing IDL interface ogata::TidyUpManager
 */
class ogata_TidyUpManagerSVC_impl
 : public virtual POA_ogata::TidyUpManager,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ogata_TidyUpManagerSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ogata_TidyUpManagerSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ogata_TidyUpManagerSVC_impl();

   // attributes and operations
   ogata::RETURN_VALUE tidyup(const RTC::TimedPose2D& path, const RTC::TimedString& kind);

};

/*!
 * @class ogata_StringNavigationCommanderServiceSVC_impl
 * Example class implementing IDL interface ogata::StringNavigationCommanderService
 */
class ogata_StringNavigationCommanderServiceSVC_impl
 : public virtual POA_ogata::StringNavigationCommanderService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ogata_StringNavigationCommanderServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ogata_StringNavigationCommanderServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ogata_StringNavigationCommanderServiceSVC_impl();

   // attributes and operations
   ogata::RETURN_VALUE move(const RTC::TimedPose2D& path);

   ogata_lab::StringNavigationCommanderService* m_pRTC;
   void setRTC(ogata_lab::StringNavigationCommanderService* pRTC) { m_pRTC = pRTC; }

   RTC::TimedPose2D m_currentPose;
   /*!
	*/
   RTC::InPort<RTC::TimedPose2D> m_currentPoseIn;

   /*!
	*/
   RTC::CorbaPort m_mapServerPort;
   /*!
	*/
   RTC::CorbaPort m_pathPlannerPort;
   /*!
	*/
   RTC::CorbaPort m_pathFollowerPort;


   // </rtc-template>

   // Consumer declaration
   // <rtc-template block="consumer_declare">
   /*!
	*/
   RTC::CorbaConsumer<RTC::OGMapServer> m_mapServer;
   /*!
	*/
   RTC::CorbaConsumer<RTC::PathPlanner> m_pathPlanner;
   /*!
	*/
   RTC::CorbaConsumer<RTC::PathFollower> m_pathFollower;

};

/*!
 * @class ogata_PickerSVC_impl
 * Example class implementing IDL interface ogata::Picker
 */
class ogata_PickerSVC_impl
 : public virtual POA_ogata::Picker,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ogata_PickerSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ogata_PickerSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ogata_PickerSVC_impl();

   // attributes and operations
   ogata::RETURN_VALUE pick(const RTC::TimedString& kind);

};

/*!
 * @class ogata_DroperSVC_impl
 * Example class implementing IDL interface ogata::Droper
 */
class ogata_DroperSVC_impl
 : public virtual POA_ogata::Droper,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ogata_DroperSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ogata_DroperSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ogata_DroperSVC_impl();

   // attributes and operations
   ogata::RETURN_VALUE drop(const RTC::TimedString& kind);

};



#endif // TIDYUPMANAGERSVC_IMPL_H



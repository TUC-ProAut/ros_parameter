/******************************************************************************
*                                                                             *
* parameter_pa_node.cpp                                                       *
* =====================                                                       *
*                                                                             *
*******************************************************************************
*                                                                             *
* github repository                                                           *
*   https://github.com/peterweissig/ros_pcdfilter                             *
*                                                                             *
* Chair of Automation Technology, Technische Universität Chemnitz             *
*   https://www.tu-chemnitz.de/etit/proaut                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
* New BSD License                                                             *
*                                                                             *
* Copyright (c) 2015-2017, Peter Weissig, Technische Universität Chemnitz     *
* All rights reserved.                                                        *
*                                                                             *
* Redistribution and use in source and binary forms, with or without          *
* modification, are permitted provided that the following conditions are met: *
*     * Redistributions of source code must retain the above copyright        *
*       notice, this list of conditions and the following disclaimer.         *
*     * Redistributions in binary form must reproduce the above copyright     *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*     * Neither the name of the Technische Universität Chemnitz nor the       *
*       names of its contributors may be used to endorse or promote products  *
*       derived from this software without specific prior written permission. *
*                                                                             *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
* ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY      *
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR          *
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT          *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   *
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH *
* DAMAGE.                                                                     *
*                                                                             *
******************************************************************************/

// local headers
#include "parameter_pa/parameter_pa_node.h"
#include "parameter_pa/parameter_pa_ros.h"

// standard headers
#include <string>
#include <math.h>

//**************************[main]*********************************************
int main(int argc, char **argv) {

    ros::init(argc, argv, "pcd_filter_pa_node");
    cParameterPaNode pcd_filter;

    ros::spin();

    return 0;
}

//**************************[cParameterPaNode]*********************************
cParameterPaNode::cParameterPaNode() {

    cParameterPaRos paramloader;
    std::string str_service = paramloader.resolveRessourcename("~/");

    // service for path substitution
    ser_path_ = nh_.advertiseService( str_service + "substitutePath",
      &cParameterPaNode::substitutePathCallbackSrv, this);
    // service for ressource name substitution
    ser_ressource_ = nh_.advertiseService(
      str_service + "substituteRessource",
      &cParameterPaNode::substituteNameCallbackSrv, this);
}

//**************************[~cParameterPaNode]********************************
cParameterPaNode::~cParameterPaNode() {

}

//**************************[substitutePathCallbackSrv]*************************
bool cParameterPaNode::substitutePathCallbackSrv(
  parameter_pa::ParameterPaString::Request  &req,
  parameter_pa::ParameterPaString::Response &res) {

    std::string str = req.in_string;
    res.ok = cParameterPaRos::replaceFindpack(str);
    res.out_string = str;

    return true;
}

//**************************[substituteNameCallbackSrv]*************************
bool cParameterPaNode::substituteNameCallbackSrv(
  parameter_pa::ParameterPaString::Request  &req,
  parameter_pa::ParameterPaString::Response &res) {

    res.out_string = cParameterPaRos::resolveRessourcename(req.in_string);
    res.ok = true;
    
    return true;
}

/******************************************************************************
*                                                                             *
* parameter_pa_node.h                                                         *
* ===================                                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
* github repository                                                           *
*   https://github.com/peterweissig/ros_parameter                             *
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

#ifndef __PARAMETER_PA_NODE_H
#define __PARAMETER_PA_NODE_H

// local headers
#include "parameter_pa/parameter_pa_ros.h"
#include "parameter_pa/ParameterPaString.h"

// ros headers
#include <ros/ros.h>

//**************************[main]*********************************************
int main(int argc, char **argv);

//**************************[cParameterPaNode]*********************************
class cParameterPaNode : public cParameterPaRos {
  public:
    //! default constructor
    cParameterPaNode();

    //! default destructor
    ~cParameterPaNode();

  protected:
    //! node handler for topic subscription and advertising
    ros::NodeHandle nh_;

    //! service for path substitution
    ros::ServiceServer ser_path_;
    //! service for ressource name substitution
    ros::ServiceServer ser_ressource_;

    //! callback function for path substitution
    bool substitutePathCallbackSrv(
        parameter_pa::ParameterPaString::Request  &req,
        parameter_pa::ParameterPaString::Response &res);
    //! callback function for ressource name substitution
    bool substituteNameCallbackSrv(
        parameter_pa::ParameterPaString::Request  &req,
        parameter_pa::ParameterPaString::Response &res);
};

#endif // __PARAMETER_PA_NODE_H

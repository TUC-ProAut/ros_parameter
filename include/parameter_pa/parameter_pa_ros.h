/******************************************************************************
*                                                                             *
* parameter_pa_ros.h                                                          *
* ==================                                                          *
*                                                                             *
*******************************************************************************
*                                                                             *
* github repository                                                           *
*   https://github.com/TUC-ProAut/ros_parameter                               *
*                                                                             *
* Chair of Automation Technology, Technische Universität Chemnitz             *
*   https://www.tu-chemnitz.de/etit/proaut                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
* New BSD License                                                             *
*                                                                             *
* Copyright (c) 2015-2021, Peter Weissig, Technische Universität Chemnitz     *
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

#ifndef __PARAMETER_PA_ROS_H
#define __PARAMETER_PA_ROS_H

// ros headers
#include <ros/ros.h>

// standard headers
#include <string>
#include <vector>

#include <eigen3/Eigen/Core>

//**************************[cParameterPaRos]**********************************
class cParameterPaRos {
  public:
    bool load(const std::string name, bool        &value,
              const bool print_default = true) const;

    bool load(const std::string name, std::string &value,
              const bool print_default = true) const;
    bool loadTopic(const std::string name, std::string &value,
                   const bool print_default = true) const;
    bool loadPath(const std::string name, std::string &value,
                  const bool print_default = true) const;

    bool load(const std::string name, int         &value,
              const bool print_default = true) const;

    bool load(const std::string name, double      &value,
              const bool print_default = true) const;


    bool load(const std::string name, std::vector<bool       > &value,
              const bool print_default = true) const;

    bool load(const std::string name, std::vector<std::string> &value,
              const bool print_default = true) const;

    bool load(const std::string name, std::vector<int        > &value,
              const bool print_default = true) const;

    bool load(const std::string name, std::vector<double     > &value,
              const bool print_default = true) const;

    bool load(const std::string name, Eigen::MatrixXf &value,
              const bool print_default = true) const;

    static bool replaceFindpack(std::string &path);
    static std::string resolveRessourcename(const std::string name);
    static std::string boolToStr(const bool value);

    // deprecated function names, just for compatibility
    // (starting after next ros-release, those names will
    //  marked as deprecated)
    // __attribute__ ((deprecated))
    bool load_topic(const std::string name, std::string &value,
                    const bool print_default = true) const;
    // __attribute__ ((deprecated))
    bool load_path(const std::string name, std::string &value,
                   const bool print_default = true) const;

    //__attribute__ ((deprecated))
    static bool replace_findpack(std::string &path);
    //__attribute__ ((deprecated))
    static void resolve_ressourcename(std::string &name);
    //__attribute__ ((deprecated))
    static std::string bool_to_str(const bool value);

  private:
    void loadSub(const std::string &n, const std::string &v,
                 const bool p, const bool r) const;
    static std::list<std::string> splitRessourcename(
      const std::string name);

    ros::NodeHandle nh_;
};

#endif // __PARAMETER_PA_ROS_H

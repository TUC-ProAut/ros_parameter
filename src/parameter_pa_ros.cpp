/******************************************************************************
*                                                                             *
* parameter_pa_ros.c                                                          *
* ==================                                                          *
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

// local headers
#include "parameter_pa/parameter_pa_ros.h"

// ros headers
#include <ros/package.h>
#if ROS_VERSION_MINIMUM(1, 12, 0)
    // everything after ros indigo
    #include <xmlrpcpp/XmlRpcValue.h>
#else //#if ROS_VERSION_MINIMUM(1, 12, 0)
    // only for ros indigo
    #include <XmlRpcValue.h>
#endif //#if ROS_VERSION_MINIMUM(1, 12, 0)

// standard headers
#include <sstream>

//**************************[load - bool]**************************************
bool cParameterPaRos::load (const std::string name,
  bool &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);

    loadSub(name, boolToStr(value), print_default, result);

    return result;
}

//**************************[load - string]************************************
bool cParameterPaRos::load (const std::string name,
  std::string &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);

    loadSub(name, value, print_default, result);

    return result;
}

//**************************[loadTopic]****************************************
bool cParameterPaRos::loadTopic (const std::string name,
  std::string &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);
    if (value != "") {
        resolveRessourcename(value);
    }

    loadSub(name, value, print_default, result);

    return result;
}

//**************************[loadPath]*****************************************
bool cParameterPaRos::loadPath (const std::string name,
  std::string &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);
    replaceFindpack(value);

    loadSub(name, value, print_default, result);

    return result;
}

//**************************[load - int]***************************************
bool cParameterPaRos::load (const std::string name,
  int &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);

    std::stringstream value_s;
    value_s << value;
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - double]************************************
bool cParameterPaRos::load (const std::string name,
  double &value, const bool print_default) const {

    bool result;

    result = nh_.getParam(resolveRessourcename(name), value);

    std::stringstream value_s;
    value_s << value;
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - vector<bool>]******************************
bool cParameterPaRos::load (const std::string name,
  std::vector<bool> &value, const bool print_default) const {

    bool result;

    std::vector<bool> value_temp;
    result = nh_.getParam(resolveRessourcename(name), value_temp);
    if (result) {value = value_temp;}

    std::stringstream value_s;
    value_s << "[";
    if (value.size() > 0) {
        value_s << boolToStr(value[0]);
        for (int i = 1; i < value.size(); i++) {
            value_s << ", " << boolToStr(value[i]);
        }
    }
    value_s << "]";
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - vector<string>]****************************
bool cParameterPaRos::load (const std::string name,
  std::vector<std::string> &value, const bool print_default) const {

    bool result;

    std::vector<std::string> value_temp;
    result = nh_.getParam(resolveRessourcename(name), value_temp);
    if (result) {value = value_temp;}

    std::stringstream value_s;
    value_s << "[";
    if (value.size() > 0) {
        value_s << value[0];
        for (int i = 1; i < value.size(); i++) {
            value_s << ", " << value[i];
        }
    }
    value_s << "]";
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - vector<int>]*******************************
bool cParameterPaRos::load (const std::string name,
  std::vector<int> &value, const bool print_default) const {

    bool result;

    std::vector<int> value_temp;
    result = nh_.getParam(resolveRessourcename(name), value_temp);
    if (result) {value = value_temp;}

    std::stringstream value_s;
    value_s << "[";
    if (value.size() > 0) {
        value_s << value[0];
        for (int i = 1; i < value.size(); i++) {
            value_s << ", " << value[i];
        }
    }
    value_s << "]";
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - vector<double>]****************************
bool cParameterPaRos::load (const std::string name,
  std::vector<double> &value, const bool print_default) const {

    bool result;

    std::vector<double> value_temp;
    result = nh_.getParam(resolveRessourcename(name), value_temp);
    if (result) {value = value_temp;}

    std::stringstream value_s;
    value_s << "[";
    if (value.size() > 0) {
        value_s << value[0];
        for (int i = 1; i < value.size(); i++) {
            value_s << ", " << value[i];
        }
    }
    value_s << "]";
    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[load - matrix]************************************
bool cParameterPaRos::load (const std::string name,
  Eigen::MatrixXf &value, const bool print_default) const {

    bool result = true;

    Eigen::MatrixXf mat;

    XmlRpc::XmlRpcValue xml;
    nh_.getParam(resolveRessourcename(name), xml);

    // check type and minimum size
    if((xml.getType() != XmlRpc::XmlRpcValue::TypeArray) ||
      (xml.size() < 1)) {
        result = false;
    } else {
        for (int y = 0; y < xml.size(); y++) {
            // check type and minimum size
            if ((xml[y].getType() != XmlRpc::XmlRpcValue::TypeArray) ||
                (xml[y].size() < 1)) {
                result = false;
                break;
            }

            // set and check size
            if (y == 0) {
                mat.resize((int) xml.size(),(int) xml[y].size());
            } else if (xml[y].size() != mat.cols()){
                result = false;
                break;
            }

            for (int x = 0; x < xml[y].size(); x++) {
                if (result == false) {break;}

                switch (xml[y][x].getType()) {
                    case XmlRpc::XmlRpcValue::TypeDouble:
                        mat(y,x) = (double) xml[y][x];
                        break;
                    case XmlRpc::XmlRpcValue::TypeInt:
                        mat(y,x) = (int) xml[y][x];
                        break;

                    default:
                        result = false;
                        break;
                }
            }
            if (result == false) {
                break;
            }
        }
    }

    if (result) {value = mat;}

    std::stringstream value_s;
    value_s << '[';
    for (int y = 0; y < value.rows(); y++) {
        if (y > 0) { value_s << ", ";}
        value_s << '[';
        for (int x = 0; x < value.cols(); x++) {
            if (x > 0) { value_s << ", ";}
            value_s  << value(y,x);
        }
        value_s << ']';
    }
    value_s << ']';

    // Vergleich
    value_s << std::endl << "Vergleich:" << std::endl << value;

    loadSub(name, value_s.str(), print_default, result);

    return result;
}

//**************************[replaceFindpack]**********************************
bool cParameterPaRos::replaceFindpack(std::string &path) {

    while(1) {
        // check for string "$(find ...)"
        std::string::size_type start;
        start = (int) path.find("$(find ");
        if ((start < 0) || (start >= path.length())) {return true;}

        std::string::size_type end;
        end = path.find(")", (std::string::size_type) start);
        if ((end  < 0) || (end  >= path.length())) {return false;}

        // get replacement
        std::string replace;
        try {
            replace = ros::package::command(
              path.substr(start + 2, end - start - 2));
        } catch (std::runtime_error &e) {
            return false;
        }
        if (replace == "") { return false;}

        // extract white spaces from replacement
        std::string::size_type pos_save = 0;
        std::string::size_type pos_current;
        for (pos_current = 0; pos_current < replace.length(); pos_current++) {
            char c;
            c = replace[pos_current];

            if ((c == '\r') || (c == '\n') || (c == ' ') || (c == '\t')) {
                continue;
            }

            if (pos_save != pos_current) {
                replace[pos_save] = c;
            }
            pos_save++;
        }
        if (pos_save != replace.length()) {
            replace.resize(pos_save);
        }

        // replace
        path = path.substr(0,start) + replace + path.substr(end + 1);
    }
}

//**************************[resolveRessourcename]*****************************
std::string cParameterPaRos::resolveRessourcename(const std::string name) {

    if (name ==  "") {return "";}

    bool full_path = false;
    bool end_with_slash = name[name.length()-1] == '/';
    std::list<std::string> parts = splitRessourcename(name);

    if (parts.empty()) {
        return "";
    }

    if (parts.front() == "" ) { 
        full_path = true;
        parts.pop_front();
    } else if (parts.front() == "." ) { 
        parts.front() = "..";
        parts.push_front("~");
    }

    std::list<std::string>::iterator iter = parts.begin();
    while (iter != parts.end()) {

        // check for expansion to full ressource name
        if (((parts.front() == "~") || (parts.front() == "")) &&
          (full_path == false)) {
            
            // get full ressource name (including node name)
            std::list<std::string> temp = splitRessourcename(
              ros::names::resolve("~"));
            std::list<std::string>::iterator iter_temp = temp.end();
            iter_temp--; // to point to last element (not beyond)

            // remove current node name (if not wanted)
            // This happens only if absolute ressource name is implicitly
            // needed - e.g. by calling with "../xyz".
            if (parts.front() != "~") { 
                iter_temp--;  
            }

            // removing part, which was expanded
            parts.pop_front();

            for ( ; iter_temp != temp.end(); iter_temp--) {
                parts.push_front(*iter_temp);
            }

            // updated variables
            full_path = true;
            iter = parts.begin();
            continue;
        }

        // check for "" or "."
        if ((*iter == "") or (*iter == ".")) {
            iter = parts.erase(iter);
            continue;
        }

        // check for "../"
        if (*iter == "..") {
            if (iter == parts.begin()) {
                if (full_path) {
                    // there is no higher ressource name then "/"
                    // so a "/../xyz" will result in "/xyz"
                    iter = parts.erase(iter);
                    continue;
                } else {
                    // force full ressource name before continueing
                    parts.push_front("");
                    continue;
                }
            }
            // remove last ressource name
            iter--;
            iter = parts.erase(iter);
            iter = parts.erase(iter);
            continue;
        }

        iter++;
    }

    // concate resulting string
    std::string result;
    if (full_path) { result = "/";}

    if (parts.size() > 0) {
        result+= parts.front();
    }
    for (iter = ++parts.begin() ; iter != parts.end(); iter++) {
        result+= '/';
        result+= *iter;
    }

    if (end_with_slash && (parts.size() > 0)) {
        result+= '/';
    }

    return result;
}

//**************************[boolToStr]****************************************
std::string cParameterPaRos::boolToStr(const bool value) {

    if (value) {
        return "true";
    } else {
        return "false";
    }
}

//! ##### deprecated function names, just for compatibility #####

//**************************[load_topic]***************************************
bool cParameterPaRos::load_topic (const std::string name,
  std::string &value, const bool print_default) const {

    return loadTopic(name, value, print_default);
}

//**************************[load_path]****************************************
bool cParameterPaRos::load_path (const std::string name,
  std::string &value, const bool print_default) const {

    return loadPath(name, value, print_default);
}

//**************************[replace_findpack]*********************************
bool cParameterPaRos::replace_findpack(std::string &path) {

     return replaceFindpack(path);
}

//**************************[resolve_ressourcename]****************************
void cParameterPaRos::resolve_ressourcename(std::string &name) {

    name = resolveRessourcename(name);
}

//**************************[bool_to_str]**************************************
std::string cParameterPaRos::bool_to_str(const bool value) {

    return boolToStr(value);
}

//! ##### private functions #####
//**************************[loadSub]******************************************
void cParameterPaRos::loadSub(const std::string &n, const std::string &v,
  const bool p, const bool r) const {

    std::string result;

    if (r) {
        result = "load parameter " + n + " (" + v + ")";
    } else {
        result = "parameter " + n + " not set";

        if (p) {
            result+= " (defaults to " + v + ")";
        }
    }

    ROS_INFO_STREAM(result);
}

//**************************[splitRessourcename]*******************************
std::list<std::string> cParameterPaRos::splitRessourcename(
  const std::string name) {

    std::list<std::string> result;
    int count                  = 0; // number of parts (seperated by slashes)
    std::string::size_type pos = 0; // current position within string

    while(pos < name.length()) {
        // check for string "/"
        std::string::size_type end;
        end = (int) name.find("/", pos);

        if ((end < 0) || (end > name.length())) {
            end = name.length();
        }

        if (pos < end) {
            result.push_back(name.substr(pos, end - pos));
        } else {
            result.push_back("");
        }
            
        pos = end + 1;
    }

    return result;
}

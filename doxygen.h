/** \mainpage ProAut Parameter
 *
 * \section intro_sec Introduction
 *
 * This is a simple helper-package for loading variables from the parameter
 * server.
 *
 * The main idea is to simplify the handling of parameters, which can be set to
 * default values. The <em>load()</em> function will print if a parameter is loaded from
 * the server or if its default value is used. In each case, the final value
 * is printed, too.
 *
 * The main <em>load()</em> function can handle bool, int, double and string - all as
 * single values and as vectors. Also matrices of double (float) can be loaded.
 *
 * Additionaly, there are two more dedicated load functions: <em>load_path()</em> and
 * <em>load_topic()</em>. Both are basically loading a simple string from the parameter
 * server as descript above. Furthermore the strings are specificly manipulated:
 *  + <em>load_path()</em>: Every "$(find xyz)" will be replaced with the path of
 *    package xyz.
 *  + <em>load_topic()</em>: Names are resolved relativ to current namespace or node.
 *    "~xyz" will resolve to "/ns/current_node/xyz" and "/xyz" will resolve to
 *    "/ns/xyz" (not in namespace of current node).
 *
 * \section example_sec Example
 *
 * A typical output looks like this:
 * \verbatim
[ INFO] [1499357951.543886548]: load parameter ~tf_lookup_time (0.1)
[ INFO] [1499357951.544331412]: parameter ~buffer_pointcloud not set (defaults to false)
[ INFO] [1499357951.544867951]: load parameter ~debugging (true)\endverbatim
 *
 * Here is the related source code, which is taken from
 * <a href="https://github.com/peterweissig/ros_pcdfilter/blob/master/src/pcdfilter_pa_node.cpp">pcdfilter_pa</a>:
 * \verbatim
cParameterPaRos paramloader;

// ...
paramloader.load("~tf_lookup_time"   , filters_.tf_lookup_time_     );
paramloader.load("~buffer_pointcloud", rosparams_.buffer_pointcloud_);
paramloader.load("~debugging"        , rosparams_.debugging_        );\endverbatim
 *
 * \section links_sec Links
 *
 * Source code at github:
 *  + https://github.com/peterweissig/ros_parameter
 *
 * \section doc_sec ROS Documentation
 *
 * ROS-Distribution | Documentation
 * -----------------|---------------
 * Indigo  | <a href="http://docs.ros.org/indigo/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Jade    | <a href="http://docs.ros.org/jade/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Kinetic | <a href="http://docs.ros.org/kinetic/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Lunar   | <a href="http://docs.ros.org/lunar/api/parameter_pa/html/index.html">docs.ros.org</a>
 **/

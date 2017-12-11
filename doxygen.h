/** @mainpage ProAut Parameter
 *
 * @section intro_sec Introduction
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
 * 
 * @b load_path() \n
 * Every "$(find xyz)" will be replaced with the path of package xyz.
 * 
 * @b load_topic() \n
 * Names are resolved with additional operators.
 * 
 * For these examples assume that ROS\_NAMESPACE is set to "/name/space" and that the nodes' name is "parameter\_pa\_node"
 * 
 * Regular ressource names (<em>no change</em>):
 * in_string      | out_string     | comment
 * ---------------|----------------|--------
 * ressource      | ressource      | relative name
 * ressource/     | ressource/     | relative name ending with slash
 * ns/ressource   | ns/ressource   | relative name with namespace
 * ns/ressource/  | ns/ressource/  | relative name with namespace ending with slash
 * /ressource     | /ressource     | absolute name
 * /ressource/    | /ressource/    | absolute name ending with slash
 * /ns/ressource  | /ns/ressource  | absolute name with namespace
 * /ns/ressource/ | /ns/ressource/ | absolute name with namespace ending with slash
 * 
 * Private ressource names (<em>~/</em>):
 * in_string       | out_string                                    | comment
 * ----------------|-----------------------------------------------|--------
 * ~               | /name/space/parameter\_pa\_node               | private namespace
 * ~/              | /name/space/parameter\_pa\_node/              | private namespace ending with slash
 * ~/ressource     | /name/space/parameter\_pa\_node/ressource     | private namespace with relative name
 * ~/ns/ressource/ | /name/space/parameter\_pa\_node/ns/ressource/ | private namespace with relative name and relative namespace ending in slash
 * /abc/~/xyz      | Error                                         | no private namespace within absolute name allowed
 * 
 * Locale ressource names (<em>./</em>):
 * in_string       | out_string                | comment
 * ----------------|---------------------------|--------
 * .               | /name/space               | local namespace
 * ./              | /name/space/              | local namespace ending with slash
 * ./ressource/    | /name/space/ressource/    | local namespace with relative name ending in slash
 * ./ns/ressource  | /name/space/ns/ressource  | local namespace with relative name and relative namespace 
 * /abc/./xyz      | /abc/xyz                  | local namespace within absolute name
 * 
 * Previous ressource names (<em>../</em>):
 * in_string       | out_string                | comment
 * ----------------|---------------------------|--------
 * ..              | /name                     | previous namespace
 * ../             | /name/                    | previous namespace ending with slash
 * ../ressource/   | /name/ressource/          | previous namespace with relative name ending in slash
 * ../ns/ressource | /name/ns/ressource        | previous namespace with relative name and relative namespace 
 * /abc/def/../xyz | /abc/xyz                  | previous namespace within absolute name
 * 
 * Removal of double slashes:
 * in_string      | out_string     | comment
 * ---------------|----------------|--------
 * ressource//    | ressource/     | relative name ending with slash
 * //ns/ressource | /ns/ressource  | absolute name with namespace
 * 
 * More examples:
 * in_string                         | out_string
 * ----------------------------------|-----------
 * ~/abc/.//def/../ns//ressource/    | /name/space/parameter\_pa\_node/abc/ns/ressource
 * ns//.././..//ressource            | /name/space/ressource
 * ../../../../../../ressource/      | /ressource/
 * 
 *
 * @section example_sec Example
 *
 * A typical output looks like this:
 * @verbatim
[ INFO] [1499357951.543886548]: load parameter ~/tf_lookup_time (0.1)
[ INFO] [1499357951.544331412]: parameter ~/buffer_pointcloud not set (defaults to false)
[ INFO] [1499357951.544867951]: load parameter ~/debugging (true)@endverbatim
 *
 * Here is the related source code, which is taken from
 * <a href="https://github.com/peterweissig/ros_pcdfilter/blob/master/src/pcdfilter_pa_node.cpp">pcdfilter_pa</a>:
 * @verbatim
cParameterPaRos paramloader;

// ...
paramloader.load("~/tf_lookup_time"   , filters_.tf_lookup_time_     );
paramloader.load("~/buffer_pointcloud", rosparams_.buffer_pointcloud_);
paramloader.load("~/debugging"        , rosparams_.debugging_        );@endverbatim
 *
 * @section links_sec Links
 *
 * Source code at github:
 *  + https://github.com/peterweissig/ros_parameter
 *
 * @section doc_sec ROS Documentation
 *
 * ROS-Distribution    | Documentation
 * --------------------|---------------
 * Indigo              | <a href="http://docs.ros.org/indigo/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Jade (EOL May 2017) | <a href="http://docs.ros.org/jade/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Kinetic             | <a href="http://docs.ros.org/kinetic/api/parameter_pa/html/index.html">docs.ros.org</a>
 * Lunar               | <a href="http://docs.ros.org/lunar/api/parameter_pa/html/index.html">docs.ros.org</a>
 **/

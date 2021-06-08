# ProAut Parameter

## Introduction

This is a simple helper-package for loading variables from the parameter
server.

The main idea is to simplify the handling of parameters, which can be set
to default values. The _load()_ function will print if a parameter is
loaded from the server or if its default value is used. In each case, the
final value is printed, too.


## Node

```
rosrun parameter_pa parameter_pa_node
roslaunch parameter_pa parameter_pa.launch
```


### Services:

Service Name            | Type                                                                                                                | Description
------------------------|---------------------------------------------------------------------------------------------------------------------|---------------------------------
"~/substitutePath"      | [parameter_pa/ParameterPaString](https://github.com/TUC-ProAut/ros_parameter/blob/master/srv/ParameterPaString.srv) | Replaces each "$(find xyz)" with the corresponding path - this is similar to calling _loadPath_().
"~/substituteRessource" | [parameter_pa/ParameterPaString](https://github.com/TUC-ProAut/ros_parameter/blob/master/srv/ParameterPaString.srv) | Resolves ressource name - this is similar to calling _loadTopic_().


## Functions

The main _load()_ function can handle bool, int, double and string - all as
single values and as vectors. Also matrices of double (float) can be loaded.

Additionaly, there are two more dedicated load functions: _loadPath()_
and _loadTopic()_. Both are basically loading a simple string from the
parameter server as descript above. Furthermore the strings are specificly
manipulated:

### loadPath()
Every "$(find xyz)" will be replaced with the path of package xyz.

### loadTopic()
Names are resolved with additional operators.

For these examples assume that ROS\_NAMESPACE is set to "/name/space" and
that the nodes' name is "parameter_pa_node"

#### Regular ressource names

in_string      | out_string     | comment
---------------|----------------|---------
ressource      | ressource      | relative name
ressource/     | ressource/     | relative name ending with slash
ns/ressource   | ns/ressource   | relative name with namespace
ns/ressource/  | ns/ressource/  | relative name with namespace ending with slash
/ressource     | /ressource     | absolute name
/ressource/    | /ressource/    | absolute name ending with slash
/ns/ressource  | /ns/ressource  | absolute name with namespace
/ns/ressource/ | /ns/ressource/ | absolute name with namespace ending with slash

#### Private ressource names

in_string       | out_string                                    | comment
----------------|-----------------------------------------------|---------
~               | /name/space/parameter\_pa\_node               | private namespace
~/              | /name/space/parameter\_pa\_node/              | private namespace ending with slash
~/ressource     | /name/space/parameter\_pa\_node/ressource     | private namespace with relative name
~/ns/ressource/ | /name/space/parameter\_pa\_node/ns/ressource/ | private namespace with relative name and relative namespace ending in slash
/abc/~/xyz      | Error                                         | no private namespace within absolute name allowed

#### Locale ressource names

in_string       | out_string                | comment
----------------|---------------------------|---------
.               | /name/space               | local namespace
./              | /name/space/              | local namespace ending with slash
./ressource/    | /name/space/ressource/    | local namespace with relative name ending in slash
./ns/ressource  | /name/space/ns/ressource  | local namespace with relative name and relative namespace
/abc/./xyz      | /abc/xyz                  | local namespace within absolute name

#### Previous ressource names

in_string       | out_string                | comment
----------------|---------------------------|---------
..              | /name                     | previous namespace
../             | /name/                    | previous namespace ending with slash
../ressource/   | /name/ressource/          | previous namespace with relative name ending in slash
../ns/ressource | /name/ns/ressource        | previous namespace with relative name and relative namespace
/abc/def/../xyz | /abc/xyz                  | previous namespace within absolute name

#### Removal of double slashes

in_string      | out_string     | comment
---------------|----------------|---------
ressource//    | ressource/     | relative name ending with slash
//ns/ressource | /ns/ressource  | absolute name with namespace

#### More examples

in_string                         | out_string
----------------------------------|------------
~/abc/.//def/../ns//ressource/    | /name/space/parameter\_pa\_node/abc/ns/ressource/
ns//.././..//ressource            | /name/space/ressource
../../../../../../ressource/      | /ressource/


## Example Usage

A typical output looks like this:
```
[ INFO] [1499357951.543886548]: load parameter ~/tf_lookup_time (0.1)
[ INFO] [1499357951.544331412]: parameter ~/buffer_pointcloud not set (defaults to false)
[ INFO] [1499357951.544867951]: load parameter ~/debugging (true)
```

Here is the related source code, which is taken from [pcdfilter_pa](https://github.com/TUC-ProAut/ros_pcdfilter/blob/master/src/pcdfilter_pa_node.cpp):
```
cParameterPaRos paramloader;

// ...
paramloader.load("~/tf_lookup_time"   , filters_.tf_lookup_time_     );
paramloader.load("~/buffer_pointcloud", rosparams_.buffer_pointcloud_);
paramloader.load("~/debugging"        , rosparams_.debugging_        );
```


## Links and packages

### Source code at github
https://github.com/TUC-ProAut/ros_parameter

### ROS packages
ros-kinetic-parameter-pa


## ROS Build-Status and Documentation

ROS-Distribution | Build-Status                                                                                                                                                            | Documentation
-----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------
Indigo           | EOL April 2019                                                                                                                                                          | [docs.ros.org/indigo](http://docs.ros.org/indigo/api/parameter_pa/html/index.html)
Jade             | EOL May 2017                                                                                                                                                            | [docs.ros.org/jade](http://docs.ros.org/jade/api/parameter_pa/html/index.html)
Kinetic          | EOL April 2021                                                                                                                                                          | [docs.ros.org/kinetic](http://docs.ros.org/kinetic/api/parameter_pa/html/index.html)
Lunar            | EOL May 2019                                                                                                                                                            | [docs.ros.org/lunar](http://docs.ros.org/lunar/api/parameter_pa/html/index.html)
Melodic          | [![Build Status](http://build.ros.org/buildStatus/icon?job=Mdev__parameter_pa__ubuntu_bionic_amd64)](http://build.ros.org/job/Mdev__parameter_pa__ubuntu_bionic_amd64/) | [docs.ros.org/melodic](http://docs.ros.org/melodic/api/parameter_pa/html/index.html)
Noetic           | [![Build Status](http://build.ros.org/buildStatus/icon?job=Ndev__parameter_pa__ubuntu_focal_amd64)](http://build.ros.org/job/Ndev__parameter_pa__ubuntu_focal_amd64/) | [docs.ros.org/melodic](http://docs.ros.org/melodic/api/parameter_pa/html/index.html)

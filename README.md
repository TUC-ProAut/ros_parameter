# ProAut Parameter

## Introduction

This is a simple helper-package for loading variables from the parameter server.

The main idea is to simplify the handling of parameters, which can be set to default values. The _load()_ function will print if a parameter is loaded from the server or if its default value is used. In each case, the final value is printed, too.

The main _load()_ function can handle bool, int, double and string - all as single values and as vectors. Also matrices of double (float) can be loaded.

Additionaly, there are two more dedicated load functions: _load_path()_ and _load_topic()_. Both are basically loading a simple string from the parameter server as descript above. Furthermore the strings are specificly manipulated:
* _load_path()_: Every "$(find xyz)" will be replaced with the path of package xyz.
* _load_topic()_: Names are resolved relativ to current namespace or node. "~xyz" will resolve to "/ns/current_node/xyz" and "/xyz" will resolve to "/ns/xyz" (not in namespace of current node).

## Example

A typical output looks like this:
```
[ INFO] [1499357951.543886548]: load parameter ~tf_lookup_time (0.1)
[ INFO] [1499357951.544331412]: parameter ~buffer_pointcloud not set (defaults to false)
[ INFO] [1499357951.544867951]: load parameter ~debugging (true)
```

Here is the related source code, which is taken from [pcdfilter_pa](https://github.com/peterweissig/ros_pcdfilter/blob/master/src/pcdfilter_pa_node.cpp):
```
cParameterPaRos paramloader;

// ...
paramloader.load("~tf_lookup_time"   , filters_.tf_lookup_time_     );
paramloader.load("~buffer_pointcloud", rosparams_.buffer_pointcloud_);
paramloader.load("~debugging"        , rosparams_.debugging_        );
```
## Links

Source code at github:

> https://github.com/peterweissig/ros_parameter

## ROS Build-Status and Documentation

ROS-Distribution | Build-Status | Documentation      
-----------------|--------------|---------------
Indigo | [![Build Status](http://build.ros.org/buildStatus/icon?job=Idev__parameter_pa__ubuntu_trusty_amd64)](http://build.ros.org/job/Idev__parameter_pa__ubuntu_trusty_amd64/) | [docs.ros.org](http://docs.ros.org/indigo/api/parameter_pa/html/index.html)
Jade | [![Build Status](http://build.ros.org/buildStatus/icon?job=Jdev__parameter_pa__ubuntu_trusty_amd64)](http://build.ros.org/job/Jdev__parameter_pa__ubuntu_trusty_amd64/) | [docs.ros.org](http://docs.ros.org/jade/api/parameter_pa/html/index.html)
Kinetic | [![Build Status](http://build.ros.org/buildStatus/icon?job=Kdev__parameter_pa__ubuntu_xenial_amd64)](http://build.ros.org/job/Kdev__parameter_pa__ubuntu_xenial_amd64/) | [docs.ros.org](http://docs.ros.org/kinetic/api/parameter_pa/html/index.html)
Lunar | [![Build Status](http://build.ros.org/buildStatus/icon?job=Ldev__parameter_pa__ubuntu_xenial_amd64)](http://build.ros.org/job/Ldev__parameter_pa__ubuntu_xenial_amd64/) | [docs.ros.org](http://docs.ros.org/lunar/api/parameter_pa/html/index.html)

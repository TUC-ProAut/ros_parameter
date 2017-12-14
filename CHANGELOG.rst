^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package parameter_pa
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1.2.1 (2017-12-14)
------------------
* bugfixed loadTopic (loaded topic was not resolved)
* bugfixed documentation (some typos)
* Contributors: Peter Weissig

1.2.0 (2017-12-11)
------------------
* removed unnecessary headers
* bugfixed include of xmlrpcpp
  (before kinetic those files were not related to a package)
* update README.md
  bugfixed formatting (missing blanc line before table)
* added new features ("./" and "../" within ressource names)
  added visual studio code config files (for ros kinetic)
  updated documentation
* Contributors: Peter Weissig

1.1.0 (2017-08-01)
------------------
* moved header from include/ to include/${project_name}
  also fixed related paths
* Contributors: Peter Weissig

1.0.2 (2017-07-31)
------------------
* updated year within license
* updated version number
* added install target to CMakeLists.txt
* Contributors: Peter Weissig

1.0.0
-----
* updated package.xml to format version 2
* updated doxygen.h and README.md
* updated CMakeLists.txt and package.xml
  added Eigen3
* updated git policies
* Initial commit
* Contributors: Peter Weissig

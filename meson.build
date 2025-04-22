project('BroodBox', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])


incdir = include_directories('include')
libdir = include_directories('libs')

executable('BroodBox',
           'src/BroodBox.cpp',
           'src/Simulation.cpp',
           'src/Wrapper.cpp',
           'src/Physics.cpp',
           'src/Hardware.cpp',
           install : true,
           include_directories : [incdir, libdir])
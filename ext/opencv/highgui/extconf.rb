require 'mkmf'

# not valid for C++ code
$warnflags = ($warnflags.split - %w(-Wdeclaration-after-statement -Wimplicit-function-declaration)) * ' '

# OpenCV includes
$INCFLAGS << ' -I ../include'

# Find stuff
if have_library('jpeg')
  $defs.push '-DHAVE_JPEG'
end

if have_library('tiff')
  $defs.push '-DHAVE_TIFF'
end

if have_library('png')
  $defs.push '-DHAVE_PNG'
end

if have_library('jasper')
  $defs.push '-DHAVE_JASPER'
end

create_header('cvconfig.h')

create_makefile("opencv_highgui")

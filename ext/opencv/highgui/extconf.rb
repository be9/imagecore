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

create_header('cvconfig.h')

create_makefile("opencv_highgui")

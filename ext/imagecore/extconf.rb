require 'mkmf'

# not valid for C++ code
$warnflags = ($warnflags.split - %w(-Wdeclaration-after-statement -Wimplicit-function-declaration)) * ' '

# OpenCV includes
$INCFLAGS << ' -I ../opencv/include'

create_makefile("imagecore")

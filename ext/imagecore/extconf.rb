require 'mkmf'

# not valid for C++ code
$warnflags = ($warnflags.split - %w(-Wdeclaration-after-statement -Wimplicit-function-declaration)) * ' '

# OpenCV includes
$INCFLAGS << ' -I OpenCV'

# Sources
$srcs = %w(analyze_image.cxx imagecore.cxx)

dir_config("imagecore")

create_makefile("imagecore")

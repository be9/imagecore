require 'mkmf'

# not valid for C++ code
if $warnflags
  $warnflags = ($warnflags.split - %w(-Wdeclaration-after-statement -Wimplicit-function-declaration)) * ' '
end

# OpenCV includes
inc = File.expand_path('../opencv/include', __FILE__)

$INCFLAGS << " -I #{inc}"

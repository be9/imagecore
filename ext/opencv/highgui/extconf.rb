require File.expand_path('../../../extconf_common', __FILE__)

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

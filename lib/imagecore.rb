require "imagecore/version"

dir = File.dirname(__FILE__)

require dir + '../../ext/opencv/core/opencv_core'
require dir + '../../ext/opencv/highgui/opencv_highgui'
require dir + '../../ext/opencv/imgproc/opencv_imgproc'
require dir + '../../ext/imagecore/imagecore'

module ImageCore
  def analyze(filename, threshold = 150)
    ImageCore::Ext::analyze(filename, threshold)
  end

  module_function :analyze
end

# -*- encoding: utf-8 -*-
require File.expand_path('../lib/imagecore/version', __FILE__)

Gem::Specification.new do |gem|
  gem.authors       = ["oleg dashevskii"]
  gem.email         = ["olegdashevskii@gmail.com"]
  gem.description   = %q{Determine the core of an image file, stripping any borders}
  gem.summary       = %q{Get image file core}
  gem.homepage      = "https://github.com/be9/imagecore"

  gem.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  gem.files         = `git ls-files`.split("\n")
  gem.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  gem.name          = "imagecore"
  gem.require_paths = ["lib"]
  gem.version       = ImageCore::VERSION

  gem.extensions    = %w(ext/opencv/core/extconf.rb ext/opencv/imgproc/extconf.rb
                         ext/opencv/highgui/extconf.rb ext/imagecore/extconf.rb)
end

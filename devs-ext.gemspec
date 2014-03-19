# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'devs/ext'

Gem::Specification.new do |spec|
  spec.name          = "devs-ext"
  spec.version       = DEVS::Ext::VERSION.dup
  spec.authors       = ["Romain Franceschini"]
  spec.email         = ["franceschini.romain@gmail.com"]
  spec.description   = %q{DEVS Extensions}
  spec.summary       = %q{C extensions to accelerate Ruby DEVS implementation}
  spec.homepage      = "https://github.com/romain1189/devs-ext"
  spec.license       = 'MIT'

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec)/})
  spec.require_paths = ['lib']

  spec.add_development_dependency('bundler', '~> 1.3')
  spec.add_development_dependency('yard', '~> 0.8')
  spec.add_development_dependency('rake')
  spec.add_development_dependency('minitest')
  spec.add_development_dependency('rake-compiler', '~> 0.9')
  spec.add_development_dependency('pry', '~> 0.9')

  spec.add_dependency('devs', '~> 1.0')

  if RUBY_PLATFORM =~ /java/
    spec.platform = "java"
  else
    spec.extensions = ['ext/devs/extconf.rb']
    spec.add_development_dependency('pry-nav')
    spec.add_development_dependency('pry-stack_explorer')
  end
end
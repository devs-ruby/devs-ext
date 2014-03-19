require 'bundler/gem_tasks'
require 'rake/testtask'
require 'rake/extensiontask'
require 'rake/javaextensiontask'

if RUBY_PLATFORM =~ /java/
  Rake::JavaExtensionTask.new('devs') do |ext|
    ext.ext_dir = 'ext/java/devs'
    ext.lib_dir = 'lib/devs'
  end
else
  Rake::ExtensionTask.new('devs') do |ext|
    ext.ext_dir = 'ext/devs'
    ext.lib_dir = 'lib/devs'
  end
end

Rake::TestTask.new do |t|
  t.libs = ['lib', 'spec', 'test']
  t.test_files = FileList['test/**/*_test.rb']
end

desc "Clean, compile and run tests"
task :default => [:clean, :compile, :test]

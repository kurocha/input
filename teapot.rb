# Teapot v3.0.0 configuration generated at 2019-02-23 16:51:42 +1300

required_version "3.0"

define_project "input" do |project|
	project.title = "Input"
	
	project.license = "MIT License"
	
	project.add_author 'Samuel Williams', email: 'samuel.williams@oriontransfer.co.nz'
end

# Build Targets

define_target 'input-library' do |target|
	target.depends 'Language/C++14'
	
	target.depends 'Library/Streams'
	target.depends 'Library/Logger'
	
	target.depends 'Library/Time', public: true
	target.depends 'Library/Parallel', public: true
	target.depends 'Library/Numerics', public: true
	target.depends 'Library/Geometry', public: true
	
	target.provides 'Library/Input' do
		source_root = target.package.path + 'source'
		
		library_path = build static_library: 'Input', source_files: source_root.glob('Input/**/*.cpp')
		
		append linkflags library_path
		append header_search_paths source_root
	end
end

define_target 'input-test' do |target|
	target.depends 'Library/Input'
	target.depends 'Library/UnitTest'
	
	target.depends 'Language/C++14'
	
	target.provides 'Test/Input' do |arguments|
		test_root = target.package.path + 'test'
		
		run tests: 'Input', source_files: test_root.glob('Input/**/*.cpp'), arguments: arguments
	end
end

# Configurations

define_configuration 'development' do |configuration|
	configuration[:source] = "https://github.com/kurocha"
	configuration.import "input"
	
	# Provides all the build related infrastructure:
	configuration.require 'platforms'
	
	# Provides unit testing infrastructure and generators:
	configuration.require 'unit-test'
	
	# Provides some useful C++ generators:
	configuration.require 'generate-cpp-class'
	
	configuration.require "generate-project"
end

define_configuration "input" do |configuration|
	configuration.public!
	
	configuration.require "time"
	configuration.require "numerics"
	configuration.require "geometry"
	configuration.require "parallel"
	
	configuration.require "logger"
	configuration.require "streams"
end

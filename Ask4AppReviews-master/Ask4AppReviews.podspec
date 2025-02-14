Pod::Spec.new do |s|
  s.name         = "Ask4AppReviews"
  s.version      = "0.1"
  s.summary      = "Reminds iPhone app's users to review the app, but also asks for feedback (through email) if the user is having issues" 
  s.description  = <<-DESC
Ask4AppReviews is a class that you can drop into any iPhone app (iOS 5.0 or later) that will help remind your users to review your app on the App Store. The code is released under the MIT/X11, so feel free to modify and share your changes with the world. To find out more, check out the homepage.
                   DESC
  s.homepage     = "http://lukedurrant.com/2012/07/appirater-github-fork/"
  s.screenshots  = "http://lukedurrant.com/wp-content/uploads/2012/06/hackbookfeedback.jpg"
  s.license      = 'MIT/X11'
  s.author       = { "Luke Durrant" => "http://lukedurrant.com/contact/" }
  s.source       = { :git => "https://github.com/LukeDurrant/Ask4AppReviews.git", :tag => s.version.to_s}

  s.platform     = :ios, '5.0'
  # s.ios.deployment_target = '5.0'
  # s.osx.deployment_target = '10.7'
  s.requires_arc = true

  s.source_files = 'Ask4AppReviews.m', 'Ask4AppReviews.h'
  # s.resources = 'Assets'

  # s.ios.exclude_files = 'Classes/osx'
  # s.osx.exclude_files = 'Classes/ios'
  # s.public_header_files = 'Classes/**/*.h'
  s.frameworks = 'CFNetwork', 'SystemConfiguration', 'MessageUI'
  # s.dependency 'JSONKit', '~> 1.4'
end

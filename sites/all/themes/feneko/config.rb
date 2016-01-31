
# as a default susy is included
require 'rubygems'
require 'bundler/setup'


# Require any additional compass plugins here.
require "gridle"

# Set this to the root of your project when deployed:
http_path = "/"
css_dir = "css"
sass_dir = "sass"
images_dir = "img"
javascripts_dir = "js"

# Optimize sprites
# will break if you dont have ImageOptim installed
on_sprite_saved do |file|
  optimize(file, 'ImageOptim')
end

# methods
def optimize(file, image_app)
  system 'open -a ' + image_app + '.app ' + file
  # growl('Sprite: ' + File.basename(file) + ' optimized')
end

# You can select your preferred output style here (can be overridden via the command line):
# output_style = :expanded or :nested or :compact or :compressed
output_style = :expanded

# To enable relative paths to assets via compass helper functions. Uncomment:
relative_assets = true

# To disable debugging comments that display the original location of your selectors. Uncomment:
line_comments = false
# sass_options = { :debug_info => true } # This is required for fireSASS to work

# If you prefer the indented syntax, you might want to regenerate this
# project again passing --syntax sass, or you can uncomment this:
# preferred_syntax = :sass
# and then run:
# sass-convert -R --from scss --to sass sass scss && rm -rf sass && mv scss sass

# DEVS Extensions - Discrete Event Specification System

C extensions to accelerate Ruby DEVS implementation

## Installation

Install it as:

    $ gem install devs
    $ gem install devs-ext

Inside of your Ruby program do:

    require 'devs'
    require 'devs/ext'

...to pull it in as a dependency.

## Usage

```ruby
require 'devs'
require 'devs/ext'

DEVS.simulate do
  # ...
end
```

## Suggested Reading

* Bernard P. Zeigler, Herbert Praehofer, Tag Gon Kim. *Theory of Modeling and Simulation*. Academic Press; 2 edition, 2000. ISBN-13: 978-0127784557

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

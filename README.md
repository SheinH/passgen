# passgen
passgen is a Unix philosophy utility for generating random passwords in the style of Safari:

![Safari passwords](https://i.imgur.com/CJfHg5d.png)


passgen makes random passwords that look like this:

    o6uaFo-vvypoc-ucbbtn

Usually this makes for a secure password while satisfying the length and
character requirements of most websites. Passgen makes use of [libsodium](https://github.com/jedisct1/libsodium)
to ensure that all generated passwords are cryptographically secure.

## Usage

To build passgen:

1. Install `pkg-config` and `libsodium` from your package manager
2. Clone this repository then `cd` into its directory
2. Run `build.sh`

To use passgen, simply execute the passgen binary.

On MacOS, passgen can also be piped into the system clipboard using this command

    passgen | pbcopy

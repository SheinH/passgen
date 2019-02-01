# passgen
passgen is a Unix philosophy utility for generating random passwords in the style of Safari:

![Safari passwords](https://i.imgur.com/cihqhzS.png)


passgen makes random passwords that look like this:

    o6uaFo-vvypoc-ucbbtn

Usually this makes for a secure password while satisfying the length and
character requirements of most websites.

## Usage

To build passgen:

1. Install `pkg-config` and `libsodium` from your package manager
2. Clone this repository and `cd` into it
2. Run `build.sh`

To use passgen, simply execute the passgen executable.

On MacOS, passgen can also be piped into the system clipboard using this command

    passgen | pbcopy

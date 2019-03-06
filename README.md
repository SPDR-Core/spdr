![SPDR Logo](src/qt/res/images/spdr_logo_horizontal.png)

"SpiderVPS - is the future of vps hosting"

[![HitCount](http://hits.dwyl.io/216k155/spdr.svg)](http://hits.dwyl.io/216k155/spdr)
<a href="https://discord.gg/vqzqWJg"><img src="https://discordapp.com/api/guilds/518071066678263815/widget.png" alt="Discord server" /></a> <a href="https://twitter.com/intent/follow?screen_name=SPDRCOIN"><img src="https://img.shields.io/twitter/follow/SPDRCOIN.svg?style=social&logo=twitter" alt="follow on Twitter"></a>
                                                                                                                                                     
[Website](https://spidervps.net) — [Block Explorer](http://explorer.spidervps.net/) — [Forum](https://bitcointalk.org/index.php?topic=5116197) — [Twitter](https://twitter.com/SPDRCOIN)


=============

* Hybrid PoW/PoS algorithm
* Hybrid masternode
* Segwit
* Smart contract (soon)
* PHI2 PoW/PoS hybrid algorithm

Spider VPS is the first social vps hosting platform based on blockchain technology aimed at creating a strong community around it and offering high-tech services  

## Coin Specifications

| Specification | Value |
|:-----------|:-----------|
| Total Blocks | `1,000,000` |
| Block Size | `4MB` |
| Block Time | `60s` |
| PoW Block Time | `120s`   |
| PoW Reward | `0.1-35 SPDR` |
| PoS Reward | `0.1-7 SPDR` |
| Stake Time | `1 hour` | 
| Masternode Requirement | `7000 SPDR` |
| Masternode Reward | `Dynamic` |
| Port | `53617` |
| RPC Port | `53616` |
| Masternode Port | `53617` |
| Spider legacy address start with | `S` |
| p2sh-segwit address start with | `D` |
| Bech32 address start with | `bc` |

* NOTE: "getrawchangeaddress p2sh-segwit" to get p2sh-segwit address 

Instructions

Build Spider wallet
----------

### Building for 32-bit Windows

The next three steps are an example of how to acquire the source and build in an appropriate way.
        
Acquire the source and install dependencies.

    git clone https://github.com/SPDR-Core/spdr
    sudo chmod -R a+rw spdr
    cd spdr/depends
    ./install-dependencies.sh
    
Set the default mingw-w32 g++ compiler option to auto (option 0) by default.

    sudo update-alternatives --config i686-w64-mingw32-g++
    
Build in the usual way.

    ./build-wins.sh
    
### Building for 64-bit Windows   

The next three steps are an example of how to acquire the source and build in an appropriate way.
        
Acquire the source and install dependencies.

    git clone https://github.com/SPDR-Core/spdr
    sudo chmod -R a+rw spdr
    cd spdr/depends
    ./install-dependencies.sh
    
Set the default mingw-w64 g++ compiler option to posix (option 1).

    sudo update-alternatives --config x86_64-w64-mingw32-g++
    
Build in the usual way.

    ./build-wins.sh x64

### Build on Ubuntu

Use

    sudo add-apt-repository ppa:bitcoin/bitcoin; git clone https://github.com/SPDR-Core/spdr; cd spdr; depends/install-dependencies.sh; ./autogen.sh; ./configure --disable-tests --with-boost-libdir=/usr/local/lib; make clean; make -j$(nproc)



Build spdr 

    cd spdr
    ./depends/install-dependencies.sh
    ./autogen.sh
    ./configure --disable-tests
    make -j$(nproc)

### Build on OSX

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

#### Preparation

Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

If you're running macOS Mojave 10.14/Xcode 10.0 or later, and want to use the depends system, you'll also need to use the following script to install the macOS system headers into /usr/include.

    open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg

Then install [Homebrew](https://brew.sh)

    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

#### Dependencies

    brew install cmake automake berkeley-db4 leveldb libtool boost@1.64 --c++11 --without-single --without-static miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick --with-librsvg

Link boost 1.64

    brew link boost@1.64 --force

#### Build Spidercore

Clone the Spider source code and cd into spdr

        git clone https://github.com/SPDR-Core/spdr
        cd spdr
        ./building/mac/requirements.sh
        ./building/mac/build.sh

Setup and Build: Arch Linux
-----------------------------------
This example lists the steps necessary to setup and build a command line only, non-wallet distribution of the latest changes on Arch Linux:

    pacman -S git base-devel boost libevent python
    git clone https://github.com/SPDR-Core/spdr
    cd spdr/
    ./autogen.sh
    ./configure --without-miniupnpc --disable-tests
    make -j$(nproc)

Note:
Enabling wallet support requires either compiling against a Berkeley DB newer than 4.8 (package `db`) using `--with-incompatible-bdb`,
or building and depending on a local version of Berkeley DB 4.8. The readily available Arch Linux packages are currently built using
`--with-incompatible-bdb` according to the
As mentioned above, when maintaining portability of the wallet between the standard Bitcoin Core distributions and independently built
node software is desired, Berkeley DB 4.8 must be used.


ARM Cross-compilation
-------------------
These steps can be performed on, for example, an Ubuntu VM. The depends system
will also work on other Linux distributions, however the commands for
installing the toolchain will be different.

Make sure you install the build requirements mentioned above.
Then, install the toolchain and curl:

    sudo apt-get install g++-arm-linux-gnueabihf curl

To build executables for ARM:

    cd depends
    make HOST=arm-linux-gnueabihf NO_QT=1
    cd ..
    ./configure --prefix=$PWD/depends/arm-linux-gnueabihf --enable-glibc-back-compat --enable-reduce-exports LDFLAGS=-static-libstdc++
    make -j$(nproc)

For further documentation on the depends system see [README.md](../depends/README.md) in the depends directory.

Building on FreeBSD
--------------------

Clang is installed by default as `cc` compiler, this makes it easier to get
started than on [OpenBSD](build-openbsd.md). Installing dependencies:

    pkg install autoconf automake libtool pkgconf
    pkg install boost-libs openssl libevent
    pkg install gmake

You need to use GNU make (`gmake`) instead of `make`.
(`libressl` instead of `openssl` will also work)

For the wallet (optional):

    ./contrib/install_db4.sh `pwd`
    setenv BDB_PREFIX $PWD/db4

Then build using:

    ./autogen.sh
    ./configure BDB_CFLAGS="-I${BDB_PREFIX}/include" BDB_LIBS="-L${BDB_PREFIX}/lib -ldb_cxx"
    gmake

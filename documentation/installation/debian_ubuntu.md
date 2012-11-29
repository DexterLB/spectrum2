---
layout: page
title: Spectrum 2
---

We have APT repositories for Debian and Ubuntu that make it very easy to install Spectrum 2.

To use the repositories, just add the following lines to @/etc/apt/sources.list@:

	deb http://packages.spectrum.im $dist spectrum2

where $dist is either lenny, squeeze, hardy, intrepid, jaunty, karmic or lucid. If you are unsure, you can usually find your distribution in the file /etc/lsb-release. We also have a source repository at the same location if you want to build the package yourself.

### Add GPG key

After you have added the repository, you still have to import the GPG key that is used to sign the packages in the repository. You can do this in two ways:

You can download and add the key manually (apt-key requires root privileges):

	wget -O - http://packages.spectrum.im/keys/apt-repository@fsinf.at | apt-key add -

You can simply update the repositories and install the fsinf-keyring packages:

	apt-get update
	apt-get install fsinf-keyring
	apt-get update

Don’t worry about the warnings that the packages can’t be identified, they will be gone after you installed the fsinf-keyring package.

### Install spectrum2 - development version

After you have done that, simply do:

	apt-get install spectrum2 spectrum2-backend-libpurple

Note that these repositories pull in quite a few dependencies, depending on the distribution you use.

# bondSafe

Does shit when a bluetooth device around you disappears!

Loosely based on https://www.youtube.com/watch?v=-bpX8YvNg6Y @ 52:00


# What it does right now
Only scans, and checks for the mac provided, if it doesn't find it in the few iterations it's hardcoded to now it will quit (4 * 15 seconds scans).

It will also print all the devices with resolved names it finds in the scans, you can simply run it once with a fake MAC if you don't know your devices MAC and simply place it near your computer, it will shortly print it assuming it is enabled and all, do it as so:

> ./bondsafe 00:11:22:33:44:55

And then you can run it with the correct MAC later.

Future usage will be something like
>./bondsafe [MAC] <List of commands to run/devices to unmount/files to delete> 


# How to build
> cd src
> make all

# Requirements
> * GCC
> * libbluetooth-devel (debian/ubuntu? I think?)
> * bluez-libs (Fedora)
> * bluez-libs-devel (Fedora)

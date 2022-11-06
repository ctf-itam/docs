# ctf@itam_course_docs

## what_is_this

this repository contains docs for the ctf course at itam (at nust misis).
we post our debriefs here, and we also link our students' notes.

## how_to_clone

to clone this repository, you need to have git installed. if you don't have it, you can install it with:

```bash
# debian/ubuntu
sudo apt install git

# arch
sudo pacman -S git  # if the command errors out, you need to update your repo cache (see below)
# `sudo pacman -Syu` will update your repo cache and upgrade your system (partial upgrades are discouraged)
```

then, you can clone this repository with:

```bash
git clone --recurse-submodules -j8 <repository link>
```

after cloning, can navigate the repository with your favorite file manager, or with terminal commands.

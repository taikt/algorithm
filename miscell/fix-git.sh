#!/bin/sh

find .git/objects/ -type f -empty | xargs rm
git fetch -p
git fsck --full

-- tips
 git ls-files --deleted -z | xargs -0 git rm

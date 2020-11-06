#! /bin/sh
# setup to to board
adb push mytest.service /etc/systemd/system/.
adb shell chmod 777 /etc/systemd/system/mytest.service
adb push test /usr/bin/.
adb shell chmod 777 /usr/bin/test

#on board
# systemctl start mytest
# systemctl enable mytest (to allow run at boot time)
# systemctl disable mytest (to disallow run at boot time)
# -- after reboot, if cannot access device from adb
# adb kill-server


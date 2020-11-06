#! /bin/sh
# setup on local PC
g++ -o test main.cpp
sudo cp -rf mytest.service /etc/systemd/system/.
sudo chmod 777 /etc/systemd/system/mytest.service
sudo cp -rf test /usr/bin/.
sudo chmod 777 /usr/bin/test

systemctl start mytest
journalctl -u mytest -f

# to stop service
# systemctl stop mytest

# to check status
# systemctl status mytest

# to run at boot time
# systemtctl enable mytest

# to stop at boot time
# systemctl disable mytest

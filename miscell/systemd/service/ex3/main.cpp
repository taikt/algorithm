#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cerrno>
#include <unistd.h>
#include <syslog.h>

#define PREFIX_NOTICE "<5>"

/*
 *  log levels defined in syslog
 *  LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR, LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG
 *  https://linux.die.net/man/3/syslog
 *  
 *  build daemon named "test", service named mytest.service
 *  -- to see log a service in systemd by syslog
 *  journalctl -u service_name -f (i.e journalctl -u mytest -f)
 *  or journalctl _PID=id -f
 *  -- add service to systemd
 *  cp -rf mytest.service /etc/systemd/system/.
 *  cp -rf test /usr/bin/.  
 *  systemctl start mytest
 *  systemctl status mytest
 *  -- enable service run automatically at boot
 *  systemctl enable mytest  (https://www.linode.com/docs/quick-answers/linux/start-service-at-boot/)
 * 
 *
 */

int main() {
    // https://linux.die.net/man/3/setlogmask
    // https://stackoverflow.com/questions/18685774/syslog-not-logging-my-program-log-entries
    setlogmask (LOG_UPTO (LOG_DEBUG)); //enable logging from EMer to Debug level.
    syslog(LOG_NOTICE,"tai2.tran started test service..");

    while (1) {
        printf(PREFIX_NOTICE "tai2.tran, testing service\n"); //print log when run as normal program or daemon
        syslog(LOG_NOTICE,"tai2.tran running.."); // logging via syslog, only logging when service is run as a daemon

        sleep(2);
    }

    return 0;
}

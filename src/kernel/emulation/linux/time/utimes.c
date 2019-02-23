#include "utimes.h"
#include "../base.h"
#include "../errno.h"
#include <linux-syscalls/linux.h>

long sys_utimes(const char* path, struct bsd_timeval* tv)
{
	int ret;
	struct linux_timeval ltv[2];

	if (tv) {
		ltv[0].tv_sec = tv[0].tv_sec;
		ltv[0].tv_usec = tv[0].tv_usec;
		ltv[1].tv_sec = tv[1].tv_sec;
		ltv[1].tv_usec = tv[1].tv_usec;
	}

	ret = LINUX_SYSCALL(__NR_utimes, path, tv ? ltv : 0);
	if (ret < 0)
		ret = errno_linux_to_bsd(ret);

	return ret;
}

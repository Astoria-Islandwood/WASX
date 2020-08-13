#ifndef __SANDBOX_ROOTLESS_H__
#define __SANDBOX_ROOTLESS_H__

int rootless_allows_task_for_pid(pid_t pid);

int rootless_restricted_environment();
int rootless_check_trusted(const char* path);

#endif
